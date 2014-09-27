#include<stdio.h>

struct point{
	int x;
	int y;
};

struct point addpoints(struct point p,struct point q);

main()
{
	struct point p={1,2},q={3,4};
	
	p=addpoints(p,q);
	printf("\n%d\t%d\n",p.x,p.y);
}

struct point addpoints(struct point p,struct point q)
{
	p.x+=q.x;
	p.y+=q.y;
	return p;
}
