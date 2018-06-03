class Car{
  private:
    int id;
    Coordinate* position;
    Velocity* velocity;
    float vehicular_gap;
    void display();
    void draw_car_poligon();
    void hide();
    void accelate();
    void set_vehicular_gap();
    bool exist_former_car(Car* car);
    bool is_former_position(Car* car);
    void draw_car();
    float to_line_distance();
  public:
    Car(int init_id, Coordinate* init_position, Velocity* init_velocity);
    ~Car();
    void Run();
};
