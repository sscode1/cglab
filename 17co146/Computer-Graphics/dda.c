#include<stdio.h>
#include<graphics.h>

void main ()
{
	int gd=DETECT,gm,x1,y1,x2,y2,dy,dx,temp;
	float xinc,yinc;
	printf("\n===DDA Line Drawing Algorithm===\n\n");
	printf("Enter the co-ordinates of the first point :\nx1 : ");
	scanf("%d",&x1);
	printf("\ny1 : ");
	scanf("%d",&y1);
	printf("Enter the co-ordinates of the second point :\nx2 : ");
	scanf("%d",&x2);
	printf("\ny2 : ");
	scanf("%d",&y2);
	dy=y2-y1;
	dx=x2-x1;
	if(abs(dx)>=abs(dy))
		temp=abs(dx);
	else
		temp=abs(dy);
	xinc=dx/temp;
	yinc=dy/temp;
	initgraph(&gd,&gm,"C://TC//BGI");
	while(x1!=x2 && y1!=y2)
	{
		putpixel(x1,y1,15);
		x1+=xinc;
		y1+=yinc;
		delay(20);
	}
	//closegraph();
	getch();
}
