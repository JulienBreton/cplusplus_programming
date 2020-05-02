import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 89
        y: 127
        width: 200
        height: 200
        color: "#240bc5"

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            Connections {
                target: mouseArea
                onClicked: rectangle1.title = "Hello"
            }
        }
    }

    Rectangle {
        id: rectangle1
        x: 347
        y: 127
        width: 200
        height: 200
        color: "#036f05"
        property string title: "Title"

        Text {
            id: element
            color: "#ffffff"
            text: parent.title
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 35
        }
    }

}

/*##^##
Designer {
    D{i:2;anchors_height:100;anchors_width:100}
}
##^##*/
