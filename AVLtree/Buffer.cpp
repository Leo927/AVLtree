//
//  Buffer.cpp
//

#include <iostream>

#include "Buffer.h"

using namespace std;

static const char BORDER = '#';
static const char EMPTY = ' ';



Buffer::Buffer()
// contents will be initialized by clear below
{
	row_offset = 0;
	column_offset = 0;
	rowCount = 0;
	columnCount = 0;
	clear();
}

Buffer::Buffer(size_t rows_, size_t columns_)
{
	rowCount = rows_;
	columnCount = columns_;
	row_offset = 0;
	column_offset = 0;
	for (size_t i = 0; i < rows_; i++)
	{
		contents.at(i) = std::vector<char>(columns_, EMPTY);
	}
}


void Buffer::print() const
{
	cout << BORDER;
	for (int r = 0; r < rowCount; r++)
		cout << BORDER;
	cout << BORDER << endl;

	for (int r = 0; r < columnCount; r++)
	{
		cout << BORDER;
		for (int c = 0; c < rowCount; c++)
		{
			cout << contents[r][c];
		}
		cout << BORDER << endl;
	}

	cout << BORDER;
	for (int r = 0; r < rowCount; r++)
		cout << BORDER;
	cout << BORDER << endl;
}



void Buffer::clear()
{
	for (int r = 0; r < columnCount; r++)
	{
		for (int c = 0; c < rowCount; c++)
		{
			contents[r][c] = EMPTY;
		}
	}
}

void Buffer::setOffset(int row_offset1, int column_offset1)
{
	row_offset = row_offset1;
	column_offset = column_offset1;
}

void Buffer::setCell(int row, int column, char value)
{
	row -= row_offset;
	column -= column_offset;

	if (row >= 0 && row < columnCount &&
		column >= 0 && column < rowCount)
	{
		contents[row][column] = value;
	}
}

const std::vector<char>& Buffer::operator[](int _row) const
{
	return contents.at(_row);
}

std::vector<char>& Buffer::operator[](int _row)
{
	return contents.at(_row);
}


