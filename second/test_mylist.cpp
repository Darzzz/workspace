#include "test_mylist.h"
#include "mylist.h"

Test_MyList::Test_MyList(QObject *parent) : QObject(parent)
{
}

void Test_MyList::addLast()
{
       MyList l;
       l.addLast(1);
       QCOMPARE(l.getItem(0), 1);
       l.addLast(2);
       QCOMPARE(l.getItem(1), 2);
}

void Test_MyList::count(){
    MyList t;
    t.addLast(1);
    QCOMPARE(t.count(), 1);
    t.addLast(2);
    QCOMPARE(t.count(), 2);
}

void Test_MyList::removLast(){
    MyList t;
    t.addLast(1);
    t.addLast(2);
    t.removLast();
    QCOMPARE(t.count(), 2);
}
void Test_MyList:: getItem(){
    MyList t;
    t.addLast(1);
    QCOMPARE(t.getItem(0), 1);
    }
