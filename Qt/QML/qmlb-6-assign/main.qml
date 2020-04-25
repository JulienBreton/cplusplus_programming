import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        color: "red"
        width: 100
        height: 100
        x: (parent.width / 2) - (width / 2)
        y: (parent.height / 2) - (height / 2)
        focus: true //Permet que les actions du clavier bougent ce rectangle.

        Keys.onUpPressed: y -= 10
        Keys.onDownPressed: y += 10
        Keys.onRightPressed: x += 10
        Keys.onLeftPressed: x -= 10
    }
}
