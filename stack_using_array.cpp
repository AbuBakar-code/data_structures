#include <iostream>
using namespace std;


class stack
{
private:
	int* top, count, size;
public:
	stack(int a);
	~stack();
	void push(int info);
	void pop();
	void display();
};



stack::stack(int a)
{
	size = a;
	top = new int[size];
	for (int i = 0; i < size; i++)
	{
		*(top + i) = 0;
	}
}



stack::~stack()
{
	delete[] top;
}



void stack::push(int data)
{
	if (count == size)
	{
		cout << "--Overflow--" << endl;
		return;
	}
	*(top + count) = data;
	count++;
	return;

}

void stack::pop()
{
	if (count == 0)
	{
		cout << "--Underflow--" << endl;
		return;
	}
	count--;
}

void stack::display()
{
	int tempCount = 0;
	while (tempCount != count)
	{
		cout << *(top + tempCount);
		tempCount++;
	}
	cout << endl;
}

int main()
{
	stack s(3);
	s.pop();
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.display();
	s.pop();
	s.pop();
	s.push(23);
	s.display();
	return 0;
}