/*
  Header file for Words Utilities
*/

/* Word Type
  @description: Type for a single Word. Holds string for word and length of word
*/
typedef struct Word
{
  char *word;
  int length;
} Word;

/* Word Entry Type
  @description: Type for a single Word Entry. Holds a Word and a pointer to the next Word Entry
*/
typedef struct WordEntry
{
  Word *word;
  struct WordEntry *next;
} WordEntry;

/* Word List Type
  @description: Linked List of Words composing the Word List. Holds the Head Entry of the list and the total size
*/
typedef struct WordList
{
  WordEntry *head;
  int size;
} WordList;

/* Return Types */
typedef enum
{
  CharResultSuccess = 2,
  CharResultIncluded = 4,
  CharResultWrong = 0,
} ResultSet;

/* Word List Functions */

/* Creates empty Word List */
WordList *createWordList();

/* Initalize Word List with built-in Word Data */
void initWordList(WordList *list);

/* Adds Word to List
  @param list: WordList* - Word List to add Word to
  @param word: Word* - Word to add to Word List
*/
void addWord(WordList *list, Word *word);

/* Removes Word from List
  @param list: WordList* - Word List to remove Word from
  @param word: Word* - Word to remove from Word List
*/
void removeWord(WordList *list, Word *word);

/* Read Words From Text File and Add words to Word List
  @param filename: char* - Name of file to read words from
  @param list: WordList* - Word List to add words to
*/
void readWordsFromFile(char *filename, WordList *list);

/* Get Random Word From Word List
  @param list: WordList* - Word List to get random word from
  @return: Word* - Random Word from Word List
*/
Word *getRandomWord(WordList *list);

/* Check Guessed Word against Selected Word
  @param selected: Word* - Selected Word
  @param guess: char* - Guessed Word
  @return ResultSet[] - Results of each Character in Guessed Word
*/
ResultSet *checkWord(Word *selected, char *guess);
