#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class Queue {
private:
	node* rare;
	node* front;
	int size;
public:
	Queue() {
		front = NULL;
		rare = NULL;
		size = 0;
	}

	void enqueue(int val) {
		if (front == NULL) {
			node* temp = new node;
			temp->data = val;
			temp->next = NULL;
			front = temp;
			rare = temp;
			size++;
			return;
		}
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		rare->next = temp;
		rare = rare->next;
		size++;
	}

	void dequeue() {
		node* temp = front;
		if (front == NULL) {
			cout << "Queue underflow\n";
		}
		if (front == rare) {
			delete temp;
			front = NULL;
			rare = NULL;
			size--;
		}
		front = front->next;
		delete temp;
		size--;
	}

	void display() {
		node* temp = front;
		if (front == NULL) {
			cout << "queue is empty\n";
			return;
		}
		while (temp!=NULL)
		{
			cout << temp->data << "\n";
			temp = temp->next;
		}
		cout << "Value of rare\t" << rare->data << "\n";
		cout << "Value of front\t" << front->data << "\n";
		cout << "Size of Queue\t" << size << "\n";
	}

};

int main() {
	Queue q;
	cout << "Values in queue are\n";
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
	return 0;
}