#ifndef PREORDER_HPP_
#define PREORDER_HPP_
#include <iostream>

void preorder(Node* root) {
	Node* current = root;
	while (current) {
		if (!current->left) {
			std::cout << current->val << " ";
			current = current->right;
		}
		else {
			Node* prev = current->left;
			while (prev->right && prev->right != current) {
				prev = prev->right;
			}
			if (!prev->right) {
				prev->right = current;
				std::cout << current->val;
				current = current->left;
			}
			else {
				prev->right = nullptr;
				current = current->right;
			}
		}
	}
}

//Time complexity O(n)
//Space complaxity O(1)
#endif //PREORDER_HPP_
