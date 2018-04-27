class Speed{
  private:
    double x;
    double y;

  public:
    Speed(double x, double y);
    double get_x(){ return x; }
    double get_y(){ return y; }
};

Speed::Speed(double init_x, double init_y) : x(init_x), y(init_y)
{
}
