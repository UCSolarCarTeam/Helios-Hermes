#include "SchulichDeltaHermes.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QScopedPointer<SchulichDeltaHermes> app;
    app.reset(new SchulichDeltaHermes(argc, argv));
    return app->exec();
}
