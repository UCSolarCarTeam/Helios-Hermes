#include "HeliosHermes.h"

#include <QDebug>

HeliosHermes::HeliosHermes(int& argc, char** argv) :
    QCoreApplication(argc, argv)
{
    qDebug() << "Here We Go Again";
}

HeliosHermes::~HeliosHermes(){}
