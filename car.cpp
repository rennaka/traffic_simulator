class Car{
  private:
    Coordinate* position;
    Speed* speed;
    void display();
    void draw_car_poligon();
    void hide();
  public:
    Car(Coordinate* init_position);
    ~Car();
    void Run();
};

Car::Car(Coordinate* init_position) : position(init_position)
{
  speed = &(Speed::DEFAULT);
  Car::display();
}

Car::~Car(){
}

void Car::Run(){
  hide();
  position->set_x(position->get_x() + speed->get_x());
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
