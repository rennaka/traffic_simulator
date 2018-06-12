#include "car.h"
#include <vector>       // ヘッダファイルインクルード
#include <cmath>
using namespace std;

extern vector<Car*> cars;
extern TrafficSignal* traffic_signal;
extern int vehicle_count;
extern bool signal_use;

Car::Car(int init_id, Coordinate* init_position, Velocity* init_velocity, double init_max_speed) :
id(init_id), position(init_position), velocity(init_velocity), max_speed(init_max_speed)
// 0.54 * init_max_speed + 0.125712 * init_max_speed * init_max_speed
{
  srand(time(NULL));
  safety_distance = init_max_speed * 3.6 - 15; //(0.15 * init_max_speed + 0.0097 * init_max_speed * init_max_speed) * (1 + (double)rand()/RAND_MAX);
  display();
}

Car::~Car(){
}

double Car::vehicular_gap(){
  double vehicular_gap = pow(10, 3);
  if (signal_use) {
    vehicular_gap = min(1000.0, to_line_distance());
  }
  for(int i = 0; i < cars.size(); i++) {
    if (exist_former_car(cars[i])) {
      vehicular_gap = min(vehicular_gap, Coordinate::distance(cars[i]->position, this->position) * Const::scale);
    } else {
      vehicular_gap = min(vehicular_gap, (2 - Coordinate::distance(cars[i]->position, this->position)) * Const::scale);
    }
  }
  return vehicular_gap;
}

double Car::to_line_distance(){
  switch(velocity->get_direction()){
  case 'E':
    if (traffic_signal->get_EW_color() == 'R' && position->get_x() < traffic_signal->E_line_position->get_x()) {
      return Coordinate::distance(position, traffic_signal->E_line_position) * Const::scale;
    }
    return pow(10, 3);
  case 'W':
    if (traffic_signal->get_EW_color() == 'R' && position->get_x() > traffic_signal->W_line_position->get_x()) {
      return Coordinate::distance(position, traffic_signal->W_line_position) * Const::scale;
    }
    return pow(10, 3);
  case 'N':
    if (traffic_signal->get_NS_color() == 'R' && position->get_y() < traffic_signal->N_line_position->get_y()) {
      return Coordinate::distance(position, traffic_signal->N_line_position) * Const::scale;
    }
    return pow(10, 3);
  case 'S':
    if (traffic_signal->get_NS_color() == 'R' && position->get_y() > traffic_signal->S_line_position->get_y()) {
      return Coordinate::distance(position, traffic_signal->S_line_position) * Const::scale;
    }
    return pow(10, 3);
  }
}

bool Car::exist_former_car(Car* car){
  return this->velocity->get_direction() == car->velocity->get_direction() && is_former_position(car);
}

bool Car::is_former_position(Car* car){
  switch(velocity->get_direction()){
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
  display();
}

void Car::accelate(){
  switch(this->velocity->get_direction()){
  case 'E':
    position->set_x(position->get_x() + velocity->get_speed() * Const::dt);
    break;
  case 'W':
    if (position->get_x() - velocity->get_speed() * Const::dt < -1.0) {
      position->set_x(position->get_x() - velocity->get_speed() * Const::dt + 2);
      vehicle_count++;
      std::cout << vehicle_count <<std::endl;
    } else {
      position->set_x(position->get_x() - velocity->get_speed() * Const::dt);
    }
    break;
  case 'N':
    position->set_y(position->get_y() + velocity->get_speed() * Const::dt);
    break;
  case 'S':
    position->set_y(position->get_y() - velocity->get_speed() * Const::dt);
    break;
  }
  velocity->set_speed(velocity->get_speed() + (Const::sensitivity * (max_speed / 2 * (std::tanh(vehicular_gap() - safety_distance) + std::tanh(safety_distance)) - velocity->get_speed() * Const::scale)) / Const::scale);
  safety_distance = max(velocity->get_speed() * Const::scale * 2,5.0);
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
