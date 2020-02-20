#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
 
/* Global variables */
char title[] = "3D Shapes";
float tx,ty,tz;
void display();
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}
 /*
void dis(){

int opt; 
    printf("\nEnter\n\t<1> for Cube\n\t<2> for Pyramid"); 
    scanf("%d", &opt); 
    printf("\nGo to the window..."); 
float x1,y1,x2,y2,r;
int n;
    switch (opt) { 
    case 1: 
	
	n = 8;
	int size;
	printf("Enter size of sides\n");
/*	scanf("%d",&size);
	int i;
	int aa[] = {0,size,size,0,0,size,size,0};
	int bb[] = {0, 0, size, size,0,0,size,size};
	int cc[] = {0,0,0,0,size,size,size,size};

	for(i=0;i<n;i++){
		a[i] = aa[i];
		b[i] = bb[i];
		c[i] = cc[i];
	}
	
	printf("Enter x,y,z for translation\n");
	scanf("%f %f %f",&tx,&ty,&tz);
	//printf("%f %f %f %f %f %f\n",x1,y1,x2,y2,tx,ty);
     //   translatePoint(tx,ty,tz,n); 
	display();
        break; 
    case 2: 
        
        break; 
    case 3: 
       // scalePoint(10, 20, 2, 3); 
        break; 
    } 

}*/
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */

void display2() {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();  // Nice perspective corrections    // Reset the model-view matrix
   glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
 
   glBegin(GL_LINE_STRIP);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
 //glutPostRedisplay();

glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -6.0f);

glBegin(GL_LINE_STRIP);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f*cos(tx) - 1.0f*sin(tx), 0.0f*sin(tx) + 1.0f*cos(tx), 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f*cos(tx) + 1.0f*sin(tx), -1.0f*sin(tx) - 1.0f*cos(tx), 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f*cos(tx) + 1.0f*sin(tx), 1.0f*sin(tx) - 1.0f*cos(tx), 1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f*cos(tx) - 1.0f*sin(tx), 0.0f*sin(tx) + 1.0f*cos(tx), 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f*cos(tx) + 1.0f*sin(tx), 1.0f*sin(tx) - 1.0f*cos(tx), 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f*cos(tx) + 1.0f*sin(tx), 1.0f*sin(tx) - 1.0f*cos(tx), -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f*cos(tx) - 1.0f*sin(tx), 0.0f*sin(tx) + 1.0f*cos(tx), 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f*cos(tx) + 1.0f*sin(tx), 1.0f*sin(tx) - 1.0f*cos(tx), -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f*cos(tx) + 1.0f*sin(tx), -1.0f*sin(tx) - 1.0f*cos(tx), -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f*cos(tx) - 1.0f*sin(tx), 0.0f*sin(tx) + 1.0f*cos(tx), 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f*cos(tx) + 1.0f*sin(tx), -1.0f*sin(tx) - 1.0f*cos(tx),-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f*cos(tx) + 1.0f*sin(tx), -1.0f*sin(tx) - 1.0f*cos(tx), 1.0f);
   glEnd();


   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 

void display() {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();  // Nice perspective corrections    // Reset the model-view matrix
   glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
 

   glBegin(GL_LINE_STRIP);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
 //glutPostRedisplay();

glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -6.0f);

glBegin(GL_LINE_STRIP);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0*cos(tx)-0.0*sin(tx),1.0*sin(tx)+ 0.0*cos(tx));
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0*cos(tx)-1.0*sin(tx),-1.0*sin(tx)+ 1.0*cos(tx));
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0*cos(tx)-1.0*sin(tx),-1.0*sin(tx)+ 1.0*cos(tx));
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0*cos(tx)-0.0*sin(tx),1.0*sin(tx)+ 0.0*cos(tx));
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0*cos(tx)-1.0*sin(tx),-1.0*sin(tx)+ 1.0*cos(tx));
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0*cos(tx)+1.0*sin(tx),-1.0*sin(tx)- 1.0*cos(tx));
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0*cos(tx)-0.0*sin(tx),1.0*sin(tx)+ 0.0*cos(tx));
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0*cos(tx)+1.0*sin(tx),-1.0*sin(tx)- 1.0*cos(tx));
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0*cos(tx)+1.0*sin(tx),-1.0*sin(tx) -1.0*cos(tx));
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0*cos(tx)-0.0*sin(tx),1.0*sin(tx)+ 0.0*cos(tx));
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0*cos(tx)+1.0*sin(tx),-1.0*sin(tx)-1.0*cos(tx));
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0*cos(tx)-1.0*sin(tx),-1.0*sin(tx)+1.0*cos(tx));
   glEnd();


   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 

void display1() {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();  // Nice perspective corrections    // Reset the model-view matrix
   glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
 
  
   glBegin(GL_LINE_STRIP);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
 //glutPostRedisplay();

glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -6.0f);

glBegin(GL_LINE_STRIP);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f*sin(tx)+0.0*cos(tx), 1.0f, 0.0f*cos(tx)-0.0*sin(tx));
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f*sin(tx)-1.0*cos(tx), -1.0f, 1.0f*cos(tx)+1.0*sin(tx));
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f*sin(tx)+1.0*cos(tx), -1.0f, 1.0f*cos(tx)-1.0*sin(tx));
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f*sin(tx)+0.0*cos(tx), 1.0f, 0.0f*cos(tx)-0.0*sin(tx));
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f*sin(tx)+1.0*cos(tx), -1.0f, 1.0f*cos(tx)-1.0*sin(tx));
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f*sin(tx)+1.0*cos(tx), -1.0f, -1.0f*cos(tx)-1.0*sin(tx));
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f*sin(tx)+0.0*cos(tx), 1.0f, 0.0f*cos(tx)-0.0*sin(tx));
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f*sin(tx)+1.0*cos(tx), -1.0f, -1.0f*cos(tx)-1.0*sin(tx));
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f*sin(tx)-1.0*cos(tx), -1.0f, -1.0f*cos(tx)+1.0*sin(tx));
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f(0.0f*sin(tx)+0.0*cos(tx), 1.0f, 0.0f*cos(tx)-0.0*sin(tx));
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f*sin(tx)-1.0*cos(tx), -1.0f, -1.0f*cos(tx)+1.0*sin(tx));
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(1.0f*sin(tx)-1.0*cos(tx), -1.0f, 1.0f*cos(tx)+1.0*sin(tx));
   glEnd();


   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {

	int opt;
	printf("To rotate about<1>X axis\n\t<2>Y axis\n\t<3>Z axis\n");
	scanf("%d",&opt);
printf("Enter radians of rotation\n");
	scanf("%f",&tx);


   glutInit(&argc, argv);       


     // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title); 
if(opt==1)         // Create window with the given title
   glutDisplayFunc(display); 
else if(opt==2)
	glutDisplayFunc(display1);
else	
	glutDisplayFunc(display2); 
      // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
