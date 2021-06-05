#include <iostream>
#include "ExamDetails.h"

ExamDetails::ExamDetails(int course_number, int month, int day, double hour, int length, std::string zoom_link = "")
    : course_number(course_number), month(month), day(day), hour(hour), length(length), zoom_link(zoom_link) {}

ExamDetails::ExamDetails(const ExamDetails &exam)
    : course_number(exam.course_number), month(exam.month), day(exam.day), hour(exam.hour),
      length(exam.length), zoom_link(exam.zoom_link) {}

std::string ExamDetails::getLink() const
{
    return zoom_link;
}

void ExamDetails::setLink(std::string new_link)
{
    zoom_link = new_link;
}

int ExamDetails::operator-(const ExamDetails &exam) const
{
    return (month - exam.month) * 30 + (day - exam.day);
}

bool ExamDetails::operator<(const ExamDetails &exam) const
{
    return (*this - exam == 0) ? (*this - exam) < 0 : (hour - exam.hour) < 0;
}

std::ostream &operator<<(std::ostream & os, const ExamDetails & exam)
{
}

ExamDetails makeMatamExam()
{
    return ExamDetails(234124, 7, 28, 13.0, 3, "https://tinyurl.com/59hzps6m");
}
