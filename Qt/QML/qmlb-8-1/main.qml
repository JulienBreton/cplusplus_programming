import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BusyIndicator {
        id: busyIndicator
        x: 290
        y: 210
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Dial {
        id: dial
        x: 26
        y: 280
    }

    CheckBox {
        id: checkBox
        x: 493
        y: 18
        text: qsTr("Check Box")
    }

    SpinBox {
        id: spinBox
        x: 112
        y: 136
    }

    ToolBar {
        id: toolBar
        x: 240
        y: 280
        width: 360

        DelayButton {
            id: delayButton
            x: 72
            y: -100
            text: qsTr("Delay Button")
            delay: 200
        }
    }

    TextArea {
        id: textArea
        x: 290
        y: 358
        text: qsTr("Text Area")
    }

    ComboBox {
        id: comboBox
        x: 84
        y: 45
    }

    RangeSlider {
        id: rangeSlider
        x: 290
        y: 307
        second.value: 0.75
        first.value: 0.25
    }

    RadioButton {
        id: radioButton
        x: 483
        y: 77
        text: qsTr("Radio Button")
    }

    Switch {
        id: element
        x: 500
        y: 136
        text: qsTr("Switch")
    }

    CheckDelegate {
        id: checkDelegate
        x: 290
        y: 33
        text: qsTr("Check Delegate")
    }
}
