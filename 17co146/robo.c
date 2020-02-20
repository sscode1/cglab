#include<stdio.h>
#include<GL/glut.h>
#define ll int
ll x[12],y[12];
ll xc=0,yc=0;
ll in=0,ri=20,ro=50,ss=25;
float ai=2.0f,ti=1.0f;
float w=100,h=100;
float angle = 3.0f,tx=0;
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
    glColor3f(1.0f, 1.0f, 0.0f);
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
void circlebre2(ll xc,ll yc,ll r){    
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
        drawcir2(xc,yc,x,y);
    }  
    glFlush();
}
void drawcir2(ll xc,ll yc,ll x,ll y){
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2i(xc+x,yc+y);
    glVertex2i(xc+y,yc+x);
    //glVertex2i(xc-x,yc-y);
    //glVertex2i(xc+x,yc-y);
    glVertex2i(xc-y,yc+x);
    glVertex2i(xc-x,yc+y);
    
    //glVertex2i(xc+y,yc-x);
    
    //glVertex2i(xc-y,yc-x);    
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
        glColor3f(1.0f, 1.0f, 0.0f);
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
        glColor3f(1.0f, 1.0f, 0.0f);
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
    glTranslatef(tx,0.0f,0.0f);
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
    // drawline(-ss,ss,ss,ss);
    // drawline(ss,-ss,ss,ss);
    // drawline(-ss,-ss,-ss,ss);
    // drawline(-ss,-ss,ss,-ss);
    // drawline(-25,-25,25,25);
    // drawline(-25,-25,25,25);
    //glTranslatef(,0.0f,0.0f); 
    //drawline(-ss,ss,ss,ss);   
    body();
    //glRotatef(angle,1.0f,0.0f,0.0f);
    larm();
    rarm();
    head();
    //glRotatef(angle,1.0f,0.0f,0.0f);
    
    //rleg();
    //lleg();
    glFlush();
}
void larm(){
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
      glColor3f(1.0f, 1.0f, 0.0f);      
      glVertex2f(w/2-110,h/2);
      glVertex2f(w/2-130,h/2);
      glVertex2f(w/2-130,-h/2);
      glVertex2f(w/2-110,-h/2);      
   glEnd();
}
void body(){
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
      glColor3f(1.0f, 1.0f, 0.0f);      
      glVertex2f(w/2,h/2);
      glVertex2f(-w/2,h/2);
      glVertex2f(-w/2,-h/2);
      glVertex2f(w/2,-h/2);      
   glEnd();
}
void rarm(){
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
      glColor3f(1.0f, 1.0f, 0.0f);      
      glVertex2f(-w/2+110,h/2);
      glVertex2f(-w/2+130,h/2);
      glVertex2f(-w/2+130,-h/2);
      glVertex2f(-w/2+110,-h/2);      
   glEnd();
}
void head(){
     
    glColor3f(1.0f, 1.0f, 0.0f);           // These vertices form a closed polygon
    circlebre2(0,70,w/2);     
    drawlin(-w/2,70,w/2,70);
    circlebre(-20,100,10);
    circlebre(+20,100,10);
    // drawlin(-w/2,70,w/2,70);
    // drawlin(-w/2,70,w/2,70);
   glFlush();
}
void lleg(){
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
      glColor3f(1.0f, 1.0f, 0.0f);      
      glVertex2f(-w/2+110,-h/2);
      glVertex2f(-w/2+130,-h/2);
      glVertex2f(-w/2+130,-h/2-10);
      glVertex2f(-w/2+110,-h/2-10);      
   glEnd();
}
void rleg(){
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
      glColor3f(1.0f, 1.0f, 0.0f);      
      glVertex2f(w/2+w/2*0.9,h/2);
      glVertex2f(w/2+100,h/2);
      glVertex2f(w/2+100,-h/2);
      glVertex2f(w/2+90,-h/2);      
   glEnd();
}
void keyboard(unsigned char key,ll x,ll y){
    //printf("%d\n",key);
    switch(key){
        case 'C': 
        glutPostRedisplay();   
        break;
        case 'I':
        glutPostRedisplay();   
        w+=10;
        h+=10;
        break;
        case 'D':
        glutPostRedisplay();   
        w-=10;
        h-=10;
        break;
        case 'T':
        tx+=10;
        glutPostRedisplay();   
        break;
        case 'H':
        tx=0;
        tx-=10;
        glutPostRedisplay();   
        break;
        case 'E':
        exit(0);
        case 'R':
        angle+=10;
        break;
        case 'S':
        tx=0;
        glutPostRedisplay();
    }
}
void mouse(ll b,ll state,ll x,ll y){
    switch(b){
        case GLUT_LEFT_BUTTON:
        // circlebre(0,0,50);
        // circlebre(0,0,20);    
        // drawline(ri,0,ro,0);    
        // drawline(-ro,0,-ri,0);
        // drawline(0,ri,0,ro);
        // drawline(0,-ro,0,-ri);
        //drawlin(1.4*ri/2,1.4*ri,1.4*ro/2,1.4*ro/2);
        //drawlin(-1.4*ri/2,-1.4*ri,-1.4*ro/2,-1.4*ro/2);
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