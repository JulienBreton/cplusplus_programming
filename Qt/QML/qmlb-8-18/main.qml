import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property string username: "Julien"
    property string password: "password"
    property string status: "Failed"

    Popup {
        id: statusPopup
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        anchors.centerIn: parent
        width: 200
        height: 300
        modal: true
        focus: true

        Label {
            id: statusLabel
            anchors.centerIn: parent
            text: status
            font.bold: true
        }

    }

    Column {
        id: column
        width: 282
        height: 145
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Grid {
            id: grid
            width: 300
            height: 100
            spacing: 10
            columns: 2

            Label {
                id: label
                text: qsTr("Username")
            }

            TextField {
                id: txtUsername
                text: ""
            }

            Label {
                id: label1
                text: qsTr("Password")
            }

            TextField {
                id: txtPassword
                text: ""
                echoMode: TextInput.Password
            }

        }

        Button {
            id: button
            text: qsTr("Login")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                if(username === txtUsername.text && password === txtPassword.text) {
                    status = "Hello!"
                } else {
                    status = "Failed"
                }

                statusPopup.open()
            }
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_height:229;anchors_width:256}
}
##^##*/
