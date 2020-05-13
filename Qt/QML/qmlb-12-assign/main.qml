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
        width: 300
        height: 274
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Genie {
            id: genie
            width: 300
            height: 194

            onGenerated: {
                label.text = value
            }
        }

        Label {
            id: label
            text: qsTr("No number yet")
            font.bold: true
            font.pointSize: 25
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    
}
