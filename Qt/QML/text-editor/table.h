#ifndef TABLE_H
#define TABLE_H

#include <QObject>

class Table
{

    Q_PROPERTY(int tableRows READ tableRows WRITE setTableRows)
    Q_PROPERTY(int tableColumns READ tableColumns WRITE setTableColumns)

public:
    Table();

    int tableRows();
    void setTableRows(int rows);

    int tableColumns();
    void setTableColumns(int columns);

private:

    int m_rows;
    int m_columns;

};

#endif // TABLE_H
