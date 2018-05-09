class Speed{
  private:
    float x;
    float y;

  public:
    Speed(float x, float y);
    float get_x(){ return x; }
    float get_y(){ return y; }
    void set_x(float new_x){ x = new_x; }
    void set_y(float new_y){ y = new_y; }
};

Speed::Speed(float init_x, float init_y) : x(init_x), y(init_y)
{
}
