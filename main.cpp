#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <vector>       // ヘッダファイルインクルード
#include <math.h>
#include "const.cpp"
#include "coordinate.cpp"
#include "set_color.cpp"
#include "signal.cpp"
#include "road.cpp"
#include "velocity.cpp"
#include "car.cpp"
using namespace std;

Coordinate window_position(100,100);
int WindowWidth = 1024;    //生成するウィンドウの幅
int WindowHeight = 1024;    //生成するウィンドウの高さ
char WindowTitle[] = "Traffic_simulator";  //ウィンドウのタイトル
vector<Car*> cars;
TrafficSignal* traffic_signal;
int count = 0;

void Definition_Road(){
  Road(50, new Coordinate(-1.0,0), new Coordinate(1.0,0));
  Road(50, new Coordinate(0,-1.0), new Coordinate(0,1.0));
}

void Definition_Signal(){
  extern TrafficSignal* traffic_signal;
  traffic_signal = new TrafficSignal(40,15,15,2,3,new Coordinate(0,0),0.1,0.1);
}

void Definition_Cars(){
  ifstream ifs("car_data.csv");
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

void Display_Content(void) {
  Run_Car();
  extern TrafficSignal* traffic_signal;
  traffic_signal->Change(count * Const::dt);
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
