#include <iostream>
using namespace std;


class node {
public:
	int data;
	node* left;
	node* right;
};


int Max_Height(node* value)
{
	
	if (value == NULL)
		return 0;
	else
	{
		int lD = Max_Height(value->left);
		int rD = Max_Height(value->right);


		if (lD > rD)
			return(lD + 1);
		else return(rD + 1);
	}


}
int isBalanced(node* root)
{
	int lh; 
	int rh; 
	int balance;

	
	if (root == NULL)
		return 1;

	
	lh = Max_Height(root->left);
	rh = Max_Height(root->right);

	balance = lh - rh;
	return balance;

}


node* newNode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return (temp);
}


int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left = newNode(9);
	root->left->right = newNode(7);
	root->left->left->left = newNode(8);
	cout << "Height of tree:" << Max_Height(root) << endl;
	int temp;
	cout << "Balance of tree:";
	temp = isBalanced(root);
	cout << temp << endl;


	return 0;
}