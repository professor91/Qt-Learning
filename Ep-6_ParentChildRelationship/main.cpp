/*
 * Qt memory management
 * Parent child relationship
*/

#include <QCoreApplication>
#include<QTimer>

#include"test.h"

// Setting in the constructor
Test* getTest(QObject* parent) {
    return new Test(parent);
}

// Setting in after the constructor
Test* getTest() {
    return new Test();  // No parent
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;

    timer.singleShot(3000, //ms
                     &a,
                     &QCoreApplication::quit);

    // Setting in the constructor
    Test* dog = getTest(&a);
    dog->setObjectName("Spot");

    // Setting in after the constructor
    Test* cat = getTest();
    cat->setObjectName("Princess");
    // since cat has no parent it won't be deconstructed and this has created
    // a memory leak
    cat->setParent(dog);
    // now we have set cat's parent as dog so it will be deconstructed
    // since now it is in the object tree


    int value= a.exec();
    qInfo() << "Exit code: " << value;
    return value;
}
