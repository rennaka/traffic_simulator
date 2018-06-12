class Velocity{
  private:
    double speed;
    char direction;

  public:
    Velocity(double init_speed, char init_direction);
    double get_speed(){ return speed; }
    char get_direction(){ return direction; }
    void set_speed(double new_speed){ speed = new_speed; }
};
