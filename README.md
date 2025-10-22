# slm — Small Language Model

**Course:** Kandidatkurs i programmering – Lab 5  
**Author:** Robert Rekefors  
**Date:** 2025-10-17  
**Version:** Final submission  

---

## Overview

This project was created as part of the Bachelor Programming Course (Lab 5: Small Language Model).  
It implements a simple probabilistic language model in C++ that learns character-based patterns from a text file and generates new text with similar statistical structure.  
The purpose of the lab was to demonstrate how fundamental concepts in language modeling, randomness, and data structures can be combined in a small yet complete C++ program.

---

## Compilation

To build the program, use the provided Makefile:

```bash
make

This will produce an executable named slm in the project folder.
Usage

The program takes three arguments:

./slm <k> <input_file> <output_length>

Example:

./slm 3 big_training.txt 500

Example output:

the man and the sea and the ships move in the wind and the harbor shines in the sun

Project structure

slm/
├── src/
│   ├── main.cpp
│   ├── LanguageModel.cpp
│   ├── LanguageModel.h
│   ├── TextGenerator.cpp
│   └── TextGenerator.h
├── doc/
│   └── report.txt
├── Makefile
└── README.md

Implementation details

    LanguageModel builds frequency tables and probability distributions.

    TextGenerator uses the model to produce new text.

    main.cpp handles command-line input and program flow.

    Uses std::map for frequency storage and std::random for sampling.

This project demonstrates how a simple probabilistic language model can be implemented in C++.
Git was used throughout development for version control, and GitHub served as the platform for publishing the project.

By organizing the code into separate classes, using a Makefile for compilation, and providing clear documentation,
the project fulfills all requirements stated in the lab instructions.
License

This project was developed for academic purposes as part of the Bachelor Programming Course (Lab 5).
No external libraries or pre-trained models were used.
