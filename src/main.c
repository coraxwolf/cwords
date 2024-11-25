/*
  Header file for Main Program
  @Author Jeremy Hawkins <coraxwolf@gmail.com>
  @Date 11/25/2024
  @Description C Clone of Wordle Word Game
*/

#include <stdio.h>
#include "main.h"
#include "words.h"

int main(int, char **)
{
  char *wf = "./data/words";
  WordList words = read_words(wf);
}