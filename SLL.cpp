#include<iostream>
#include<vector>
using namespace std;
template<class T>
class SLL
{
    private:
    class Node
    {
        public:
        T data;
        Node* nextPointer;
        Node()
        {
            data=0;
            nextPointer=NULL;
        }
        Node(T a)
        {
            data=a;
            nextPointer=NULL;
        }
        
    };


    Node* head;

    public:
    SLL();                              // Constructor initializes head pointer to 0
    int length();                       // Returns the length of the SLL
    void pushBack(T data);              // Pushes a to the SLL
    void appendAfter(T key, T data);    // Appends data after a particular key
    void appendBefore(T key, T data);   // Appends data before a particular key
    void appendAtHead(T data);          // Appends at head
    void deleteNodeByData(T data);      // Deletes the SllNode that has the "data" value stored
    void deleteNodeByIndex(int index);  // Deletes the SllNode using the index
    T accessNodeByIndex(int index);     // For accessing SLL like array
    void concat(T arr[]);               // Appends array to SLL and can also be used to convert array to SLL
    void concat(vector<T> vec);         // Appends vector to SLL and can also be used to convert vector to SLL
    void concat(SLL<T> sll);            // Appends another SLL to the present SLL
    T *toArray();                       // Converts SLL to array
    vector<T> toVector();               // Converts SLL to Vector
    void print();                       // Prints SLL
    void printReverse();                // Prints the SLL in reverse order without actually changing the order of SLL
    void reverse();                     // Reverses the SLL
    void sort();                        // Sorts the SLL using selection sort
    int search(T data);                 // Searches the data in SLL and returns the index(returns -1 if not found and -2 if empty sll is found)


};















template<class T>
SLL<T>::SLL()
{
    head=NULL;
}


template<class T>
int SLL<T>::length()
{
    int counter = 0;
    if (head != NULL)
    {
        Node *p = head;
        while (true)
        {
            counter++;
            if (p->nextPointer == NULL)
            {
                break;
            }
            p = p->nextPointer;
        }
    }
    return counter;
}






template<class T>
void SLL<T>::pushBack(T data)
{
    Node* temp=new Node(data);
    if (head == NULL)
    {
        head = temp;
        temp->nextPointer = NULL;
    }
    else
    {
        Node *p=head;
        while (p->nextPointer != NULL)
        {
            p = p->nextPointer;
        }
        p->nextPointer=temp;
    }
}


template <class T>
void SLL<T>::appendAfter(T key, T data)
{
    if (head != NULL)
    {
        bool flag = false;
        Node *p = head;
        while (true)
        {
            if (p->data == key)
            {
                flag = true;
                break;
            }
            else if (p->nextPointer != NULL)
            {
                p = p->nextPointer;
            }
            else
            {
                break;
            }
        }
        if (flag == true)
        {
            Node *temp = new Node(data);
            temp->nextPointer = p->nextPointer;
            p->nextPointer = temp;
        }
        else
        {
            throw(string("No matching data found"));
        }
    }
    else
    {
        throw(string("Empty linked list"));
    }
}

template <class T>
void SLL<T>::print()
{
    if (head == NULL)
    {
        throw(string("Linked list is empty"));
    }
    else
    {
        Node *p = head;
        while (p->nextPointer != NULL)
        {
            cout << p->data << " --> ";
            p = p->nextPointer;
        }
        cout << p->data << endl;
    }
}

template<class T>
void SLL<T>::appendBefore(T key, T data)
{
    Node *temp = new Node(data);
    int index = search(key);
    if (index == -2)
    {
        throw(string("Empty SLL"));
    }
    else if (index == -1)
    {
        throw(string("key not found"));
    }
    else if (index == 0)
    {
        temp->nextPointer = head;
        head = temp;
    }
    else
    {
        Node *p = head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->nextPointer;
        }
        temp->nextPointer = p->nextPointer;
        p->nextPointer = temp;
    }
}

template <class T>
int SLL<T>::search(T data)
{
    int ret;
    bool flag = false;
    int counter = 0;
    if (head == NULL)
    {
        ret = -2;
    }
    else
    {
        Node *p = head;
        while (true)
        {
            if (p->data == data)
            {
                flag = true;
                ret = counter;
                break;
            }
            if (p->nextPointer != NULL)
            {
                p = p->nextPointer;
                counter++;
            }
            else
            {
                break;
            }
        }
    }
    if (flag == false)
    {
        ret = -1;
    }
    return ret;
}


template <class T>
void SLL<T>::appendAtHead(T data)
{
    Node *temp = new Node(data);
    temp->nextPointer = head;
    head = temp;
}

template <class T>
void SLL<T>::deleteNodeByData(T data)
{
    Node *p = head;
    if (p == NULL)
    {
        throw(string("empty linked list"));
    }
    else if (p->nextPointer == NULL)
    {
        if (p->data == data)
        {
            head = NULL;
        }
    }
    else
    {
        Node *p1 = p->nextPointer;
        if (p->data == data)
        {
            head = p1;
        }
        else if (p1->data == data)
        {
            p->nextPointer = p1->nextPointer;
        }
        else
        {
            while (true)
            {
                if (p1->data == data)
                {
                    p->nextPointer = p1->nextPointer;
                    break;
                }
                if (p1->nextPointer == NULL)
                {
                    break;
                }
                p = p->nextPointer;
                p1 = p1->nextPointer;
            }
        }
    }
}


template <class T>
void SLL<T>::deleteNodeByIndex(int index)
{
    if (index > (length() - 1))
    {
        throw(string("index out of bounds"));
    }
    else if (index == 0)
    {
        Node *p = head;
        head = p->nextPointer;
    }
    else
    {
        Node *p = head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->nextPointer;
        }
        Node *delp = p->nextPointer;
        p->nextPointer = delp->nextPointer;
    }
}

template <class T>
T SLL<T>::accessNodeByIndex(int index)
{
    T ret;
    if (index > (length() - 1))
    {
        throw(string("index out of bounds"));
    }
    else if (index == 0)
    {
        Node *p = head;
        ret = p->data;
    }
    else
    {
        Node *p = head;
        for (int i = 0; i <= index - 1; i++)
        {
            p = p->nextPointer;
        }
        ret = p->data;
    }
    return ret;
}

template <class T>
void SLL<T>::reverse()
{
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->nextPointer;
        current->nextPointer = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


template <class T>
void SLL<T>::sort()
{
    Node *temp = head;
    while (temp)
    {
        Node *min = temp;
        Node *r = temp->nextPointer;

        while (r)
        {
            if (min->data > r->data)
                min = r;

            r = r->nextPointer;
        }

        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->nextPointer;
    }
}   

















// int main()
// {
//     SLL<int> list;
//     list.pushBack(5);
//     list.pushBack(6);
//     list.pushBack(7);
//     list.print();
//     int arr[]={2,3,4};
//     list.concat(arr);
//     list.appendAfter(6,10);
//     list.print();
//     list.appendBefore(7,11);
//     list.appendAtHead(100);
//     list.deleteNodeByData(10);
//     list.reverse();
//     list.print();
//     list.sort();
//     list.deleteNodeByIndex(3);
//     list.print();


//     return 0;
// }
        