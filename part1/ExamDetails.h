#ifndef EXAMDETAILS_H_
#define EXAMDETAILS_H_
#include <string>

class ExamDetails
{
private:
    int course_number;
    int month;
    int day;
    double hour;
    int length;
    std::string zoom_link;

public:
    ExamDetails(int course_number, int month, int day, double hour, int length, std::string zoom_link = "");
    ~ExamDetails();
};


std::string getLink();

#endif