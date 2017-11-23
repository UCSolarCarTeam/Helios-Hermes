#pragma once

#include <QFile>
#include <QScopedPointer>
#include <QString>
#include <QTextStream>
#include <QtGlobal>

class Logging
{
public:

    enum LogLevel
    {
        DEBUG = 4,
        INFO = 3,
        WARNING = 2,
        CRITICAL = 1,
        FATAL = 0,
    };
    void init(int level);
    QTextStream& logStream();
    LogLevel logLevel();
    static Logging& instance();
private:
    Logging();
    ~Logging();
    static Logging instance_;

    LogLevel logLevel_;
    QFile logFile_;
    QTextStream logStream_;
    static void logMessageHandler(
        QtMsgType type,
        const QMessageLogContext& ctx,
        const QString& msg);
};
