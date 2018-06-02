class Draw{
  public:
    static void car(Coordinate* position);
    static void road(float width, Coordinate* start_position, Coordinate* end_position);
    static void signal(Coordinate* position, float EW_line_distance, float NS_line_distance, float time_in_loop);
};
