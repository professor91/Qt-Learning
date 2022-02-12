/*
 * Qt memory management
 * QScoped Pointer  -   Automatically deletes when the pointer goes out of scope
 * QShared Pointer
*/

#include <QCoreApplication>
#include <QScopedPointer>
#include "test.h"

void testScope () {
    QScopedPointer<Test> ptr(new Test());
    ptr->message("Hello");
    // Here the pointer went out of scope and automatically got deleted
}

void finish (QSharedPointer<Test> ptr) {
    ptr->message("Finished");
}

void work (QSharedPointer<Test> ptr) {
    ptr->message("Working");
}

void step (QSharedPointer<Test> ptr) {
    ptr->message("Stepping");
    for (int i= 0; i< 3; i++) {
        work(ptr);
    }
    finish(ptr);
}

void testShared (Test* test) {
    QSharedPointer<Test> ptr(test);
    ptr->message("Starting");
    step(ptr);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testShared(new Test());

//    testScope();
    return a.exec();
}
