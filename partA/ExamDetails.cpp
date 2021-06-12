#include <iostream>
namespace mtm
{
#include "ExamDetails.h"
#define MAX_MONTH 12
#define MAX_DAY 30
#define HALF 0.5

    ExamDetails::ExamDetails(int course_number_new, int month_new, int day_new, double hour_new,
                             int length_new, std::string zoom_link_new) : zoom_link(zoom_link_new)
    {
        if (course_number_new <= 0 || length_new <= 0)
        {
            throw InvalidArgsException();
        }
        if (month_new <= 0 || month_new > MAX_MONTH || day_new <= 0 || day_new > MAX_DAY)
        {
            throw InvalidDateException();
        }
        if ((hour_new - (int)hour_new != 0) && (hour_new - (int)hour_new != HALF))
        {
            throw InvalidTimeException();
        }
        course_number = course_number_new;
        month = month_new;
        day = day_new;
        hour = hour_new;
        length = length_new;
    }

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

    std::ostream &operator<<(std::ostream &os, const ExamDetails &exam)
    {
        os << "Course Number: " << exam.course_number << std::endl;
        os << "Time: " << exam.day << "." << exam.month << " at ";
        os << (int)exam.hour;
        os << (exam.hour - (int)exam.hour == 0) ? ":00" : ":30";
        os << std::endl;
        os << "Duration: " << exam.length << std::endl;
        os << "Zoom Link: " << exam.zoom_link << std::endl;
        return os;
    }

    ExamDetails ExamDetails::makeMatamExam()
    {
        return ExamDetails(234124, 7, 28, 13.0, 3, "https://tinyurl.com/59hzps6m");
    }
}