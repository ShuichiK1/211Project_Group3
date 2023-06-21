#include "iostream"
#include "vector"
#include <fstream>
#include "gradebook.h"

GradeBook::GradeBook() {

}

GradeBook::GradeBook(std::vector<std::vector<std::string>> vec, std::vector<std::string> categories, std::string courseName, std::string fname){
    this->inputVec = vec;
    this->categories = categories;
    this->courseName = courseName;
    this->fname = fname;
}

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

void GradeBook::calcGrades() {
    double tempPossiblePoints;
    //gets total possible points and total points earned across all categories
    double totPointsEarned;
    double totalPosPoints;
    for (int i = 0; i < inputVec.size(); i++){
        categoryGrades.push_back(0);
        grades.push_back({});
        letterGradesArr.push_back({});
        for (int j = 0; j < inputVec[i].size() ; j+= 3){
            grades[i].push_back(std::stod(inputVec[i][j+1]) / std::stod(inputVec[i][j+2]) * 100);
            letterGradesArr[i].push_back(getLetterGrade(grades[i][j/3]));

            totPointsEarned+= std::stod(inputVec[i][j+1]);
            totalPosPoints+= std::stod(inputVec[i][j+2]);

            categoryGrades[i] += std::stod(inputVec[i][j+1]);
            tempPossiblePoints += std::stod(inputVec[i][j+2]);
        }

        categoryGrades[i] = categoryGrades[i] / tempPossiblePoints * 100;
        categoryLetterGrades.push_back(getLetterGrade(categoryGrades[i]));
        tempPossiblePoints = 0;
    }

    courseGrade = totPointsEarned/totalPosPoints * 100;
    courseLetGrade = getLetterGrade(courseGrade);
}

bool GradeBook::outputIndividual(std::string target){
    for (int i =0; i < inputVec.size(); i++){
        for (int j = 0; j < inputVec[i].size(); j+=3){
            if (inputVec[i][j] == target){
                std::ofstream outfile;
                outfile.open(fname);
                outfile << courseName << "\n";
                outfile << inputVec[i][j] << " " << inputVec[i][j+1] << " " << inputVec[i][j+2] << " "
                        << grades[i][j/3] << " " << letterGradesArr[i][j/3] << "\n";
                return true;
            }
        }
    }
    std::cout << "\ntarget not found\n";
    return false;
}

bool GradeBook::outputCat(std::string target) {
    for (int i = 0; i < categoryGrades.size(); i++){
        if (categories[i] == target){
            std::ofstream outfile;
            outfile.open(fname);
            outfile << courseName << "\n";
            outfile << categories[i] << "\n";
            for (int j = 0; j < inputVec[i].size(); j+=3){
                outfile << inputVec[i][j] << " " << inputVec[i][j+1] << " " << inputVec[i][j+2] << " "
                        << grades[i][j/3] << " " << letterGradesArr[i][j/3] << "\n";
            }
            outfile << "\nCategory total\n";
            outfile << categoryGrades[i] << " " << categoryLetterGrades[i] << "\n";
            return true;
        }
    }
    std::cout << "\ntarget not found\n";
    return false;
}

void GradeBook::outputCatTot(){
    std::ofstream outfile;
    outfile.open(fname);
    outfile << courseName << "\n";
    outfile << "\nCategory Grades\n";
    for (int i = 0; i < categories.size(); i ++){
        outfile << categories[i] << " " << categoryGrades[i] << " " << categoryLetterGrades[i] << "\n";
    }

    outfile << "\nCourse Overall\n";
    outfile << courseGrade << " " << courseLetGrade;
}

void GradeBook::outputOver(){
    std::ofstream outfile;
    outfile.open(fname);
    outfile << courseName << "\n";
    outfile << "\nCourse Overall\n";
    outfile << courseGrade << " " << courseLetGrade;
}

void GradeBook::outputAll(){
    std::ofstream outfile;
    outfile.open(fname);
    outfile << courseName << "\n";
    for (int i = 0; i < categories.size(); i++){
        outfile << "\n"<<categories[i] << "\n";
        for (int j = 0; j < inputVec[i].size(); j+=3){
            outfile << inputVec[i][j] << " " << inputVec[i][j+1] << " " << inputVec[i][j+2] << " "
                    << grades[i][j/3] << " " << letterGradesArr[i][j/3] << "\n";
        }
    }

    outfile << "\nCategory Grades\n";
    for (int i = 0; i < categories.size(); i ++){
        outfile << categories[i] << " " << categoryGrades[i] << " " << categoryLetterGrades[i] << "\n";
    }

    outfile << "\nCourse Overall\n";
    outfile << courseGrade << " " << courseLetGrade;
}
