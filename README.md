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
./cwordle
```


