#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <string>

namespace Logger {
    void spacer(std::string const &);
    void spacer();
    void info(std::string const &);
    void warn(std::string const &);
    template<class U> void trace(U const &);
    void error(std::string const &, int const);

    // void test(std::string const &);
};

std::string const lines("------------------------------------------------------------");
std::string const spacer_id("Spacer");
std::string const info_id("Info");
std::string const warn_id("Warn");
std::string const trace_id("Trace");
std::string const error_id("Error");

template<class U> void formatter(std::string const & title, U const & msg) {
    std::time_t t(std::time(0));
    std::tm * now(std::localtime(&t));

    int year((now->tm_year) + 1900);
    int month((now->tm_mon) + 1);
    int day(now->tm_mday);
    int hour(now->tm_hour);
    int min(now->tm_min);
    int sec(now->tm_sec);

    // std::cout << t << "\n";
    // printf("%i/%i/%i -- %i:%i:%i\t%c: %c\n", year, month, day, hour, min, sec, title, msg);
    std::cout
    << "\t"
    << year << "/" << month << "/" << day
    << " - "
    << hour << ":" << min << ":" << sec
    << "\t"
    << title
    << ":\t"
    << msg
    << "\n";

    return;
}

template<class U> void Logger::trace(U const & msg) {
    formatter<U>(trace_id, msg);
    return;
}

#endif
