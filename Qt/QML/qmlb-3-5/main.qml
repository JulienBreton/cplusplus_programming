import QtQuick 2.12
import QtQuick.Window 2.12

//Parent and children relationships

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Image {
        id: name
        source: "https://upload.wikimedia.org/wikipedia/commons/0/0b/Qt_logo_2016.svg"
        width: 150
        height: 100
        x: 100
        y: 100
        z: 0

        Rectangle {
            color: "blue"
            x: 0
            y: 0
            width: 50
            height: parent.height
            opacity: 0.5
            z: 4
        }

        Rectangle {
            color: "white"
            x: width
            y: 0
            width: 50
            height: parent.height
            opacity: 0.5
            z: 0
        }

        Rectangle {
            color: "red"
            x: parent.width - width
            y: parent.height - height
            width: 50
            height: parent.height
            opacity: 0.5
            z: 0
        }
    }
}
