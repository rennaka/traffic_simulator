class Road{
  private:
    double width;
    Coordinate* start_position;
    Coordinate* end_position;
  public:
    Road(double width, Coordinate* start_position, Coordinate* end_position);
    void Create();
};

Road::Road(double init_width, Coordinate* init_start_position, Coordinate* init_end_position) : width(init_width), start_position(init_start_position), end_position(init_end_position)
{
}

void Road::Create(){
	glColor3d( 1.0, 1.0, 1.0);
  glLineWidth(width);
	glBegin( GL_LINES );
  	glVertex2d(start_position->get_x(),start_position->get_y());
  	glVertex2d(end_position->get_x(),end_position->get_y());
	glEnd();
	glFlush();
}
