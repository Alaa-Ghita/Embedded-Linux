#include <stdio.h>
float divide (float x, float y)
{
	if(y==0)
	{
		printf("Can't divide by zero!\n");
		return 0.0;
	}
	else
	{ return x/y; }
}
