#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
	Node* pre;
};


class Doubly_Ring{

private:
	Node* head;
public:

	Doubly_Ring() {
		head = NULL;
    }

	~Doubly_Ring() {
		Node* temp1 = head->next;
		Node* pre = temp1;
		while (temp1->next != head)
		{
			pre = temp1;
			temp1 = temp1->next;
			delete pre;
		}
		delete head, temp1;
   }


	void insert(int val) {
		if (head == NULL)
		{
			head = new Node;
			head->value = val;
			head->next = head;
			head->pre = head;
		}
		
		
			Node* temp1 = head;
			while (temp1->next != head)
			{
				temp1 = temp1->next;
			}
			Node* temp = new Node;
			temp->next = head;
			temp->pre = temp1;
			temp->value = val;
			head->pre = temp;
			temp1->next = temp;
		
    }


	void remove(int val1) {

		if (head == NULL)
		{
			cout << "Doubly Ring List is empty\n";
		}
		else if (head->value == val1 && head->next == head)
		{
			Node* temp1 = head;
			delete temp1;
			head = NULL;
		}
		else
		{
			Node* temp1 = head;
			while (temp1->next != head)
			{
				if (temp1->value == val1 && temp1 == head)
				{
					head = head->next;
					head->pre = temp1->pre;
					temp1->pre->next = head;
					delete temp1;
					return;
				}
				if (temp1->value == val1)
				{
					temp1->pre->next = temp1->next;
					temp1 = temp1->pre;
					delete temp1->next->pre;
					temp1->next->pre = temp1;
					return;
				}
				temp1 = temp1->next;
			}
			if (temp1->value == val1 && temp1->next == head)
			{
				temp1->pre->next = temp1->next;
				temp1 = temp1->pre;
				delete temp1->next->pre;
				temp1->next->pre = temp1;
				return;
			}
		}
	
    }


	void display() {
		if (head == NULL)
		{
			cout << "Doubly Ring List is empty" << "\n";
			return;
		}
		Node* temp1 = head;
		if (temp1->next == head)
		{
			cout << temp1->value << "\t";
		}
		else
		{
			while (temp1->next != head)
			{
				cout << temp1->value << "\t";
				temp1 = temp1->next;
			}
			cout << temp1->value << "\t\n";
		}
    }

};


int main() {
	Doubly_Ring DRL;
	DRL.insert(1);
	DRL.insert(2);
	DRL.insert(3);
	DRL.insert(4);
	DRL.insert(5);
	DRL.insert(6);
	DRL.insert(7);
	cout << "You doubly ring list is:";
	DRL.display();
	cout << "\n";
	cout << "Your doubly ring list after deleting value:";
	DRL.remove(5);
	DRL.remove(2);
	DRL.display();

	return 0;
}