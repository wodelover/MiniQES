/*************************************************************************/
/*                          Copyright Notice                             */
/* The code can not be copied or provided to other people without the    */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/

#ifndef QPLUGINSYSTEM_H
#define QPLUGINSYSTEM_H

#include <QObject>
#include <QQmlEngine>

/**
 * @ClassName: QPluginSystem
 * @Description: 用于插件中的系统方法实现
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2019-03-15 13:21:04
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
class QPluginSystem : public QObject
{
    Q_OBJECT
public:
    static QPluginSystem *getInstance();
    static QObject* QPluginSystem_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine);
    void close();
signals:
    void quit();

private:
    static QPluginSystem * instance;
    explicit QPluginSystem(QObject *parent = nullptr);

};

#endif // QPLUGINSYSTEM_H
