#ifndef CIRCULARQUEUE_H_INCLUDED
#define CIRCULARQUEUE_H_INCLUDED
#include "linkNode.h"
#include <iostream>
using namespace std;
template <class T>
class circularQueue
{
private:
    int qFront;
    int qRear;
    bool tag;
    int qSize;
    int num;
    T* cirQueue;
public:
    circularQueue(int s=10);
    ~circularQueue();
    bool isEmpty();
    bool isFull();
    circularQueue<T>& enQueue(T item);
    circularQueue<T>& deQueue(T& item);
    T getFront();
};
template <class T>
circularQueue<T>::circularQueue(int s)
{
    num=0;
    tag=0;
    qSize=s;
    cirQueue=new T[qSize];
    qFront=0;
    qRear=1;
}
template <class T>
circularQueue<T>::~circularQueue()
{
    delete cirQueue;
    num=0;
    tag=0;
    qFront=0;
    qRear=1;
}
template <class T>
bool circularQueue<T>::isEmpty()
{
    if(num==0)
        tag=0;
    else
        tag=1;
    return tag;
}
template <class T>
bool circularQueue<T>::isFull()
{
    return qFront==qRear;
}
template <class T>
circularQueue<T>& circularQueue<T>::enQueue(T item)
{
    if(isFull())
    {
        cout<<"the queue is full!";
        return *this;
    }
    cirQueue[qRear-1]=item;
    qRear=(qRear+1)%qSize;
    num++;
    return *this;
}
template <class T>
circularQueue<T>& circularQueue<T>::deQueue(T& item)
{
    if(isEmpty())
    {
        cout<<"the queue is empty!";
        return *this;
    }
    item=cirQueue[qRear-2];
    qRear=(qRear-1)%qSize;
    num--;
    return *this;
}
template <class T>
T circularQueue<T>::getFront()
{
    if(isEmpty())
    {
        cout<<"the queue is empty!";
        return 0;
    }
    return cirQueue[qFront];
}
#endif // CIRCULARQUEUE_H_INCLUDED
