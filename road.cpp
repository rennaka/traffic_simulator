#include "road.h"

Road::Road(float init_width, Coordinate* init_start_position, Coordinate* init_end_position) : width(init_width), start_position(init_start_position), end_position(init_end_position)
{
  Create();
}

Road::~Road(){
  delete start_position;
  delete end_position;
}

void Road::Create(){
  Set_Color::road();
  draw_road();
}

void Road::draw_road(){
  GLfloat lineWidthRange[2] = {0.0f, 10000.0f};
  glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, lineWidthRange);
  glLineWidth(width);
  glBegin( GL_LINES );
    glVertex2d(start_position->get_x(),start_position->get_y());
    glVertex2d(end_position->get_x(),end_position->get_y());
  glEnd();
}
