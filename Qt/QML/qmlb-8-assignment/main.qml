import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 400
        height: 400
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Grid {
            width: 200
            height: 200
            anchors.verticalCenter: parent.verticalCenter
            spacing: 50
            rows: 4
            columns: 2
            leftPadding: 50

            Label {
                id: lbFirstNamePopUp
                width: 38
                height: 17
                text: qsTr("First Name: ")
            }

            Label {
                id: firstName
                width: 38
                height: 17
                leftPadding: 50
                text: ""
            }

            Label {
                id: lbLastNamePopUp
                width: 38
                height: 17
                text: qsTr("Last Name: ")
            }

            Label {
                id: lastName
                width: 38
                height: 17
                leftPadding: 50
                text: ""
            }

            Label {
                id: lbGenderPopUp
                width: 38
                height: 17
                text: qsTr("Gender: ")
            }

            Label {
                id: gender
                width: 38
                height: 17
                leftPadding: 50
                text: ""
            }

            Label {
                id: lbAgePopUp
                width: 38
                height: 17
                text: qsTr("Age : ")
            }

            Label {
                id: age
                width: 38
                height: 17
                leftPadding: 50
                text: ""
            }

        }
    }

    Grid {
        id: grid
        x: 48
        y: 44
        width: 307
        height: 241
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 25
        rows: 4
        columns: 2

        Label {
            id: lbFirstName
            width: 38
            height: 17
            text: qsTr("First Name")
        }

        TextField {
            id: tfFirstName
            text: qsTr("First")
        }

        Label {
            id: lbLastName
            text: qsTr("Last Name")
        }

        TextField {
            id: tfLastName
            text: qsTr("Last")
        }

        Label {
            id: lbGender
            text: qsTr("Gender")
        }

        ComboBox {
            id: cbGender

            model: ListModel {
                id: listmodel
                ListElement {text: "Male"}
                ListElement {text: "Female"}
            }
        }

        Label {
            id: lbAge
            text: qsTr("Age")
        }

        SpinBox {
            id: sbAge
            editable: true
        }
    }

    Button {
        id: btClickMe
        x: 271
        y: 347
        text: qsTr("Click Me")
        onClicked: {
            popup.open()
            firstName.text = tfFirstName.text
            lastName.text = tfLastName.text
            gender.text = cbGender.currentText
            age.text = sbAge.displayText
        }
    }

}
