import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import com.company.backend 1.0

ApplicationWindow {

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Backend {
        id: backend
        target: textEdit
        cursorPosition: textEdit.cursorPosition
        selectionStart: textEdit.selectionStart
        selectionEnd: textEdit.selectionEnd
        //indexTextStyle: textEdit.
        //onPathChanged: console.log("Path:", path)
        //onDataChanged: console.log("Path:", path)
    }

    FileDialog {
        id: openDialog
        title: qsTr("Please choose a file")
        folder: shortcuts.home
        selectMultiple: false
        selectExisting: true

        onAccepted: {
            backend.path = openDialog.fileUrl
            textEdit.text = backend.data
        }
    }

    FileDialog {
        id: saveDialog
        title: qsTr("Please choose a file")
        folder: shortcuts.home
        selectMultiple: false
        selectExisting: false

        onAccepted: {
            backend.path = saveDialog.fileUrl
            backend.data = textEdit.text
        }
    }

    Action {
        id: actionNew
        text: qsTr("New")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oNew.png"
        onTriggered: textEdit.clear()
    }

    Action {
        id: actionOpen
        text: qsTr("Open")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oOpen.png"
        onTriggered: openDialog.open()
    }

    Action {
        id: actionSave
        text: qsTr("Save")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oSave.png"
        onTriggered: saveDialog.open()
    }

    Action {
        id: actionCopy
        text: qsTr("Copy")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oCopy.png"
        onTriggered: textEdit.copy()
    }

    Action {
        id: actionCut
        text: qsTr("Cut")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oCut.png"
        onTriggered: textEdit.cut()
    }

    Action {
        id: actionPaste
        text: qsTr("Paste")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oPaste.png"
        onTriggered: textEdit.paste()
    }

    Action {
        id: actionToggleCheckState
        text: qsTr("Checked")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/checkbox-checked.png"
        onTriggered: {

            backend.myMessage = "<ul><li>Item 1</li><li>Item 2</li><li>Item 3</li></ul>"
            textEdit.insert(textEdit.cursorPosition, backend.myMessage)
        }
    }

    Action {
        id: actionBold
        text: qsTr("Bold")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/textbold.png"
        onTriggered: backend.bold = !backend.bold
        checkable: true
        checked: backend.bold
    }

    Action {
        id: actionChecked
        text: qsTr("checked")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/textbold.png"
        onTriggered: backend.listChecked = !backend.listChecked
        checkable: true
        checked: backend.listChecked
    }

    //To do - add actions

    menuBar: MenuBar {
        Menu {
            id: menuFile
            title: qsTr("File")
            MenuItem { action : actionNew }
            MenuItem { action : actionOpen }
            MenuItem { action : actionSave }
        }

        Menu {
            id: menuEdit
            title: qsTr("Edit ")
            MenuItem { action : actionCopy }
            MenuItem { action : actionCut }
            MenuItem { action : actionPaste }
        }
    }

    header: ToolBar {
        Row {
            ToolButton {display: AbstractButton.IconOnly; action: actionNew}
            ToolButton {display: AbstractButton.IconOnly; action: actionOpen}
            ToolButton {display: AbstractButton.IconOnly; action: actionSave}
            ToolButton {display: AbstractButton.IconOnly; action: actionCopy}
            ToolButton {display: AbstractButton.IconOnly; action: actionCut}
            ToolButton {display: AbstractButton.IconOnly; action: actionPaste}
            //ToolButton {display: AbstractButton.IconOnly; action: actionToggleCheckState}
            ToolButton {display: AbstractButton.IconOnly; action: actionBold}
            //ToolButton {display: AbstractButton.IconOnly; action: actionChecked}

            ComboBox {
                model: ["Standard", "Bullet List (Disc)", "Bullet List (Circle)", "Bullet List (Square)",
                "Task List (Unchecked)", "Task List (Checked)", "Ordered List (Decimal)", "Ordered List (Alpha lower)",
                "Ordered List (Alpha upper)", "Ordered List (Roman lower)", "Ordered List (Roman upper)",
                "Heading 1", "Heading 2", "Heading 3", "Heading 4", "Heading 5", "Heading 6"]

                id: comboStyle
                onActivated: {
                    //console.log(currentIndex)
                    backend.indexTextStyle = currentIndex
                }
            }
        }
    }

    ScrollView {
        anchors.fill: parent
        TextArea {
            id: textEdit
            textFormat: TextEdit.MarkdownText
            focus: true
            //text: "It's very easy to make some words **bold** and other words *italic* with Markdown. You can even [link to Google!](http://google.com)"
            selectByMouse: true
            persistentSelection: true


        }
    }

}
