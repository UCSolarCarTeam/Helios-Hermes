#include <QCoreApplication>
#include <QLockFile>
#include <QDir>
#include "HeliosHermes.h"

int main(int argc, char *argv[])
{
    QString tmpDir = QDir::tempPath();
    QLockFile lockFile(tmpDir + "/heliosHermes.lock");

    /* Trying to close the Lock File, if the attempt is unsuccessful for 100 milliseconds,
     * then there is a Lock File already created by another process.
     * Therefore, we issue a warning and close the program
     */
    if (!lockFile.tryLock(100))
    {
        qDebug() << "An instance of Hermes already exists.";
        qDebug() << "If you are sure you only have one instance of Hermes running, please delete the file /tmp/epsilonHermes.lock as root.";
        qDebug() << "Quitting...";
        return 1;
    }
    else
    {
        qDebug() << "No other instance of Hermes exists.";
        qDebug() << "Launching Hermes...";
    }

    QScopedPointer<HeliosHermes> app;
    app.reset(new HeliosHermes(argc, argv));

    QCoreApplication a(argc, argv);

    return a.exec();
}
