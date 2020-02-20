#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define ll int
ll xc,yc,r,ch,nop;
float xa[100],ya[100];
float tx,ty;
ll x1,y11,x2,y2;
void drawlin(ll x1,ll y11,ll x2,ll y2){
    ll dx,dy,steps,i,j;
    double xin,yin,X,Y;
    dx=x2-x1;
    dy=y2-y11;
    steps=(abs(dx)>abs(dy)?abs(dx):abs(dy));
    xin=(double)dx/steps;
    yin=(double)dy/steps;
    X=x1;
    Y=y11;
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
    // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // glClear(GL_COLOR_BUFFER_BIT);
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
    //glFlush();
}
void disp(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);    
    switch(ch){
        case 1:       
        drawlin(x1,y11,x2,y2);
        drawlin(x1*sin(tx)+y11*cos(tx),x1*cos(tx)-y11*sin(tx),x2*sin(tx)+y2*cos(tx),x2*cos(tx)-y2*sin(tx));
        break;
        case 2:
        circlebre();
        xc+=tx;
        yc+=ty;
        circlebre();
        break;
        case 3:
        glBegin(GL_POLYGON);            // These vertices form a closed polygon
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        ll i;
        for(i=0;i<nop;i++){
            glVertex2f(xa[i], ya[i]); 
        }      
        
        glEnd();
        glBegin(GL_POLYGON);            // These vertices form a closed polygon
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        
        for(i=0;i<nop;i++){
            glVertex2f(xa[i]*sin(tx)+ ya[i]*cos(tx),xa[i]*cos(tx)- ya[i]*sin(tx)); 
        }      
        
        glEnd();
        break;
    }
    glFlush();
}
int main(int argc, char** argv){
    ll i,j;
    glutInit(&argc,argv);
    //printf("Enter xc, yc and radius\n");
    //scanf("%d%d%d",&xc,&yc,&r);
    printf("Choice-1. line 2. circle 3. polygon\n");
    scanf("%d",&ch);   
    switch(ch){
        case 1:        
        printf("enter end points\n");
        scanf("%d%d%d%d",&x1,&y11,&x2,&y2);        
        break;
        case 2:
        printf("Enter xc, yc and radius\n");
        scanf("%d%d%d",&xc,&yc,&r);
        break;
        case 3:
        printf("enter the points followed by points\n");
        scanf("%d",&nop);
        for(i=0;i<nop;i++){
            scanf("%f%f",&xa[i],&ya[i]);
        }
        break;
    }    
    printf("Enter the angle\n");
    scanf("%f",&tx);
    tx*=(3.14/180.0);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutCreateWindow("2 d translation");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(1.0);
    gluOrtho2D(-200,200,-200,200);
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}