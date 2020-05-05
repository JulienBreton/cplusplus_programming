import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BusyIndicator {
        id: busyIndicator
        x: 251
        y: 186
        width: 150
        height: 108
    }

    Label {
        id: label
        x: 268
        y: 132
        text: qsTr("Progress = ") + busyIndicator.running

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                if(busyIndicator.running){
                    console.log("Turning off")
                    busyIndicator.running = false
                } else {
                    console.log("Turning on")
                    busyIndicator.running = true
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:3;anchors_height:100;anchors_width:100;anchors_x:26;anchors_y:8}
}
##^##*/
