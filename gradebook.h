//James McCaffrey
//Shuichi Kameda
//Evan Ung
//211 Project
//6/26/2023
#ifndef UNTITLED8_GRADEBOOK_H
#define UNTITLED8_GRADEBOOK_H

#include "iostream"
#include "vector"
#include <fstream>
#include <sstream>

class GradeBook{
private:
    //datamembers
    std::vector<std::vector<std::string>> inputVec;
    std::vector<std::vector<double>> grades;

    std::vector<std::string> categories;
    std::vector<double> categoryGrades;
    std::vector<std::string> categoryLetterGrades;

    std::vector<std::vector<std::string>> letterGradesVec;

    double courseGrade;
    std::string courseLetGrade;

    std::string fname;
    std::string courseName;

public:
    //constructors
    GradeBook();
    GradeBook(std::vector<std::vector<std::string>> vec, std::vector<std::string> categories, std::string courseName, std::string fname);

    //functions
    std::string getLetterGrade(double grade);

    void calcGrades();

    std::string toStringAll();
    std::string toStringIndividual( std::string target);
    std::string toStringCat(std::string target);
    std::string toStringCatTot();
    std::string toStringOver();

    void writeAll();
};

#endif //UNTITLED8_GRADEBOOK_H
