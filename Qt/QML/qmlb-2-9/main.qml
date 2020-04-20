import QtQuick 2.12
import QtQuick.Window 2.12

//ID - must be unique
//Root Object - there cna be only one

//Top level object is the root!
Window {
    id: maFenetre
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        id: element
        text: qsTr("Welcome to QML")
        font.bold: true
        font.pixelSize: 25
    }

    Image{
        id: qtLogo
        source: "https://upload.wikimedia.org/wikipedia/commons/0/0b/Qt_logo_2016.svg"
        anchors.centerIn: parent
        width: 150
        height: 100

        Rectangle{
            color: "blue"
            width: parent.width
            height: parent.height
            opacity: 0.5
        }
    }
}
