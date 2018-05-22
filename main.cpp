#include <GL/glut.h>
#include <fstream>
#include <vector>       // ヘッダファイルインクルード
#include "coordinate.cpp"
#include "set_color.cpp"
#include "draw.cpp"
#include "road.cpp"
#include "speed.cpp"
#include "car.cpp"
using namespace std;

Coordinate window_position(100,100);
int WindowWidth = 512;    //生成するウィンドウの幅
int WindowHeight = 512;    //生成するウィンドウの高さ
char WindowTitle[] = "Traffic_simulator";  //ウィンドウのタイトル
static vector<Car*> cars;

void Definition_Road(){
  Road(50, new Coordinate(-1.0,0), new Coordinate(1.0,0));
  Road(50, new Coordinate(0,-1.0), new Coordinate(0,1.0));
}

void Definition_Cars(){
  ifstream ifs("car_data.txt");
  string str;
  if(ifs.fail()) {
		exit(0);
	}
  while(getline(ifs, str)) {
    float start_position_x,start_position_y,start_speed_x,start_speed_y;
    char direction;
		sscanf(str.data(), "%f,%f,%f,%f,%c", &start_position_x, &start_position_y, &start_speed_x, &start_speed_y, &direction);
    cars.push_back(new Car(new Coordinate(start_position_x,start_position_y), new Speed(start_speed_x,start_speed_y),direction));
	}
}

void Definition_Content(void) {
  Definition_Road();
  Definition_Cars();
}

void Display_Content(void) {
  for(int i = 0; i < cars.size(); i++) {
    cars[i]->Run();
  }
}

int main(int argc, char *argv[]){
  glutInitWindowPosition(window_position.get_x(),window_position.get_y());//ウィンドウの位置の指定
  glutInitWindowSize(WindowWidth,WindowHeight); //ウィンドウサイズの指定
  glutInit(&argc, argv);//環境の初期化
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);//ディスプレイモードの指定
  glutCreateWindow(WindowTitle);  //ウィンドウの作成
  Set_Color::background();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //バッファの消去
  glutSwapBuffers();
  glEnable(GL_DEPTH_TEST);//デプスバッファを使用：glutInitDisplayMode() で GLUT_DEPTH を指定する
  glClear( GL_COLOR_BUFFER_BIT );
  glutDisplayFunc(Definition_Content); //描画時に呼び出される関数を指定する（関数名：Display）
  glutIdleFunc(Display_Content);
  glutMainLoop();
  return 0;
}

// void timer(int value) {
//   glutPostRedisplay();
//   glutTimerFunc(100, timer, 0);
// }
