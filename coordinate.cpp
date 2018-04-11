class Coordinate{
  private:
    double x;
    double y;

  public:
    Coordinate(double x, double y);
    double get_x(){ return x; }
    double get_y(){ return y; }
};

Coordinate::Coordinate(double x, double y){
  x = x;
  y = y;
}
