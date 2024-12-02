
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "words.h"

int main()
{
  printf("Hello, World!\n");
  char *filename = "./data/words";
  WordList *list = createWordList();
  readWordsFromFile(filename, list);
  printf("Word List Size: %d\n", list->size);
  printf("Getting 2 Random Words\n");
  Word *word1 = getRandomWord(list);
  Word *word2 = getRandomWord(list);
  printf("Word 1: %s\n", word1->word);
  printf("Word 2: %s\n", word2->word);
  return EXIT_SUCCESS;
}