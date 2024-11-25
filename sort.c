#include <stdio.h>
#include <stdlib.h>

#define MY_DATA 10

unsigned int arr[MY_DATA] = {8, 5, 6, 2, 3, 4, 0, 7, 1, 9};
unsigned int arr1[MY_DATA] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
void Swap_Two_Numbers(unsigned int *num1, unsigned int *num2);
void Execute_Bubbel_Sort(unsigned int My_arr[], unsigned int lengh);
void Print_My_Array(unsigned int My_arr[], unsigned int lengh);

int main()
{
	Print_My_Array(arr1, MY_DATA);
	Execute_Bubbel_Sort(arr1, MY_DATA);
	Print_My_Array(arr1, MY_DATA);
	
	
	return 0;
}

void Swap_Two_Numbers(unsigned int *num1, unsigned int *num2){
	unsigned int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void Execute_Bubbel_Sort(unsigned int My_arr[], unsigned int lengh){
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int flag = 0;
	
	for(x=0; x<lengh-1 ;x++){
		for(y=0; y<lengh-1-x ;y++){
			if(My_arr[y] > My_arr[y+1]){
				Swap_Two_Numbers(&My_arr[y], &My_arr[y+1]);
				flag = 1;
			}
			Print_My_Array(My_arr, lengh);
		}
		if(flag == 0){
			return;
		}
	}
}
void Print_My_Array(unsigned int My_arr[], unsigned int lengh){
	unsigned int i = 0;
	for(i=0; i<lengh; i++){
		printf("%i \t", My_arr[i]);
	}
	printf("\n");
}