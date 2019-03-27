#include "plugin.h"
#include <QDebug>
#include <QQmlContext>
Plugin *Plugin::instance = nullptr;

void Plugin::ShowWindow()
{
    qmlRegisterSingletonType<QPluginSystem>("com.kingderzhang.QPluginSystem.QPlugin", 1, 0, "QPlugin", QPluginSystem::QPluginSystem_singletontype_provider);

    engine.load(QUrl(QLatin1String("qrc:/test.qml")));
}

void Plugin::closeWindow()
{
//    engine.destroyed();
    QPluginSystem::getInstance()->close();
}

Plugin *Plugin::getInstance()
{
    if(instance==nullptr){
        instance = new Plugin;
    }
    return instance;
}

Plugin::Plugin()
{

}

void showMainWindow()
{
    Plugin::getInstance()->ShowWindow();
}

void CloseWindowApp()
{
    Plugin::getInstance()->closeWindow();
}
