class Car{
  private:
    Coordinate* position;
    Speed* speed;
    void display();
    void draw_car_poligon();
    void hide();
  public:
    Car(Coordinate* init_position, Speed* init_speed);
    ~Car();
    void Run();
};

Car::Car(Coordinate* init_position, Speed* init_speed) : position(init_position), speed(init_speed)
{
  Car::display();
}

Car::~Car(){

}

void Car::Run(){
  hide();
  position->set_x(position->get_x() + -0.002);
  position->set_y(position->get_y() + speed->get_y());
  display();
}

void Car::display(){
  glColor3d( 1.0, 0.0, 0.0);
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
