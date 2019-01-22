//
// Created by WANGZEYAO on 2018/9/17.
//
#include "Date.h"
#include <iostream>
#include <cstring>

bool Date::isLeapYear(int year)
{
    return ((abs(year) % 4 == 0) && (abs(year) % 100 != 0) || abs(year) % 400 ==0);
}

 bool Date::isValid(Date date)
{
    if (date.year == 0 || date.month < 1 || date.month > 12)
    {
        return false;
    }
    if (date.day > getDaysOfMonth(date) || date.day < 1)
    {
        return false;
    }
    return true;
}
int Date::getDaysOfMonth(Date date)
{
    int num;
    switch (date.month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            num = 31;
            break;
        case 2:
            if (isLeapYear(date.year))
            {
                num = 29;
            } else{
                num = 28;
            }
            break;
        default:
            num = 30;
    }
    return num;
}

void Date::addDay(Date &date)
{
    date.day++;
    if (date.day > getDaysOfMonth(date))
    {
        date.day = 1;
        date.month++;
        if (date.month > 12)
        {
            date.month = 1;
            date.year++;
        }
    }
}

void Date::minDay(Date &date)
{
    date.day--;
    if (date.day < 1 )
    {
        if (date.month == 1)
        {
            date.day = 31;
            date.month = 12;
            date.year--;
        } else{
            Date date1(date.year,date.month-1,date.day);
            date.day = getDaysOfMonth(date1);
            date.month--;
        }

    }
}

//return 1 if date1 is earlier than date2,ohterwise return 0;
int Date::Compare(Date date1, Date date2)
{
    if (date1.year < date2.year)
    {
        return 1;
    }
    if (date1.year == date2.year && date1.month < date2.month)
    {
        return 1;
    }
    if (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day )
    {
        return 1;
    }
    return 0;
}

int Date::operator-(Date date1)
{
    long num = 0;
    Date date3 = *this;
    if(Compare(date3, date1) == 1)
    {
        while(Compare(date3,date1) == 1)
        {
            addDay(date3);
            num++;
        }
    }
    if (Compare(date3,date1) == 0)
    {
        while(Compare(date1,date3) == 1)
        {
            addDay(date1);
            num++;
        }
    }
    return num;
}

Date Date::operator+ (int day)
{
    Date date = *this;
    for (int i = 0; i < day; ++i) {
        addDay(date);
    }

    return date;
}

Date Date::operator++()
{
    addDay(*this);
    return *this;
}

Date Date::operator- (int day)
{
    Date date = *this;
    for (int i = 0; i < day; ++i) {
        minDay(date);
    }
    return date;
}

//为什么一定要加一个const
ostream& operator <<(ostream &out,const Date &date)
{
    out<<date.getYear()<<"/" << date.getMonth()<<"/" << date.getDay()<<endl;

    return out;
}
istream& operator>>(istream &in, Date &date)
{
    //        method 1) not using strtok()
    int year,month,day;
    char symbol1,symbol2;
    in >> year >> symbol1 >> month >> symbol2 >> day;
    if (symbol1 == '/' || symbol2 == '/')
    {
        Date date1(year,month,day);
        if (date1.isValid(date1))
        {
            date.setDay(day);
            date.setMonth(month);
            date.setYear(year);
        } else{
            cout << "Invalide date.";
        }

    }
//        method 2) using strtok()


//        char dateString[15];
//        in >> dateString;
//        const char symbol[2] = "/";
//        char *token;
//        token = strtok(dateString,symbol);
//        int year = atoi(token);
//        token = strtok(NULL,symbol);
//        int month = atoi(token);
//        token = strtok(NULL,symbol);
//        int day = atoi(token);
//        Date date1(year,month,day);
//        if (date1.isValid(date1))
//        {
//            date.setDay(day);
//            date.setMonth(month);
//            date.setYear(year);
//        } else{
//            cout << "Invalide date;";
//        }
    return in;
}

bool Date::operator<= (Date date)
{

    if (Compare(*this,date) == 1)
    {
        return true;
    } else{
        return false;
    }
}

bool Date::operator<(Date date)
{
    if (this->day == date.day && this->month == this->month && this->year == date.year)
    {
        return false;
    }
    if (Compare(*this,date) == 1)
    {
        return true;
    } else{
        return false;
    }
}