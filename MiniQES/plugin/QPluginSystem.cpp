#include "QPluginSystem.h"
#include <QDebug>

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
    if(m_engine==nullptr){
        qDebug()<<__FILE__<<__LINE__<<"QQmlApplicationEngine is Empty.";
        qDebug()<<"did you forget call initQPluginSystem function to set QQmlApplicationEngine?";
        return;
    }
    m_engine->destroyed();
}

void QPluginSystem::initQPluginSystem(QGuiApplication &app, QQmlApplicationEngine &engine)
{
    m_app = &app;
    m_engine = &engine;
}

QPluginSystem::QPluginSystem()
{
    // nothing to do
}
