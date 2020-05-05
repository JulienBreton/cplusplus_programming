import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        id: row
        width: 232
        height: 45
        spacing: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        property var value: 0

        RoundButton {
            id: roundButton
            text: "+"
            font.pointSize: 15
            font.bold: true
            onClicked: row.value++
        }

        RoundButton {
            id: roundButton1
            text: "-"
            font.pointSize: 15
            font.bold: true
            onClicked: row.value--
        }

        Label {
            id: label
            text: qsTr("Value: " + row.value)
            font.pointSize: 25
            font.bold: true
        }
    }


}
