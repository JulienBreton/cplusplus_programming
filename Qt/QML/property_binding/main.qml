import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: fenetre
    visible: true
    width: 400
    height: 200
    title: qsTr("Hello World")

    Rectangle {
        id: monRectangle
        width: fenetre.width; height: fenetre.height;
        color: "lightblue"

        MouseArea {
            id: principale
            anchors.fill: parent
            width: monRectangle.width
            height: monRectangle.height
        }

        Text {
            id: monTexte
            anchors.centerIn: parent
            text: "Press me"; font.pixelSize: 48
            color:{
                if(principale.pressed){
                    color: "purple"
                }
                else if(secondaire.pressed){
                    color: "yellow"
                }
                else{
                    color: "black"
                }
             }

            MouseArea {
                id: secondaire
                anchors.fill: monTexte
                width: monTexte.with
                height: monTexte.height
                //Si on change la couleur en cliquant dans cette MouseArea
                //alors il n'est plus possible de modifier la couleur du texte.
                //onPressed: monTexte.color = "red"
                //onReleased: monTexte.color = "yellow"
            }
        }
    }

}
