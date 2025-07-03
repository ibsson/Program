#include <stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	c=c+d%60;
	if (c>=60)
	{
		c=c-60;
		b=b+1;
	}
	b=b+d/60;
	if (b>=60)
	{	
		a=a+b/60;
		b=b%60;
	}
	if (a>23)
	{
		a=a%24;
	}
	printf("%d %d %d",a,b,c);
}
