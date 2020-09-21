#include "backend.h"

Backend::Backend(QObject *parent) : QObject(parent)
  , m_target(0)
  , m_doc(0)
  , m_cursorPosition(-1)
  , m_selectionStart(0)
  , m_selectionEnd(0)
  , m_tableRow(0)
  , m_tableColumn(0)
{
    m_path = QCoreApplication::applicationDirPath();
    m_path.append("/file.txt");
}

void Backend::setCursorPosition(int position)
{
    if (position == m_cursorPosition)
        return;

    m_cursorPosition = position;

    reset();
}

void Backend::setSelectionStart(int position)
{
    m_selectionStart = position;
}

void Backend::setSelectionEnd(int position)
{
    m_selectionEnd = position;
}

void Backend::setTarget(QQuickItem *target)
{
    m_doc = 0;
    m_target = target;
    if (!m_target)
        return;

    QVariant doc = m_target->property("textDocument");
    if (doc.canConvert<QQuickTextDocument*>()) {
        QQuickTextDocument *qqdoc = doc.value<QQuickTextDocument*>();
        if (qqdoc)
            m_doc = qqdoc->textDocument();
    }
    emit targetChanged();
}

QString Backend::path()
{
    return m_path;
}

void Backend::setPath(QString value)
{
    m_path = value;
    m_path.remove("file://");
    emit pathChanged();
}

QString Backend::data()
{
    QFile file(m_path);
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "data : could not read file!";
        return "";
    }
    QTextStream stream(&file);
    QString value = stream.readAll();
    file.close();
    return value;
}

void Backend::setData(QString value)
{
    QFile file(m_path);
    if(!file.open(QIODevice::WriteOnly)) {
        qWarning() << "setData : Could not read file!";
    }
    QTextStream stream(&file);
    stream << value;
    stream.flush();
    file.close();

    emit dataChanged();
}

QString Backend::message()
{
    return m_message;
}

void Backend::setMessage(QString message)
{
    m_message = message;
    qDebug() << m_message;
    emit messageChanged();
}

bool Backend::italic() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return false;

    return textCursor().charFormat().fontItalic();
}

bool Backend::strick() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return false;
    return textCursor().charFormat().fontStrikeOut();
}

bool Backend::bold() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return false;
    return textCursor().charFormat().fontWeight() == QFont::Bold;
}

bool Backend::checked() const
{
    return false;
    /*QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return false;
    return textCursor().currentList()->format().style() == QTextListFormat::lis*/
}

int Backend::currentTextStyle()
{
    return m_currentTextStyle;
}

void Backend::setBold(bool arg)
{
    if(!strick())
    {
        QTextCharFormat fmt;
        fmt.setFontWeight(arg ? QFont::Bold : QFont::Normal);
        mergeFormatOnWordOrSelection(fmt);
        emit boldChanged();
    }
}

void Backend::setItalic(bool italic)
{
    if(!strick())
    {
        QTextCharFormat format;
        format.setFontItalic(italic);
        mergeFormatOnWordOrSelection(format);
        emit italicChanged();
    }
}

void Backend::setStrick(bool strick)
{
    if(!bold() && !italic())
    {
        QTextCharFormat format;
        format.setFontStrikeOut(strick);
        mergeFormatOnWordOrSelection(format);
        emit strickChanged();
    }
}

void Backend::setCurrentTextStyle(int currentIndexStyleBox){
    m_currentTextStyle = currentIndexStyleBox;
    qDebug() << "Le style est : " << m_currentTextStyle;
    emit textStyleChanged();
}

QTextCursor Backend::textCursor() const
{
    if (!m_doc)
        return QTextCursor();

    QTextCursor cursor = QTextCursor(m_doc);
    if (m_selectionStart != m_selectionEnd) {
        cursor.setPosition(m_selectionStart);
        cursor.setPosition(m_selectionEnd, QTextCursor::KeepAnchor);
    } else {
        cursor.setPosition(m_cursorPosition);
    }
    return cursor;
}

void Backend::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
}

void Backend::reset()
{
    emit fontFamilyChanged();
    //emit alignmentChanged();
    emit boldChanged();
    emit checkedChanged();
    emit italicChanged();
    emit strickChanged();
    emit textColorChanged();
}

void Backend::setChecked(bool checked)
{
    QTextCursor cursor = textCursor();
    QTextListFormat::Style style = QTextListFormat::ListStyleUndefined;
    QTextBlockFormat::MarkerType marker = QTextBlockFormat::MarkerType::NoMarker;

    style = QTextListFormat::ListDecimal;

    /*if (cursor.currentList()){
        style = cursor.currentList()->format().style();
        qDebug() << "Le style est : " << style;
    }
    else{
        style = QTextListFormat::ListSquare;
    }*/

    //Permet d'afficher la checkbox non cochée
    //https://doc.qt.io/qt-5/qtextblockformat.html#MarkerType-enum
    marker = QTextBlockFormat::MarkerType::Unchecked;

    cursor.beginEditBlock();

    QTextBlockFormat blockFmt = cursor.blockFormat();

        blockFmt.setMarker(marker);
        cursor.setBlockFormat(blockFmt);
        QTextListFormat listFmt;
        if (cursor.currentList()) {
            listFmt = cursor.currentList()->format();
        } else {
            listFmt.setIndent(blockFmt.indent() + 1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);
   // }

    cursor.endEditBlock();

    emit checkedChanged();
}

void Backend::textStyle(int styleIndex)
{
    QTextCursor cursor = textCursor();
    QTextListFormat::Style style = QTextListFormat::ListStyleUndefined;
    QTextBlockFormat::MarkerType marker = QTextBlockFormat::MarkerType::NoMarker;

    switch (styleIndex) {
    case 1:
        style = QTextListFormat::ListDisc;
        break;
    case 2:
        style = QTextListFormat::ListCircle;
        break;
    case 3:
        style = QTextListFormat::ListSquare;
        break;
    case 4:
        if (cursor.currentList())
            style = cursor.currentList()->format().style();
        else
            style = QTextListFormat::ListSquare;
        marker = QTextBlockFormat::MarkerType::Unchecked;
        break;
    case 5:
        if (cursor.currentList())
            style = cursor.currentList()->format().style();
        else
            style = QTextListFormat::ListSquare;
        marker = QTextBlockFormat::MarkerType::Checked;
        break;
    case 6:
        style = QTextListFormat::ListDecimal;
        break;
    case 7:
        style = QTextListFormat::ListLowerAlpha;
        break;
    case 8:
        style = QTextListFormat::ListUpperAlpha;
        break;
    case 9:
        style = QTextListFormat::ListLowerRoman;
        break;
    case 10:
        style = QTextListFormat::ListUpperRoman;
        break;
    default:
        break;
    }

    cursor.beginEditBlock();

    QTextBlockFormat blockFmt = cursor.blockFormat();

    if (style == QTextListFormat::ListStyleUndefined) {
        blockFmt.setObjectIndex(-1);
        int headingLevel = styleIndex >= 11 ? styleIndex - 11 + 1 : 0; // H1 to H6, or Standard
        blockFmt.setHeadingLevel(headingLevel);
        cursor.setBlockFormat(blockFmt);

        int sizeAdjustment = headingLevel ? 4 - headingLevel : 0; // H1 to H6: +3 to -2
        QTextCharFormat fmt;
        fmt.setFontWeight(headingLevel ? QFont::Bold : QFont::Normal);
        fmt.setProperty(QTextFormat::FontSizeAdjustment, sizeAdjustment);
        cursor.select(QTextCursor::LineUnderCursor);
        cursor.mergeCharFormat(fmt);
        //textEdit->mergeCurrentCharFormat(fmt);
    } else {
        blockFmt.setMarker(marker);
        cursor.setBlockFormat(blockFmt);
        QTextListFormat listFmt;
        if (cursor.currentList()) {
            listFmt = cursor.currentList()->format();
        } else {
            listFmt.setIndent(blockFmt.indent() + 1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);
    }

    cursor.endEditBlock();
}

void Backend::insertTable(int r, int c)
{
    QTextCursor cursor;
    cursor = textCursor();
    bool result = false;

    QTextTable * table = cursor.currentTable();
    /*this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(table, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(ShowContextMenu(const QPoint &)));*/

    if (table != nullptr)
    {
       //tableSettings = new WindowTableSettings(table->rows(), table->columns());
       //tableSettings->exec();
       table->resize(r, c);
    }
    else
    {
        //tableSettings = new WindowTableSettings;
        //result = tableSettings->exec();

        //if(result)
        //{
            if(table == nullptr)
            {
                /*QTextTableFormat tableFormat;
                tableFormat.setBackground(QColor("#e0e0e0"));
                QVector<QTextLength> constraints;
                constraints << QTextLength(QTextLength::PercentageLength, 16);
                constraints << QTextLength(QTextLength::PercentageLength, 28);
                constraints << QTextLength(QTextLength::PercentageLength, 28);
                constraints << QTextLength(QTextLength::PercentageLength, 28);
                tableFormat.setColumnWidthConstraints(constraints);*/
                cursor = textCursor();
                cursor.insertTable(r, c);
            }
        //}
    }
}

int Backend::tableRows()
{
    return m_tableRow;
}

void Backend::setTableRows(int nbrOfRows)
{
    m_tableRow = nbrOfRows;
    qDebug() << "Nbr de lignes" << m_tableRow;
    //insertTable();
    //emit insertTable();
}

int Backend::tableColumns()
{
    return m_tableColumn;
}

void Backend::setTableColumns(int nbrOfColumns)
{
    m_tableColumn = nbrOfColumns;
    qDebug() << "Nbr de colonnes" << m_tableColumn;
    //insertTable();
}

QString Backend::fontFamily() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return QString();
    QTextCharFormat format = cursor.charFormat();
    return format.font().family();
}

void Backend::setFontFamily(const QString &family)
{
    QTextCharFormat format;
    format.setFontFamily(family);
    mergeFormatOnWordOrSelection(format);
    emit fontFamilyChanged();
}

QColor Backend::textColor() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return QColor(Qt::black);
    QTextCharFormat format = cursor.charFormat();
    return format.foreground().color();
}

void Backend::setTextColor(const QColor &color)
{
    QTextCharFormat format;
    format.setForeground(QBrush(color));
    mergeFormatOnWordOrSelection(format);
    emit textColorChanged();
}

