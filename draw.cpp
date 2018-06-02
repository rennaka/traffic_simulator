#include "draw.h"
using namespace std;

// extern vector<Signal*> traffic_signals;
extern Signal* traffic_signal;

void Draw::car(Coordinate* position){
  glPointSize(3);
  glBegin(GL_POINTS);
    glVertex2d(position->get_x() , position->get_y());
  glEnd();
}

void Draw::road(float width, Coordinate* start_position, Coordinate* end_position){
  GLfloat lineWidthRange[2] = {0.0f, 10000.0f};
  glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, lineWidthRange);
  glLineWidth(width);
  glBegin( GL_LINES );
    glVertex2d(start_position->get_x(),start_position->get_y());
    glVertex2d(end_position->get_x(),end_position->get_y());
  glEnd();
}

void Draw::signal(Coordinate* position, float EW_line_distance, float NS_line_distance, float time_in_loop){
  // for(int i = 0; i < traffic_signals.size(); i++) {
    glLineWidth(3);
    traffic_signal->set_EW_color(time_in_loop);
    glBegin( GL_LINES );
      glVertex2d(position->get_x() + EW_line_distance, position->get_y());
      glVertex2d(position->get_x() + EW_line_distance, position->get_y() - 0.07);
    glEnd();
    glBegin( GL_LINES );
      glVertex2d(position->get_x() - EW_line_distance, position->get_y());
      glVertex2d(position->get_x() - EW_line_distance, position->get_y() + 0.07);
    traffic_signal->set_NS_color(time_in_loop);
    glEnd();
    glBegin( GL_LINES );
      glVertex2d(position->get_x() , position->get_y() + NS_line_distance);
      glVertex2d(position->get_x() + 0.05 , position->get_y() + NS_line_distance);
    glEnd();
    glBegin( GL_LINES );
      glVertex2d(position->get_x() , position->get_y() - NS_line_distance);
      glVertex2d(position->get_x() - 0.05 , position->get_y() - NS_line_distance);
    glEnd();
  // }
}
