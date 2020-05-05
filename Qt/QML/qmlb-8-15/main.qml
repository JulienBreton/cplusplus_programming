
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Grid {
        id: grid
        width: 254
        height: 41
        topPadding: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25

        SpinBox {
            id: spinBox
//            onValueChanged: label.text = value

//            Connections {
//                target: spinBox
//                onValueModified: label.text = target.value
//            }
        }

        Label {
            id: label
            text: spinBox.value
            font.pointSize: 25
            font.bold: true
        }
    }
}
