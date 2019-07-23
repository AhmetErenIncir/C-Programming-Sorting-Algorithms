#include <stdio.h>
#include <stdlib.h>

void merge_it(int array[] , int head ,int mid, int tail , int size){
	int temp_arr1[size] , temp_arr2[size] ;
	int temp_n1 , temp_n2 , i , j , k;

	temp_n1 = mid - tail + 1 ;
	temp_n2 = head - mid ;

	for(i=0;i<temp_n1;i++){
		temp_arr1[i]=array[tail+i];
	}
	temp_arr1[i] = 9999;


  	for(j=0;j<temp_n2;j++){
		temp_arr2[j]=array[mid+1+j];
	}
	temp_arr2[i] = 9999;
	j = 0;
	i = 0;
	for(k=tail  ; k<=head ; k++){
		if(temp_arr1[i] <= temp_arr2[j]){
			array[k] = temp_arr1[i];
			i++;
		}
		else{
			array[k] = temp_arr2[j];
			j++;
		}
	}


}

void mergeSort(int array[] , int head , int tail , int size ){
	int mid;

	if(tail<head){
		mid = (head + tail) / 2;
		mergeSort(array , head , mid , size);
		mergeSort(array , mid+1 , tail , size);
		merge_it(array,head,mid,tail,size);
	}
}

// 3 4 9 12 1 8 6 // Array to merge

int main(){
	int size,i;

	printf("Enter the array size\n");
	scanf("%d",&size);

	int arr[size];

	for(i=0 ; i<size ; i++){
		scanf("%d",&arr[i]);
	}

	mergeSort(arr,0,size-1,size);

	for(i=0 ; i<size ; i++){
		printf("%d ",arr[i]);
	}

}
