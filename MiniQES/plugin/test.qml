import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Window 2.9
import com.kingderzhang.QPluginSystem 1.0
Window {
    id:applicationWindow
    visible: true
    width: 320
    height: 240
   // title: qsTr("这是插件")

    Connections{
        target: QPluginSystem
        onQuit:{
            console.log("quit")
        }
    }

    Button{
        id:button
        text: qsTr("adadsa")
        height:48
        width:120
        anchors.centerIn: parent
        MouseArea{
            id:mouseArea
            anchors.fill: parent
            onPressed: {
                console.debug(qsTr("9999999999999"));
            }
        }
    }
}
