#include <stdio.h>
#include <stdlib.h>

#define MY_DATA 10

unsigned int arr[MY_DATA] = {8, 5, 6, 2, 3, 4, 0, 7, 1, 9};
unsigned int arr1[MY_DATA] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
void Swap_Two_Numbers(unsigned int *num1, unsigned int *num2);
void Execute_Selection_Sort(unsigned int My_arr[], unsigned int lengh);
void Print_My_Array(unsigned int My_arr[], unsigned int lengh);

int main()
{
	Print_My_Array(arr, MY_DATA);
	Execute_Selection_Sort(arr, MY_DATA);
	Print_My_Array(arr, MY_DATA);
	
	
	return 0;
}

void Swap_Two_Numbers(unsigned int *num1, unsigned int *num2){
	unsigned int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void Execute_Selection_Sort(unsigned int My_arr[], unsigned int lengh){
	unsigned int x = 0;
	unsigned int min_index = 0;
	unsigned int comp_item = 0;
	
	for(x=0; x<lengh-1 ;x++){
		min_index = x;
		for(comp_item = x+1; comp_item<lengh ;comp_item++){
			if(My_arr[comp_item] < My_arr[min_index]){
				min_index = comp_item;
			}
			else{
				/* Nothing */
			}
		}
		Swap_Two_Numbers(&My_arr[min_index] ,&My_arr[x]);
	}
}
void Print_My_Array(unsigned int My_arr[], unsigned int lengh){
	unsigned int i = 0;
	for(i=0; i<lengh; i++){
		printf("%i \t", My_arr[i]);
	}
	printf("\n");
}