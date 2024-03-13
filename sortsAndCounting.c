#include <stdio.h>
#include <stdlib.h>
/*
Portions of code have been copied from samples in the modules for this course.
*/

void printArray(int arr[], int swaps[], int size)
{
    int i;
    for (i=0; i < size; i++){
        printf("%d: %d swaps\n", arr[i], swaps[i]);
    }
    printf("\n");
}

//The total number of swaps is half the sum of swaps of each element, because each swap affects 2 elements
int getHalfTotal(int arr[], int size) {
    int i, count = 0;
    for (i=0; i < size; i++){
        count+=arr[i];
    }
    return count/2;
}

void selectionSortWithCount(int arr[], int n)
{
	int i, j, min_idx, temp;

    //Declare array to hold swap counts
    int swaps[n];
    //Initialize
    for (i = 0; i < n; i++) {
        swaps[i] = 0;
    }

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
	    //printf("\nIteration# %d\n",i+1);
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++){
		    if (arr[j] < arr[min_idx]){
			    min_idx = j;
            }
        }
		// Swap the found minimum element with the first element
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
        //make the swap counts follow the elements and increment
        temp = swaps[i];
        swaps[i] = swaps[min_idx] + 1;
        swaps[min_idx] = temp + 1;
	}

    printArray(arr, swaps, n);
    printf("Total %d swaps\n", getHalfTotal(swaps, n));
}

void bubbleSortWithCount(int arr[], int n)
{
   //printf("\nUsing Bubble sort\n\n");

   int i, j,temp;

    //Declare array to hold swap counts
    int swaps[n];
    //Initialize
    for (i = 0; i < n; i++) {
        swaps[i] = 0;
    }

   for (i = 0; i < n-1; i++)
   {
        //printf("Iteration# %d\n",i+1);
        for (j = 0; j < n-i-1; j++)
        {
           if (arr[j] > arr[j+1])
           {//then swap
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
                //make the swap counts follow the elements and increment
                temp = swaps[j];
                swaps[j] = swaps[j+1] + 1;
                swaps[j+1] = temp + 1;
           }
        }

    }
    printArray(arr, swaps, n);
    printf("Total %d swaps\n", getHalfTotal(swaps, n));
}

int main() {
    int arr1[] = {97 , 16 , 45 , 63 , 13 , 22 , 7 , 58 , 72};
    int arr1b[] = {97 , 16 , 45 , 63 , 13 , 22 , 7 , 58 , 72};
    int arr2[] = {90 , 80 , 70 , 60 , 50 , 40 , 30 , 20 , 10};
    int arr2b[] = {90 , 80 , 70 , 60 , 50 , 40 , 30 , 20 , 10};
    
    printf("Array 1 selection sort.\n");
    selectionSortWithCount(arr1, 9);
    printf("Array 1 bubble sort.\n");
    bubbleSortWithCount(arr1b, 9);
    printf("Array 2 selection sort.\n");
    selectionSortWithCount(arr2, 9);
    printf("Array 2 bubble sort.\n");
    bubbleSortWithCount(arr2b, 9);
}