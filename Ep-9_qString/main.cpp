#include <QCoreApplication>
#include <iostream>

void test (QString data) {
    qInfo() << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Creating
    QString line("Namaste World");
    qInfo() << line;

    QString name;
    name= "Keshav Saini";
    qInfo() << name;

    int pos= 504;
    int max= 7439;
    QString status= QString("Processing file %1 of %2").arg(pos).arg(max);
    qInfo() << status;

    // Reading each char
    for (int i= 0; i< line.length(); i++) {
        QChar c = line.at(i);
        qInfo() << c;
    }

    // Comparing and Searching
    // default- case sensitive
    qInfo() << "Compare" << line.compare("namaste world",Qt::CaseSensitivity::CaseInsensitive);
    qInfo() << "Compare" << line.compare("namaste world",Qt::CaseSensitivity::CaseSensitive);
    qInfo() << "Starts" << line.startsWith("namaste", Qt::CaseInsensitive);
    qInfo() << "Ends" << line.endsWith("world", Qt::CaseInsensitive);
    qInfo() << "Contains" << line.contains("world");
    qInfo() << "Index" << line.indexOf("World");

    // Modifying and Parsing
    line.append("Today Mukesh said \"Let's Bunk College\"");
    qInfo() << "Escape" << line;

    line.append("\r\n<i>This</i> is HTML<br>");
    qInfo() << "HTML" << line.toHtmlEscaped();

    line.replace("Mukesh", "Rakesh");
    qInfo() << "Replaced" << line;

    qInfo() << "Upper" << line.toUpper();
    qInfo() << "Lower" << line.toLower();
    qInfo() << "Mid" << line.mid(3,5);

    QStringList list = line.split('\n');
    foreach (QString item, list) {
        // trimmed remves whitespace character (return, space, tab)
        qInfo() << "item" << item.trimmed();
    }

    // Conversion
    std::cout <<"std " << line.toStdString() << std::endl;

    // toUtf8 returns byte array
    qInfo() << "UTF8" << line.toUtf8();
    qInfo() << "Base64" << line.toUtf8().toBase64();
    qInfo() << "Base64" << line.toUtf8().toHex();

    // QString is not a QObject
    test(line);

    return a.exec();
}
