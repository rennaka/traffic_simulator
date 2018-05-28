class Coordinate{
  private:
    float x;
    float y;

  public:
    Coordinate(float x, float y);
    float get_x(){ return x; }
    float get_y(){ return y; }
    void set_x(float new_x){ x = new_x; }
    void set_y(float new_y){ y = new_y; }
    static float distance(Coordinate* coordinate1, Coordinate* coordinate2);
};

Coordinate::Coordinate(float init_x, float init_y) : x(init_x), y(init_y)
{
}

float Coordinate::distance(Coordinate* coordinate1, Coordinate* coordinate2){
  return sqrt(pow((coordinate1->get_x() - coordinate2->get_x()), 2) + pow((coordinate1->get_y() - coordinate2->get_y()), 2));
}
