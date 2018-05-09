#include <GL/glut.h>
#include "coordinate.cpp"
#include "road.cpp"
#include "speed.cpp"
#include "car.cpp"

Coordinate window_position(100,100);
int WindowWidth = 512;    //生成するウィンドウの幅
int WindowHeight = 512;    //生成するウィンドウの高さ
char WindowTitle[] = "Traffic_simulator";  //ウィンドウのタイトル
static Road* road;
static Car* car1;

void Definition_Content(void) {
  Coordinate start_position(-1.0,0);
  Coordinate end_position(1.0,0);
  road = new Road(50,&start_position,&end_position);
  road->Create();
}

  void Display_Content(void) {
    if (!car1) {
      Coordinate car1_start_position(1.0,0);
      Speed car1_speed(-0.003,0);
      car1 = new Car(&car1_start_position,&car1_speed);
    }
    car1->Run();
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
