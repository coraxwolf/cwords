
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "words.h"

/* Get User Guess */
char *getUserGuess()
{
  char *guess = (char *)malloc(100);
  printf("Enter Your Guess: ");
  scanf("%s", guess);
  return guess;
}

int main(int argc, char *argv[])
{
  int level;
  int word_length;
  int attempts;
  // check for arguments
  if (argc != 1)
  {
    level = 1;
  }
  else if (argc == 2 && atoi(argv[1]) > 0 && atoi(argv[1]) < 6)
  {
    level = atoi(argv[1]);
  }
  else
  {
    printf("Usage: %s [level]\n*Levels go from 1 to 5\n", argv[0]);
    return EXIT_FAILURE;
  }
  switch (level)
  {
  case 1:
    attempts = 7;
    word_length = 5;
    break;
  case 2:
    attempts = 6;
    word_length = 5;
    break;
  case 3:
    attempts = 5;
    word_length = 5;
    break;
  case 4:
    attempts = 4;
    word_length = 5;
    break;
  case 5:
    attempts = 3;
    word_length = 5;
    break;
  default:
    attempts = 7;
    word_length = 5;
    break;
  }

  WordList *list = createWordList();
  printf("Initalizing Word List with Data Words\n");
  initWordList(list);
  printf("Word List Size: %d\n", list->size);
  printf("Picking a Random Word with length of %d characters\n", word_length);
  Word *randomWord = getRandomWordofLength(list, word_length);
  int attempt = 0;
  bool solved = false;
  while (attempt < attempts && !solved)
  {
    attempt++;
    printf("Attempt: %d of %d\n", attempt, attempts);
    /* Get User Guess */
    char *guess = getUserGuess();
    /* Check Word */
    ResultSet *results = checkWord(randomWord, guess);
    if (strcmp(randomWord->word, guess) == 0)
    {
      solved = true;
      printf("You Guessed the Word!\n\n");
    }
    /* Print Results */
    printf("Results: 0 = Wrong, 2 = Correct, 4 = Included\n");
    for (int i = 0; i < randomWord->length; i++)
    {
      printf("%c: %d ", guess[i], results[i]);
    }
    printf("\n");
  }
  if (!solved)
  {
    printf("You Failed to Guess the Word!\n");
    printf("The Word was: %s\n", randomWord->word);
  }

  return EXIT_SUCCESS;
}
