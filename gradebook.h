#ifndef UNTITLED8_GRADEBOOK_H
#define UNTITLED8_GRADEBOOK_H

#include "iostream"
#include "vector"
#include <fstream>
#include <sstream>

class GradeBook{
private:
    std::vector<std::vector<std::string>> inputVec;
    std::vector<std::vector<double>> grades;

    std::vector<std::string> categories;
    std::vector<double> categoryGrades;
    std::vector<std::string> categoryLetterGrades;

    std::vector<std::vector<std::string>> letterGradesArr;

    double courseGrade;
    std::string courseLetGrade;

    std::string fname;
    std::string courseName;
    
public:
    GradeBook();
    GradeBook(std::vector<std::vector<std::string>> vec, std::vector<std::string> categories, std::string courseName, std::string fname);

    std::string getLetterGrade(double grade);

    void calcGrades();

    bool outputIndividual( std::string target);
    bool outputCat(std::string target);

    void outputAll();
    void outputCatTot();
    void outputOver();
};

#endif //UNTITLED8_GRADEBOOK_H
