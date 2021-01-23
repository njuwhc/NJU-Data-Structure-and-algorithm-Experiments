#include "MySort.h"
void Myqsort(int *array,int size)
{
    int p;
    if (0 < size - 1)
    {
        p = partition(array, 0, size - 1);
        Myqsort(array, p);
        Myqsort(array + p, size - p);
  }
}

int partition(int* array, int low, int high)
{
    int x = array[high];
    int i, j,temp;
    i = low - 1;
    for (j = low; j <= high - 1;j++)
        if (array[j] <= x)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

        }
    temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return (i + 1);
    
}