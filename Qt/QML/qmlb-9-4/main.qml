import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")
    id: root
    property string name: ""

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        //Editor
        Page1Form {
            id: page1
            Component.onCompleted: {
                nameEditor = root.name
            }
        }

        //Display
        Page2Form {
            id: page2
        }

        onCurrentIndexChanged: {
            console.log(currentIndex)

            //Page 1
            if(currentIndex === 0 && page1.nameEditor !== "") {
                root.name = page2.nameDisplay
                page1.nameEditor = root.name
            }

            //Page 2
            if(currentIndex === 1) {
                root.name = page1.nameEditor
                page2.nameDisplay = root.name
            }
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
