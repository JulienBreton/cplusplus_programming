import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property string strDrink: ""
    property string strFood: ""

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 200
        height: 200
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Column {
            anchors.fill: parent
            spacing: 25
            Label {
                id: lblDetails
                text: strFood + " with " + strDrink
            }

            Button {
                id: closeButton
                text: "Close"
                onClicked: {
                    popup.close()
                }
            }

        }
    }

    Row {
        id: row
        x: 0
        y: 0
        width: 426
        height: 191
        anchors.verticalCenterOffset: -57
        anchors.horizontalCenterOffset: 0
        spacing: 25
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        GroupBox {
            id: groupBox
            width: 200
            height: 190
            title: qsTr("Food")

            Column {
                id: colFood
                anchors.fill: parent
                spacing: 5

                RadioButton {
                    id: rdoFish
                    text: qsTr("Fish")
                }

                RadioButton {
                    id: rdoSteak
                    text: qsTr("Steak")
                }

                RadioButton {
                    id: rdoVegan
                    text: qsTr("Vegan")
                }
            }

        }

        GroupBox {
            id: groupBox1
            width: 200
            height: 190
            Column {
                id: colDrink
                spacing: 5
                anchors.fill: parent
                RadioButton {
                    id: rdoWater
                    text: qsTr("Water")
                }

                RadioButton {
                    id: rdoWine
                    text: qsTr("Wine")
                }

                RadioButton {
                    id: rdoSoda
                    text: qsTr("Soda")
                }

            }
            title: qsTr("Drinks")
        }
    }

    Button {
        id: button
        x: 270
        y: 335
        text: qsTr("Click Me")
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter

        Connections {
            target: button
            onClicked: {
                //get the food
                for (var i = 0; i < colFood.children.length; i++) {
                    var rdoF = colFood.children[i]
                    if(rdoF.checked) strFood = rdoF.text
                }

                //get the drink
                for (var j = 0; j < colDrink.children.length; j++) {
                    var rdoD = colDrink.children[j]
                    if(rdoD.checked) strDrink = rdoD.text
                }

                popup.open()

            }
        }
    }
}

/*##^##
Designer {
    D{i:3;anchors_height:166;anchors_width:176}D{i:2;anchors_height:190;anchors_width:200}
D{i:8;anchors_height:166;anchors_width:176}D{i:7;anchors_height:200;anchors_width:200}
}
##^##*/
