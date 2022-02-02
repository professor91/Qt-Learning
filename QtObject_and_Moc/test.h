#ifndef TEST_H
#define TEST_H

#include <QObject>
#include<QtDebug>

class Test : public QObject {
    Q_OBJECT

    public:
            // parent child hierarchy
            explicit Test(QObject *parent = nullptr);

/*
 * Signals and slots are a communication channels between objects.

*/
    signals:
            void close();

    public slots:
            void dostuff();     // right-click -> "Refractor" -> Defination test.cpp

};

#endif // TEST_H
