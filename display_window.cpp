#include "coordinate.cpp"

class DisplayWindow{
  private:
    void Create(Coordinate window_position, int width, int height, char* title);
    void Setting();
    static void Display_Content();

  public:
    DisplayWindow(int argc, char *argv[], Coordinate coordinate, int width, int height, char* title);
};

DisplayWindow::DisplayWindow(int argc, char *argv[], Coordinate window_position, int width, int height, char* title){
  glutInit(&argc, argv);//環境の初期化
  Create(window_position, width, height, title);
  Setting();
  glutMainLoop();
}

void DisplayWindow::Display_Content(void) {
  
}

void DisplayWindow::Create(Coordinate window_position, int width, int height, char* title){
  glutInitWindowPosition(window_position.get_x(),window_position.get_y());//ウィンドウの位置の指定
  glutInitWindowSize(width,height); //ウィンドウサイズの指定
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);//ディスプレイモードの指定
  glutCreateWindow(title);  //ウィンドウの作成
  glClearColor(1.0, 1.0, 1.0, 1.0); //背景色
}

void DisplayWindow::Setting(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //バッファの消去
  glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)でダブルバッファリングを利用可
  glEnable(GL_DEPTH_TEST);//デプスバッファを使用：glutInitDisplayMode() で GLUT_DEPTH を指定する
  glutDisplayFunc(Display_Content); //描画時に呼び出される関数を指定する（関数名：Display）
}
