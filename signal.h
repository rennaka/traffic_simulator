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
    char EW_color;
    char NS_color;
    void set_EW_color(float time_in_loop);
    void set_NS_color(float time_in_loop);
    void set_signal_color(char color);
  public:
    Coordinate* E_line_position;
    Coordinate* W_line_position;
    Coordinate* N_line_position;
    Coordinate* S_line_position;
    char get_EW_color(){ return EW_color; }
    char get_NS_color(){ return NS_color; }
    TrafficSignal(float cycle_length, float EW_green_length, float NS_green_length, float yellow_length, float all_red_length, Coordinate* position, float EW_line_distance, float NS_line_distance);
    ~TrafficSignal();
    void Change(float elapsed_time);
};
