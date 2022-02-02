#include <QCoreApplication>
#include<QtDebug>

#include<cat.h>

void test (cat &ct) {
    qInfo() << "Addrs: " << &ct;
}

void test2 (cat *ct) {
    qInfo() << "Ptr: " << ct;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cat kitty;
    kitty.setObjectName("kitty");

    cat kitty2;
    kitty2.setObjectName("kitty2");

    /* cannot use copy constructor in Qt
     * because if we do then there would be disaster with signals and
     * Qt uses memory addresses to track the uniqueness of the objects
     */
    // test(kitty);

    test(kitty);
    test2(&kitty);

    test(kitty2);
    test2(&kitty2);

    return a.exec();
}
