//
//  Buffer.cpp
//

#include <iostream>

#include "Buffer.h"

using namespace std;

static const char BORDER = '#';
static const char EMPTY  = ' ';


template<int BUFFER_ROW_COUNT, int BUFFER_COLUMN_COUNT>
Buffer<BUFFER_ROW_COUNT,BUFFER_COLUMN_COUNT> :: Buffer ()
		// contents will be initialized by clear below
		: row_offset(0),
		  column_offset(0)
{
	clear();
}

template<int BUFFER_ROW_COUNT, int BUFFER_COLUMN_COUNT>
void Buffer<BUFFER_ROW_COUNT,BUFFER_COLUMN_COUNT> :: print () const
{
	cout << BORDER;
	for(int r = 0; r < BUFFER_COLUMN_COUNT; r++)
		cout << BORDER;
	cout << BORDER << endl;

	for(int r = 0; r < BUFFER_ROW_COUNT; r++)
	{
		cout << BORDER;
		for(int c = 0; c < BUFFER_COLUMN_COUNT; c++)
		{
			cout << contents[r][c];
		}
		cout << BORDER << endl;
	}

	cout << BORDER;
	for(int r = 0; r < BUFFER_COLUMN_COUNT; r++)
		cout << BORDER;
	cout << BORDER << endl;
}


template<int BUFFER_ROW_COUNT, int BUFFER_COLUMN_COUNT>
void Buffer<BUFFER_ROW_COUNT,BUFFER_COLUMN_COUNT> :: clear ()
{
	for(int r = 0; r < BUFFER_ROW_COUNT; r++)
	{
		for(int c = 0; c < BUFFER_COLUMN_COUNT; c++)
		{
			contents[r][c] = EMPTY;
		}
	}
}
template<int BUFFER_ROW_COUNT, int BUFFER_COLUMN_COUNT>
void Buffer<BUFFER_ROW_COUNT,BUFFER_COLUMN_COUNT> :: setOffset (int row_offset1, int column_offset1)
{
	row_offset    = row_offset1;
	column_offset = column_offset1;
}
template<int BUFFER_ROW_COUNT, int BUFFER_COLUMN_COUNT>
void Buffer<BUFFER_ROW_COUNT,BUFFER_COLUMN_COUNT> :: setCell (int row, int column, char value)
{
	row    -= row_offset;
	column -= column_offset;

	if(row    >= 0 && row    < BUFFER_ROW_COUNT &&
	   column >= 0 && column < BUFFER_COLUMN_COUNT)
	{
		contents[row][column] = value;
	}
}


