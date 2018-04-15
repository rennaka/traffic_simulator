#include <GL/glut.h>
#include "display_window.cpp"

int WindowPositionX = 100;  //生成するウィンドウ位置のX座標
int WindowPositionY = 100;  //生成するウィンドウ位置のY座標
Coordinate window_position(WindowPositionX,WindowPositionY);
int WindowWidth = 512;    //生成するウィンドウの幅
int WindowHeight = 512;    //生成するウィンドウの高さ
char WindowTitle[] = "Traffic_simulator";  //ウィンドウのタイトル

int main(int argc, char *argv[]){
  DisplayWindow window(argc,argv,&window_position,WindowWidth,WindowHeight,WindowTitle);
  return 0;
}
