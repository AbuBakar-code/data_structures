#include <iostream>
using namespace std;

struct Queue {
    int front, back, space;
    int* queue;
    Queue(int s)
    {
        front = 0;
        back = 0;
        space = s;
        queue = new int;
    }

    ~Queue() { delete[] queue; }

    
    void Enqueue(int val)
    {
     
        if (space == back) {
            cout<<("\nQueue is full\n");
            return;
        }

        
        else {
            queue[back] = val;
            back++;
        }
        return;
    }

    void Dequeue()
    {
        
        if (front == back) {
            cout<<("\nQueue is empty\n");
            return;
        }

        
        else {
            for (int i = 0; i < back - 1; i++) {
                queue[i] = queue[i + 1];
            }

            
            back--;
        }
        return;
    }

   
    void queuePrint()
    {
        int i;
        if (front == back) {
            cout<<("\nQueue is Empty\n");
            return;
        }

        for (i = front; i < back; i++) {
            cout<< queue[i];
        }
        return;
    }
};


int main(void)
{
    
    Queue Q(5);

    Q.queuePrint();

    Q.Enqueue(10);
    Q.Enqueue(30);
    Q.Enqueue(50);
    Q.Enqueue(60);
    Q.Enqueue(80);

    Q.queuePrint();

    Q.Enqueue(90);

    Q.queuePrint();

    Q.Dequeue();
    Q.Dequeue();

    cout<<("\n\nafter two node deletion\n\n");

    Q.queuePrint();

   

    return 0;
}