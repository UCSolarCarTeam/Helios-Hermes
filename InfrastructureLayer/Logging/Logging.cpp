#include "Logging.h"

#include <QDebug>

Logging* Logging::instance_ = new Logging;

void Logging::init(int level)
{
    qInstallMessageHandler(Logging::logMessageHandler);

    switch (level)
    {
        case 0:
            logLevel_ = Logging::DEBUG;
            break;

        case 1:
            logLevel_ = Logging::INFO;
            break;

        case 2:
            logLevel_ = Logging::WARNING;
            break;

        case 3:
            logLevel_ = Logging::CRITICAL;
            break;

        case 4:
            logLevel_ = Logging::FATAL;
            break;

        default:
            logLevel_ = Logging::DEBUG;
            qWarning() << "Configured log level unrecognized. "
                       << "DEBUG=0,INFO=1,WARNING=2,CRITICAL=3,FATAL=4. "
                       << "Defaulting to DEBUG.";
            break;
    }
}

Logging* Logging::instance()
{
    if (!instance_)
    {
        instance_ = new Logging;
    }

    return instance_;
}

Logging::Logging()
    : logLevel_(LogLevel::INFO)
{
}

void Logging::logMessageHandler(
    QtMsgType type,
    const QMessageLogContext& ctx,
    const QString& msg)
{
    QByteArray localMsg = msg.toLocal8Bit();

    switch (type)
    {
        case QtDebugMsg:
            fprintf(
                stderr, "Debug: %s (%s:%u, %s)\n",
                localMsg.constData(), ctx.file, ctx.line, ctx.function);
            break;

        case QtInfoMsg:
            fprintf(
                stderr, "Info: %s (%s:%u, %s)\n",
                localMsg.constData(), ctx.file, ctx.line, ctx.function);
            break;

        case QtWarningMsg:
            fprintf(
                stderr, "Warning: %s (%s:%u, %s)\n",
                localMsg.constData(), ctx.file, ctx.line, ctx.function);
            break;

        case QtCriticalMsg:
            fprintf(
                stderr, "Critical: %s (%s:%u, %s)\n",
                localMsg.constData(), ctx.file, ctx.line, ctx.function);
            break;

        case QtFatalMsg:
            fprintf(
                stderr, "Fatal: %s (%s:%u, %s)\n",
                localMsg.constData(), ctx.file, ctx.line, ctx.function);
            abort();
    }
}
