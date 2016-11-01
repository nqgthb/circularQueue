#include "queue.h"
#include "linkNode.h"
#include <iostream>
using namespace ;
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
    if(rear=NULL)
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
