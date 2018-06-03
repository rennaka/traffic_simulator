class TrafficSignal{
  private:
    float cycle_length;
    float EW_green_length;
    float NS_green_length;
    float yellow_length;
    float all_red_length;
    Coordinate* position;
    float EW_line_distance;
    float NS_line_distance;
    void set_EW_color(float time_in_loop);
    void set_NS_color(float time_in_loop);
  public:
    TrafficSignal(float cycle_length, float EW_green_length, float NS_green_length, float yellow_length, float all_red_length, Coordinate* position, float EW_line_distance, float NS_line_distance);
    ~TrafficSignal();
    void Change(float elapsed_time);
};
