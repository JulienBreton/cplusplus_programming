import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 88
        y: 83
        width: 100
        height: 100
        color: "#c5450b"

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            Connections {
                target: mouseArea
                onClicked: {

                    print("clicked")
                    rectangle.width = 50
                    rectangle.height = 150
                    rectangle.opacity = 0.5
                }
            }
        }


    }

    Rectangle {
        id: rectangle1
        x: 211
        y: 83
        width: rectangle.width
        height: rectangle.height
        color: "#0bc50e"

    }

    Rectangle {
        id: rectangle2
        x: 333
        y: 83
        width: 100
        height: 100
        color: "#240bc5"
        opacity: rectangle.opacity
    }


}



/*##^##
Designer {
    D{i:2;anchors_height:100;anchors_width:100;anchors_x:0;anchors_y:0}
}
##^##*/
