# Documentation

## Summary
Grade Book / Explanation / How to use

This is a CSC 212 grade book program that has multiple functions for the user.
It takes in a CSV file as well as a normal text file. This information will be saved into a 2d vector for easier access to information.
We have templates on specific CSV and text file formats that work with the program.



The current functions are:
1. Outputting a certain assignment, lab, or project grade.
2. Outputting the category grade with the current grades in the file.
3. Modifying the grades in the file.
4. Outputting all changes to the file

The information will be outputted into the terminal so the user can
read the information.



How to use:
First, the user must run the program. 
It will then prompt the name of the file 
- If the wrong file is typed or not found, it will then ask again.

Next, there will be several options displayed which the user can pick by typing in a number



This is the screen that will be prompted when the correct file has been entered.




The user is able to pick from the options. Once an option is chosen directions will pop on the terminal depending on the choice.





After each option is finished, the user will be asked if they want to perform another action.




The program will end once the user chooses that option.

## Planning

## Compilation Instructions 
Before you can compile the program, you must first download the relevant source files (**main.cpp**, **gradebook.cpp**, and **gradebook.h**). Any IDE can be used as long as the C++ language standard is set to C++11.

We opted to use a text file to hold all of the grade values. The text file must be structured as shown below in order for the program to run correctly. If you are creating it from scratch, it is important to include any whitespaces as shown - or you can use the example datasets provided as template.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/dataset_example.png)

For the program to read and write to the file, it must be stored in the working directory. The name of the file must be passed through as a command-line argument as shown. 

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/cla_example.png)

After which, you can run and compile as normal.

## Runtime Instructions

## Sample input/output screenshots

