class Road{
  private:
    float width;
    Coordinate* start_position;
    Coordinate* end_position;
  public:
    Road(float width, Coordinate* start_position, Coordinate* end_position);
    ~Road();
    void Create();
};

Road::Road(float init_width, Coordinate* init_start_position, Coordinate* init_end_position) : width(init_width), start_position(init_start_position), end_position(init_end_position)
{
  Create();
}

Road::~Road(){
  delete start_position;
  delete end_position;
}

void Road::Create(){
  Set_Color::road();
  Draw::road(width, start_position, end_position);
}
