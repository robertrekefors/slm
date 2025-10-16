slm — Small Language Model

This project implements a small character-based language model in C++. It reads a text file, builds a statistical model of character sequences (k-grams), and generates new text by sampling from the learned probabilities.

Overview

The program analyses the input text to count the frequency of each k-gram (substring of length k), and estimates the conditional probabilities P(c|w) for each character c following a k-gram w. The model can then generate new text that statistically resembles the training data.

Compilation

To build the program, use the provided Makefile.
Command:
make
This will produce an executable named slm in the project folder.

Usage

The program takes three arguments:
./slm <k> <filename> <output_length>

Example:
./slm 3 big_training.txt 500

Example output:
the man and the sea and the ships move in the wind and the harbor shines in the sun

Project structure

slm/
├── src/
│ ├── main.cpp
│ ├── LanguageModel.cpp
│ ├── LanguageModel.h
│ ├── TextGenerator.cpp
│ ├── TextGenerator.h
├── doc/
│ └── report.txt (optional lab report)
├── Makefile
└── README.md

Implementation details

LanguageModel builds the frequency tables and probability distributions.

TextGenerator uses the model to produce new text.

main.cpp handles command-line input and overall control.

Uses std::map for frequency storage and std::random for sampling.

This project was developed as part of the Bachelor Programming Course and demonstrates how a simple probabilistic language model can be implemented in C++.
Git was used throughout the development process for version control, and GitHub served as the platform for sharing and publishing the project.

By organizing the code into separate classes, using a Makefile for compilation, and providing clear documentation through README and report files, the project fulfills all requirements stated in the lab instructions.
The work illustrates how programming, statistics, and systematic version control can be combined to create a complete and well-structured software project.

Author

Robert Rekefors
Kandidatkurs i programmering – Lab 5: Your own small language model
