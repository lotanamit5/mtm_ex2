#ifndef EXAMDETAILS_H_
#define EXAMDETAILS_H_

#include <string>

namespace mtm
{
    class ExamDetails
    {
        int course_number, month, day, length;
        double hour;
        std::string zoom_link;

    public:
        class InvalidDateException
        {
        };
        class InvalidTimeException
        {
        };
        class InvalidArgsException
        {
        };
        ExamDetails(int course_number, int month, int day, double hour, int length, std::string zoom_link = "");
        ExamDetails(const ExamDetails &exam);
        ~ExamDetails() = default;
        ExamDetails &operator=(const ExamDetails &exam) = default;
        std::string getLink() const;
        void setLink(const std::string new_link);
        int operator-(const ExamDetails &) const;
        bool operator<(const ExamDetails &) const;
        friend std::ostream &operator<<(std::ostream &os, const ExamDetails &exam);
        static ExamDetails makeMatamExam();
    };
}

#endif