#include "ConfigManager.h"

#include <QSettings>
#include <QFile>
#include <QFileInfo>
#include <QCoreApplication>
#include <QDir>

/** Singleton instance of ConfigManager */
ConfigManager& ConfigManager::instance() {
    static ConfigManager instance(QDir(QCoreApplication::applicationDirPath()).filePath("config.ini"));
    return instance;
}

/** Read ini file and assign settings values */
ConfigManager::ConfigManager(const QString& path){
    qDebug() << "Reading Config File at: " << path;
    QSettings settings(path, QSettings::IniFormat);

    if (!QFile::exists(path)) {
        qDebug() << "WARNING: Config file does not exist at path:" << path;
        qDebug() << "Default settings will be used, this may cause unexpected behavior";
        return;
    }

    forwardPeriod = settings.value("forwardPeriod", 500).toInt();

    settings.beginGroup("UnitNumbers");
    numberOfMotors = settings.value("numberOfMotors", 2).toInt();
    numberOfMppts = settings.value("numberOfMppts", 4).toInt();
    settings.endGroup();

    settings.beginGroup("JsonFormat");
    packetTitle = settings.value("packetTitle", "Hermes").toString();
    settings.endGroup();

    settings.beginGroup("SerialPort");
    portName = settings.value("portName", "/dev/ttyUSB0").toString();
    baudrate = settings.value("baudrate", 115200).toInt();
    settings.endGroup();

    settings.beginGroup("Mqtt");
    localTopic = settings.value("localTopic", "hermesExchange").toString();
    localHostname = settings.value("localHostname", "127.0.0.1").toString();
    localPort = settings.value("localPort", 6969).toInt();
    telemetryTopic = settings.value("telemetryTopic", "packet").toString();
    telemetryHostname = settings.value("telemetryHostname", "aedes.solarcar.ca").toString();
    telemetryPort = settings.value("telemetryPort", 1883).toInt();
    telemetryUsername = settings.value("telemetryUsername", "YouDontBelongHere").toString();
    telemetryPassword = settings.value("telemetryPassword", "QuitBeingNaughty").toString();
    settings.endGroup();

    settings.beginGroup("Logging");
    logLevel = settings.value("logLevel", 3).toInt();
    loggingEnabled = settings.value("loggingEnabled", true).toBool();
    settings.endGroup();
}

//Getters
int ConfigManager::getForwardPeriod() const { return forwardPeriod; }

int ConfigManager::getNumberOfMotors() const { return numberOfMotors; }

int ConfigManager::getNumberOfMppts() const { return numberOfMppts; }

QString ConfigManager::getPacketTitle() const { return packetTitle; }

QString ConfigManager::getPortName() const { return portName; }

int ConfigManager::getBaudrate() const { return baudrate; }

QString ConfigManager::getLocalTopic() const { return localTopic; }

QString ConfigManager::getLocalHostname() const { return localHostname; }

int ConfigManager::getLocalPort() const { return localPort; }

QString ConfigManager::getTelemetryTopic() const { return telemetryTopic; }

QString ConfigManager::getTelemetryHostname() const { return telemetryHostname; }

int ConfigManager::getTelemetryPort() const { return telemetryPort; }

QString ConfigManager::getTelemetryUsername() const { return telemetryUsername; }

QString ConfigManager::getTelemetryPassword() const { return telemetryPassword; }

int ConfigManager::getLogLevel() const { return logLevel; }

bool ConfigManager::getLoggingEnabled() const { return loggingEnabled; }
