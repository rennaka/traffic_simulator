class TrafficSignal{
  private:
    double cycle_length;
    double EW_green_length;
    double NS_green_length;
    double yellow_length;
    double all_red_length;
    Coordinate* position;
    double EW_line_distance;
    double NS_line_distance;
    char EW_color;
    char NS_color;
    void set_EW_color(double time_in_loop);
    void set_NS_color(double time_in_loop);
    void set_signal_color(char color);
  public:
    Coordinate* E_line_position;
    Coordinate* W_line_position;
    Coordinate* N_line_position;
    Coordinate* S_line_position;
    char get_EW_color(){ return EW_color; }
    char get_NS_color(){ return NS_color; }
    TrafficSignal(double cycle_length, double EW_green_length, double NS_green_length, double yellow_length, double all_red_length, Coordinate* position, double EW_line_distance, double NS_line_distance);
    ~TrafficSignal();
    void Change(double elapsed_time);
};
