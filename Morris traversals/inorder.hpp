#ifndef INORDER_HPP_
#define INORDER_HPP_
#include <iostream>

void inorder(Node* root) {
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
				current = current->left;
			}
			else {
				prev->right = nullptr;
				std::cout << current->val << " ";
				current = current->right;
			}
		}
	}
}
//Time complexity O(n)
//Space complexity O(1)
#endif //INORDER_HPP_
