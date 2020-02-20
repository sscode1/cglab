#include<stdio.h>
#include<GL/glut.h>
#define ll int
ll xc,yc,r;
void drawlin(ll x1,ll y1,ll x2,ll y2){
    ll dx,dy,steps,i,j;
    double xin,yin,X,Y;
    dx=x2-x1;
    dy=y2-y1;
    steps=(abs(dx)>abs(dy)?abs(dx):abs(dy));
    xin=(double)dx/steps;
    yin=(double)dy/steps;
    X=x1;
    Y=y1;
    //printf("%lf %lf %d",xin,yin,steps);
    for(i=0;i<steps;i++){
        glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(X,Y);
        X+=xin;
        Y+=yin;
    }
    glEnd();
}
void drawcir(ll x,ll y){
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc-y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+y,yc+x);
    glVertex2i(xc+y,yc-x);
    glVertex2i(xc-y,yc+x);
    glVertex2i(xc-y,yc-x);
    glEnd();
}
void circlebre(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ll x=0,y=r,dp=3-2*r;  
    while(y>=x){
        x++;
        if(dp>0){
            y--;
            dp=dp+4*(x-y)+10;
        }
        else
        {
            dp=dp+4*x+6;
        }
        drawcir(x,y);
    }  
    glFlush();
}
int main(int argc, char** argv){
    ll i,j;
    glutInit(&argc,argv);
    printf("Enter xc, yc and radius\n");
    scanf("%d%d%d",&xc,&yc,&r);   
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Bresenham's Algo");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(2.0);
    gluOrtho2D(-100,600,-100,600);
    glutDisplayFunc(circlebre);
    glutMainLoop();
    return 0;
}