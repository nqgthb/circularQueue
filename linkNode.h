#ifndef LINKNODE_H_INCLUDED
#define LINKNODE_H_INCLUDED
template <class T>
class linkNode
{
public:
    T data;
    linkNode<T>* link;
    linkNode(T item,linkNode<T>* pstr)
    {
        data=item;
        link=pstr;
    }
};

#endif // LINKNODE_H_INCLUDED
