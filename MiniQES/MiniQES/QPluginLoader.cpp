#include "QPluginLoader.h"
#include <QDebug>

QPluginLoader* QPluginLoader::m_instace = nullptr;

QPluginLoader *QPluginLoader::getInstance()
{
    if(m_instace==nullptr){
        m_instace = new QPluginLoader;

    }
    return m_instace;
}

QObject *QPluginLoader::QPluginLoader_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return getInstance();
}

bool QPluginLoader::loadPlugin(QString pluginPath)
{
#ifdef WIN_PLATFORM
    if(!pluginPath.endsWith(".dll")){
        qDebug()<<__FILE__" line"<<__LINE__<<":file is not surport.";
        qDebug()<<"file:"<<pluginPath;
        return false;
    }
#endif

#ifdef UNIX_PLATFORM
    if(!pluginPath.endsWith(".1.0")){
        qDebug()<<__FILE__" line"<<__LINE__<<":file is not surport.";
        qDebug()<<"file:"<<pluginPath;
        return false;
    }
#endif

    typedef void(*FUN1)();
    lib.setFileName(pluginPath);
    if (lib.load())
    {
        FUN1 pShow = static_cast<FUN1>(lib.resolve("showMainWindow"));
        if (pShow)
        {
            pShow();
//            m_libs.insert(pluginPath,lib);
            return true;
        }
        else
        {
            qDebug() <<__FILE__<<" "<<__LINE__<< ":resolve entry function error.";
            qDebug() << "plase check the entry func is named with showMainWindow";
            return false;
        }
    }
    else
    {
        qDebug() <<__FILE__<<" "<<__LINE__<< ":load plugin false.";
        qDebug() << "plugin file path not right,you should be use Relative path.";
        return false;
    }
}

bool QPluginLoader::unLoadPlugin(QString pluginPath)
{

#ifdef WIN_PLATFORM
    if(!pluginPath.endsWith(".dll")){
        qDebug()<<__FILE__" line"<<__LINE__<<":file is not surport.";
        qDebug()<<"file:"<<pluginPath;
        return false;
    }
#endif

#ifdef UNIX_PLATFORM
    if(!pluginPath.endsWith(".1.0")){
        qDebug()<<__FILE__" line"<<__LINE__<<":file is not surport.";
        qDebug()<<"file:"<<pluginPath;
        return false;
    }
#endif
//    QMap<QString,QLibrary>::iterator itr = m_libs.begin();

//    for(;itr!=m_libs.end();itr++){
//        if(itr.key()==pluginPath){
//            bool status = itr.value().unload();
//            m_libs.remove(pluginPath);
//            return status;
//        }
//    }
    typedef void(*FUN1)();
    FUN1 pShow = static_cast<FUN1>(lib.resolve("CloseWindowApp"));
    if (pShow)
    {
        pShow();
//            m_libs.insert(pluginPath,lib);
        return true;
    }
    return false;
}

QStringList QPluginLoader::getPlugins()
{
    return m_libs;
}

QPluginLoader::QPluginLoader(QObject *parent) : QObject(parent)
{
}
