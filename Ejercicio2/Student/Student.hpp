#pragma once
#include <string>
#include <map>
#include <iostream>

class Student {
private:
    std::string name;
    int ID;
    std::map<std::string, double> subjects; // nombre del curso -> nota

public:
    Student(const std::string& name, int ID);

    std::string get_name() const;
    int get_ID() const;
    void set_subjects(const std::string& course, double score);
    double average() const;

    bool operator<(const Student& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Student& est);
};
