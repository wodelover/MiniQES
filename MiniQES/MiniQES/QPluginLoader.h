/*************************************************************************/
/*                          Copyright Notice                             */
/* The code can not be copied or provided to other people without the    */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/

#ifndef QPLUGINLOADER_H
#define QPLUGINLOADER_H

#include <QObject>
#include <QQmlEngine>
#include <QStringList>
#include <QCoreApplication>
#include <QLibrary>
#include <QVector>
/**
 * @ClassName: QPluginLoader
 * @Description: 用于加载动态库文件,win应该加载dll文件
 * unix应该将  xxx.1.0.0 文件修改为 xxx.1.0 ,然后进行加载
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2019-03-13 17:23:42
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
class QPluginLoader : public QObject
{
    Q_OBJECT

public:
    static QPluginLoader *getInstance();
    static QObject* QPluginLoader_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine);

    Q_INVOKABLE bool loadPlugin(QString pluginPath);

    Q_INVOKABLE bool unLoadPlugin(QString pluginPath);

    Q_INVOKABLE QStringList getPlugins();

private:
    static QPluginLoader* m_instace;
    explicit QPluginLoader(QObject *parent = nullptr);
    QStringList m_libs;
        QLibrary lib;
};

#endif // QPLUGINLOADER_H
