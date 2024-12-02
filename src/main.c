
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

int main()
{
  printf("Hello, World!\n");
  WordList *list = createWordList();
  printf("Initalizing Word List with Data Words\n");
  initWordList(list);
  printf("Word List Size: %d\n", list->size);
  printf("Picking a Random Word with length of 5 characters\n");
  Word *randomWord = getRandomWord(list);
  while (randomWord->length != 5)
  {
    randomWord = getRandomWord(list);
  }
  int attempt = 0;
  bool solved = false;
  while (attempt < 7 && !solved)
  {
    attempt++;
    printf("Attempt: %d\n", attempt);
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
