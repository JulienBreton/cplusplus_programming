import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")
    id: root

    property string nameRoot: "Bryan"

    //https://doc.qt.io/qt-5/qml-var.html#property-value-initialization-semantics
    property var page1: ({}) // empty object
    property var page2: ({}) // empty object

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

//        Page1Form {
//        }

//        Page2Form {
//        }

        Component.onCompleted: {
            //Once we learn javascript we can add function

            var component1 = Qt.createComponent("Page1Form.ui.qml")
            page1 = component1.createObject(swipeView,{nameEditor: root.nameRoot})
            addItem(page1)

            var component2 = Qt.createComponent("Page2Form.ui.qml")
            page2 = component2.createObject(swipeView,{nameDisplay: root.nameRoot})

            addItem(page2)
        }

        onCurrentIndexChanged: {
            //console.log(page2.nameDisplay)

           if(currentIndex === 0 && page2.nameDisplay) {
                root.nameRoot = page2.nameDisplay
                page1.nameEditor = root.nameRoot
            }

            /*if(currentIndex === 1) {
                root.nameRoot = page1.nameEditor
                page2.nameDisplay = root.nameRoot
            }*/
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }
}
