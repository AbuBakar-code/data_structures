#include<iostream>
using namespace std;


struct node {
	int value;
	node* next;
	node* pre;
};

class LinkedList {
private:
	node* head, * curr; //head will always point to first element, temp and temp2 will be used for moving and adding new nodes in the list
public:
	LinkedList() {


		head = NULL;
		curr = NULL;

	}

	//you can take value using user input within function or by passing value to the add function using a parameter
	//assuming you will use user input within function
	void add(int val) {


		//code for checking whether the first element exists or not
		//if 1st element doesn't exists, write code to create 1st element
		//first element will always be pointed by head pointer
		if (head == NULL) {

			//your code goes here
			node* temp = new node;
			temp->value = val;
			temp->pre = NULL;
			temp->next = NULL;
			head = temp;
			curr = head;
			return;




		}

		//if first element already exsist, move the temp pointer to the last element


		//create a new node
		//assign it a value
		//make it's next pointer null
		//the newly created node will be poined by the next pointer of last node
		//your code goes here

		node* temp = new node;
		temp->value = val;
		temp->next = NULL;
		curr->next = temp;
		temp->pre = curr;
		curr = curr->next;




	}

	//function to add a new value after an existing value
	//you can take value using user input within function or by passing value to the add function using a parameter
	//assuming you will use user input within function
	void addAfterSomeValue(int val, int after_val) { //val parameter is for the value after which we want to add another value

		//temp=head;
		curr = head;

		if (head == NULL) {
			cout << "list is empty" << endl;
			return;
		}


		while (curr != NULL) {
			if (curr->value == val) {
				if (curr->next != NULL) {

					node* temp = new node;
					temp->value = after_val;
					temp->next = curr->next;
					temp->pre = curr;
					curr->next->pre = temp;
					curr->next = temp;
					return;
				}
			}
			if (curr->value == val) {
				if (curr->next == NULL) {

					node* temp = new node;
					temp->value = after_val;
					temp->next = NULL;
					curr->next = temp;
					temp->pre = curr;
					return;
				}
			}
			curr = curr->next;
		}

		//write code to find the value after which you want to add the new value
		//create a new node,assign it value
		//assign the address of the next pointer of the node which is pointed by temp to the next pointer of newly created node 
		//assign the address of newly created node to the next pointer of node pointed by temp
		//your code goes here




	}

	void del_1st(int val) {//val contains the value to be deleted, if the value exists multiple times in the list, then delete it's first occurence
		curr = head;

		//check whether the list is empty or not, if list is empty, prompt a message and return
		//your code goes here
		if (head == NULL) {
			cout << "list is empty" << endl;
			return;

		}

		if (head->value == val && head->next == NULL) {
			delete head;
			head = NULL;
			curr = NULL;
			return;


		}
		if (head->value == val && head->next != NULL) {
			node* temp;
			temp = head;
			head = head->next;
			head->pre = NULL;
			curr = head;
			delete temp;
			return;
		}

		while (curr != NULL) {
			if (curr->next != NULL) {

				if (curr->next->value == val) {
					node* temp;
					temp = curr->next;
					temp->pre->next = temp->next;
					temp->next->pre = curr;
					delete temp;
					return;

				}
			}
			curr = curr->next;
		}

		/*	if(curr->value == val){
				node* temp;
				temp=curr->pre;
				temp->next=NULL;
				//curr->pre=NULL;
				delete curr;
				return;
			}
			*/
		cout << endl << "the value is not in the list" << endl;


		//first check if the first node contains the desired value or not, if yes then delete it and point the head to next element.
		//return from the function	
		//your code goes here     




		//write code to find the node having the desired value,if first element doesn't containws the desired value
		//hint: you need to check value of each next node while staying on the previous node
		//once node with desired value is found, first make arrangement for next pointer
		//delete the node with the value
		//return
		//your code goes here






		//if no node contauins the desired value, prompt the user with appropriate message and return
		//your code goes here




	}//function end


	void reverse()
	{
		node** head_ref;
		node* temp = NULL;
		node* current = *head_ref;

		/* swap next and prev for all nodes of
		doubly linked list */
		while (current != NULL)
		{
			temp = current->pre;
			current->pre = current->next;
			current->next = temp;
			current = current->pre;
		}

		/* Before changing the head, check for the cases like empty
			list and list with only one node */
		if (temp != NULL)
			*head_ref = temp->pre;
	}


	void print() { //function to print all the values of the list
		curr = head;
		cout << "data in doubley link list     ";
		while (curr != NULL) {

			cout << curr->value << " ";
			curr = curr->next;
		}

		//your code goes here
		cout << endl;
	}
};




int main() {

	LinkedList obj;

	obj.add(1);//1

	obj.add(2);//2
	obj.add(3);//3
	obj.add(4);//4
	obj.add(7);//3

	obj.print();
	cout << endl;
	/*
	cout<<"After  add value"<<endl;

	obj.addAfterSomeValue(3,5);//3
	cout<<"\n";
	obj.print();
	obj.reverse();
	obj.print();*/
	/*

	cout<<"\nDelete"<<endl;

	obj.del_1st(1);

	obj.print();
	cout<<"\nDelete"<<endl;

	obj.del_1st(3);

	obj.print();
	cout<<"\nDelete"<<endl;

	obj.del_1st(5);

	obj.print();
	cout<<"\nDelete"<<endl;

	obj.del_1st(9);

	obj.print();
	*/



	system("pause");
	return 0;

}