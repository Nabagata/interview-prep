#include <iostream>
#include <climits>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class Minheap
{
    int *harr;
    int capacity, heap_size;

public:
    // constructor
    Minheap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    //To heapify a subtree with root ar given index
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[i])
            smallest = r;

        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            heapify(smallest);
        }
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int extractMin()
    {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        heapify(0);

        return root;
    }

    void decreaseKey(int i, int newval)
    {
        harr[i] = newval;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    int getMin()
    {
        return harr[0];
    }

    void printarr()
    {
        cout << "array\n";
        for (int j = 0; j < heap_size; ++j)
        {
            cout << harr[j] << " ";
        }
        cout << "\n";
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void insertKey(int k)
    {
        if (heap_size == capacity)
        {
            cout << "Heap overflow\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }
};

int main()
{
    Minheap bmh(11);
    bmh.insertKey(3);
    bmh.insertKey(2);
    bmh.printarr();
    bmh.deleteKey(1);
    bmh.printarr();
    bmh.insertKey(15);
    bmh.insertKey(5);
    bmh.insertKey(4);
    bmh.insertKey(45);
    bmh.printarr();
    cout << bmh.extractMin() << " ";
    bmh.printarr();
    cout << bmh.getMin() << " ";
    bmh.printarr();
    bmh.decreaseKey(2, 1);
    bmh.printarr();
    cout << bmh.getMin();
    bmh.printarr();

    return 0;
}