import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Grid {
        id: keyBoard
        anchors.centerIn: parent
        columns: 3
        rows: 5
        spacing: 5
        Rectangle {
            id: result
            height: 50
            width: 50

            Text {
                id: textResult
                text: "?"
                font.pointSize: 25
            }
        }

        Item {width: 50; height: 50}
        Item {width: 50; height: 50}
        PadButton {
            display.text: "7"
            area.onClicked: textResult.text = "7"
        }
        PadButton {
            display.text: "8"
            area.onClicked: textResult.text = "8"
        }
        PadButton {
            display.text: "9"
            area.onClicked: textResult.text = "9"
        }
        PadButton {
            display.text: "4"
            area.onClicked: textResult.text = "4"
        }
        PadButton {
            display.text: "5"
            area.onClicked: textResult.text = "5"
        }
        PadButton {
            display.text: "6"
            area.onClicked: textResult.text = "6"
        }
        PadButton {
            display.text: "1"
            area.onClicked: textResult.text = "1"
        }
        PadButton {
            display.text: "2"
            area.onClicked: textResult.text = "2"
        }
        PadButton {
            display.text: "3"
            area.onClicked: textResult.text = "3"
        }
        Item {width: 50; height: 50}
        PadButton {
            display.text: "0"
            area.onClicked: textResult.text = "0"
        }
    }
}
