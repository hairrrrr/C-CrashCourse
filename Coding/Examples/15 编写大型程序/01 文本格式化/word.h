#ifndef WORD_H
#define WORD_H

/***********************************************************************
*
*	read_word: Read the next word from the input and stores it in word.
*			   Make word empty if no word could be read because of EOF.
*			   Truncates the word if its length exceeds len.
*
************************************************************************/

void read_word(char* word, int len);

#endif