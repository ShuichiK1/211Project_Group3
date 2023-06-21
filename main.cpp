#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "gradebook.h"

GradeBook readFile(std::string fname){

    std::string courseName;

    int depth = -1;
    int length = 0;

    int maxLength = 0;

    std::vector<std::vector<std::string>> inputVec;

    std::vector<std::string> categories;

    std::ifstream infile{fname};
    std::getline(infile, courseName);
    std::string inputString;

    std::vector<std::string> lineVector;
    while (std::getline(infile, inputString)) {
        std::stringstream stream(inputString);
        while (true) {
            std::string in;
            stream >> in;
            if (!stream)
                break;
            lineVector.push_back(in);
        }
        if (lineVector.empty()){
            std::string category;
            std::getline(infile, category);
            categories.push_back(category);

            inputVec.push_back({});

            depth++;

            if (length > maxLength){
                maxLength = length;
            }
            length = 0;
        }
        else{
            inputVec[depth].push_back(lineVector[0]);
            inputVec[depth].push_back(lineVector[1]);
            inputVec[depth].push_back(lineVector[2]);
            length += 3;
        }
        lineVector = {};
    }
    return GradeBook(inputVec, categories, courseName, fname);
}

void getChoice(GradeBook gb){
    bool loop = true;
    while (loop){
        std::cout << "Choose option:\n";
        std::cout << "1 - individual search\n";
        std::cout << "2 - category search\n";
        std::cout << "3 - output all grades\n";
        std::cout << "4 - output category totals and overall\n";
        std::cout << "5 - output only the course total\n";
        std::string input;
        std::cin >> input;
        if (input == "1"){
            bool goodInput = false;
            while (!goodInput) {
                std::cout << "enter the assignment name: ";
                std::string asTarget;
                std::cin >> asTarget;
                goodInput = gb.outputIndividual(asTarget);
            }
            loop = false;
        }
        else if (input == "2"){
            bool goodInput = false;
            while (!goodInput) {
                std::cout << "enter the category name: ";
                std::string catTarget;
                std::cin >> catTarget;
                goodInput = gb.outputCat(catTarget);
            }
            loop = false;
        }
        else if (input == "3"){
            gb.outputAll();
            loop = false;
        }
        else if (input == "4"){
            gb.outputCatTot();
            loop = false;
        }
        else if (input == "5"){
            gb.outputOver();
            loop = false;
        }
        else{
            std::cout << "\n invalid input\n";
        }
    }
}

int main(int argc, char* argv[]) {
    std::string fname(argv[1]);
    GradeBook gb = readFile(fname);
    gb.calcGrades();
    getChoice(gb);
    std::cout << "changes have been written to the input file";
}
