#include <GL/glut.h>

int WindowPositionX = 100;  //生成するウィンドウ位置のX座標
int WindowPositionY = 100;  //生成するウィンドウ位置のY座標
int WindowWidth = 512;    //生成するウィンドウの幅
int WindowHeight = 512;    //生成するウィンドウの高さ
char WindowTitle[] = "世界の始まり";  //ウィンドウのタイトル

//----------------------------------------------------
// 関数プロトタイプ（後に呼び出す関数名と引数の宣言）
//----------------------------------------------------
void Initialize(void);
void Display(void);
//----------------------------------------------------
// メイン関数
//----------------------------------------------------
int main(int argc, char *argv[]){
  glutInit(&argc, argv);//環境の初期化
  glutInitWindowPosition(WindowPositionX, WindowPositionY);//ウィンドウの位置の指定
  glutInitWindowSize(WindowWidth, WindowHeight); //ウィンドウサイズの指定
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);//ディスプレイモードの指定
  glutCreateWindow(WindowTitle);  //ウィンドウの作成
  glutDisplayFunc(Display); //描画時に呼び出される関数を指定する（関数名：Display）
  Initialize(); //初期設定の関数を呼び出す
  glutMainLoop();
  return 0;
}
//----------------------------------------------------
// 初期設定の関数
//----------------------------------------------------
void Initialize(void){
  glClearColor(1.0, 1.0, 1.0, 1.0); //背景色
  glEnable(GL_DEPTH_TEST);//デプスバッファを使用：glutInitDisplayMode() で GLUT_DEPTH を指定する
}
//----------------------------------------------------
// 描画の関数
//----------------------------------------------------
void Display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //バッファの消去
  glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)でダブルバッファリングを利用可
}
