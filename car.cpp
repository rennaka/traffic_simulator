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
  Set_Color::car();
  Draw::car(position);
  glutSwapBuffers();
}

void Car::hide(){
  Set_Color::road();
  Draw::car(position);
}
