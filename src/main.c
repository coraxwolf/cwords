
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "words.h"

int main()
{
  printf("Hello, World!\n");
  WordList *list = createWordList();
  printf("Initalizing Word List with Data Words\n");
  initWordList(list);
  printf("Word List Size: %d\n", list->size);
  printf("Picking a Random Word with length of 5 characters\n");
  Word *randomWord = getRandomWord(list);
  int t = 1;
  while (randomWord->length != 5)
  {
    randomWord = getRandomWord(list);
    t++;
  }
  printf("Finally Ended Up with Word: %s after %d Tries\n", randomWord->word, t);
  return EXIT_SUCCESS;
}