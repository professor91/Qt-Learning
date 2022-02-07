#include "test.h"

test::test(QObject * parent) : QObject(parent)
{
    qInfo() << this << "Contructed" << parent;
}

test::~test() {
    qInfo() << this << "Deconstructed" << parent();
}
