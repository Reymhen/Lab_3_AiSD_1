#pragma once
class Structure
{
protected:
	struct Elem {
		Elem* next = NULL;
		Elem* prev = NULL;
		void* data = NULL;
	};

	Elem* head = new Elem;
	Elem* tail = NULL;

public:
	virtual void push(void* data) = 0;
	virtual void* pop() = 0;

	// Check if structure is empty
	bool empty() {
		return head == NULL;
	}
};
