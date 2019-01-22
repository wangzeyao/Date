//
// Created by WANGZEYAO on 2018/9/17.
//

#include <iostream>
#include <cmath>
#include <cstring>
#ifndef DATE_DATE_H
#define DATE_DATE_H

using namespace std;





class Date
{
private:
    int day;
    int month;
    int year;


public:
    Date()
    {
        day = 1;
        month = 1;
        year = 1970;
    }

    Date(int year,int month,int day)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    Date(int sec)
    {
        int year = sec / 31536000;
       Date date (2018 + year,1,1);
       int day = (sec % 31536000) / 86400;
        for (int i = 0; i < day; ++i) {
            date.addDay(date);
        }
        this->year = date.year;
        this->month = date.month;
        this->day = date.day;
    }
    ~Date(){}

    int getYear()const { return year;}
    int getMonth()const { return month;}
    int getDay()const { return day;}
    void setYear(int year){this->year = year;}
    void setMonth(int month){this->month = month;}
    void setDay(int day){this->day = day;}
    bool isLeapYear(int year);
    int getDaysOfMonth(Date date);
    bool isValid(Date date);
    void addDay(Date &date);
    void minDay(Date &date);
    int Compare(Date date1,Date date2);
    int operator -(Date date1);
    Date operator +(int day);
    Date operator ++();
    Date operator -(int day);
    bool operator <=(Date date);
    bool operator <(Date date);
    friend istream& operator >> (istream &in,Date &date);
    friend ostream& operator << (ostream &out,const Date &date);
};
#endif //DATE_DATE_H

