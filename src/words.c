/*
  Word Utilities Functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "words.h"
#include "word_data.h"

/* Create New Word List */
WordList *createWordList()
{
  /* Calling Seed Random In Create Word List to avoid reseeding the random generator too often */
  srand(time(NULL)); /* Seed Random Number Generator */
  WordList *newList = (WordList *)malloc(sizeof(WordList));
  newList->head = NULL;
  newList->size = 0;
  return newList;
}

/* Creates Word
  @param word: char* - String to create Word from
  @return: Word* - Word created from string
*/
Word *createWord(char *word)
{
  Word *newWord = (Word *)malloc(sizeof(Word));
  newWord->word = word;
  newWord->length = strlen(word);
  return newWord;
}

/* Extract Words from Data Words */
char *strndup(const char *s, size_t n)
{
  size_t len = strlen(s) < n ? strlen(s) : n;
  char *new_str = malloc(len + 1);
  if (new_str == NULL)
  {
    return NULL;
  }
  memcpy(new_str, s, len);
  new_str[len] = '\0';
  return new_str;
}

/* Initalize Word List with Built-In Word Data
  @param list: WordList* - Word List to initalize
*/
void initWordList(WordList *list)
{
  char *data_copy = strndup((char *)data_words, data_words_len);
  char *token = strtok(data_copy, "\n");
  while (token != NULL)
  {
    Word *newWord = createWord(token);
    addWord(list, newWord);
    token = strtok(NULL, "\n");
  }
  free(data_copy);
}

/* Add Word to Word List
  @param list: WordList* - Word List to add Word to
  @param word: Word* - Word to add to Word List
*/
void addWord(WordList *list, Word *word)
{
  WordEntry *newEntry = (WordEntry *)malloc(sizeof(WordEntry));
  newEntry->word = word;
  newEntry->next = list->head;
  list->head = newEntry;
  list->size++;
}

/* Removes Word from Word List
  @param list: WordList* - Word List to remove Word from
  @param word: Word* - Word to remove from Word List
*/
void removeWord(WordList *list, Word *word)
{
  WordEntry *current = list->head;
  WordEntry *previous = NULL;

  while (current != NULL)
  {
    if (strcmp(current->word->word, word->word) == 0)
    /* Current Word matches Word to Remove */
    {
      if (previous == NULL)
      /* This is the Head of the Word List */
      {
        list->head = current->next; /* Make Head equal to next word is list */
      }
      else
      {
        previous->next = current->next; /* Make Previous Head equal next word in the list*/
      }
      list->size--;        /* Decrement the size of the list */
      free(current->word); /* Remove Choosen Word */
      free(current);       /* Remove Choosen Word Entry */
      return;              /* Exit Function */
    }
    /* Advance to Next Word in list */
    previous = current;
    current = current->next;
  }
}

/* Read Words From Text File and Add to Word List
  @param filename: char* - Name of file to read words from
  @param list: WordList* - Word List to add words to
*/
void readWordsFromFile(char *filename, WordList *list)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Error: Unable to open file %s\n", filename);
    exit(1);
  }

  /* Read Text file chracter by character */
  char c;                         /* Current Character Read */
  int len = 0;                    /* Length of Word Read */
  char *word = (char *)malloc(1); /* Create Holder for Word; sized for one character */
  while ((c = fgetc(file)) != EOF)
  /* Read Character until reaching EOF (End of File) Value (-1)*/
  {
    /* Check for EOL (End of Line) character(s)*/
    if (c == '\n')
    {
      /* End of Line so Should have a new word */
      if (len > 0)
      /* Length is greater than 0 so we have a word*/
      {
        Word *newWord = createWord(word); /* Create Word from word */
        addWord(list, newWord);           /* Add Word to Word List */
        /* Reset len and word */
        len = 0;
        word = (char *)malloc(1);
      }
    }
    else if (c == '\r')
    /* Checking for Windows End of Line (\r\n)*/
    {
      /* Get Next Character */
      char cn = fgetc(file);
      if (cn == '\n')
      /* Found Two Character End of Line for Windows */
      {
        /* End of Line so Should have a new word */
        if (len > 0)
        /* Length is greater than 0 so we have a word*/
        {
          Word *newWord = createWord(word); /* Create Word from word */
          addWord(list, newWord);           /* Add Word to Word List */
          /* Reset len and Word */
          len = 0;
          word = (char *)malloc(1);
        }
      }
    }
    else
    /* Read in Character Keep Adding to Word */
    {
      word = (char *)realloc(word, len + 1); /* Resize Word to hold new character */
      word[len] = c;                         /* Add Character to Word */
      len++;                                 /* Increment Length of Word */
    }
  }

  fclose(file);
}

/* Get Random Word from List
  @param list: WordList* - Word List to get random word from
  @return: Word* - Random Word from Word List
*/
Word *getRandomWord(WordList *list)
{
  int randomIndex = rand() % list->size; /* Get Random Index */
  WordEntry *current = list->head;       /* Start at Head of List */
  for (int i = 0; i < randomIndex; i++)
  /* Loop to Random Index */
  {
    current = current->next; /* Move to Next Word */
  }
  return current->word; /* Return Random Word */
}