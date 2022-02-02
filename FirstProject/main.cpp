#include <QCoreApplication>
#include<iostream>
#include<string>

// Standard C++ way
void do_cpp () {
    std::string name;

    std:: cout << "Please enter your name: ";
    std:: getline(std::cin, name);

    std:: cout << "Hello " << name << std::endl;
}

#include<QTextStream>
// Qt way
void do_qt () {
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "Please enter your name: ";
    qout.flush();
    QString name= qin.readLine();
    qout << "Hello " << name << "\n";
    qout.flush();
}

#include<QDebug>
// Standard C++ + Qt way
void do_mixed () {
    QTextStream qin(stdin);

    qInfo() << "Please enter your name: ";
    QString name= qin.readLine();
    qInfo() << "Hello" << name;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    do_cpp();
//    do_qt();
    do_mixed();

    return a.exec();
}
