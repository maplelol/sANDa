
#include "util.h"

int find_binary(int* nums,int count,int target,int* used_times);

int main() {
	int nums[] = {2,3,5,7,9,11,18};
	int nums_count = sizeof(nums)/sizeof(int);

	printf("nums=");
	print_array(nums,nums_count);
	printf("\n");

	int target = nums[2];
	printf("target=%d\n",target);

	int used_times = 0;
	int pos = find_binary(nums,nums_count,target,&used_times);
	printf("find pos=%d used_times=%d\n",pos,used_times);

	return 0;
}

int find_binary(int* nums,int count,int target,int* used_times) {
	int start = 0;
	int end = count - 1;
	while (start <= end) {
		++(*used_times);

		int mid = (start + end) / 2;
		if (target == nums[mid]) {
			return mid;
		} else if (target > nums[mid]) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return -1;
}
