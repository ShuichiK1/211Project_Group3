//James McCaffrey
//Shuichi Kameda
//Evan Ung
//211 Project
//6/26/2023
#include "iostream"
#include "vector"
#include <fstream>
#include "gradebook.h"
#include <cmath>

//default constructor
GradeBook::GradeBook() {

}

//constructor that just sets values
//of some data members
GradeBook::GradeBook(std::vector<std::vector<std::string>> vec, std::vector<std::string> categories, std::string courseName, std::string fname){
    this->inputVec = vec;
    this->categories = categories;
    this->courseName = courseName;
    this->fname = fname;
}

//this returns the letter grade
//based on the number grade
//passed into the function
std::string GradeBook::getLetterGrade(double grade) {
    if (grade >= 93){
        return "A";
    }
    if (grade >= 90){
        return "A-";
    }
    if (grade >= 87){
        return "B+";
    }
    if (grade >= 83){
        return "B";
    }
    if (grade >= 80){
        return "B-";
    }
    if (grade >= 77){
        return "C+";
    }
    if (grade >= 73){
        return "C";
    }
    if (grade >= 70){
        return "C-";
    }
    if (grade >= 67){
        return "D+";
    }
    if (grade >= 63){
        return "D";
    }
    if (grade >= 60){
        return "D-";
    }
    return "F";
}

//function calculates all grades from the input vector
//and changes objects data members to contain the calculated
//grades
void GradeBook::calcGrades() {
    double tempPossiblePoints;
    //gets total possible points and total points earned across all categories
    double totPointsEarned;
    double totalPosPoints = 0;
    //loops through the input vector
    for (int i = 0; i < inputVec.size(); i++){
        categoryGrades.push_back(0);
        grades.push_back({});
        letterGradesVec.push_back({});
        //loops through the category
        for (int j = 0; j < inputVec[i].size() ; j+= 3){
            //calculates the individual assignment grade and letter grade
            grades[i].push_back(std::stod(inputVec[i][j+1]) / std::stod(inputVec[i][j+2]) * 100);
            letterGradesVec[i].push_back(getLetterGrade(grades[i][j/3]));

            //adds to the total points earnedand total possible points
            totPointsEarned+= std::stod(inputVec[i][j+1]);
            totalPosPoints+= std::stod(inputVec[i][j+2]);

            //adds to category grade and temporary possible points
            categoryGrades[i] += std::stod(inputVec[i][j+1]);
            tempPossiblePoints += std::stod(inputVec[i][j+2]);
        }

        //calculates category grade and letter grade
        categoryGrades[i] = categoryGrades[i] / tempPossiblePoints * 100;
        categoryLetterGrades.push_back(getLetterGrade(categoryGrades[i]));
        tempPossiblePoints = 0;
    }

    //calculates course overall grade and letter grade
    courseGrade = totPointsEarned/totalPosPoints * 100.0;
    courseLetGrade = getLetterGrade(courseGrade);
}

//function linearly searches for inputted
//assignment name and stringafies assignments data
std::string GradeBook::toStringIndividual(std::string target){
    std::string stringafied;
    for (int i =0; i < inputVec.size(); i++){
        for (int j = 0; j < inputVec[i].size(); j+=3){
            if (inputVec[i][j] == target){

                stringafied +=  courseName + "\n";
                stringafied += inputVec[i][j] + " " + inputVec[i][j+1] + " " + inputVec[i][j+2] + " "
                        +std::to_string(grades[i][j/3])  + " " + letterGradesVec[i][j/3] + "\n";
                return stringafied;
            }
        }
    }
    return "\ntarget not found\n";
}

//function linearly searches for inputted
//category name and stringafies categorys data
std::string GradeBook::toStringCat(std::string target) {
    std::string stringafied;
    for (int i = 0; i < categoryGrades.size(); i++){
        if (categories[i] == target){

            stringafied += courseName + "\n";
            stringafied += categories[i] + "\n";
            for (int j = 0; j < inputVec[i].size(); j+=3){
                stringafied += inputVec[i][j] + " " + inputVec[i][j+1] + " " + inputVec[i][j+2] + " " + std::to_string(grades[i][j/3])
                        + " " + letterGradesVec[i][j/3] + "\n";
            }
            stringafied += "\nCategory total\n";
            stringafied += std::to_string(categoryGrades[i])  + " " + categoryLetterGrades[i] + "\n";
            return stringafied;
        }
    }
    return "\ntarget not found\n";
}

//stringafies the category total grades
std::string GradeBook::toStringCatTot(){
    std::string stringafied;

    stringafied += courseName + "\n";
    stringafied += "\nCategory Grades\n";
    for (int i = 0; i < categories.size(); i ++){
        stringafied += categories[i] + " " + std::to_string(categoryGrades[i])  + " " + categoryLetterGrades[i] + "\n";
    }

    stringafied += "\nCourse Overall\n";
    stringafied += std::to_string(courseGrade)  + " " + courseLetGrade;
    return stringafied;
}

//stringafies the overall grade
std::string GradeBook::toStringOver(){
    std::string stringafied;
    stringafied += courseName + "\n";
    stringafied += "\nCourse Overall\n";
    stringafied +=std::to_string(courseGrade)  + " " + courseLetGrade;
    return stringafied;
}

//functions writes all changes made in the program
//back into the input file
void GradeBook::writeAll() {
    std::ofstream outfile;
    outfile.open(fname);
    outfile << courseName << "\n";
    for (int i = 0; i < categories.size(); i++){
        outfile << "\n"<<categories[i] << "\n";
        for (int j = 0; j < inputVec[i].size(); j+=3){
            outfile << inputVec[i][j] << " " << inputVec[i][j+1] << " " << inputVec[i][j+2] << " "
                    << round(grades[i][j/3] * 100.0)/ 100.0 << " " << letterGradesVec[i][j/3] << "\n";
        }
    }

    outfile << "--- \nCategory Grades\n";
    for (int i = 0; i < categories.size(); i ++){
        outfile << categories[i] << " " << round(categoryGrades[i] * 100.0) / 100.0 << " " << categoryLetterGrades[i] << "\n";
    }
    outfile << "\nCourse Overall\n";

    outfile << round(courseGrade * 100.0) / 100.0 << " " << courseLetGrade;
}

//writes all data to the input file(this is a modified
//version of the writeAll file)
std::string GradeBook::toStringAll(){
    std::string stringafied;
    stringafied += courseName + "\n";
    for (int i = 0; i < categories.size(); i++){
        stringafied += "\n" + categories[i] + "\n";
        for (int j = 0; j < inputVec[i].size(); j+=3){
            stringafied += inputVec[i][j] + " " + inputVec[i][j+1] + " " + inputVec[i][j+2] + " "
                    + std::to_string(grades[i][j/3])  + " " + letterGradesVec[i][j/3] + "\n";
        }
    }

    stringafied += "--- \nCategory Grades\n";
    for (int i = 0; i < categories.size(); i ++){
        stringafied += categories[i] + " " + std::to_string(categoryGrades[i])  + " " + categoryLetterGrades[i] + "\n";
    }
    stringafied += "\nCourse Overall\n";
    stringafied += std::to_string(courseGrade) + " " + courseLetGrade;
    return stringafied;
}
