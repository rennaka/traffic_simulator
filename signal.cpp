#include "signal.h"
using namespace std;

TrafficSignal::TrafficSignal(float init_cycle_length, float init_EW_green_length, float init_NS_green_length, float init_yellow_length, float init_all_red_length, Coordinate* init_position, float init_EW_line_distance, float init_NS_line_distance)
: cycle_length(init_cycle_length), EW_green_length(init_EW_green_length), NS_green_length(init_NS_green_length), yellow_length(init_yellow_length), all_red_length(init_all_red_length), position(init_position), EW_line_distance(init_EW_line_distance), NS_line_distance(init_NS_line_distance), EW_color('G'), NS_color('R'),
E_line_position(new Coordinate(init_position->get_x() - EW_line_distance, 0.02)), W_line_position(new Coordinate(init_position->get_x() + EW_line_distance, -0.02)), N_line_position(new Coordinate(-0.02,init_position->get_y() - NS_line_distance)), S_line_position(new Coordinate(0.02,init_position->get_y() + NS_line_distance))
{
}

TrafficSignal::~TrafficSignal(){
}

void TrafficSignal::Change(float elapsed_time){
  float time_in_loop = fmod(elapsed_time,cycle_length);
  glLineWidth(3);
  set_EW_color(time_in_loop);
  set_signal_color(EW_color);
  glBegin( GL_LINES );
    glVertex2d(position->get_x() + EW_line_distance, position->get_y());
    glVertex2d(position->get_x() + EW_line_distance, position->get_y() - 0.07);
  glEnd();
  glBegin( GL_LINES );
    glVertex2d(position->get_x() - EW_line_distance, position->get_y());
    glVertex2d(position->get_x() - EW_line_distance, position->get_y() + 0.07);
  glEnd();
  set_NS_color(time_in_loop);
  set_signal_color(NS_color);
  glBegin( GL_LINES );
    glVertex2d(position->get_x() , position->get_y() + NS_line_distance);
    glVertex2d(position->get_x() + 0.05 , position->get_y() + NS_line_distance);
  glEnd();
  glBegin( GL_LINES );
    glVertex2d(position->get_x() , position->get_y() - NS_line_distance);
    glVertex2d(position->get_x() - 0.05 , position->get_y() - NS_line_distance);
  glEnd();
}

void TrafficSignal::set_EW_color(float time_in_loop){
  if (0 <= time_in_loop && time_in_loop <= EW_green_length) {
    EW_color = 'G';
  } else if (EW_green_length <= time_in_loop && time_in_loop <= EW_green_length + yellow_length){
    EW_color = 'Y';
  } else{
    EW_color = 'R';
  }
}

void TrafficSignal::set_NS_color(float time_in_loop){
  if (EW_green_length + yellow_length + all_red_length <= time_in_loop && time_in_loop <= cycle_length - yellow_length - all_red_length) {
    NS_color = 'G';
  } else if (cycle_length - yellow_length - all_red_length <= time_in_loop && time_in_loop <= cycle_length - all_red_length){
    NS_color = 'Y';
  } else{
    NS_color = 'R';
  }
}

void TrafficSignal::set_signal_color(char color){
  switch (color) {
  case 'G':
    Set_Color::green_signal();
    break;
  case 'Y':
    Set_Color::yellow_signal();
    break;
  case 'R':
    Set_Color::red_signal();
    break;
  }
}
