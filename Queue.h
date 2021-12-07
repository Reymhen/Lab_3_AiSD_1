#pragma once
#include <stdexcept>
#include "Structure.h"

class Queue : public Structure
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
	// Construct queue with element
	Queue(void* data) {
		head->data = data;
		tail = head;
	}

	~Queue() {
		Elem* temp = head; // Create temporary node
		while (head != NULL) {
			temp = head->next;
			delete head;
			head = temp;
		}
		tail = NULL;		
	}
	// Check if queue is empty
	bool empty() {
		return head == NULL;
	}
	// Push back  element
	void push(void* data) {
		Elem* new_tail = new Elem;
		new_tail->data = data;
		if (head != NULL) {
			new_tail->prev = tail;
			tail->next = new_tail;
		}
		else { // If queue was empty
			head = new_tail;
		}
		tail = new_tail;
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
			else { // If queue is empty
				delete head, tail;
				head = tail = NULL;
			}
			return data;
		}
		else {
			throw std::out_of_range("The Queue is empty");
		}
	}
};
