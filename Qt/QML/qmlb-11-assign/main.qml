
import QtQuick 2.12
import QtQuick.Window 2.12
import Qt.labs.calendar 1.0
import QtQuick.Controls 2.13

//On apporte le type cat
import com.company.cat 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Cat{
        id: myCat
        nameCat: ""

        onMeow: {
            console.log("Signal onMeow du chat avec le nom : -" + nameCat + "-")

            if(myCat.nameCat === ""){
                lbNewName.text = "Quel est le nom de mon chat?"
                popUpCatName.open()
            }else{
                lbNewName.text = "MEOW"
                popUpCatName.open()
            }
        }

        onNameChanged: {
            console.log("Signal onNameChanged")

            if(tfName.text === "" || tfName.text === "Donne un nom à ton chat :)"){
                tfName.text = "Donne un nom à ton chat :)"
            }else{
                lbNewName.text = "Name : " + myCat.nameCat
                popUpCatName.open()
            }

        }
    }

    Popup {
        id: popUpCatName
        width: 300
        height: 100
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        anchors.centerIn: parent

        Label {
            id: lbNewName
            text: myCat.nameCat //Ca va actualiser automatiquement le nom quand on va le changer.
            anchors.centerIn: parent
        }
    }

    Column {
        id: column
        x: 170
        y: 111
        width: 300
        height: 226
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25

        Label {
            id: lnName
            text: qsTr("Name")
        }

        TextField {
            id: tfName
            width: 300
            text: "Donne un nom à ton chat :)"
        }

        Button {
            id: btChange
            text: qsTr("Change")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                console.log("Click on change the name");
                //nameCat c'est le nom de la propriété définie das cat.h
                //Q_PROPERTY(QString nameCat READ name WRITE setName NOTIFY nameChanged)
                //Le fait de la renseigner provoque l'appel à la fonction setName().
                //Ensuite emission du signal onNameChanged().
                if(tfName.text !== "" && tfName.text !== "Donne un nom à ton chat :)")
                {
                   myCat.nameCat = tfName.text;
                } else if (myCat.nameCat != "") {
                   tfName.text =  myCat.nameCat
                }

            }
        }

        Button {
            id: btCall
            text: qsTr("Call")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                console.log("Click on call the cat");
                myCat.call();
            }
        }
    }

}
