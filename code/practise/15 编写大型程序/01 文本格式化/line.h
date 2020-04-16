#ifndef LINE_H
#define LINE_H

/********************************************************
*
*	clear_line:	Clears the current line.
*
*********************************************************/
void clear_line();


/********************************************************
*
*	add_word: Adds word to the end of current line.
*			  If this is not the first word on the line,
*			  puts one space before word.
*
*********************************************************/
void add_word(const char* word);


/********************************************************
*
* space_remaining: Returns the number of characters left 
*				   in the current line.
*
*********************************************************/
int space_remaining();


/********************************************************
*
* write_line: Writes the current line with justification.
*
*********************************************************/
void write_line();


/********************************************************
*
* flush_line: Write the current line without 
*			  justification.If the line is empty,
*			  does nothing.
*
*********************************************************/
void flush_line(void);

#endif