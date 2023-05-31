#ifndef POSTORDER_HPP_
#define POSTORDER_HPP_
#include <iostream>

void reverse(Node* start, Node* end) {
	if (start == end) {
		return;
	}
	Node* prev = nullptr;
	Node* cur = start;
	while (prev != end) {
		Node* next = cur->right;
		cur->right = prev;
		prev = cur;
		cur = next;
	}
}

void postorder(Node* root) {
	if (!root) {
		return;
	}
	Node fake;
	fake.left = root;
	Node* current = &fake;
	while (current) {
		if (!current->left) {
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
				reverse(current->left, prev);
				Node* tmp = prev;
				while (tmp != current->left) {
					std::cout << tmp->val << " ";
					tmp = tmp->right;
				}
				std::cout << tmp->val << " ";
				reverse(prev, current->left);
				prev->right = nullptr;
				current = current->right;
			}
		}
	}
}

//Time complexity O(n)
//Space complexity O(1)
#endif //POSTORDER_HPP_
