#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <vector>       // ヘッダファイルインクルード
#include <math.h>
#include "const.cpp"
#include "coordinate.cpp"
#include "set_color.cpp"
#include "draw.cpp"
#include "road.cpp"
#include "velocity.cpp"
#include "car.cpp"
#include "signal.cpp"
using namespace std;

Coordinate window_position(100,100);
int WindowWidth = 1024;    //生成するウィンドウの幅
int WindowHeight = 1024;    //生成するウィンドウの高さ
char WindowTitle[] = "Traffic_simulator";  //ウィンドウのタイトル
vector<Car*> cars;
Signal* traffic_signal;
// vector<Signal*> traffic_signals;
int count = 0;
/*
  座標1が1km相当、最高速度は54km/h = 15m/s つまりコード上では0.015で表現
*/
void Definition_Road(){
  Road(50, new Coordinate(-1.0,0), new Coordinate(1.0,0));
  Road(50, new Coordinate(0,-1.0), new Coordinate(0,1.0));
}

void Definition_Signal(){
  // traffic_signals.push_back(new Signal(90,40,40,2,3,new Coordinate(0,0),0.1,0.1));
  traffic_signal = new Signal(90,40,40,2,3,new Coordinate(0,0),0.1,0.1);
}

void Definition_Cars(){
  ifstream ifs("car_data.txt");
  string str;
  if(ifs.fail()) {
		exit(0);
	}
  while(getline(ifs, str)) {
    int id;
    float start_position_x,start_position_y,start_speed;
    char direction;
		sscanf(str.data(), "%i,%f,%f,%f,%c",&id, &start_position_x, &start_position_y, &start_speed, &direction);
    cars.push_back(new Car(id, new Coordinate(start_position_x,start_position_y), new Velocity(start_speed / Const::scale, direction)));
	}
}

void Definition_Content(void) {
  Definition_Road();
  Definition_Signal();
  Definition_Cars();
  glutSwapBuffers();
}

void Run_Car(){
  for(int i = 0; i < cars.size(); i++) {
    extern vector<Car*> cars;
    cars[i]->Run();
  }
}

// void Change_signals(){
//   for(int i = 0; i < traffic_signals.size(); i++) {
//     extern vector<Signal*> traffic_signals;
//     traffic_signals[i]->Change(count * Const::dt);
//   }
// }

void Display_Content(void) {
  Run_Car();
  extern Signal* traffic_signal;
  traffic_signal->Change(count * Const::dt);
  // Change_signals();
  count++;
  std::cout << count <<std::endl;
  glutSwapBuffers();
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
