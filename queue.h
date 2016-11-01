#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "linkNode.h"
#include <iostream>
using namespace std;
template <class T>
class linkqueue
{
private:
    int sizeNow;
    linkNode<T>* frontPtr;
    linkNode<T>* rear;
public:
    linkqueue(int s=0);
    ~linkqueue();
    linkqueue<T>& enQueue(T item);
    linkqueue<T>& deQueue(T & item);
    T getFront();
    bool isEmpty();
    linkNode<T>* getFrontPtr();
    linkNode<T>* getRear();
};
template <class T>
linkqueue<T>::linkqueue(int s)
{
    sizeNow=0;
    frontPtr=NULL;
    rear=NULL;
}
 template <class T>
linkqueue<T>::~linkqueue()
{
    while(frontPtr!=NULL)
    {
        rear=frontPtr;
        frontPtr=frontPtr->link;
        delete rear;
    }
    rear=NULL;
    sizeNow=0;
}
template <class T>
linkqueue<T>& linkqueue<T>::enQueue(T item)
{
    if(rear==NULL)
    {
        frontPtr=rear=new linkNode<T>(item,NULL);
    }
    else{
        rear->link=new linkNode<T>(item,NULL);
        rear=rear->link;
    }
    sizeNow++;
    return *this;
}
template <class T>
linkqueue<T>& linkqueue<T>::deQueue(T& item)
{
    linkNode<T>* temp;
    if(sizeNow==0)
    {
        cout<<"the queue is empty!";
        return *this;
    }
    else{
        item=frontPtr->data;
        temp=frontPtr;
        frontPtr=frontPtr->link;
        delete temp;
        sizeNow--;
        return *this;
    }
}
template <class T>
T linkqueue<T>::getFront()
{
    if(sizeNow==0)
    {
        cout<<"the queue is empty!";
        return 0;
    }
    else{
        return frontPtr->data;
    }
}
template <class T>
linkNode<T>* linkqueue<T>::getFrontPtr()
{
    return frontPtr;
}
template <class T>
linkNode<T>* linkqueue<T>::getRear()
{
    return rear;
}
template <class T>
bool linkqueue<T>::isEmpty()
{
    return sizeNow==0;
}
#endif // QUEUE_H_INCLUDED
