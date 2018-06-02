#include "coordinate.h"

Coordinate::Coordinate(float init_x, float init_y) : x(init_x), y(init_y)
{
}

float Coordinate::distance(Coordinate* coordinate1, Coordinate* coordinate2){
  return sqrt(pow((coordinate1->get_x() - coordinate2->get_x()), 2) + pow((coordinate1->get_y() - coordinate2->get_y()), 2));
}
