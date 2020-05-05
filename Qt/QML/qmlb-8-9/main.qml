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
        width: 320
        height: 400
        spacing: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Label {
            id: label
            text: qsTr("Value")
            font.pointSize: 50
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Dial {
            id: dial
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            onMoved: label.text = Math.round(dial.value * 100)

            //Unique cas où il est bien d'utiliser les connexions : quand on veut pouvoir activer/désactiver la connexion
//            Connections {
//                target: dial
//                onMoved: label.text = Math.round(dial.value * 100)
//            }
        }
    }


}
