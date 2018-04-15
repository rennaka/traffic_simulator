#include "coordinate.cpp"
#include "road.cpp"

class DisplayWindow{
  private:
    void Create(int argc, char *argv[], Coordinate* window_position, int width, int height, char* title);
    void Setting();
    static void Display_Content();

  public:
    DisplayWindow(int argc, char *argv[], Coordinate* window_position, int width, int height, char* title);
};

DisplayWindow::DisplayWindow(int argc, char *argv[], Coordinate* window_position, int width, int height, char* title){
  Create(argc, argv, window_position, width, height, title);
  Setting();
  glutMainLoop();
}

void DisplayWindow::Display_Content(void) {
  Coordinate start_position(-1.0,0);
  Coordinate end_position(1.0,0);
  Road* main_road = new Road(50,&start_position,&end_position);
  main_road->Create();
}

void DisplayWindow::Create(int argc, char *argv[], Coordinate* window_position, int width, int height, char* title){
  glutInitWindowPosition(window_position->get_x(),window_position->get_y());//ウィンドウの位置の指定
  glutInitWindowSize(width,height); //ウィンドウサイズの指定
  glutInit(&argc, argv);//環境の初期化
  glutInitDisplayMode(GLUT_RGBA);//ディスプレイモードの指定
  glutCreateWindow(title);  //ウィンドウの作成
  glClearColor(0.6, 0.8, 0.8, 1.0); //背景色
}

void DisplayWindow::Setting(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //バッファの消去
  glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)でダブルバッファリングを利用可
  glEnable(GL_DEPTH_TEST);//デプスバッファを使用：glutInitDisplayMode() で GLUT_DEPTH を指定する
  glutDisplayFunc(Display_Content); //描画時に呼び出される関数を指定する（関数名：Display）
}
