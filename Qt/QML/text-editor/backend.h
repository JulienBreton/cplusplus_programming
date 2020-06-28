#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTextCursor>
#include <QQuickItem>
#include <QQuickTextDocument>
#include <QTextList>

class Backend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQuickItem *target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(int cursorPosition READ cursorPosition WRITE setCursorPosition NOTIFY cursorPositionChanged)
    Q_PROPERTY(int selectionStart READ selectionStart WRITE setSelectionStart NOTIFY selectionStartChanged)
    Q_PROPERTY(int selectionEnd READ selectionEnd WRITE setSelectionEnd NOTIFY selectionEndChanged)

    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)
    Q_PROPERTY(QString myMessage READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(bool bold READ bold WRITE setBold NOTIFY boldChanged)
    Q_PROPERTY(bool listChecked READ checked WRITE setChecked NOTIFY checkedChanged)

    Q_PROPERTY(int indexTextStyle READ currentTextStyle WRITE textStyle NOTIFY textStyleChanged)
    //Q_PROPERTY(bool listStyle READ listStyle WRITE getListStyle NOTIFY listStyleChanged)


public:
    explicit Backend(QObject *parent = nullptr);

    QQuickItem *target() { return m_target; }

    void setCursorPosition(int position);
    void setSelectionStart(int position);
    void setSelectionEnd(int position);

    int cursorPosition() const { return m_cursorPosition; }
    int selectionStart() const { return m_selectionStart; }
    int selectionEnd() const { return m_selectionEnd; }

    void setTarget(QQuickItem *target);

    QString path();
    void setPath(QString value);
    QString data();
    void setData(QString value);
    QString message();
    void setMessage(QString message);
    bool bold() const;
    bool checked() const;
    int currentTextStyle();
    void setCurrentTextStyle(int currentIndexStyleBox);

    void sayHelloFromCpp(){
           qDebug() << "Hello you have called this function from C++";
    };

public Q_SLOTS:
    void setBold(bool arg);
    void setChecked(bool checked);

private Q_SLOTS:
    void textStyle(int styleIndex);

Q_SIGNALS:
    void targetChanged();
    void cursorPositionChanged();
    void selectionStartChanged();
    void selectionEndChanged();

    void pathChanged();
    void dataChanged();
    void messageChanged();
    void boldChanged();
    void checkedChanged();
    void textStyleChanged();

private:
    QTextCursor textCursor() const;
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void reset();

    QQuickItem *m_target;

    QString m_path;
    QString m_message;

    QTextDocument *m_doc;

    int m_cursorPosition;
    int m_selectionStart;
    int m_selectionEnd;

    int m_currentTextStyle;

};

#endif // BACKEND_H
