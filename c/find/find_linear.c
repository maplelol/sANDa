
#include "util.h"

extern int linear_find(int* nums,int count,int target,int* used_times);

int main() {
	int nums[] = {9,3,11,5,2,18,7};
	int nums_count = sizeof(nums)/sizeof(int);

	printf("nums=");
	print_array(nums,nums_count);
	printf("\n");

	int target = nums[2];
	printf("target=%d\n",target);

	int used_times = 0;
	int pos = linear_find(nums,nums_count,target,&used_times);
	printf("find pos=%d used_times=%d\n",pos,used_times);

	return 0;
}

int linear_find(int* nums,int count,int target,int* used_times) {
	for (int i=0; i<count; ++i) {
		++(*used_times);
		if (nums[i] == target) {
			return i;
		}
	}
	return -1;
}
