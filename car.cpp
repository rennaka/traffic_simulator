class Car{
  private:
    Coordinate* position;
    Speed* speed;
    char direction;
    void display();
    void draw_car_poligon();
    void hide();
    void accelate();
  public:
    Car(Coordinate* init_position, Speed* init_speed, char init_direction);
    ~Car();
    void Run();
};

Car::Car(Coordinate* init_position, Speed* init_speed, char init_direction) : position(init_position), speed(init_speed), direction(init_direction)
{
  Car::display();
}

Car::~Car(){

}

void Car::Run(){
  hide();
  // accelate();
  position->set_x(position->get_x() + speed->get_x());
  position->set_y(position->get_y() + speed->get_y());
  display();
}

void Car::accelate(){
  speed->set_x(speed->get_x() + 0.0001);
}

void Car::display(){
  glColor3d( 0.0, 0.0, 0.0);
  draw_car_poligon();
  glutSwapBuffers();
}

void Car::hide(){
  glColor3d( 1.0, 1.0, 1.0);
  draw_car_poligon();
}

void Car::draw_car_poligon(){
  glPointSize(5);
  glBegin(GL_POINTS);
    glVertex2d(position->get_x() , position->get_y());
  glEnd();
}
