#include "Times.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>

Times::Times(int h, int m, int s, std::string td) {
    check_hourlimit(h);
    check_timelimit60(m);
    check_timelimit60(s);

    td = format_timeday(td);
    check_timeday(td);

    hour = h;
    min = m;
    sec = s;
    tday = td;
}

void Times::print_time() const {
    std::cout << std::setfill('0') << std::setw(2) << hour << "h:";
    std::cout << std::setfill('0') << std::setw(2) << min << "m:";
    std::cout << std::setfill('0') << std::setw(2) << sec << "s ";
}

void Times::check_timelimit60(int x) const {
    if (x > 59 || x < 0) {
        throw std::runtime_error("ERROR: Parámetros de entrada inválidos");
    }
}

void Times::check_hourlimit(int h) const {
    if (h > 11 || h < 0) {
        throw std::runtime_error("ERROR: Parámetros de entrada inválidos");
    }
}

void Times::check_timeday(const std::string& td) const {
    if (td != "a.m." && td != "p.m.") {
        throw std::runtime_error("ERROR: Parámetros de entrada inválidos");
    }
}

std::string Times::format_timeday(const std::string& td) const {
    std::string result;
    for (char c : td) {
        if (c != ' ' && c != '.') {
            result += c;
        }
    }
    result.insert(1, ".");
    result.insert(3, ".");
    return result;
}

int Times::get_hour() const {
    return hour;
}

void Times::set_hour(int h) {
    check_hourlimit(h);
    hour = h;
}

int Times::get_minute() const {
    return min;
}

void Times::set_minute(int m) {
    check_timelimit60(m);
    min = m;
}

int Times::get_sec() const {
    return sec;
}

void Times::set_sec(int s) {
    check_timelimit60(s);
    sec = s;
}

std::string Times::get_timeday() const {
    return tday;
}

void Times::set_timeday(const std::string& td) {
    tday = format_timeday(td);
}

void Times::print_time12() const {
    std::cout << "Tiempo formato 12h: ";
    print_time();
    std::cout << tday << std::endl;
}

void Times::print_time24() {
    int h24 = hour;
    if (tday == "p.m.") {
        h24 += 12;
    }

    std::cout << "Tiempo formato 24h: ";
    print_time();
    std::cout << std::endl;
}
