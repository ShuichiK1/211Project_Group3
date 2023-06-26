//James McCaffrey
//Shuichi Kameda
//Evan Ung
//211 Project
//6/26/2023
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "gradebook.h"

//function that reads in an input txt file
//and returns a gradebook object
//gets the category vector and
//input vector (which contains assignment name
//points earned and total possible points)
//and the course name
GradeBook readFile(std::string fname){

    std::string courseName;

    //starts at -1 because of the new line after
    //the coruse name in the input file
    int depth = -1;

    std::vector<std::vector<std::string>> inputVec;
    std::vector<std::string> categories;

    std::ifstream infile{fname};
    std::getline(infile, courseName);
    std::string inputString;

    std::vector<std::string> lineVector;
    //outer loop gets line from input file
    while (std::getline(infile, inputString)) {
        //this if statement is so a file that has already been outputted
        //by the program can be modified and reused as new input
        if (inputString == "--- "){break;}
        std::stringstream stream(inputString);
        //this breaks the line into a vector
        while (true) {
            std::string in;
            stream >> in;
            if (!stream)
                break;
            lineVector.push_back(in);
        }
        //if the line is empty pushes back the input vector
        //and the category vector and increments the depth
        //this seperates the input vector up by category
        if (lineVector.empty()){
            std::string category;
            std::getline(infile, category);
            categories.push_back(category);

            inputVec.push_back({});
            depth++;
        }
        //pushes back assignemnt name, points earned
        //and total possible points to the input vector
        else{
            inputVec[depth].push_back(lineVector[0]);
            inputVec[depth].push_back(lineVector[1]);
            inputVec[depth].push_back(lineVector[2]);
        }
        lineVector = {};
    }
    //creates the gradebook object and returns
    return GradeBook(inputVec, categories, courseName, fname);
}

//this is to get input from the user to see if
//they want to exit the program
bool exit(){
    std::string input;
    std::cout << "\ninput 'yes' to exit: ";
    std::cin >> input;
    if (input == "yes") {return true;}
    else{return false;}
}

//function that gets a choice from the user
//of which particular output they want to be
//displayed in the console
void getChoice(GradeBook gb){
    //the loop is so the user can choose from
    //the options multiple times
    bool loop = true;
    while (loop){
        //this is just displaying the options to the user
        std::cout << "Choose option:\n";
        std::cout << "1 - individual search\n";
        std::cout << "2 - category search\n";
        std::cout << "3 - output all grades\n";
        std::cout << "4 - output category totals and overall\n";
        std::cout << "5 - output only the course total\n\n";
        //gets user input
        std::string input;
        std::cin >> input;
        //gets data for an individual assignment
        if (input == "1"){
            std::string goodInput = "\ntarget not found\n";
            //this loop is so the user can enter data
            //until correct data is found
            while (goodInput == "\ntarget not found\n") {
                std::cout << "enter the assignment name: ";
                std::string asTarget;
                std::cin >> asTarget;
                goodInput = gb.toStringIndividual(asTarget);
                std::cout << goodInput;
            }

            loop = !exit();
        }
        //gets data for an individual category
        else if (input == "2"){
            std::string goodInput = "\ntarget not found\n";
            //this loop is so the user can enter data
            //until correct data is found
            while (goodInput == "\ntarget not found\n") {
                std::cout << "enter the category name: ";
                std::string catTarget;
                std::cin >> catTarget;
                goodInput = gb.toStringCat(catTarget);
                std::cout << goodInput;
            }

            loop = !exit();
        }
        //gets all data
        else if (input == "3"){
            std::cout <<gb.toStringAll();
            loop = !exit();
        }
        //gets the category totals
        else if (input == "4"){
            std::cout << gb.toStringCatTot();
            loop = !exit();
        }
        //gets the overall course grade
        else if (input == "5"){
            std::cout << gb.toStringOver();
            loop = !exit();
        }
        //tells the user their input was
        //invalid
        else{
            std::cout << "\n invalid input\n";
            loop = !exit();
        }
    }
}

//main function
int main(int argc, char* argv[]) {
    std::string fname(argv[1]);
    GradeBook gb = readFile(fname);
    gb.calcGrades();
    gb.writeAll();
    std::cout << "changes have been written to the input file\n";
    getChoice(gb);
}
