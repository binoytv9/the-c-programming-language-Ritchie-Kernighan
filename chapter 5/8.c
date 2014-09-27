#include<stdio.h>

int doy(int y,int m,int dm);
int dom(int y,int dy,int *m,int *dm);

char dt[][13]={
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
		};
		
char mn[][4]={"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};		

main()
{
	int m,d;
	int y,month,dm,dy,day;
	y=2014;
	month=12;
	dm=31;
	dy=365;
	
	if(day=doy(y,month,dm)){	
		printf("\n\n%dth of [%d]%s, %d is :",dm,month,mn[month],y);
		printf("\n\t\t\t%dth day of %d \n",day,y);
	}
	
	if(dom(y,dy,&m,&d)){
		printf("\n\n%dth day of %d is :",dy,y);
		printf("\n\t\t\t%dth day of %s month[%d] \n\n",d,mn[m],m);
	}
	
}

int doy(int y,int m,int dm)
{
	int l,i;
	
	l=(y%4==0 && y%100!=0 || y%400==0);	//printf("\n%d\n",dt[l][m]);

	if(y<1 || (m>12) || (dm>dt[l][m])){
		printf("\nInvalid Date !!!\n");
		return 0;
	}
			
	for(i=1;i<m;++i)
		dm+=dt[l][i];
	
	return dm;
}

int dom(int y,int dy,int *m,int *dm)
{
	int l,i;
	
	l=(y%4==0 && y%100!=0 || y%400==0);

	if((y<1) || (dy>(l==0?365:366))){
		printf("\nInvalid Date !!!\n");
		return 0;
	}
	
	for(i=1;dy>dt[l][i];++i)
		dy-=dt[l][i];
		
	*m=i;
	*dm=dy;
	
	return i;
}
