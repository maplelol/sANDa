
#include "util.h"

extern void heap_sort(int* nums,int count);

extern int left_child_index(int i);
extern int father_index(int i);
extern void adjust_heap(int* nums,int start,int end);

int main() {
	int nums[] = {9,3,11,5,2,18,7};
	int nums_count = sizeof(nums)/sizeof(int);

	printf("before sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	heap_sort(nums,nums_count);

	printf("after sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	return 0;
}

void heap_sort(int* nums,int count) {
	for (int i=count/2 - 1; i>=0; --i) {
		adjust_heap(nums,i,count);
	}

	printf("\n");

	for (int j=count-1; j>=0; --j) {
		swap_array_pos_value(nums,0,j);
		adjust_heap(nums,0,j);
	}
}

int left_child_index(int i) {
	return i*2 + 1;
}

int father_index(int i) {
	return i/2;
}

void adjust_heap(int* nums,int start,int end) {
	int fatherVal = nums[start];
	for (int i=left_child_index(start); i<end; i=left_child_index(i)) {
		if (i + 1 < end && nums[i+1] > nums[i]) {
			++i;
		}
		if (nums[i] > fatherVal) {
			nums[start] = nums[i];
			start = i;
			print_array(nums,end);
		} else {
			break;
		}
	}
	nums[start] = fatherVal;
	printf("\n");
}
