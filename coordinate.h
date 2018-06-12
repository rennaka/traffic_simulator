class Coordinate{
  private:
    double x;
    double y;

  public:
    Coordinate(double x, double y);
    double get_x(){ return x; }
    double get_y(){ return y; }
    void set_x(double new_x){ x = new_x; }
    void set_y(double new_y){ y = new_y; }
    static double distance(Coordinate* coordinate1, Coordinate* coordinate2);
};
