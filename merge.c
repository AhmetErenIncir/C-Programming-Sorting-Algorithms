#include<stdio.h>
#define MAX_SIZE_OF_ARRAY 50

void merge(int array[],int  tail,int  mid, int head )
{
	int temp_array1[MAX_SIZE_OF_ARRAY] , i = tail , j = mid +1 , k = tail;

	while( (i <= mid) && (j <=head) )
	{
		if(array[i] <= array[j])
			temp_array1[k++] = array[i++] ;
		else
			temp_array1[k++] = array[j++] ;
	}
	
	while( i <= mid )
		temp_array1[k++]=array[i++];
	
	while( j <= head )
		temp_array1[k++]=array[j++];

	for(i= tail; i <= head ; i++)
		array[i]=temp_array1[i];
	
}

void merge_sort( int array[],int tail, int head )
{
	int mid;
	if( tail != head )
	{
		mid = (tail+head)/2;
		merge_sort(array ,tail , mid );
		merge_sort( array,mid+1, head );
		merge(array,tail, mid, head );
	}
}
int main()
{
	int i,size,array[MAX_SIZE_OF_ARRAY];

	printf("Enter the number of elements : ");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		printf("Enter %d . element : ",i+1);
		scanf("%d",&array[i]);
	}

	merge_sort( array,0, size-1);

	for( i = 0 ; i<size ; i++)
		printf("%d ", array[i]);
	printf("\n");
	
}

