#include<stdio.h>
#include<GL/glut.h>
#define ll int
ll x1,x2,y1,y2;
ll abs(ll x)
{
    return (x>0)?x:(-x);
}
void dda(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ll dx,dy,steps,i,j;
    double xin,yin,X,Y;
    dx=x2-x1;
    dy=y2-y1;
    steps=(abs(dx)>abs(dy)?abs(dx):abs(dy));
    xin=(double)dx/steps;
    yin=(double)dy/steps;
    X=x1;
    Y=y1;
    printf("%lf %lf %d",xin,yin,steps);
    for(i=0;i<steps;i++){
        glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(X,Y);
        X+=xin;
        Y+=yin;
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
    glutCreateWindow("DDA Algo");
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(-200,200,-200,200);
    glutDisplayFunc(dda);
    glutMainLoop();
    return 0;
}