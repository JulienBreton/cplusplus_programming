import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    /*TestCB {
        id: cmbTest
        anchors.centerIn: parent
    }*/

    IconCombo {
        id: cmbColor
        anchors.centerIn: parent
    }
}
