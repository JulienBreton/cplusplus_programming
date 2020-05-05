import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 640
    height: 480
    color: "#7b7777"
    title: qsTr("Hello World")

    Row {
        id: row
        x: 0
        y: 0
        width: 640
        height: 45
        spacing: 5

        Button {
            id: cat
            text: qsTr("Cat")

            Connections {
                target: cat
                onClicked: image.source = "qrc:/images/images/cat.jpg"
            }
        }

        Button {
            id: dog
            text: qsTr("Dog")

            Connections {
                target: dog
                onClicked: image.source = "qrc:/images/images/dog.jpg"
            }
        }

        Button {
            id: fish
            text: qsTr("Fish")

            Connections {
                target: fish
                onClicked: image.source = "qrc:/images/images/fish.jpg"
            }
        }

        Button {
            id: bird
            text: qsTr("Bird")

            Connections {
                target: bird
                onClicked: image.source = "qrc:/images/images/bird.jpg"
            }
        }
    }

    Image {
        id: image
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 51
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        fillMode: Image.PreserveAspectFit
        source: "qrc:/qtquickplugin/images/template_image.png"
    }
}

/*##^##
Designer {
    D{i:6;anchors_height:429;anchors_width:640;anchors_x:0;anchors_y:51}
}
##^##*/
