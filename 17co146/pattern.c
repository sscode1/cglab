#include<stdio.h>
#include<GL/glut.h>
#define ll int
ll x[12],y[12];
ll abs(ll x)
{
    return (x>0)?x:(-x);
}
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
void drawline(ll x1,ll y1,ll x2,ll y2){
    ll dx=x2-x1;
    ll dy=y2-y1;
    if(dy<0)
    dy=-dy;
    if(dx<0)
    dx=-dx;
    if(dy<=dx){
    ll mnew=2*(dy);
    ll slerrornew=mnew-(dx),x,y;
    for(x=x1,y=y1;x<=x2;x++){
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glColor3f(1.0f, 0.0f, 0.0f);
        slerrornew+=mnew;
        if(slerrornew>=0)
        {
            y++;
            slerrornew-=2*(dx);
        }
    }
    glEnd();
    }
    else{
    ll mnew=2*(dx);
    ll slerrornew=mnew-(dy),x,y;
    for(x=x1,y=y1;y<=y2;y++){
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glColor3f(1.0f, 0.0f, 0.0f);
        slerrornew+=mnew;
        if(slerrornew>=0)
        {
            x++;
            slerrornew-=2*(dy);
        }
    }
    glEnd();
    }
}
void bre(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);    
    drawline(0,0,200,0);
    drawline(0,100,200,100);      
    drawline(0,0,0,100);
    drawline(200,0,200,100); 
    drawlin(0,50,100,0);
    drawline(100,0,200,50);      
    drawlin(200,50,100,100);
    drawline(0,50,100,100);
    drawline(50,75,150,75);
    drawline(50,25,50,75);      
    drawline(50,25,150,25);
    drawline(150,25,150,75);   
    glFlush();
}
int main(int argc, char** argv){
    ll i,j;
    glutInit(&argc,argv);
    // printf("Enter x[0], y[0]\n");
    // scanf("%d%d",&x[0],&y[0]);
    // printf("Enter x[1], y[1]\n");
    // scanf("%d%d",&x[1],&y[1]);    
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Bresenham's Algo");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(2.0);
    gluOrtho2D(-10,600,-10,600);
    glutDisplayFunc(bre);
    glutMainLoop();
    return 0;
}