class Car{
  private:
    Coordinate* position;
    Speed* speed;
  public:
    Car(Coordinate* init_position, Speed* init_speed);
    void Run();
};

Car::Car(Coordinate* init_position, Speed* init_speed) : position(init_position), speed(init_speed)
{
}
void Car::Run(){
	glColor3d( 1.0, 0.0, 0.0);
  glPointSize(5);
  glBegin(GL_POINTS);
    glVertex2i(position->get_x() , position->get_y());
  glEnd();
  glFlush();
}
