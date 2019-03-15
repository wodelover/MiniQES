import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import com.kingderzhang.QPluginLoader 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Mini QES")

    Button{
        id: open
        text: "open"
        onClicked: {
            QPluginLoader.loadPlugin("./plugin.dll")
        }
    }
    Button{
        id: close
        y: 50
        text: "close"
        onClicked: {
            QPluginLoader.unLoadPlugin("./QmlPlugin.dll")
        }
    }
}
