#include <GL/glut.h>
#include <vector>       // ヘッダファイルインクルード
#include "coordinate.cpp"
#include "road.cpp"
#include "speed.cpp"
#include "car.cpp"
using namespace std;

Coordinate window_position(100,100);
int WindowWidth = 512;    //生成するウィンドウの幅
int WindowHeight = 512;    //生成するウィンドウの高さ
char WindowTitle[] = "Traffic_simulator";  //ウィンドウのタイトル
static vector<Road*> roads;
static vector<Car*> cars;

void Definition_Content(void) {
  // Coordinate start_position(-1.0,0);
  // Coordinate end_position(1.0,0);
  // for(int i = 0; i < roas.size(); i++) {
  //   roads[i]->Run();
  // }
  Road(50, new Coordinate(-1.0,0), new Coordinate(1.0,0));
  // roads.push_back(new Road(50,new Coordinate(-1.0,0),new Coordinate(1.0,0)));
  // road->Create();
  cars.push_back(new Car(new Coordinate(1.0,0.02), new Speed(-0.003,0),'S'));
  cars.push_back(new Car(new Coordinate(-1.0,-0.02), new Speed(0.004,0),'L'));
}

void Display_Content(void) {
  for(int i = 0; i < cars.size(); i++) {
    cars[i]->Run();
  }
}

void timer(int value) {
  glutPostRedisplay();
  glutTimerFunc(100, timer, 0);
}

int main(int argc, char *argv[]){
  glutInitWindowPosition(window_position.get_x(),window_position.get_y());//ウィンドウの位置の指定
  glutInitWindowSize(WindowWidth,WindowHeight); //ウィンドウサイズの指定
  glutInit(&argc, argv);//環境の初期化
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);//ディスプレイモードの指定
  glutCreateWindow(WindowTitle);  //ウィンドウの作成
  glClearColor(0.6, 0.8, 0.8, 1.0); //背景色
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //バッファの消去
  glutSwapBuffers();
  glEnable(GL_DEPTH_TEST);//デプスバッファを使用：glutInitDisplayMode() で GLUT_DEPTH を指定する
  glClear( GL_COLOR_BUFFER_BIT );
  glutDisplayFunc(Definition_Content); //描画時に呼び出される関数を指定する（関数名：Display）
  glutIdleFunc(Display_Content);
  glutMainLoop();
  return 0;
}
