
#pragma once

#include <stdio.h>
#include <stdlib.h>

#define PRINT_SIZE_OF(n) printf(#n); printf("%s:%ld\n","",n);

void print_array(int* array,int count) {
	printf("[");
	for (int i=0; i<count; ++i) {
		printf("%d",array[i]);
		if (i < count - 1) {
			printf(",");
		}
	}
	printf("]");
}

void swap_array_pos_value(int* array,int i,int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
