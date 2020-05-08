import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Window {
        color: "green"
        visible: true
        width: 640
        height: 480
        title: qsTr("fenetre 1")
        x: 1200
        y: 500
    }

    Window {
        color: "red"
        visible: true
        width: 640
        height: 480
        title: qsTr("fenetre 2")
    }
}


