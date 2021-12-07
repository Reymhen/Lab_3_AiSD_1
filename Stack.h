#pragma once
#include <stdexcept>
#include "Structure.h"

class Stack : public Structure
{
//private:
//	class Elem {//node of the queue
//	public:Elem* next = NULL;
//		  Elem* prev = NULL;
//		  void* data = NULL;
//	};
//
//	Elem* head = new Elem;
//	Elem* tail = NULL;
public:
	// Construct stack with element
	Stack(void* data) {
		head->data = data;
	}

	~Stack() {
		Elem* temp = head; // Create temporary node
		while (head != NULL) {
			temp = head->next;
			delete head;
			head = temp;
		}
		tail = NULL;
	}
	// Check if stack is empty
	bool empty() {
		return head == NULL;
	}
	// Push front new element
	void push(void* data) {
		Elem* new_head = new Elem;
		new_head->data = data;
		if (head != NULL) {
			new_head->next = head;
			head->prev = new_head;
		}
		head = new_head;
	}

	// Pop front element
	void* pop() {
		if (!empty()) {
			void* data = head->data;
			if (head->next != NULL) {
				head = head->next;
				delete head->prev;
				head->prev = NULL;
			}
			else { // If stack is empty
				delete head;
				head = NULL;
			}
			return data;
		}
		else {
			throw std::out_of_range("The Stack is empty");
		}
	}
};