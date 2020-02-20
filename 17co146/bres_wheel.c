#include<stdio.h>
#include<GL/glut.h>
#define ll int
ll x[12],y[12];
ll xc=0,yc=0;
ll in=0,ri=20,ro=50;
float ai=2.0f,ti=1.0f;
float angle = 30.0f,tx=5;
// void update(int value)
// {
// if(tx>=200){
//     ai=-ai;
//     ti=-ti;
// }
// else if(tx<-10)
// {
//     ai=-ai;
//     ti=-ti;
// }
// angle-=ai;
// tx+=ti;
// if(angle>360.f)

// {
// angle-=360;
// }
// glutPostRedisplay();
// glutTimerFunc(25,update,0);

// }
void drawcir(ll xc,ll yc,ll x,ll y){
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
void circlebre(ll xc,ll yc,ll r){ 
    r=r+in;   
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
        drawcir(xc,yc,x,y);
    }  
    glFlush();
}

ll abs(ll x)
{
    return (x>0)?x:(-x);
}
void drawlin(ll x1,ll y1,ll x2,ll y2){
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
        glVertex2i(xc+x,yc+y);
        glVertex2i(xc+x,yc-y);
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
        glVertex2i(xc+x,yc+y);
        glVertex2i(xc+x,yc-y);
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
    //drawline(-100,-50,500,-50);        
    //glPushMatrix();
    //glTranslatef(tx,0.0f,0.0f);
    //glRotatef(angle,0.0f,0.0f,1.0f);    
    // circlebre(0,0,50);
    // circlebre(0,0,20);    
    // drawline(20,0,50,0);    
    // drawline(-50,0,-20,0);
    // drawline(0,20,0,50);
    // drawline(0,-50,0,-20);
    // drawlin(14,14,35,35);
    // drawlin(-35,-35,-14,-14);
    //glPopMatrix();
    glFlush();
}
void keyboard(unsigned char key,ll x,ll y){
    //printf("%d\n",key);
    switch(key){
        case 'c': 
        glutPostRedisplay();   
        break;
        case 'i':
        glutPostRedisplay();   
        in+=10;
        ri+=10;
        ro+=10;
        break;
        case 'd':
        glutPostRedisplay();
        in-=10;
        ri-=10;
        ro-=10;   
        break;
    }
}
void mouse(ll b,ll state,ll x,ll y){
    switch(b){
        case GLUT_LEFT_BUTTON:
        circlebre(0,0,50);
        circlebre(0,0,20);    
        drawline(ri,0,ro,0);    
        drawline(-ro,0,-ri,0);
        drawline(0,ri,0,ro);
        drawline(0,-ro,0,-ri);
        //drawlin(1.4*ri/2,1.4*ri,1.4*ro,1.4*ro);
        //drawlin(-35,-35,-14,-14);
        break;
        case GLUT_RIGHT_BUTTON:
        exit(0);
    }
}

int main(int argc, char** argv){
    ll i,j;
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Bresenham's Algo");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(1.0);
    gluOrtho2D(-100,600,-100,600);
    glutDisplayFunc(bre);
    //glutTimerFunc(25,update,0);
    //glutSpecialFunc(specialKeys); 
    glutKeyboardFunc(keyboard);           
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}