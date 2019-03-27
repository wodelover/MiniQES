#ifndef PLUGIN_H
#define PLUGIN_H
#pragma once
#include "plugin_global.h"
#include <QQmlApplicationEngine>
#include <QPluginSystem.h>

class Q_DECL_EXPORT Plugin
{

public:
    void ShowWindow();
    void closeWindow();
    static Plugin * getInstance();
private:
    QQmlApplicationEngine engine;
    Plugin();
    static Plugin *instance;
};

extern "C" Q_DECL_EXPORT void showMainWindow();

extern "C" Q_DECL_EXPORT void CloseWindowApp();


#endif // PLUGIN_H
