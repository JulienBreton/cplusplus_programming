import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        id: row
        x: 127
        width: 390
        height: 41
        anchors.verticalCenter: parent.verticalCenter
        spacing: 50

        DelayButton {
            id: delayButton
            text: qsTr("Delete Everything")
            delay: 1000
            //progress: 0.5
            onProgressChanged: {
                label.text = Math.round(progress * 100)
                label.opacity = progress
                if(progress === 0){
                    text = "Delete Everything"
                    label.text = "Satus"
                    label.opacity = 0
                }
            }

            onActivated: {
                label.text = "Done";
                text = "BOOOOM"
            }

        }

        Label {
            id: label
            text: qsTr("Status")
            font.bold: true
            font.pointSize: 25
            opacity: 0
        }
    }

}
