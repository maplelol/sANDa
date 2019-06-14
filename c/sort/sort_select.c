
#include "util.h"

extern void insert_sort(int* nums,int count);

int main() {
	int nums[] = {9,3,11,5,2,18,7};
	int nums_count = sizeof(nums)/sizeof(int);

	printf("before sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	insert_sort(nums,nums_count);

	printf("after sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	return 0;
}

void insert_sort(int* nums,int count) {
	for (int i=0; i<count-1; ++i) {
		int minIndex = i;
		for (int j=i+1; j<count; ++j) {
			if (nums[j] < nums[minIndex]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			swap_array_pos_value(nums,i,minIndex);
		}
	}
}
