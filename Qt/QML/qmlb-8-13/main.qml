import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Column {
        id: column
        width: 414
        height: 199
        spacing: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter


        Label {
            id: label
            x: 150
            y: 10
            text: qsTr("X to Y")
            font.pointSize: 25
            font.bold: true
        }
        RangeSlider {
            id: rangeSlider
            x: 100
            y: 0
            second.value: 0.75
            first.value: 0.25

            Connections {
                target: rangeSlider.first
                onValueChanged: {
                    label.text = Math.round(rangeSlider.first.value * 100) + " to " + Math.round(rangeSlider.second.value * 100)
                }
            }

            Connections {
                target: rangeSlider.second
                onValueChanged: {
                    label.text = Math.round(rangeSlider.first.value * 100) + " to " + Math.round(rangeSlider.second.value * 100)
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:2;anchors_y:10}
}
##^##*/
