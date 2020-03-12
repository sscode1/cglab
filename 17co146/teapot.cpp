#include <GL/glut.h> 
static int window;
static int menu_id;
static int submenu_id1;
static int submenu_id2;
static int value = 0; 
static int col=0;
void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
} 
void menu1(int num){
  value=2;
  col=num;
  glutPostRedisplay();
} 
void menu2(int num){
  value=3;
  col=num;
  glutPostRedisplay();
} 
void createMenu(void){ 
    submenu_id1=glutCreateMenu(menu1);
    glutAddMenuEntry("red", 10);
    glutAddMenuEntry("green", 11);
    submenu_id2=glutCreateMenu(menu2);
    glutAddMenuEntry("red", 12);
    glutAddMenuEntry("green", 13);
    
    menu_id = glutCreateMenu(menu);
    glutAddSubMenu("Wired Teapot", submenu_id1);
    glutAddSubMenu("Solid teapot", submenu_id2);
    glutAddMenuEntry("Clear", 4);
    glutAddMenuEntry("Exit", 0);
    // menu_id = glutCreateMenu(menu);
    // glutAddSubMenu("Select", submenu_id);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 
void display(void){
  float x=1.0,y=0,z=0;
  glClear(GL_COLOR_BUFFER_BIT);   if(value == 1){
    return; //glutPostRedisplay();
  }else if(value == 2){
    glPushMatrix();
    if(col==11)
    {
        x=0;
        y=1;
    }
    glColor3d(x, y, z);
    glutWireTeapot(0.5);
    glPopMatrix();
  }else if(value==3){
    glPushMatrix();
    if(col==13)
    {
        x=0;
        y=1;
    }
    glColor3d(x, y, z);
    glutSolidTeapot(0.5);
    glPopMatrix();
  }
  else if(value==4){
      glLoadIdentity();
  }  
  glFlush();
} 
int main(int argc, char **argv){     glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("Menus and Submenus - Programming Techniques");
    createMenu();     glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);     glutMainLoop();
    return EXIT_SUCCESS;
}
