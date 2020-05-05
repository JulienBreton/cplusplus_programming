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
        x: 0
        y: 0
        width: 606
        height: 58
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25
        columns: 2

        Slider {
            id: slider
            width: 300
            height: 40
            stepSize: 0.1
            anchors.verticalCenter: parent.verticalCenter
            value: 0

            Connections {
                target: slider
                onMoved: label.text = Math.round(slider.value * 100)
            }
        }
    }

    Label {
        id: label
        x: 350
        y: 232
        text: "0"
        anchors.verticalCenter: parent.verticalCenter
        font.bold: true
        font.pointSize: 25
    }
}
