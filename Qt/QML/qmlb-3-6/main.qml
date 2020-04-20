import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangleA
        width: 100
        height: 100
        x : 100
        y : 100

        color:  inputHandlerA.pressed ? "red" : "blue"

        TapHandler{
            id: inputHandlerA
        }
    }

    Rectangle {
        id: rectangleB
        width: 100
        height: 100
        x: 300
        y: 100

        color:  inputHandlerB.pressed ? "red" : "blue"

        TapHandler{
            id: inputHandlerB
        }
    }
}
