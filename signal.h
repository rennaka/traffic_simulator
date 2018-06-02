class Signal{
  private:
    float cycle_length;
    float EW_green_length;
    float NS_green_length;
    float yellow_length;
    float all_red_length;
    Coordinate* position;
    float EW_line_distance;
    float NS_line_distance;
  public:
    Signal(float cycle_length, float EW_green_length, float NS_green_length, float yellow_length, float all_red_length, Coordinate* position, float EW_line_distance, float NS_line_distance);
    ~Signal();
    void Change(float elapsed_time);
    void set_EW_color(float elapsed_time);
    void set_NS_color(float elapsed_time);
};
