class Road{
  private:
    double width;
    Coordinate* start_position;
    Coordinate* end_position;
    void draw_road();
    void Create();
  public:
    Road(double width, Coordinate* start_position, Coordinate* end_position);
    ~Road();
};
