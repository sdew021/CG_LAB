#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<graphics.h>
#include <X11/Xlib.h> 
int abs(int x){
	return ((x>0)? x : (x*(-1)));
}
void wait_for_char()
{

    //Wait for a key press
    int in = 0;

    while (in == 0) {
        in = getch();
    }
}

int main(){
	XInitThreads();
	int gd= DETECT,gm,COLOR = GREEN;
	float x,y,x1,y1,x2,y2,dx,dy,step;
	initgraph(&gd,&gm,"");

	//set the values of x1,y1 & x2,y2 here
	x1 = 320 -50;
	y1 = 250 - 50;

	x2 = 320 + 0;
	y2 = 250 + 0;

	dx=abs(x2-x1);
	dy=abs(y2-y1);

	if(dx>=dy)
		step=dx;
	else
		step=dy;

	dx=dx/step;
	dy=dy/step;

	x=x1;
	y=y1;

	int i=1;
	while(i<=step)
	{
		putpixel(x,y,5);
		x=x+dx;
		y=y+dy;
		i=i+1;
		delay(10);
		if(x == 480 || y==480){
			//closegraph();
			break;
		}
	}
	
	//putpixel(0 + 320,0 + 250,COLOR);
	
	wait_for_char();
	
	closegraph();
	
	return 0;
}
