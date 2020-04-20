import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Hello World")

    Image {
        id: logoQt
        source: "https://upload.wikimedia.org/wikipedia/commons/0/0b/Qt_logo_2016.svg"
        width: 150
        height: 100
        x: 275
        y: 100
        z: 1
    }

    Rectangle {
        color: "blue"
        width: 200
        height: 200
        x: 50
        y: 50
        z: 0
    }

    Rectangle {
        color: "white"
        width: 200
        height: 200
        x: 250
        y: 50
        z: 0
    }

    Rectangle {
        color: "red"
        width: 200
        height: 200
        x: 450
        y: 50
        z: 0
    }

    Image {
        id: pirate
        source: "https://upload.wikimedia.org/wikipedia/commons/1/1b/Jolly-roger.svg"
        width: 250
        height: 200
        x: 300
        y: 325
        z: 1
    }

    Rectangle {
        color: "red"
        width: 300
        height: 250
        x: 275
        y: 300
        z: 0
        //opacity: 0.5
    }

}
