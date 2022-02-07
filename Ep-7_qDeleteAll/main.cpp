#include <QCoreApplication>
#include"test.h"

// Get a list of pointers
typedef QList<test*> testList;

testList getlist() {
    testList list;
    for (int i=0; i<5; i++) {
        list.append(new test);
        list.last()->setObjectName("Test " + QString::number(i));
    }
    return list;
}

// Display the list of pointers
void display(testList list) {
    foreach(test* item, list) {
        qInfo() << item;
    }
}

// qDeleteall in action
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testList list = getlist();
    display(list);

    qInfo() << "Deleting...";
    qDeleteAll(list);       // delete entire list

    //using this you can delete any chunck of the list
    // qDeleteAll(list.begin(), list.end());

    /* we have a bad pointer here
     * the items of the pointer list are deleted but
     * the list is not cleared yet
    */

    list.clear();       // lets clear the list
    display(list);

    return a.exec();
}
