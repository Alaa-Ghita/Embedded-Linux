#include <stdio.h>

int BinSearch(int * ptr,int size, int num)
{
	int mid, Hi=size-1, Lo=0,i=-1;
	mid=(Hi+Lo)/2;
	while(Hi>=Lo)
	{
		mid=(Hi+Lo)/2;
		if(ptr[mid]>num)
		{
			Hi=mid-1;
		}
		else if(ptr[mid]<num)
		{
			Lo=mid+1;
		}
		else
		{
			i=mid;
			break;
		}
	}
	return i;
}

int main(void)
{
	int arr[10]={3,12,27,35,40,56,68,79,81,94};
	int index;
	index=BinSearch(arr,10,81);
	if(index>-1)
	{
		printf("Found the element at index %i\n",index);
	}
	else{
		printf("Element not found!\n");
	}
	return 0;
}
	
