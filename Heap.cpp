#include<iostream>

using namespace std;

class Heap
{
private:
    int* h;
    int maxSize;
    int n;
public:
    Heap(int* arr, int ms, int sz)
    {
        h = arr; 
        maxSize = ms; 
        n = sz;         
    }

    Heap(int ms)
    {
        maxSize = ms;
        h = new int[maxSize + 1];
        n = 0;
    }
    void insert(int x);
    void print();
    int deleteMin();
    int deleteMinH();
    void heapify(int i);
    void buildHeap();
};

void Heap::insert(int x)
{
    if (n == maxSize)
    {
        cout << "Heap is full" << endl;
        return;
    }

    n++;
    int i;
    for (i = n; i > 1; i = i / 2)
    {
        if (x >= h[i / 2])
            break;

        h[i] = h[i / 2];
             
    }
    h[i] = x;
}

void Heap::print()
{
    for (int i = 1; i <= n; i++)
        cout << h[i] << "\t";
    cout << endl;
}

int Heap::deleteMin()
{
    if (n == 0)
    {
        cout << "Heap Empty..." << endl;
        return 0;
    }

    int x = h[1];
    int last = h[n];
    n--;
    int i, j;
    for (i = 1, j = 2; j <= n; i = j, j *= 2)
    {
        if (j < n)
            if (h[j] > h[j + 1])
                j++;    

        if (last <= h[j])
            break;
        h[i] = h[j]; 
    }
    h[i] = last;
    return x;
}

int Heap::deleteMinH()
{
    int root = h[1];
    h[1] = h[n]; 
    n--;
    heapify(1);
    return root;
}

void Heap::heapify(int i)
{
    int smallest = i;  
    int l = 2 * i; 
    int r = 2 * i + 1; 

    if (l <= n && h[l] < h[smallest])
        smallest = l;

    
    if (r <= n && h[r] < h[smallest])
        smallest = r;

    
    if (smallest != i)
    {
        swap(h[i], h[smallest]);

        
        heapify(smallest);
    }
}


void Heap::buildHeap()
{
    
    int startIdx = (n / 2);

 
    for (int i = startIdx; i > 0; i--)
        heapify(i);
}

int main()
{
    Heap h(15);
    h.insert(13);
    h.insert(16);
    h.insert(14);
    h.insert(21);
    h.insert(19);
    h.insert(32);
    h.insert(68);
    h.insert(65);
    h.insert(26);
    h.insert(31);
    h.insert(22);
    h.print();
    h.deleteMinH();
    h.print();

    Heap h1(15);
    h1.insert(65);
    h1.insert(26);
    h1.insert(32);
    h1.insert(24);
    h1.insert(31);
    h1.insert(19);
    h1.insert(68);
    h1.insert(21);
    h1.insert(16);
    h1.insert(13);
    h1.insert(22);
    
    h1.print();
    h1.deleteMinH();
    h1.print();

    cout << "------------------------------" << endl;
    int arr[] = { 0, 65, 31, 32, 26, 21, 19, 68, 13, 24, 15, 14, 16, 5, 70, 12 };
    int arr_sz = sizeof(arr) / sizeof(int);
    cout << "Size of array: " << arr_sz << endl;
    Heap h2(arr, arr_sz, arr_sz - 1);
    cout << "Data Before heap: " << endl;
    h2.print();
    h2.buildHeap();
    cout << "Data After Heap: " << endl;
    h2.print();
    return 0;
}