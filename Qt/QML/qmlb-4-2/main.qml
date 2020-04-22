import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: myItem
        anchors.centerIn: parent
        color: "red"
        width: 200
        height: 200
        visible: true

        border.color: "#000000"
        border.width: 5

        radius: width //Dessine le vercle

        gradient: Gradient {
            GradientStop {position: 0.0; color: "red"}
            GradientStop {position: 1.0; color: "blue"}
        }
    }
}
