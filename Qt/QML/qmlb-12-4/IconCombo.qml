import QtQuick 2.0
import QtQuick.Controls 2.3

//Owner draw a Component
//https://doc.qt.io/qt-5/qtquickcontrols2-customize.html

ComboBox {
    id: root
    padding: 5

    model: ListModel {
        id: lesIcones
        ListElement { src: "qrc:/images/icon.png"; nomIco: "Calendrier" }
        ListElement { src: "qrc:/images/www.png"; nomIco: "WWW" }
    }

    contentItem: Row {
        spacing: 5
        width: root.width

        Image {
            fillMode: Image.PreserveAspectFit
            source: lesIcones.get(currentIndex).src
            width: 30
            height: 30
        }

        //Add the Text
        Text {
            text: lesIcones.get(currentIndex).nomIco
            color: "black"
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
        }
    }

    delegate: ItemDelegate {

        width: root.width
        highlighted: highlightedIndex === index

        contentItem: Row {
            spacing: 5
            width: root.width

            Image {
                fillMode: Image.PreserveAspectFit
                source: src
                width: 30
                height: 30
            }

            //Add the Text
            Text {
                text: nomIco
                color: "black"
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
            }
        }

    }
}
