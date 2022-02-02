#include <QCoreApplication>
#include<test.h>

#include<QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;

    // connect the signal and the slot
    /*
     * QObject go and connect to these two QObjects (test and a)
     * connection test to a (application)
     * when close is emitted we want to quit
    */
    QObject::connect(&test,
                     &Test::close,
                     &a,
                     &QCoreApplication::quit,
                     Qt::QueuedConnection);

    test.dostuff();

    int value = a.exec();
    qInfo() << "Exit value: " << value;

    return value;
}
