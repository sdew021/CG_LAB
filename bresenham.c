#include<stdio.h>
#include<GL/glut.h>
#include<graphics.h>
#include<math.h>
#include <X11/Xlib.h> 
void wait_for_char()
{

    //Wait for a key press
    int in = 0;

    while (in == 0) {
        in = getch();
    }
}

int abs(int x){
	return ((x>0)? x : (x*(-1)));
}

int main(){
	XInitThreads();
	int gd= DETECT,gm,COLOR = GREEN;
	float x,y,x1,y1,x0,y0,dx,dy,step;
	initgraph(&gd,&gm,"");

	//set the values of x1,y1 & x2,y2 here
	x0 = 320 + 0;
	y0 = 250 + 0;

	x1 = 320 + 50;
	y1 = 250 + 50;

	dx=x1-x0;
	dy=y1-y0;

	x=x0;
	y=y0;

	int p=2*dy-dx;

	while(x<x1)
	{
		if(p>=0)
		{
			putpixel(x,y,7);
			y=y+1;
			p=p+2*dy-2*dx;
			delay(10);
		}
		else
		{
			putpixel(x,y,7);
			p=p+2*dy;
			delay(10);
		}
		x=x+1;
	}

	wait_for_char();
	
	closegraph();
	
	return 0;
}
