#include<stdio.h>

#define XMAX 10
#define YMAX 10

struct point makep(int x,int y);

struct point{
	int x;
	int y;
};

struct rect{
	struct point p;
	struct point q;
};

main()
{
	struct rect screen;
	struct point middle;
	
	screen.p=makep(0,0);
	screen.q=makep(XMAX,YMAX);

	middle = makep((screen.p.x + screen.q.x)/2,(screen.p.y + screen.q.y)/2);
	printf("\n%d\t%d\n",middle.x,middle.y);
	
}

struct point makep(int x,int y)
{
	struct point t;
	t.x=x;
	t.y=y;
	
	return t;
}
