#include<iostream>
using namespace std;

struct node {
	int data;
	node * next;
};

class list {
	node* head, * cur;
	int pos, size;
public:
	list() {
		head = NULL;
		cur = NULL;
		pos = 1;
		size = 1;
	}

	void creat(int v) {
		if (head == NULL) {
			node* temp = new node;
			temp->data = v;
			temp->next = NULL;
			head = temp;
			cur = head;
			return;
		}
		node* temp = new node;
		temp->data = v;
		temp->next = NULL;
		cur->next = temp;
		cur = cur->next;
		pos++;
		size++;

	}

	void empty() {
		if (head == NULL) {
			cout << "The list is empty\n";
		}
		else
			cout << "List is non empty\n";
	}
	void display() {
		cur == head;
		while (cur != NULL) {
			cout << cur->data<<"\t";
			cur = cur->next;
		}
	}

};

int main() {
	list l;
	l.creat(5);
	l.creat(3);
	l.creat(4);
	
	l.display();
	l.empty();
	return 0;
}