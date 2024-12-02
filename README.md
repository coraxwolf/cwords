# cwords
## Wordle Clone in C

A command-line interface (cli) implementation of the word game **wordle** written in C.
Game will pick a word of 5 or more characters from a list and give the player a number of attempts to guess the word.

## Features
* Secret word guessing game in limited number of attempts
* Number of attempts reduces as the players level goes up
* Feedback on each guess
  * Correct Letters in the correct place are marked in Green
  * Included Letters are marked in Yellow
  * Wrong Letters are marked in Red
* Uses a word list built in to randomly select the secret word from
* Levels
  * Seven (7) attempts to guess the correct word at level 1 (Newbie)
  * Six (6) attempts to guess the correct word at level 2 (Beginner)
  * Five (5) attempts to guess the correct word at level 3 (Intermediate)
  * Four (4) attempts to guess the correct word at level 4 (Advance)
  * Three (3) attempts to guess the correct word at level 5 (Expert)

## Furture Features
* Ability to Add words to internal list
* Score Boards
* Stats tracked by Words

# Getting Started

## Prerequisites
* C Compiler (GCC 12.2)
* Termail (CLI) like Powershell or Linux Terminal

## Installation
1. Clone the repository
```
git clone https://github.com/coraxwolf/cwords
cd cwords
```

2. Complie Source Code
```
gcc -o cwordle cwordle.c
```

3. Run Game
```
./bin/cwordle <level>
```

### Sample Output
```
./bin/cwordle 5
Initalizing Word List with Data Words
Word List Size: 7772
Picking a Random Word with length of 5 characters
Attempt: 1 of 7
Enter Your Guess: books
Results: 0 = Wrong, 2 = Correct, 4 = Included
b: 0 o: 0 o: 0 k: 0 s: 2
Attempt: 2 of 7
Enter Your Guess: ahems
Results: 0 = Wrong, 2 = Correct, 4 = Included
a: 0 h: 0 e: 0 m: 0 s: 2
Attempt: 3 of 7
Enter Your Guess: allow
Results: 0 = Wrong, 2 = Correct, 4 = Included
a: 0 l: 0 l: 0 o: 0 w: 4
Attempt: 4 of 7
Enter Your Guess: wells
Results: 0 = Wrong, 2 = Correct, 4 = Included
w: 2 e: 0 l: 0 l: 0 s: 2
Attempt: 5 of 7
Enter Your Guess: wents
Results: 0 = Wrong, 2 = Correct, 4 = Included
w: 2 e: 0 n: 2 t: 0 s: 2
Attempt: 6 of 7
Enter Your Guess: winds
Results: 0 = Wrong, 2 = Correct, 4 = Included
w: 2 i: 2 n: 2 d: 0 s: 2
Attempt: 7 of 7
Enter Your Guess: wines
Results: 0 = Wrong, 2 = Correct, 4 = Included
w: 2 i: 2 n: 2 e: 0 s: 2
You Failed to Guess the Word!
The Word was: wings
```


