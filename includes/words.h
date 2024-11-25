/*
  Header file for Words utility program
  @Author Jeremy Hawkins <coraxwolf@gmail.com>
  @Date 11/25/2024
  @Description Utilities for creating internal word list and updated/managing wordlist
*/

#ifndef WORD_FUNCTIONS
#define WORD_FUNCTIONS

/* Word List and Word Types */
/* Word List. Listing of Words */
struct word_list
{
  word_list_entry *first_word;
  int size;
};

typedef word_list WordList;

/* Word List Entry. Entry for a single word in a word list */
struct word_list_entry
{
  struct word *word;
  struct word_list_entry *next;
};

typedef word_list_entry WordListEntry;

/* Word Data Structure. This repesents one word */
struct word
{
  char *word;
  int size;
};

typedef word Word;

/* Word Utility Functions */

/* Read Words from Source Text File*/
/*
  read_words
  @param file string; Path to source text file
  @returns WordList
*/
WordList read_words(char *);

/* Create New Word */
/*
  create_word
  @param line string; Full line of text from file
  @returns Word
*/
Word create_word(char *);

/* Add Word to Word List */
/*
  add_word_entry
  @param word Word
  @param list WordList
*/
void add_word_entry(Word, WordList);

/* Get Word From List */
/*
  get_random_word
  @returns Word
*/
Word get_random_word();

#endif