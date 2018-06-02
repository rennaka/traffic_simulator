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

Signal::Signal(float init_cycle_length, float init_EW_green_length, float init_NS_green_length, float init_yellow_length, float init_all_red_length, Coordinate* init_position, float init_EW_line_distance, float init_NS_line_distance)
: cycle_length(init_cycle_length), EW_green_length(init_EW_green_length), NS_green_length(init_NS_green_length), yellow_length(init_yellow_length), all_red_length(init_all_red_length), position(init_position), EW_line_distance(init_EW_line_distance), NS_line_distance(init_NS_line_distance)
{
  Draw::signal(position, EW_line_distance, NS_line_distance, 0);
}

Signal::~Signal(){
}

void Signal::Change(float elapsed_time){
  Draw::signal(position, EW_line_distance, NS_line_distance, fmod(elapsed_time,cycle_length));
}

void Signal::set_EW_color(float time_in_loop){
  if (0 <= time_in_loop && time_in_loop <= EW_green_length) {
    Set_Color::green_signal();
  } else if (EW_green_length <= time_in_loop && time_in_loop <= EW_green_length + yellow_length){
    Set_Color::yellow_signal();
  } else{
    Set_Color::red_signal();
  }
}

void Signal::set_NS_color(float time_in_loop){
  if (EW_green_length + yellow_length + all_red_length <= time_in_loop && time_in_loop <= cycle_length - yellow_length - all_red_length) {
    Set_Color::green_signal();
  } else if (cycle_length - yellow_length - all_red_length <= time_in_loop && time_in_loop <= cycle_length - all_red_length){
    Set_Color::yellow_signal();
  } else{
    Set_Color::red_signal();
  }
}
