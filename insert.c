#include <stdio.h>
#include <stdlib.h>

#define MY_DATA 10

unsigned int arr[MY_DATA] = {8, 5, 6, 2, 3, 4, 0, 7, 1, 9};
unsigned int arr1[MY_DATA] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
void Swap_Two_Numbers(unsigned int *num1, unsigned int *num2);
void Execute_Insertion_Sort(unsigned int My_arr[], unsigned int lengh);
void Print_My_Array(unsigned int My_arr[], unsigned int lengh);

int main()
{
	
	Print_My_Array(arr, MY_DATA);
	Execute_Insertion_Sort(arr, MY_DATA);
	Print_My_Array(arr, MY_DATA);
	
	
	return 0;
}

void Swap_Two_Numbers(unsigned int *num1, unsigned int *num2){
	unsigned int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void Execute_Insertion_Sort(unsigned int My_arr[], unsigned int lengh){
	unsigned int x = 0;
	unsigned int is_item = 0;
	signed int comp_item = 0;
	
	for(x=1; x<lengh ;x++){
		is_item = My_arr[x];
		comp_item = x - 1;
		
		while((is_item<My_arr[comp_item]) && (comp_item>=0)){
			My_arr[comp_item+1] = My_arr[comp_item];
			comp_item--;
		}
		My_arr[comp_item+1] = is_item;
	}
}
void Print_My_Array(unsigned int My_arr[], unsigned int lengh){
	unsigned int i = 0;
	for(i=0; i<lengh; i++){
		printf("%i \t", My_arr[i]);
	}
	printf("\n");
}
