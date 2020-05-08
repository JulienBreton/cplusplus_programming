import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    Component {
        id : delegate

        Item {
            id: item
            width: 200
            height: 50
            Column {
                anchors.fill: parent
                spacing: 5

                Label {
                    text: name
                    font.bold: true
                }
                Label {
                    text: number
                }
            }
        }

    }

    ListModel {
        id: model
        ListElement {
            name: "Bill Smith"
            number: "555 5431"
        }
        ListElement {
            name: "Bill Smith"
            number: "555 5431"
        }
        ListElement {
            name: "Bill Smith"
            number: "555 5431"
        }
    }

    ScrollView {
        anchors.fill: parent

        ListView {
            width: parent.width
            model: model
            delegate: delegate
        }
    }
}
