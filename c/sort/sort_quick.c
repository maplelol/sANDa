
//冒泡+二分+递归，时间复杂度不稳定，平均值是O(nlogn)

#include "util.h"

extern void quick_sort(int* nums,int count);

int main() {
	int nums[] = {9,3,11,5,2,18,7};
	int nums_count = sizeof(nums)/sizeof(int);

	printf("before sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	quick_sort(nums,nums_count);

	printf("after sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	return 0;
}

int _partition(int* nums,int left,int right);
void _sort_recursively(int* nums,int left,int right);

void quick_sort(int* nums,int count) {
	_sort_recursively(nums,0,count-1);
}

int _partition(int* nums,int left,int right) {
	int pivotVal = nums[left];
	int pivotPos = left;
	while (left < right) {
		while (left < right && nums[right] >= pivotVal) {
			--right;
		}
		while (left < right && nums[left] <= pivotVal) {
			++left;
		}
		if (left < right) {
			swap_array_pos_value(nums,left,right);
		}
	}
	swap_array_pos_value(nums,left,pivotPos);
	return left;
}

void _sort_recursively(int* nums,int left,int right) {
	if (left >= right) {
		return;
	}

	int pivot = _partition(nums,left,right);
	_sort_recursively(nums,left,pivot-1);
	_sort_recursively(nums,pivot+1,right);
}

