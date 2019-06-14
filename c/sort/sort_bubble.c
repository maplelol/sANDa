
#include "util.h"

extern void bubble_sort(int* nums,int count);

int main() {
	int nums[] = {9,3,11,5,2,18,7};
	int nums_count = sizeof(nums)/sizeof(int);

	printf("before sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	bubble_sort(nums,nums_count);

	printf("after sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	return 0;
}

void bubble_sort(int* nums,int count) {
	for (int i=0; i<count-1; ++i) {
		for (int j=i+1; j<count; ++j) {
			if (nums[j] < nums[i]) {
				swap_array_pos_value(nums,i,j);
			}
		}
	}
}

