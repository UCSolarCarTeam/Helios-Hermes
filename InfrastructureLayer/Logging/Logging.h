#pragma once

#include <QScopedPointer>
#include <QtGlobal>
#include <QString>

class Logging
{
public:
    enum LogLevel
    {
        DEBUG,
        INFO,
        WARNING,
        CRITICAL,
        FATAL
    };
    void init(int level);
    static Logging* instance();
private:
    Logging();
    static Logging* instance_;

    LogLevel logLevel_;
    static void logMessageHandler(
        QtMsgType type,
        const QMessageLogContext& ctx,
        const QString& msg);
};
