#include<iostream>
using namespace std;

struct node {
	int value;
	node* next;
};

class Stack {
private:
	int size;
	node* top;
public:
	Stack(int val1) {
		top = NULL;
		size = val1;
	}

	~Stack() {
		node* temp = top;
		while (temp != NULL)
		{
			top = temp;
			temp = temp->next;
			delete top;
		}
		delete temp;
	}

	void push(int val) {
		if (size == 0) {
			cout << "Stack is overflow\n";
			return;
		}
		node* temp = new node;
		temp->next = top;
		temp->value = val;
		top = temp;
		size--;
	}

	void pop() {
		if (top == NULL)
		{
			cout << "Stack is Underflow\n";
			return;
		}

		node* temp = top;
		top = top->next;
		size++;

		delete temp;
	}

	void print() {
		node* temp = top;
		while (temp != NULL)
		{
			cout << temp->value <<"\t";
			temp = temp->next;
		}
	}
};

int main() {
	Stack s(4);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	cout << "Values in stack!\n";
	s.print();
	cout << "\n";
	cout << "Values in stack after pop\n";
	s.pop();
	s.pop();
	s.print();

	return 0;

}