import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: page
    width: 600
    height: 400

    property alias nameDisplay: labelNom.text

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Column {
        id: column
        x: 0
        y: 217
        width: 174
        height: 83
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Label {
            id: labelNom
            text: qsTr("Title")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button
            text: qsTr("Click Me")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: nameDisplay = "Hello World!!!"
        }
    }
}
