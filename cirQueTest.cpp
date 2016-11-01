#include "circularQueue.h"
void test()
{
    int temp;
    circularQueue<int> cirQueue(5);
    cirQueue.enQueue(1);
    cirQueue.enQueue(2);
    cout<<cirQueue.isEmpty()<<endl;
    cirQueue.enQueue(3);
    cirQueue.enQueue(4);
    cout<<cirQueue.isFull()<<endl;
    cout<<cirQueue.getFront()<<endl;
    cirQueue.deQueue(temp);
    cout<<temp<<endl;
}
