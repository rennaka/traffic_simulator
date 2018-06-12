class Car{
  private:
    int id;
    Coordinate* position;
    Velocity* velocity;
    double max_speed;
    double safety_distance;
    void display();
    void draw_car_poligon();
    void hide();
    void accelate();
    double vehicular_gap();
    bool exist_former_car(Car* car);
    bool is_former_position(Car* car);
    void draw_car();
    double to_line_distance();
  public:
    Car(int init_id, Coordinate* init_position, Velocity* init_velocity, double init_max_speed);
    ~Car();
    void Run();
};
