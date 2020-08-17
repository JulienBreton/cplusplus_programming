#ifndef WINDOWTABLESETTINGS_H
#define WINDOWTABLESETTINGS_H

#include <QDialog>
#include <QSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QGroupBox>
#include <QDialogButtonBox>

class WindowTableSettings : public QDialog
{
public:
    WindowTableSettings();
    WindowTableSettings(int rows, int columnns);
    int getNumberOfRows();
    int getNumberOfColumns();

private:

    QGroupBox *formGroupBox;
    QSpinBox *m_Rows;
    QSpinBox *m_Columns;
    QDialogButtonBox *m_buttonBox;
};

#endif // WINDOWTABLESETTINGS_H
