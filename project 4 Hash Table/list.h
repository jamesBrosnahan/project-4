#pragma once
#include <string>
#include <iostream>

template<class T>
struct node {
	T value;
	node<T> * next;
	node<T> * prev;
};

template<class T>
class list
{
private:
	size_t max;
	size_t current = 0;
	node<T>* head = NULL;
public:
	list(int max_) {
		max = max_;
	}
	bool append(T value) {
		if (current >= max) {
			return false;
		}
		else {
			node<T> *tmp = head;
			if (tmp == NULL) {
				current++;
				node<T> *Node = new node<T>;
				head = Node;
				Node->value = value;
				Node->next = NULL;
				return true;
			}
			while (tmp->next != NULL) {
				if (tmp->next != NULL) {
					tmp = tmp->next;
				}
			}
			current++;
			node<T> *Node = new node<T>;
			Node->value = value;
			tmp->next = Node;
			Node->next = NULL;
			return true;
		}
	}
	bool find(T val) {
		node<T> *tmp = head;
		if (tmp == NULL) {
			return false;
		}
		while (tmp->next != NULL) {
			if (tmp->value == val) {
				return true;
			}
			if (tmp->next == NULL) {
				return false;
			}
			tmp = tmp->next;
		}
		return false;
	}
	bool remove(T val) {
		node<T> *tmp = head;
		if (tmp == NULL) {
			return false;
		}
		bool removed = false;
		while (tmp->next != NULL) {
			if (tmp->next->value == val) {
				tmp->next = tmp->next->next;
				current--;
				removed = true;
			}
			if (tmp->next == NULL) {
				return removed;
			}
			tmp = tmp->next;
		}
		return removed;
	}
	bool full() {
		return current == max;
	}
};

