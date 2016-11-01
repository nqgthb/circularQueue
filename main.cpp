#include "queue.h"
#include "linkNode.h"
#include <cstdio>
void test();
int main()
{
    int i,n;
    int temp;
    int flag=1;
    linkqueue<int> linkGroup[10];
    linkqueue<int> longQueue;
    while(flag)
    {
        cin>>n;
        if(n<0||n>9)
        {
            cout<<"out of range!";
        }
        else{
            linkGroup[n].enQueue(n);
        }
        cin>>flag;
    }
    for(i=0;i<9;i++)
    {
        while(!linkGroup[i].isEmpty())
        {
            linkGroup[i].deQueue(temp);
            longQueue.enQueue(temp);
        }
    }
    while(!longQueue.isEmpty())
    {
        longQueue.deQueue(temp);
        cout<<temp<<endl;
    }
    test();
    return 0;
}
