#include "car.h"
#include <vector>       // ヘッダファイルインクルード
using namespace std;

extern vector<Car*> cars;

Car::Car(int init_id, Coordinate* init_position, Velocity* init_velocity) : id(init_id), position(init_position), velocity(init_velocity)
{
  set_vehicular_gap();
  display();
}

Car::~Car(){
}

void Car::set_vehicular_gap(){
  vehicular_gap = pow(10, 3);
  for(int i = 0; i < cars.size(); i++) {
    if (exist_former_car(cars[i])) {
      vehicular_gap = min(vehicular_gap, Coordinate::distance(cars[i]->position, this->position) * Const::scale);
    }
  }
}

bool Car::exist_former_car(Car* car){
  return this->velocity->get_direction() == car->velocity->get_direction() && is_former_position(car);
}

bool Car::is_former_position(Car* car){
  switch(this->velocity->get_direction()){
    case 'E':
      return this->position->get_x() < car->position->get_x();
    case 'W':
      return this->position->get_x() > car->position->get_x();
    case 'N':
      return this->position->get_y() < car->position->get_y();
    case 'S':
      return this->position->get_y() > car->position->get_y();
  }
}

void Car::Run(){
  hide();
  accelate();
  set_vehicular_gap();
  display();
}

void Car::accelate(){
  velocity->set_speed(velocity->get_speed() + (Const::sensitivity * (Const::max_speed / 2 * (tanh(vehicular_gap - Const::safety_distance) + tanh(Const::safety_distance)) - velocity->get_speed() * Const::scale)) / Const::scale);
  switch(this->velocity->get_direction()){
    case 'E':
      position->set_x(position->get_x() + velocity->get_speed() * Const::dt);
      break;
    case 'W':
      position->set_x(position->get_x() - velocity->get_speed() * Const::dt);
      break;
    case 'N':
      position->set_y(position->get_y() + velocity->get_speed() * Const::dt);
      break;
    case 'S':
      position->set_y(position->get_y() - velocity->get_speed() * Const::dt);
      break;
  }
}

void Car::display(){
  Set_Color::car();
  draw_car();
}

void Car::hide(){
  Set_Color::road();
  draw_car();
}

void Car::draw_car(){
  glPointSize(3);
  glBegin(GL_POINTS);
    glVertex2d(position->get_x() , position->get_y());
  glEnd();
}
