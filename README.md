# Documentation

## Summary

This is a CSC 212 grade book program that is able to perform multiple
things for the user.
They are able to interact, as well as read information about their current grade.

Our program works by getting grade information through a text file.
This information will be saved in the program.
We have templates on specific text file formats that work with the program.

The current functions are:
1. Outputting a certain assignment, lab, or project grade.
2. Outputting the category grade with the current grades in the file.
3. Modifying the grades in the file.
4. Outputting all changes to the file

Most of the information will be outputted to the terminal for
the user to read. Other information such as changes
Ex. Updating a grade,
will be changed in the original text file itself.


### Contribution Table
| Name | Contribution | Started | Ended |
| ---  |     ---      |   ---   |  ---  |
| James |worked on program   |6/15   |6/26   |
| Evan | Flow chart/Psuedo code | 6/15  | 6/17 |
| Shuichi | Readme/Supplementary files | 6/15 | 6/26 |
| James |worked on recording   |6/23   |6/23   |
| Evan | Readme | 6/15 | 6/26 |
| Shuichi | Psuedocode \ Ideas | 6/26 | 6/26 |

## Planning
For the planning stage, we had decisions such as whether this program would be universal. There were other design
decisions such as what files are taken in. 

We wanted our program to be universal but decided to make it towards 212 first.
Things we wanted to add were being able to manipulate the course name as well as max grade amounts 
for assignments, labs, etc.

An important part of the planning process was making sure the program functions as stated in the directions.
We chose to create a flowchart to illustrate choices in the program. The pseudocode would then be created later. 
After that, the classes and methods were created to then be implemented later.


## Compilation Instructions 
Before you can compile the program, you must first download the relevant source files (**main.cpp**, **gradebook.cpp**, and **gradebook.h**). Any IDE can be used as long as the C++ language standard is set to C++11.

We opted to use a text file to hold all of the grade values. The text file must be structured as shown below in order for the program to run correctly. If you are creating it from scratch, it is important to include any whitespaces as shown - or you can use the example datasets provided as template.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/dataset_example.png)

For the program to read and write to the file, it must be stored in the working directory. The name of the file must be passed through as a command-line argument as shown. 

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/cla_example.png)

After which, you can run and compile as normal.

## Runtime Instructions
Once you run the program, the input text file will automatically be updated to show individual numerical and letter grades. There will also be a summary included at the end of the file which includes grades for each category, as well as the overall course grades, all of which also display their corresponding letter grades.

Additionally, you will be shown a user interface that displays five options in the terminal as shown below.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/main_ui.png)

You can choose any of the options by inputting the corresponding number. Every option will output the result into the terminal. At the end of each option, you will be prompted to end the program by inputting **yes**. You can repeat by simply running the program again with the same text file.

## Sample input/output screenshots
In this example, the text file **James_McCaffrey1.txt** will be used. Once the program has been compiled and is running with the correct file name, you can choose any of the five options.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/main_ui.png)

### Individual Search
For the first option, we can choose to display the status of individual tasks. We are prompted to input the name of a valid task. In this case, we decided on **lab1**. If a valid task name is not passed into the terminal, the program will continue to ask the user for a valid name until one is received.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/individual_search1.png)

The result is given as a string of different information. From left to right, you can see the task name, points received, earnable points, calculated numerical grade, and the corresponding letter grade.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/individual_search2.png)

Once the result is displayed, you can input **yes** into the terminal to end the process. You may run the program again in order to choose another option. This is the case for every other option that follows.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/individual_search3.png)

### Category Search
The second option allows you to view all task grades under a specified category. In this case, we decided to view all grades under the lab classification. Additionally, it will display the overall grade of that category.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/category_search1.png)

### Output all grades
The third option provides a comprehensive overview of all task grades and their respective letter grades. Furthermore, it displays the overall course grade, as well as all category grades.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/output_all_grades1.png)
![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/output_all_grades2.png)

### Output category totals and overall
To satisfy the project requirement, the fourth option provides only the overall course grade and the category grades.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/output_tot%26overall1.png)

### Output only the course total
For the same reason previously stated, the fifth option only displays the overall course grade.

![alt text](https://github.com/ShuichiK1/211Project_Group3/blob/main/images/only_total1.png)
