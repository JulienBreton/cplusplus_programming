import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

import "code.js" as Code

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        Code.startUp(label)
        button.clicked.connect(Code.updateLabel)
    }

    Label {
        id: label
        y: 152
        text: qsTr("0")
        font.pointSize: 25
        font.bold: true
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
        id: button
        y: 254
        width: 144
        height: 49
        text: qsTr("Click Me")
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
    }

}
