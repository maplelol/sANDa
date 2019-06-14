
#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct _bs_tree {
	int value;

	struct _bs_tree* parent;
	struct _bs_tree* left_child;
	struct _bs_tree* right_child;
} bs_tree;

void _bs_tree_print_recursively(bs_tree* tree) {
	if (tree != NULL) {
		if (tree->left_child != NULL) {
			printf("%d,",tree->left_child->value);
		}
		if (tree->right_child != NULL) {
			printf("%d,",tree->right_child->value);
		}
		_bs_tree_print_recursively(tree->left_child);
		_bs_tree_print_recursively(tree->right_child);
	}
}

void bs_tree_print(bs_tree* tree) {
	if (tree != NULL) {
		printf("%d,",tree->value);
		_bs_tree_print_recursively(tree);
	}
}

bs_tree* bs_tree_new_node(int value) {
	bs_tree* n = (bs_tree*)malloc(sizeof(bs_tree));
	memset(n,0,sizeof(bs_tree));
	n->value = value;
	return n;
}

bs_tree* bs_tree_insert_node(bs_tree* parent,int value) {
	bs_tree* cur = NULL;
	bs_tree* n = bs_tree_new_node(value);
	while(parent != NULL) {
		cur = parent;
		if (n->value < parent->value) {
			parent = parent->left_child;
		} else {
			parent = parent->right_child;
		}
	}

	if (cur == NULL) {
		return n;
	} else {
		if (n->value < cur->value) {
			cur->left_child = n;
		} else {
			cur->right_child = n;
		}
		n->parent = cur;
		return n;
	}
}

void bs_tree_delete_node(bs_tree* node) {
	if (node != NULL) {
		bs_tree_delete_node(node->left_child);
		bs_tree_delete_node(node->right_child);

		printf("bs_tree_delete_node with value:%d\n",node->value);
		free(node);
	}
}

bs_tree* bs_tree_find(bs_tree* tree,int value,int* used_times) {
	while (tree != NULL && tree->value != value) {
		++(*used_times);
		if (value < tree->value) {
			tree = tree->left_child;
		} else {
			tree = tree->right_child;
		}
	}
	return tree;
}

void bs_tree_inorder_traversal(bs_tree* tree,void (*visitor)(bs_tree* node)) {
	if (tree != NULL) {
		bs_tree_inorder_traversal(tree->left_child,visitor);
		visitor(tree);
		bs_tree_inorder_traversal(tree->right_child,visitor);
	}
}

