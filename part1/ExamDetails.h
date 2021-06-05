#ifndef EXAMDETAILS_H_
#define EXAMDETAILS_H_
#include <string>

class ExamDetails
{
    int course_number, month, day, length;
    double hour;
    std::string zoom_link;

public:
    ExamDetails(int course_number, int month, int day, double hour, int length, std::string zoom_link = "");
    ExamDetails(const ExamDetails &exam);
    ~ExamDetails() = default;
    ExamDetails &operator=(const ExamDetails &exam) = default;
    std::string getLink() const;
    void setLink(std::string new_link);
    int operator-(const ExamDetails &) const;
    bool operator<(const ExamDetails &) const;
    friend std::ostream &operator<<(std::ostream &, const ExamDetails &);
};

ExamDetails makeMatamExam();

#endif