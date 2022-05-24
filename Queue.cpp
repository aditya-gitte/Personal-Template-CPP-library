#include <iostream>
#include "SLL.cpp"
using namespace std;

template <class T>
class Queue
{
    SLL<T> list;
    
    public:
    void enqueue(T data);
    T dequeue();
    T peek();
    bool isEmpty();
    void printQueue();
};

template<class T>
bool Queue<T>::isEmpty()
{
    int len=list.length();
    if(len==0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

template<class T>
void Queue<T>::enqueue(T data)
{
    list.appendAtHead(data);
}

template<class T>
T Queue<T>::dequeue()
{
    if(isEmpty()==false)
    {
        int len=list.length();
        T data=list.accessNodeByIndex(len-1);
        list.deleteNodeByIndex(len-1);
        return data;
    }
    else
    {
        throw(string("empty queue"));
    }
}

template<class T>
T Queue<T>::peek()
{
    if(isEmpty()==false)
    {
        int len=list.length();
        T data=list.accessNodeByIndex(len-1);
        return data;
    }
    else
    {
        throw(string("empty queue"));
    }

}

template<class T>
void Queue<T>::printQueue()
{
    list.print();
}

int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(9);
    q.enqueue(7);
    q.printQueue();
    int a=q.peek();
    cout<<"peeked value= "<<a<<endl;
    q.printQueue();
    int b=q.dequeue();
    cout<<"poped value "<<b<<endl;
    q.printQueue();
}