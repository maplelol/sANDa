
#include "util.h"

#include <stdlib.h>
#include <string.h>

extern void merge_sort(int* nums,int count);
extern void _merge_sort_recursively(int* nums,int start,int end);
extern void _merge(int* nums,int start,int end,int mid);

static int* nums_tmp = NULL;

int main() {
	int nums[] = {9,3,11,5,2,18,7};
	int nums_count = sizeof(nums)/sizeof(int);

	nums_tmp = (int*)malloc(sizeof(nums));
	memset(nums_tmp,0,sizeof(nums));

	printf("before sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	merge_sort(nums,nums_count);

	printf("after sort, nums=");
	print_array(nums,nums_count);
	printf("\n");

	free(nums_tmp);

	return 0;
}

void merge_sort(int* nums,int count) {
	_merge_sort_recursively(nums,0,count-1);
}

void _merge_sort_recursively(int* nums,int start,int end) {
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;
	_merge_sort_recursively(nums,start,mid);
	_merge_sort_recursively(nums,mid+1,end);
	_merge(nums,start,end,mid);
}

void _merge(int* nums,int start,int end,int mid) {
	memset(nums_tmp,0,sizeof(nums));

	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end) {
		if (nums[i] < nums[j]) {
			nums_tmp[k++] = nums[i++];
		} else {
			nums_tmp[k++] = nums[j++];
		}
	}

	while (i <= mid) {
		nums_tmp[k++] = nums[i++];
	}
	while (j <= end) {
		nums_tmp[k++] = nums[j++];
	}

	for (int x=0; x<(end-start+1); ++x) {
		nums[start+x] = nums_tmp[x];
	}
}
