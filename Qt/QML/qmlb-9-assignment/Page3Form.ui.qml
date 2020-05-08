import QtQuick 2.4
import QtQuick.Controls 2.13

Page {
    width: 600
    height: 400

    title: qsTr("Page 3")

    Label {
        id: label
        text: qsTr("Page 3")
        font.pointSize: 25
        font.bold: true
        anchors.centerIn: parent
    }
}
