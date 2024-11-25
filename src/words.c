

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words.h"

WordList read_words(char *filepath)
{
  FILE *fp;
  char ch;

  /* Open File */
  fp = fopen(filepath, "r");

  if (fp == NULL)
  {
    printf("Error Opening File %s.\n", filepath);
    exit(1);
  }

  while ((ch = fgetc(fp)) != EOF)
  {
    /* Read line into single string */
    char *line; /* String to hold Word */
    int len;    /* Length of Word */
    while (ch != "\n" || ch != "\r\n")
    {
      // Character is part of the word
      line = realloc(line, len + 2); /* Allocate Space for 2 characters */
      if (line == NULL)
      {
        printf("Memory Allocation Error for Word.\n");
        fclose(fp);
        return;
      }
      line[len++] = ch;
    }
    printf("Found word: %s.\n", line);
  }
  return;
}