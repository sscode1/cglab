

 #include <GL/glut.h>
#include<iostream>

#define ll long long
GLfloat v[4][2]={{-1.0, 1.0}, {1.0, 1.0}, {1.0,-1.0},{-1.0, -1.0}};

ll n; 
void sq( GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)
{
       glVertex2fv(a); 
       glVertex2fv(b); 
       glVertex2fv(c);
       glVertex2fv(d);       
}

void divide_sq(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m)
{
     
     GLfloat v0[2], v1[2], v2[2], v3[2], v4[2], v5[2], v6[2], v7[2], v8[2], v9[2], v10[2], v11[2];
     int j;
     if(m>0)
     {
       for(j=0; j<2; j++) v0[j]=(2*a[j]+b[j])/3;
       for(j=0; j<2; j++) v1[j]=(a[j]+2*b[j])/3;
       for(j=0; j<2; j++) v2[j]=(2*b[j]+c[j])/3;
       for(j=0; j<2; j++) v3[j]=(b[j]+2*c[j])/3;
       for(j=0; j<2; j++) v4[j]=(2*c[j]+d[j])/3;
       for(j=0; j<2; j++) v5[j]=(c[j]+2*d[j])/3;
       for(j=0; j<2; j++) v6[j]=(2*d[j]+a[j])/3;
       for(j=0; j<2; j++) v7[j]=(d[j]+2*a[j])/3;
       for(j=0; j<2; j++) v8[j]=(2*v7[j]+v2[j])/3;
       for(j=0; j<2; j++) v9[j]=(v7[j]+2*v2[j])/3;
       for(j=0; j<2; j++) v10[j]=(v6[j]+2*v3[j])/3;
       for(j=0; j<2; j++) v11[j]=(2*v6[j]+v3[j])/3;
       divide_sq(a, v0, v8, v7, m-1);
       divide_sq(v0, v1, v9, v8, m-1);
       divide_sq(v1, b, v2, v9, m-1);
       divide_sq(v9, v2, v3, v10, m-1);
       divide_sq(v10, v3, c, v4, m-1);
       divide_sq(v11, v10, v4, v5, m-1);
       divide_sq(v6, v11, v5, d, m-1);
       divide_sq(v7, v8, v11, v6, m-1);

       
     }
     else
       sq(a,b,c,d);     
}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_QUADS);
     divide_sq(v[0], v[1], v[2], v[3], n);
     glEnd();
     glFlush();
}

void myinit()
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
     glMatrixMode(GL_MODELVIEW);
     glClearColor (1.0, 1.0, 1.0,1.0);
     glColor3f(0.0,0.0,0.0);
}

int main(int argc, char **argv)
{
     std::cin>>n;
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(500, 500);
     glutCreateWindow("2D Gasket");
     glutDisplayFunc(display);
     myinit();
     glutMainLoop();
}
