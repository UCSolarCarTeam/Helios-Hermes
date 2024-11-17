#ifndef HELIOSHERMES_H
#define HELIOSHERMES_H

#include <QScopedPointer>
#include <QCoreApplication>


class HeliosHermes : public QCoreApplication
{
public:
    HeliosHermes(int& argc, char** argv);
    ~HeliosHermes();
private:
};

#endif // HELIOSHERMES_H
