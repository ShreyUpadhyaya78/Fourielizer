#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<direct.h>
#include<math.h>
#define TAU 6.2831

using namespace std;
int main()
{
	int i,n;
	float x,y,t,c=5,f[1000],r[1000];

	printf("enter number of circles : ");
	scanf("%d",&n);
	//set working window where everything is rendered
	 initwindow(1368,766);
	 //color-0 is black
	 setcolor(0);

	for(i=0;i<n;i++)
	{
		printf("\ncircle %d\n",i+1);
		printf("freq = ");
		f[i]=2*(i+1)-1;
		printf("%f\n",f[i]);
		printf("radius = ");
		r[i]=100.0/f[i];
		printf("%f\n",r[i]);
	}
	setfillstyle(1, 0);
	delay(1000);
	for(t=0;t<=c*TAU;t=t+0.001)
	{
		bar(0, 0,700, 700);
		x=0; y=0;
		for(i=0;i<n;i++)
		{
		    setcolor(1+(i%15));
			circle(x+350,-y+350,fabs(r[i]));
			x=x+r[i]*cos(f[i]*t);
			y=y+r[i]*sin(f[i]*t);
		}

        setcolor(15);
        //small circle
		circle(x+350,-y+350,4);
		//line from center to small circle
		line(350,350,x+350,-y+350);
		putpixel(700+t*20,-y+350,14);
		//line from small circle to curve generator
       //line(x+350,-y+350,700+t*20,-y+350);
	}
	getch();
	closegraph();
	return 0;
}
