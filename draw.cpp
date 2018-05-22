class Draw{
  public:
    static void car(Coordinate* position);
    static void road(float width, Coordinate* start_position, Coordinate* end_position);
};

void Draw::car(Coordinate* position){
  glPointSize(5);
  glBegin(GL_POINTS);
    glVertex2d(position->get_x() , position->get_y());
  glEnd();
}

void Draw::road(float width, Coordinate* start_position, Coordinate* end_position){
  glLineWidth(width);
  glBegin( GL_LINES );
    glVertex2d(start_position->get_x(),start_position->get_y());
    glVertex2d(end_position->get_x(),end_position->get_y());
  glEnd();
  glutSwapBuffers();
}
