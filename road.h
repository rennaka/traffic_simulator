class Road{
  private:
    float width;
    Coordinate* start_position;
    Coordinate* end_position;
    void draw_road();
    void Create();
  public:
    Road(float width, Coordinate* start_position, Coordinate* end_position);
    ~Road();
};
