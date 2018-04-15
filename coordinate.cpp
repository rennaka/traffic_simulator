class Coordinate{
  private:
    const double x;
    const double y;

  public:
    // Coordinate(){}
    Coordinate(double x, double y);
    double get_x(){ return x; }
    double get_y(){ return y; }
};

Coordinate::Coordinate(double init_x, double init_y) : x(init_x), y(init_y)
{
}
