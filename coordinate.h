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
