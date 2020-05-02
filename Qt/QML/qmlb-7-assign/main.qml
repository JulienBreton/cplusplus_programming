import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    color: "#2f51f3"
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 170
        y: 90
        width: 300
        height: 300
        color: "#9bfc07"
        radius: height

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            Connections {
                target: mouseArea
                onClicked: {
                    rectangle.radius = 0;
                }

            }
        }
    }
}

/*##^##
Designer {
    D{i:2;anchors_height:100;anchors_width:100;anchors_x:50;anchors_y:50}
}
##^##*/
