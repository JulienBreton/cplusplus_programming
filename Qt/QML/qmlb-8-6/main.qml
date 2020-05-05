import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        id: column
        width: 200
        height: 400
        anchors.centerIn: parent

        Label {
            id: label
            text: qsTr("Selected Here")
            font.bold: true
            font.pointSize: 25
        }

        ListView { //La vue, qui présente les données à l'utilisateur.
            width: 200
            height: 200
            model: ["Option A", "Option B", "Option C"] //Le modéle, c-à-d les données qui vont dans la vue.
            delegate: CheckDelegate {
                text: modelData //Le texte correspond aux données du modéle
                onCheckStateChanged: label.text = index + " - " + modelData + " = " + checked
            }
        }
    }
}
