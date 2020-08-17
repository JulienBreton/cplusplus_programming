#include "table.h"

Table::Table()
{
    m_rows = 0;
    m_columns = 0;
}

int Table::tableRows()
{
    return m_rows;
}

void Table::setTableRows(int row)
{
    m_rows = row;
}

int Table::tableColumns()
{
    return m_columns;
}

void Table::setTableColumns(int columns)
{
    m_columns = columns;
}
