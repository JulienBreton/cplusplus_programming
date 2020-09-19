import QtQuick 2.15
import QtQuick.Window 2.14
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.5
import com.company.backend 1.0

ApplicationWindow {

    id: root
    width: 1024
    height: 600
    title: qsTr("QML Markdown Editor")
    visibility: Window.Maximized
    visible: true

    //If the window is not maximized when the application starts the window will
    //be in the center of the screen.
    Component.onCompleted: {
        x = Screen.width / 2 - width / 2
        y = Screen.height / 2 - height / 2
    }

    Popup {
        id: tablePopUp
        anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        GridLayout {
            id: grid
            columns: 2
            rows: 3
            rowSpacing: 20
            columnSpacing: 20

            Text {
                text: qsTr("Rows : ")
            }

            SpinBox {
                id: tableRows
                from: 1
            }

            Text {
                text: qsTr("Columns : ")
            }

            SpinBox {
                id: tableColumns
                from: 1
            }

            Button {
                id: closeButton
                text: qsTr("Cancel")

                onClicked: {
                    tablePopUp.close()
                }
            }

            Button {
                id: addButton
                text: qsTr("Add table")
                Layout.alignment: Qt.AlignRight
                onClicked: {
                    tablePopUp.close()

                    backend.insertTable(tableRows.value, tableColumns.value)
                }
            }

        }
    }

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

    FontDialog {
        id: fontDialog
        onAccepted: {
            backend.fontFamily = font.family;
            backend.fontSize = font.pointSize;
        }
    }

    ColorDialog {
        id: colorDialog
        currentColor: "black"
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

            backend.myMessage =
                    "<ul><li>Item 1</li><li>Item 2</li><li>Item 3</li></ul>"
            textEdit.insert(textEdit.cursorPosition, backend.myMessage)
        }
    }

    Action {
        id: actionBold
        text: qsTr("Bold")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/bold.svg"
        onTriggered: backend.bold = !backend.bold
        checkable: true
        checked: backend.bold
    }

    Action {
        id: actionItalic
        text: qsTr("Italic")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/italic.svg"
        onTriggered:  backend.italic = !backend.italic
        checkable: true
        checked: backend.italic
    }

    Action {
        id: actionUnderline
        text: qsTr("Underline")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/underline.svg"
        onTriggered: backend.underline = !backend.underline
        checkable: true
        checked: backend.underline
    }

    Action {
        id: actionStrick
        text: qsTr("Strick")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/italic.svg"
        onTriggered: backend.strick = !backend.strick
        checkable: true
        checked: backend.strick
    }

    /*Action {
        id: actionChecked
        text: qsTr("checked")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/textbold.png"
        onTriggered: backend.listChecked = !backend.listChecked
        checkable: true
        checked: backend.listChecked
    }*/

    Action {
        id: actionTable
        text: qsTr("add table")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/grid.svg"
        onTriggered: {
            tablePopUp.open()
        }

        checkable: true
    }

    Action {
        id: actionSize
        text: qsTr("Size")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/size_plus.svg"
        onTriggered: {

            backend.fontSize++
        }

        checkable: true
        //checked: backend.fontSize
    }

    Action {
        id: actionSizeMenus
        text: qsTr("Size")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/size_menus.svg"
        onTriggered: {

            backend.fontSize--
        }

        checkable: true
        //checked: backend.fontSize
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

        RowLayout{

            ToolButton
            {display: AbstractButton.IconOnly; action: actionNew}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionOpen}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionSave}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionCopy}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionCut}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionPaste}
            //ToolButton
            //{display: AbstractButton.IconOnly; action: actionToggleCheckState}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionBold}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionItalic}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionUnderline}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionStrick}
            //ToolButton
            //{display: AbstractButton.IconOnly; action: actionChecked}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionTable}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionSize}
            ToolButton
            {display: AbstractButton.IconOnly; action: actionSizeMenus}

            /*ToolButton {
                id: fontFamilyToolButton
                text: qsTr("\uE808") // icon-font
                font.family: "fontello"
                font.bold: backend.bold
                font.italic: backend.italic
                font.underline: backend.underline
                onClicked: {
                    fontDialog.currentFont.family = backend.fontFamily;
                    fontDialog.currentFont.pointSize = backend.fontSize;
                    fontDialog.open();
                }
            }
            ToolButton {
                id: textColorButton
                text: "\uF1FC" // icon-brush
                font.family: "fontello"
                focusPolicy: Qt.TabFocus
                onClicked: colorDialog.open()

                Rectangle {
                    width: aFontMetrics.width + 3
                    height: 2
                    color: backend.textColor
                    parent: textColorButton.contentItem
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.baseline: parent.baseline
                    anchors.baselineOffset: 6

                    TextMetrics {
                        id: aFontMetrics
                        font: textColorButton.font
                        text: textColorButton.text
                    }
                }
            }*/
            /*ToolSeparator {
                contentItem.visible: formatRow.y === alignRow.y
            }*/

            Row{
                ComboBox {
                    property bool sizeToContents
                    property int modelWidth

                    width: (sizeToContents) ? modelWidth + 2*leftPadding
                                              + 2*rightPadding : implicitWidth

                    model:
                        ["Standard",
                        "Bullet List (Disc)", "Bullet List (Circle)",
                        "Bullet List (Square)",
                        "Task List (Unchecked)", "Task List (Checked)",
                        "Ordered List (Decimal)", "Ordered List (Alpha lower)",
                        "Ordered List (Alpha upper)",
                        "Ordered List (Roman lower)",
                        "Ordered List (Roman upper)",
                        "Heading 1", "Heading 2", "Heading 3", "Heading 4",
                        "Heading 5", "Heading 6"]

                    id: comboStyle
                    sizeToContents: true
                    onActivated: {
                        //console.log(currentIndex)
                        backend.indexTextStyle = currentIndex
                    }

                    TextMetrics {
                        id: textMetrics
                    }

                    onModelChanged: {
                        textMetrics.font = comboStyle.font
                        for(var i = 0; i < model.length; i++){
                            textMetrics.text = model[i]
                            modelWidth = Math.max(textMetrics.width, modelWidth)
                        }
                    }
                }
            }
        }


    }

    ScrollView {
        anchors.fill: parent
        TextArea {
            id: textEdit
            textFormat: TextEdit.MarkdownText
            //textFormat: TextEdit.RichText
            focus: true
            //text: ""
            selectByMouse: true
            persistentSelection: true
        }

    }
}
