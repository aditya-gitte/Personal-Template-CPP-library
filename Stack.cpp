#include <iostream>
#include "SLL.cpp"
using namespace std;

template <class T>
class Stack
{
    SLL<T> list;

public:
    bool isEmpty();
    void push(T data);
    T pop();
    void printStack();
    SLL<T> exposeLinkedList();
};

template <class T>
bool Stack<T>::isEmpty()
{
    if (list.len() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Stack<T>::push(T data)
{
    list.pushBack(data);
}

template <class T>
T Stack<T>::pop()
{

    if (isEmpty() == false)
    {
        int len = list.len();
        T data = list.accessNodeByIndex(len - 1);
        list.deleteNodeByIndex(len - 1);
        return data;
    }
    else
    {
        throw("empty stack");
    }
}

template <class T>
void Stack<T>::printStack()
{
    list.print();
}

template<class T>
SLL<T> Stack<T>::exposeLinkedList()
{
    return list;
}

// int main()
// {

//     SLL<int> l;
//     Stack<int> s;
//     s.push(1);
//     s.push(2);
//     s.printStack();
//     l=s.exposeLinkedList();
    
//     return 0;
// }