# TypeLearner
A C program to help improve home row typing speed and accuracy

## installation and use

windows was not the main OS used so it is not the primary guide here but it is added

Step 0.
make sure you have gcc installed check by typing gcc --version in console

if not <https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites> for windows

Step 1. (clone the project)\
git clone <https://github.com/skyels1/TypeLearner.git>\
after clone run `cd TypeLearner`

Step 2. (compile the program)\
run `gcc -I include src/*.c -o TypeLearner -lrt`

or if on windows run `gcc -I include src/main.c src/choseDifficulty.c src/checkTime.c src/checkSpace.c -o TypeLearner`

Step 3. (run the program)\
to run the program type `./TypeLearner` in console

on windows run `./TypeLearner.exe`

## About

this project was meant to help me (and posibly others) learn how to type home row at a acceptable speed

this is the first program I have made using C

## Features

3 selections for difficulty 
- easy (pengrams with no punctuation and no capitals)
- medium (long sentences with not puntuation or capitals)
- hard (sentences with capitals and punctuation)

and has words per minute calculator (WPM) and accuracy percentage

### Screenshot

![(image) example of what the code looks like](/previews/TypeLearner3.png)

### Screenshot - with mistakes

![(image) example of what the code looks like with mistakes](/previews/TypeLearner2wm.png)

## Plans for the future of this project

- [x] I hope to eventually have a long list of practicing sentences to test on so that the content doesnt go dry

- [ ] possibly add randomizer to it so that its just random letters and such for more practice

- [x] most importantly I plan to add code examples to this to practice typing real code instead of just sentences ie more practical for my usage

## Status

This project is a work in progress and is far from completion.\
steady progress is made, though unoptimal there is still a lot of progress.