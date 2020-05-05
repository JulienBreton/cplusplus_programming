import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        id: column
        anchors.fill: parent

        Image {
            id: image
            width: 300
            height: 300
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/sad.png"
            fillMode: Image.PreserveAspectFit
        }

        Switch {
            id: element
            text: qsTr("Sad")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 25

            onToggled: {
                if(checked) {
                    text = "Happy"
                    image.source = "qrc:/images/happy.png"
                } else {
                    text = "Sad"
                    image.source = "qrc:/images/sad.png"
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_height:400;anchors_width:200}
}
##^##*/
