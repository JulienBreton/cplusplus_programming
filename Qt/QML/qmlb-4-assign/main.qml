import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Image {
        id: logoQt
        anchors.centerIn: parent
        width: 300
        fillMode: Image.PreserveAspectFit
        source: "https://upload.wikimedia.org/wikipedia/commons/thumb/0/0b/Qt_logo_2016.svg/578px-Qt_logo_2016.svg.png"

        Rectangle {
            id: myRectangle
            width: logoQt.width
            height: logoQt.height
            color: "orange"
            visible: false
            opacity: 0.5
        }

        MouseArea {
            id: myMouse
            anchors.fill: parent
            hoverEnabled: true
            onEntered: myRectangle.visible = true
            onExited: myRectangle.visible = false
            onClicked: Qt.openUrlExternally("https://www.qt.io")
        }

    }
}
