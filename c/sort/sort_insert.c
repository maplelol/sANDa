
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
	if (count < 2) {
		return;
	}

	for (int i=1; i<count; ++i) {
		int j = i;
		int toInsertVal = nums[i];
		for (; j>=0; --j) {
			if (nums[j-1] <= toInsertVal) {
				break;
			}

			nums[j] = nums[j-1];
		}
		nums[j] = toInsertVal;
	}
}
