

#include "vector"
using namespace std;

class MinHeap
{
private:
    vector<int> _vector;
    void BubbleDown(int index);
    void BubbleUp(int index);
    void Heapify();

public:
    MinHeap(int* array, int length);
    MinHeap(const vector<int>& vector);
    MinHeap();

    void Insert(int newValue);
    int GetMin();
    void DeleteMin();
};



#include "stdafx.h"
#include "MinHeap.h"

MinHeap::MinHeap(int* array, int length) : _vector(length)
{
    for(int i = 0; i < length; ++i)
    {
        _vector[i] = array[i];
    }

    Heapify();
}

MinHeap::MinHeap(const vector<int>& vector) : _vector(vector)
{
    Heapify();
}

MinHeap::MinHeap() 
{
}

void MinHeap::Heapify()
{
    int length = _vector.size();
    for(int i=length-1; i>=0; --i)
    {
        BubbleDown(i);
    }
}

void MinHeap::BubbleDown(int index)
{
    int length = _vector.size();
    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

    if(leftChildIndex >= length)
        return; //index is a leaf

    int minIndex = index;

    if(_vector[index] > _vector[leftChildIndex])
    {
        minIndex = leftChildIndex;
    }
    
    if((rightChildIndex < length) && (_vector[minIndex] > _vector[rightChildIndex]))
    {
        minIndex = rightChildIndex;
    }

    if(minIndex != index)
    {
        //need to swap
        int temp = _vector[index];
        _vector[index] = _vector[minIndex];
        _vector[minIndex] = temp;
        BubbleDown(minIndex);
    }
}

void MinHeap::BubbleUp(int index)
{
    if(index == 0)
        return;

    int parentIndex = (index-1)/2;

    if(_vector[parentIndex] > _vector[index])
    {
        int temp = _vector[parentIndex];
        _vector[parentIndex] = _vector[index];
        _vector[index] = temp;
        BubbleUp(parentIndex);
    }
}

void MinHeap::Insert(int newValue)
{
    int length = _vector.size();
    _vector[length] = newValue;

    BubbleUp(length);
}

int MinHeap::GetMin()
{
    return _vector[0];
}
    
void MinHeap::DeleteMin()
{
    int length = _vector.size();

    if(length == 0)
    {
        return;
    }
    
    _vector[0] = _vector[length-1];
    _vector.pop_back();

    BubbleDown(0);
}



int _tmain(int argc, _TCHAR* argv[])
{
    int array[] = {10, 4, 5, 30, 3, 300};

    MinHeap minHeap(array, 6);

    for(int i=0; i<3; ++i)
    {
        cout << minHeap.GetMin() << "  ";
        minHeap.DeleteMin();
    }

    char x;
    std::cin >> x;

    return 0;
}

------------
#include <iostream>

using namespace std;

template<class T>
class doubleHeap
{
public:
    doubleHeap(
        int _size,
        int _type // 1 : max heap 2 : min heap
        );
    void extractTop(T &top);
    void deleteTop();
    bool addElement(T _new_element);
    bool empty();
    bool full();
    void printHeap(int root, int level); // for debug

private:
    void swap(int i, int j);
    int leftChild(int i);
    int rightChild(int i);
    int parent(int i);
    bool comp(int i, int j); // if the nodes should exchange

private:
    T *data;
    int max_size;
    int size;
    int type;
};

template<class T>
doubleHeap<T>::doubleHeap(int _size, int _type)
{
    max_size = 10;
    if(_size >= 10)
        max_size = _size;
    data = new T[max_size];
    size = 0;
    type = 1; // default max heap
    if(_type == 1 || type == 2)
        type = _type;
}

template<class T>
void doubleHeap<T>::extractTop(T &top)
{
    if(size == 0)
        return;

    top = data[0];
}

template<class T>
void doubleHeap<T>::deleteTop()
{
    if(size == 0)
        return;

    data[0] = data[size - 1];
    size --;

    int cur = 0; // start from the root
    int lChildIndex;
    int rChildIndex;

    // begin exchanging the node and check if it's been a heap
    while(true)
    {
        if(cur >= size) // the heap is null
            break;

        rChildIndex = rightChild(cur);
        lChildIndex = leftChild(cur);

        if(lChildIndex >= size) // right child and left child has been a null
            break;
        else if(rChildIndex >= size) // rightChild null, left not
        {
            if(comp(cur, lChildIndex))
            {
                swap(cur, lChildIndex);
                cur = lChildIndex;
            }
            else
                break; // has been a heap
        }
        else // left and right are not null
        {
            if(comp(cur, rChildIndex) || comp(cur, lChildIndex))
            {
                if(comp(lChildIndex, rChildIndex))
                {
                    swap(cur, rChildIndex);
                    cur = rChildIndex;
                }
                else
                {
                    swap(cur, lChildIndex);
                    cur = lChildIndex;
                }
            }
            else
                break;
        }
    }
}

template<class T>
bool doubleHeap<T>::addElement(T _new_element)
{
    data[size] = _new_element;
    size ++;

    int cur = size - 1;
    int parentIndex;
    while(true)
    {
        if(cur == 0)
            break;

        parentIndex = parent(cur);
        if(comp(parentIndex, cur))
        {
            swap(cur, parentIndex);
            cur = parentIndex;
        }
        else
            break;
    }
}

template<class T>
bool doubleHeap<T>::empty()
{
    return size == 0;
}

template<class T>
bool doubleHeap<T>::full()
{
    return max_size == size;
}

template<class T>
void doubleHeap<T>::swap(int i, int j)
{
    T ex;
    ex = data[i];
    data[i] = data[j];
    data[j] = ex;
}

template<class T>
int doubleHeap<T>::leftChild(int i)
{
    return 2 * (i + 1) - 1;
}

template<class T>
int doubleHeap<T>::rightChild(int i)
{
    return 2 * (i + 1);
}

template<class T>
int doubleHeap<T>::parent(int i)
{
    return (i + i) / 2 - 1;
}

template<class T>
bool doubleHeap<T>::comp(int i, int j)
{
    if(type == 1) // max heap
    {
        return data[i] < data[j];
    }
    else // min heap
    {
        return data[i] > data[j];
    }
}

template<class T>
void doubleHeap<T>::printHeap(int root, int level)
{
    int i;

    if(root >= size)
        return;

    printHeap(leftChild(root), level + 1);
    for(i = 0; i < level; i ++)
        cout << "\t";
    cout << data[root] << endl;
    printHeap(rightChild(root), level + 1);
}

int main()
{
    int a[] = {1, 10, 6, 23, 7, 8, 90, 12, 45, 76, 33, 25, 3, 17, 70, 10};
    int i, aLen = 16, e;
    doubleHeap<int> maxHeap(100, 1);

    for(i = 0; i < aLen; i ++)
    {
        maxHeap.addElement(a[i]);
    }

    maxHeap.printHeap(0, 0);

    // heap sort
    while(!maxHeap.empty())
    {
        maxHeap.extractTop(e);
        cout << e << " ";
        maxHeap.deleteTop();
    }

    return 0;
}








