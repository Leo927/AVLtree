//
//  Buffer.h
//
//  A module to represent the display buffer.
//

#pragma once




//
//  Buffer
//
//  A class to represent the display buffer.
//
template<int BUFFER_ROW_COUNT, int BUFFER_COLUMN_COUNT>
class Buffer
{
public:
	//
	//  Default Constructor
	//
	//  Purpose: To create a new, empty Buffer.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: A new Buffer is created with a current
	//               offset of row 0 and column 0.  All elements
	//               of the buffer are set to EMPTY.
	//
	Buffer ();

	//
	//  print
	//
	//  Purpose: To display the contents of this Buffer.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The current contents of this Buffer are
	//               printed, surrounded by a border of BORDER
	//               characters.
	//
	void print () const;

	//
	//  clear
	//
	//  Purpose: To clear this Buffer.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The contents of this Buffer are replaced
	//               with EMPTY characters.  The current
	//               offset is not changed.
	//
	void clear ();

	//
	//  setOffset
	//
	//  Purpose: To change the current offset for this Buffer to
	//           the specified row aand column.
	//  Parameter(s):
	//    <1> row_offset1: The new row offset
	//    <2> column_offset1: The new column offset
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The currrent offset is set to row
	//               row_offset1 and column column_offset1.  The
	//               current buffer contents are not affected.
	//
	void setOffset (int row_offset1, int column_offset1);

	//
	//  setCell
	//
	//  Purpose: To set a character in this Buffer at the
	//           specified row and column.
	//  Parameter(s):
	//    <1> row: The row of the character to change
	//    <2> column: The column of the character to change
	//    <3> value: The new character value
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The character at row row and column column,
	//               taking the current offset into account, is
	//               changed to value.
	//
	void setCell (int row, int column, char value);

private:
	char contents[BUFFER_ROW_COUNT][BUFFER_COLUMN_COUNT];
	int row_offset;
	int column_offset;
};
