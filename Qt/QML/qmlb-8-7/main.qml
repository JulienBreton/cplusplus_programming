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
        x: 220
        y: 131
        width: 200
        height: 219
        clip: false
        spacing: 20

        Label {
            id: lblFood
            color: "#f92828"
            text: qsTr("Selected Item")
            font.pointSize: 10
            font.bold: true
        }

        ComboBox {
            id: cmbFood
            model: ['Pizza', 'Steak', 'Pasta']
            onCurrentTextChanged: lblFood.text = cmbFood.currentText
        }

        Label {
            id: lblPeople
            color: "#f92828"
            text: qsTr("Selected Item")
            font.pointSize: 10
            font.bold: true
        }

        ComboBox {
            id: cmbPeople
            editable: true
            textRole: "text"
            //currentIndex: 2

            model: ListModel {
                id: listmodel
                ListElement {text: "Bryan"; age: "45"}
                ListElement {text: "Tammy"; age: "49"}
                ListElement {text: "Rango"; age: "15"}
            }

            onCurrentIndexChanged: lblPeople.text = model.get(currentIndex).text + " = " +model.get(currentIndex).age

            /*onAccepted:{
                if(find(editText) === -1) {
                    model.append({"text": editText, "age": "0"})
                    currentIndex = find(editText)
                }
            }*/
        }
    }

}
