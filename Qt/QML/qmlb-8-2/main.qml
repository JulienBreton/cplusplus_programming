import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {
        id: label
        x: 102
        y: 59
        text: qsTr("This a label")
    }

    Label {
        id: label1
        x: 102
        y: 133
        width: 111
        height: 82
        color: "#e00505"
        text: qsTr("This a long lable title - probably the longest")
        font.italic: true
        font.underline: true
        font.bold: true
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignTop
    }

    Label {
        id: label2
        x: 102
        y: 248
        text: qsTr("This is <font color='blue'><b>H<i>T</i>ML</b>!!!</font>")
        font.pointSize: 45
    }
}
