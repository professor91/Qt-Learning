/** QStringView
 *   youtube.com/watch?v=ZwmpKaByCQ4&list=PLUbFnGajtZlXbrbdlraCe3LMC_YH5abao&index=13
 *
 */
#include <QCoreApplication>

// copy is slow
// address of is access of
void readname (QString &name) {
    name.insert(0, "Mr. ");
    qInfo() << "Changed" << name;
}

/** QStringView name is actually a pointer
 *  which points to the QString that is passed to the function
 *  Since we have pointer, it is arguable that the name could be modified
 *  but since it is of QStringView type it won't let you modify name

 *  And since it is not making copy it is faster
 *
 */
void readonly (QStringView name) {
    qInfo() << "name" << name.data() << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstName= "Keshav";
    QString lastName= "Saini";

    // Copy and modification issues
    // readname(firstName);
    qInfo() << "Origional" << firstName;

    // Read only, no copy
    qInfo() << "name" << firstName.data() << firstName;
    readonly(firstName);

    // Basic parsing
    QString fullName= firstName + " " + lastName;

    // splitting the fullName QString, spliting it and saving it in part list of QStringView
    foreach(QStringView part, QStringView(fullName).split(QChar(' '))) {
        qInfo() << "part" << part;
        // Data types can get a bit annoying- didn't happen with me though
        if (part.startsWith(firstName,Qt::CaseInsensitive)) {
            qInfo() << "First name detected";
            readonly(firstName.mid(1,3));
        }
    }

    return a.exec();
}
