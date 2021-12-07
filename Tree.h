#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Iterator.h"
#include "Queue.h"
#include "Stack.h"
typedef bool IteratorType;

#define ITERATOR_DFT false // Depth iterator
#define ITERATOR_BFT true // Width iterator


class Tree
{
private:
	struct Node
	{
		int data;
		Node* parent = NULL;
		Node* left = NULL;
		Node* right = NULL;
	};

	Node* head = NULL;

	void clear(Node* temp)
	{
		if (temp != NULL) {
			clear(temp->left);
			clear(temp->right);
			delete temp;
		}
		else return;
	}

	Node* search(Node* temp, int key)
	{
		if (temp == NULL) return NULL;
		if (temp->data == key) return temp;
		if (key > temp->data)
			return search(temp->right, key);
		else
			return search(temp->left, key);
	}
public:
	~Tree()
	{
		clear(head);
	}

	bool contains(int key)
	{
		if (search(head, key) != NULL) return true;
		else return false;
	}

	void insert(int key)
	{
		if (head == NULL)	//if tree is empty, create new Node in the head
		{
			head = new Node;
			head->data = key;
		}
		else					
		{
			Node* temp = head;
			while ((temp->data < key ? temp->right : temp->left) != NULL)
				temp = (temp->data < key ? temp->right : temp->left);

			if (temp->data < key)
			{
				temp->right = new Node;
				temp->right->data = key;
				temp->right->parent = temp;
			}
			else
			{
				temp->left = new Node;
				temp->left->data = key;
				temp->left->parent = temp;
			}
		}
	}
	void remove(int key)
	{
		if (head == NULL) return;
		if (head->data == key)
		{
			Node* right_ptr = head->right;
			Node* left_ptr = head->left;
			delete head;

			if (left_ptr == NULL && right_ptr == NULL) head = NULL;
			else if (right_ptr == NULL) head = left_ptr;
			else if (left_ptr == NULL) head = right_ptr;
			else
			{
				head = right_ptr;

				Node* ptr = head;
				while (ptr->left != NULL)
					ptr = ptr->left;
				ptr->left = left_ptr;
				left_ptr->parent = ptr;
			}

		}

		Node* del = search(head, key);	//find Node to delete
		if (del == NULL) return; 

		Node* ptr_ptr = del->parent;  
		Node* right_ptr = del->right;
		Node* left_ptr = del->left;

		bool left = ptr_ptr->left == del;

		delete del;

		if (right_ptr == NULL && left_ptr == NULL)	//if deleted Node didnt have childs
		{
			if (left)
				ptr_ptr->left = NULL;
			else
				ptr_ptr->right = NULL;
		}
		else if (right_ptr != NULL)				//if deleted Node had some childs
		{
			if (left)
				ptr_ptr->left = right_ptr;
			else
				ptr_ptr->right = right_ptr;

			right_ptr->parent = ptr_ptr;

			if (left_ptr != NULL)
			{
				del = right_ptr;
				while (del->left != NULL)
					del = del->left;
				del->left = left_ptr;
				left_ptr->parent = del;
			}
		}
		else
		{
			if (left)
				ptr_ptr->left = left_ptr;
			else
				ptr_ptr->right = left_ptr;
			left_ptr->parent = ptr_ptr;
		}
	}
	

	// Return depth first traverse iterator
	Iterator* create_dft_iterator() {
		return new BinaryTreeIterator(head, ITERATOR_DFT);
	}
	// Return width first traverse iterator
	Iterator* create_bft_iterator() {
		return new BinaryTreeIterator(head, ITERATOR_BFT);
	}

	class BinaryTreeIterator : public Iterator {
	private:
		Structure* temp = NULL;
		IteratorType type;
	public:
		
		BinaryTreeIterator(Node* head, IteratorType itype = ITERATOR_DFT) {
			type = itype;
			if (type == ITERATOR_BFT) {
				temp = (Structure*) new Queue(head);
			}
			else {
				temp = (Structure*) new Stack(head);
			}
		}
		// Check if can move to next element
		bool has_next() override {
			return  !temp->empty();
		}
		// Return next element date
		int next() override {
			if (has_next()) {
				Node* node;
				if (type == ITERATOR_BFT) {
					node = (Node*)((Queue*)temp)->pop();
					if (node->left != NULL) {
						((Queue*)temp)->push(node->left);
					}
					if (node->right != NULL) {
						((Queue*)temp)->push(node->right);
					}
				}
				else {
					node = (Node*)((Stack*)temp)->pop();
					if (node->right != NULL) {
						((Stack*)temp)->push(node->right);
					}
					if (node->left != NULL) {
						((Stack*)temp)->push(node->left);
					}
				}
				return node->data;
			}
			else {
				throw std::out_of_range("No more elements");
			}
		}
	};

};