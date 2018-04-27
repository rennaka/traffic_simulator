class Car{
  private:
    Coordinate* position;
    Speed* speed;
    void display();
  public:
    Car(Coordinate* init_position, Speed* init_speed);
    void Run();
};

Car::Car(Coordinate* init_position, Speed* init_speed) : position(init_position), speed(init_speed)
{
  Car::display();
}

void Car::Run(){
  position->set_x(position->get_x() + speed->get_x());
  position->set_y(position->get_y() + speed->get_y());
  Car::display();
}

void Car::display(){
  glColor3d( 1.0, 0.0, 0.0);
  glPointSize(5);
  glBegin(GL_POINTS);
    glVertex2d(position->get_x() , position->get_y());
  glEnd();
  glFlush();
}
