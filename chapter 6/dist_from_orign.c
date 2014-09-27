#include<stdio.h>
#include<math.h>

struct point{
	int x;
	int y;
};

main()
{
	struct point p;
	p.x=1,p.y=2;
	printf("\ndistance from origin is %f\n",sqrt(p.x*p.x + p.y*p.y));
}
