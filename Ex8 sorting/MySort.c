#include "MySort.h"
void Mysort(int *array,int size)//ascending sort
{
	int i, j, t, flag;
	for (i = 0; i < size - 1; i++)
	{
		flag = 1;
		for(j=0;j<size-1-i;j++)
			if (array[j] > array[j + 1])
			{
				t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
				flag = 0;
			}
		if (flag)
			break ;
	}
}