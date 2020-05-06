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
	bool first = false;
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
	void push(T d) {
		if (this->first == true) {
			if (this->count(0) < this->max) {
				if (this->next == nullptr) this->next = new Queue(d);
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
	void unite(Queue &s) {
		if (this->next != nullptr) {
			this->max += s.max;
			this->next->unite(s);
		}
		if (this->next == nullptr) {
			this->next = &s;
			s.first = false;
			return;
		}
	}
	void pop() {
		if (this->next != nullptr) {
			if (this->next->next != nullptr) {
				this->data = this->next->data;
				this->next->pop();
			}
			else {
				this->data = this->next->data;
				this->next = nullptr;				
				return;
			}
		}

	}
	int count(int i) {
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

