import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        color: "pink"
        anchors.centerIn: parent
        width: 300
        height: 400

        clip: true

        Flow {
            anchors.centerIn: parent

            flow: Flow.LeftToRight
            spacing: 5

            MyShape {color: "red"}
            MyShape {color: "yellow"}
            MyShape {color: "green"}
            MyShape {color: "blue"}
            MyShape {color: "black"}
            MyShape {color: "gray"}
            MyShape {color: "teal"}
            MyShape {color: "brown"}
            MyShape {color: "orange"}
        }
    }
}
