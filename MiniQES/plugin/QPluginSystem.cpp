#include "QPluginSystem.h"

QPluginSystem * QPluginSystem::instance = nullptr;

QPluginSystem *QPluginSystem::getInstance()
{
    if(instance==nullptr){
        instance = new QPluginSystem;
    }
    return instance;
}

QObject *QPluginSystem::QPluginSystem_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return getInstance();
}

void QPluginSystem::close()
{
    emit quit();
}

QPluginSystem::QPluginSystem(QObject *parent) : QObject(parent)
{
    // nothing todo
}
