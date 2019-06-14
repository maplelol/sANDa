
#include "util.h"
#include "bs_tree.h"

int find_bstree(int* nums,int count,int target,int* used_times);

int main() {
	int nums[] = {9,3,11,5,2,18,7};
	int nums_count = sizeof(nums)/sizeof(int);

	printf("nums=");
	print_array(nums,nums_count);
	printf("\n");

	int target = nums[2];
	printf("target=%d\n",target);

	int used_times = 0;
	int pos = find_bstree(nums,nums_count,target,&used_times);
	printf("find pos=%d used_times=%d\n",pos,used_times);

	return 0;
}

void print_bstree_node(bs_tree* node) {
	printf("%d,",node->value);
}

int find_bstree(int* nums,int count,int target,int* used_times) {
	if (count < 1) {
		return -1;
	}

	bs_tree* root = bs_tree_new_node(nums[0]);
	bs_tree_print(root);
	printf("\n");
	for (int i=1; i<count; ++i) {
		bs_tree_insert_node(root,nums[i]);
		printf("%d\n", i);
	}

	printf("bs_tree=[");
	bs_tree_print(root);
	printf("]\n");

	printf("bs_tree_inorder_traversal=[");
	bs_tree_inorder_traversal(root,print_bstree_node);
	printf("]\n");

	bs_tree* find_n = bs_tree_find(root,target,used_times);
	int ret = find_n == NULL ? -1 : find_n->value;
	bs_tree_delete_node(root);
	return ret;
}
