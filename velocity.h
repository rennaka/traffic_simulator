class Velocity{
  private:
    float speed;
    char direction;

  public:
    Velocity(float init_speed, char init_direction);
    float get_speed(){ return speed; }
    char get_direction(){ return direction; }
    void set_speed(float new_speed){ speed = new_speed; }
};
