#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <vector>       // ヘッダファイルインクルード
#include <math.h>
#include <stdlib.h>
#include <time.h>
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
int vehicle_count = 0;
bool signal_use = false;  //信号を使う特はtrueにする 読み込みファイルの変更忘れずに

void Definition_Road(){
  Road(30, new Coordinate(-1.0,0), new Coordinate(1.0,0));
  if (signal_use) {
    Road(30, new Coordinate(0,-1.0), new Coordinate(0,1.0));
  }
}

void Definition_Signal(){
  extern TrafficSignal* traffic_signal;
  traffic_signal = new TrafficSignal(70,30,30,2,3,new Coordinate(0,0),0.04,0.06);
}

void Definition_Cars(){
  ifstream ifs("car_data.csv");
  string str;
  bool is_first_data = true;
  if(ifs.fail()) {
		exit(0);
	}
  while(getline(ifs, str)) {
    int id;
    double start_position_x,start_position_y,start_speed;
    char direction;
    srand(time(NULL));
    if (str[0] == ',') {
      break;
    } else if (is_first_data) {
      is_first_data = false;
      continue;
    }
		sscanf(str.data(), "%i,%lf,%lf,%lf,%c",&id, &start_position_x, &start_position_y, &start_speed, &direction);
    cars.push_back(new Car(id, new Coordinate(start_position_x,start_position_y), new Velocity(start_speed / Const::scale, direction), Const::base_max_speed + Const::optinal_max_speed * (double)rand()/RAND_MAX));
	}
}

void Definition_Content(void) {
  Definition_Road();
  if (signal_use) {
    Definition_Signal();
  }
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
  if (signal_use) {
    extern TrafficSignal* traffic_signal;
    traffic_signal->Change(count * Const::dt);
  }
  count++;
  if (count == 3000) {
    glutIdleFunc(NULL);
  }
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
