#include "set_color.h"

void Set_Color::background(){
  glClearColor(0.6, 0.8, 0.8, 1.0); //背景色
}

void Set_Color::road(){
  glColor3d( 1.0, 1.0, 1.0);
}

void Set_Color::car(){
  glColor3d( 0.0, 0.0, 0.0);
}

void Set_Color::green_signal(){
  glColor3d( 0.0, 1.0, 1.0);
}

void Set_Color::yellow_signal(){
  glColor3d( 1.0, 1.0, 0.0);
}

void Set_Color::red_signal(){
  glColor3d( 1.0, 0.0, 0.0);
}
