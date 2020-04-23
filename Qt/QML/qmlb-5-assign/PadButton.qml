import QtQuick 2.0

Item {
    id: root
    width: 50
    height: 50

    property alias display: textNumber
    property alias area: mousearea
    property color color: "cornflowerblue"
    property color colorHover: "blue"
    property color colorPress: "orange"

    Rectangle {
        id: number
        height: root.height //Le rectangle dans prendre la hauteur de item qui est définie dans le main.
        width: root.width //Le rectangle dans prendre la largeur de item qui est définie dans le main.
        color: root.color

        Text {
            id: textNumber
            text: ""
            anchors.centerIn: parent
            font.pointSize: 15
        }

        MouseArea {
            id: mousearea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: {
                parent.color = root.colorHover
            }

            onExited: {
                parent.color = root.color
            }

            onPressed: {
                parent.color = root.colorPress
            }

            onReleased: {
                parent.color = root.colorHover
            }
        }
    }

}
