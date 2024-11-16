#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QString>

class ConfigManager {

public:
    static ConfigManager& instance();

    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    int getForwardPeriod() const;

    int getNumberOfMotors() const;
    int getNumberOfMppts() const;

    QString getPacketTitle() const;

    QString getPortName() const;
    int getBaudrate() const;

    QString getLocalTopic() const;
    QString getLocalHostname() const;
    int getLocalPort() const;
    QString getTelemetryTopic() const;
    QString getTelemetryHostname() const;
    int getTelemetryPort() const;
    QString getTelemetryUsername() const;
    QString getTelemetryPassword() const;

    int getLogLevel() const;
    bool getLoggingEnabled() const;

private:
    ConfigManager(const QString& path);

    int forwardPeriod;
    int numberOfMotors;
    int numberOfMppts;
    QString packetTitle;
    QString portName;
    int baudrate;
    QString localTopic;
    QString localHostname;
    int localPort;
    QString telemetryTopic;
    QString telemetryHostname;
    int telemetryPort;
    QString telemetryUsername;
    QString telemetryPassword;
    int logLevel;
    bool loggingEnabled;
};

#endif // CONFIGMANAGER_H
