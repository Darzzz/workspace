#include "mylist.h"

MyList::MyList(QObject *parent) : QObject(parent)
{
    first = nullptr;
}

MyList::~MyList()
{
    while(first){
        ListNode *t = first;
        first = first -> next;
        delete t;
    }
}
void MyList:: removLast(){
    ListNode* t = first;
    if(first)
        t= nullptr;
    else{
        while(t->next->next!=nullptr)
            t=t->next;
        ListNode* t1 = t->next;
        t->next = nullptr;
        delete t1;
    }
}

void MyList::addLast(MyListData newData)
{
    ListNode *t = new ListNode;
    t->data = newData;
    t->next = nullptr;
    if(first){
        ListNode *last = first;
        while(last->next)
            last = last->next;
        last->next = t;
    } else {
        first = t;
    }
}

int MyList::count (){
    int k=0;
    ListNode* t= first;
    while(t!=nullptr){
        k++;
        t=t->next;}
    return k;
}

MyListData MyList::getItem(int index)
{
    if(index<0)
        throw "index is out of bounds";
    if (!first)
        throw "empty list";

    ListNode *node = first;
    while(node && index){
        node = node->next;
        index--;
    }
    if (index == 0)
        return node->data;
    else
        throw "index is out of bounds";
}
