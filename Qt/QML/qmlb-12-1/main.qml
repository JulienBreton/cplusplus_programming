import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        id: column
        x: 232
        y: 40
        width: 102
        height: 246
        spacing: 25
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        CoolButton {
            id: coolButton
            width: 100
            height: 100
            source: "qrc:/images/up.png"
            onClicked: console.log("Up clicked")

        }

        CoolButton {
            id: coolButton1
            width: 100
            height: 100
            source: "qrc:/images/down.png"
            onClicked: console.log("Down clicked")
        }
    }


}
