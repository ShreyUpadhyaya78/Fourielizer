#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<direct.h>
#include<math.h>
#define TAU 6.2831
#define PI 3.141592654

using namespace std;
void squareWave(){
	int i,n;
	float x,y,t,c=5,f[1000],r[1000],o,p;
    cout<<"enter number of circles : \n Higher number of circles will result in more refined curve"<<endl;
	cin>>n;
	//set working window where everything is rendered
	 initwindow(1368,766);
	 //color-0 is black
	 setcolor(0);

	for(i=0;i<n;i++)
	{
		cout<<"\ncircle %d\n"<<i+1<<endl;
		cout<<"freq = "<<endl;
		//square wave
		f[i]=2*(i+1)-1;
		printf("%f\n",f[i]);
		printf("radius = ");
		r[i]=80 * (4 / (f[i] * PI));
		printf("%f\n",r[i]);
	}
	setfillstyle(1, 0);
	delay(500);
	for(t=0;t<=c*TAU;t=t+0.001)
	{
		bar(0, 0,750, 700);
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
		//line from small circle to curve generator
		  //setcolor(15);
		  setfillstyle(1,0);
       //line(x+350,-y+350,700+t*20,-y+350);
        //wave
       putpixel(750+t*20,-y+350,14);



	}
	getch();
	closegraph();
    }
    //Sawtooth Wave
    void sawToothWave(){
	int i,n;
	float x,y,t,c=5,f[1000],r[1000],o,p;
    cout<<"enter number of circles : \n Higher number of circles will result in more refined curve"<<endl;
	cin>>n;
	//set working window where everything is rendered
	 initwindow(1368,766);
	 //color-0 is black
	 setcolor(0);

	for(i=0;i<n;i++)
	{
		cout<<"\ncircle %d\n"<<i+1<<endl;
		cout<<"freq = "<<endl;
		//square wave
		f[i]=i+1;
		printf("%f\n",f[i]);
		printf("radius = ");
		r[i]=0.5-(300/(f[i]*PI));
		printf("%f\n",r[i]);
	}
	setfillstyle(1, 0);
	delay(500);
	for(t=0;t<=c*TAU;t=t+0.001)
	{
		bar(0, 0,750, 700);
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
		//line from small circle to curve generator
		  //setcolor(15);
		  setfillstyle(1,0);
       //line(x+350,-y+350,700+t*20,-y+350);
        //wave
       putpixel(750+t*20,-y+350,14);



	}
	getch();
	closegraph();
    }
    //Triangular Wave
    void triangularWave(){
	int i,n;
	float x,y,t,c=5,f[1000],r[1000],o,p;
    cout<<"enter number of circles : \n Higher number of circles will result in more refined curve"<<endl;
	cin>>n;
	//set working window where everything is rendered
	 initwindow(1368,766);
	 //color-0 is black
	 setcolor(0);

	for(i=0;i<n;i++)
	{
		cout<<"\ncircle %d\n"<<i+1<<endl;
		cout<<"freq = "<<endl;
		//square wave
		f[i]=2*(i+1)-1;
		printf("%f\n",f[i]);
		printf("radius = ");
		r[i]=100*(8/(PI*PI*f[i]*f[i]))*pow(-1,(f[i]-1)/2);
		printf("%f\n",r[i]);
	}
	setfillstyle(1, 0);
	delay(500);
	for(t=0;t<=c*TAU;t=t+0.001)
	{
		bar(0, 0,750, 700);
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
		//line from small circle to curve generator
		  //setcolor(15);
		  setfillstyle(1,0);
       //line(x+350,-y+350,700+t*20,-y+350);
        //wave
       putpixel(750+t*20,-y+350,14);



	}
	getch();
	closegraph();
    }
int main()
{
    char c;
    cout<<"Choose the type of wave you want to simulate:\na) Square Wave\nb) Sawtooth Wave\nc) Triangular Wave"<<endl;
    cin>>c;
    if(c=='a'){
        squareWave();
    }
    else if(c=='b'){
        sawToothWave();
    }
    else{
        triangularWave();
    }

	return 0;
}
