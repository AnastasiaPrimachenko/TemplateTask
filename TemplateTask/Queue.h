#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Queue
{
private:
	T data;
	int max = 0;
	Queue* next;
	bool first = false; //first element in the queue
public:
	Queue() {
		this->data;
		this->next = nullptr;
		this->max = 0;
	}
	Queue(T d) {
		this->data = d;
		this->next = nullptr;
		this->max = 0;
	}
	Queue(T d, int max) {
		this->data = d;
		this->next = nullptr;
		this->max = max;
		this->first = true;
	}
	void push(T d) { //adding new element to the queue
 		if (this->first == true) {
			if (this->count(0) < this->max) { //checking if maximum number of elements is reached
				if (this->next == nullptr) this->next = new Queue(d); //if this is the last element, a new element is created
				else this->next->push(d);
			}
			else {
				cout << "Maximum number of elements is reached" << endl;
				return;
			}
		}
		else {
			if (this->next == nullptr) this->next = new Queue(d);
			else this->next->push(d);
		}
	}
	void unite(Queue &s) { //uniting the queues
		if (this->next != nullptr) { //searching for the last element of the first queue
			this->max += s.max;
			this->next->unite(s);
		}
		if (this->next == nullptr) { // when the last element is found
			this->next = &s;         // the first element of the second queue is attached
			s.first = false;         //the first element of the second queue is no longer the first
			return;
		}
	}
	void pop() { //deleting the first element
		if (this->next != nullptr) { 
			if (this->next->next != nullptr) { //searching for the penultimate element
				this->data = this->next->data;
				this->next->pop();
			}
			else {							   //when it is found, it's data becomes the last element's data
				this->data = this->next->data; //and it's pointer becomes null
				this->next = nullptr;				
				return;
			}
		}

	}
	int count(int i) { //counts the number of elements in the queue
		++i;
		if (this->next != nullptr) this->next->count(i); 
		else { return i; }
	}
	void print()
	{
		if (this->next != nullptr) {
			cout << this->data << " ";
			this->next->print();
		}
		else {
			cout << this->data << endl; 
			return;
		}
	}
};

