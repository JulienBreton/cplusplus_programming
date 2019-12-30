#include "windowtablesettings.h"

WindowTableSettings::WindowTableSettings()
{
    m_buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(m_buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(m_buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    formGroupBox = new QGroupBox(tr("Form layout"));

    QFormLayout *layout = new QFormLayout;

    m_Rows = new QSpinBox;
    m_Rows->setMinimum(1);
    m_Columns = new QSpinBox;
    m_Columns->setMinimum(1);
    layout->addRow(new QLabel(tr("Rows :")), m_Rows);
    layout->addRow(new QLabel(tr("Columns :")), m_Columns);
    layout->addWidget(m_buttonBox);

    setLayout(layout);
    setWindowTitle(tr("Table"));
}

WindowTableSettings::WindowTableSettings(int rows, int columnns)
{
    m_buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(m_buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(m_buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    formGroupBox = new QGroupBox(tr("Form layout"));

    QFormLayout *layout = new QFormLayout;

    m_Rows = new QSpinBox;
    m_Rows->setMinimum(1);
    m_Rows->setValue(rows);
    m_Columns = new QSpinBox;
    m_Columns->setMinimum(1);
    m_Columns->setValue(columnns);
    layout->addRow(new QLabel(tr("Rows :")), m_Rows);
    layout->addRow(new QLabel(tr("Columns :")), m_Columns);
    layout->addWidget(m_buttonBox);

    setLayout(layout);
    setWindowTitle(tr("Table"));
}

int WindowTableSettings::getNumberOfRows()
{
    return m_Rows->value();
}

int WindowTableSettings::getNumberOfColumns()
{
    return m_Columns->value();
}
