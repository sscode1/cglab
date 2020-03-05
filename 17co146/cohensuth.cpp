#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long
ll xmin,ymin,xmax,ymax;
ll n;
ll xb[100],yb[100],xe[100],ye[100];
int codept(float x,float y){
    ll c=0;
    if(y<ymin)
    c=4;
    if(y>ymax)
    c=8;
    if(x<xmin)
    c|=1;
    if(x>xmax)
    c|=2;
    return c;
}
void disp(){
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();
   glColor3f(1.0,0.0,1.0);
   glBegin(GL_LINES);
       ll i;
       for(i=0;i<n;i++){
           glVertex2f(xb[i],yb[i]);
           glVertex2f(xe[i],ye[i]);
       }
   glEnd();
   glFlush();

}
void cohen(ll i,float x1,float y1,float x2,float y2){
    int c1=codept(x1,y1);
    int c2=codept(x2,y2);
    float m=(y2-y1)/(x2-x1);
    while((c1|c2)>0){
        if((c1&c2)>0)
        {
            xb[i]=0;
            yb[i]=0;
            xe[i]=0;
            ye[i]=0;
            return;
        }
        ll c=c1;
        float xi=x1,yi=y1,x,y;
        if(c==0){
            c=c2;
            xi=x2;
            yi=y2;
        }
        if((c&8)>0){
            y=ymax;
            x=xi+(ymax-yi)/m;
        }
        else if((c&4)>0){
            y=ymin;
            x=xi+(ymin-yi)/m;
        }
        else if((c&2)>0){
            x=xmax;
            y=yi+m*(xmax-xi);
        }
        else if((c&1)>0){
            x=xmin;
            y=yi+m*(xmin-xi);
        }
        if(c==c1){
            xb[i]=x;
            yb[i]=y;
            c1=codept(x,y);
        }
        if(c==c2){
            xe[i]=x;
            ye[i]=y;
            c2=codept(x,y);
        }
    }
    disp();
}
void keypress(unsigned char key,int x,int y){
    if(key=='c'){
        ll i;
        for(i=0;i<n;i++){
            cohen(i,xb[i],yb[i],xe[i],ye[i]);
        }
    }
}

int main(int argc, char** argv){
    ll i,j;
    cout<<"Enter xmin,ymin,xmax,ymax"<<endl;
    cin>>xmin>>ymin>>xmax>>ymax;
    cout<<"Enter No of lines"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>xb[i]>>yb[i]>>xe[i]>>ye[i];
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("cohen sutherland Algo");
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);
    glutDisplayFunc(disp);
    glutKeyboardFunc(keypress);
    glutMainLoop();
    return 0;
}