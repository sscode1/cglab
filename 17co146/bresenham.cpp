#include<stdio.h>
#include<GL/glut.h>
#define ll int
ll x1,x2,y1,y2;
ll abs(ll x)
{
    return (x>0)?x:(-x);
}
void bre(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ll mnew=2*(y2-y1);
    ll slerrornew=mnew-(x2-x1);
    for(ll x=x1,y=y1;x<=x2;x++){
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glColor3f(1.0f, 0.0f, 0.0f);
        slerrornew+=mnew;
        if(slerrornew>=0)
        {
            y++;
            slerrornew-=2*(x2-x1);
        }
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv){
    ll i,j;
    glutInit(&argc,argv);
    printf("Enter x1, y1\n");
    scanf("%d%d",&x1,&y1);
    printf("Enter x2, y2\n");
    scanf("%d%d",&x2,&y2);    
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Bresenham's Algo");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(2.0);
    gluOrtho2D(0,600,0,600);
    glutDisplayFunc(bre);
    glutMainLoop();
    return 0;
}