import QtQuick 2.0
import QtQuick.Controls 2.13

Item {
    id: element
    width: 300
    height: 300

    //Ce signal permet de mettre à jour le label qui est dans le main.
    signal generated(int value)

    function updateLabel() {

        label.text = Math.round(rangeSlider.first.value) + " to " + Math.round(rangeSlider.second.value)
    }

    Column {
        id: column
        spacing: 10
        anchors.fill:parent

        Label {
            id: label
            text: "25 to 75"
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pointSize: 25
        }

        RangeSlider {
            id: rangeSlider
            anchors.horizontalCenter: parent.horizontalCenter
            from: 1
            to: 100
            first.value: 25
            second.value: 75

            first.onMoved: {
                updateLabel()
            }

            second.onMoved: {
                updateLabel()
            }

        }

        Button {
            id: button
            text: qsTr("Generate")
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {

                generated(Math.floor(Math.random() * (rangeSlider.second.value - rangeSlider.first.value + 1) + rangeSlider.first.value))
            }
        }

    }


}


