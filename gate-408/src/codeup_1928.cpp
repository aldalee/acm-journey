//  日期差值 Codeup1928
// Created by HuanyuLee on 2022/1/6.
//
#include <iostream>
using namespace std;
struct Date{
    int year;
    int month;
    int day;
};
int months[13][2] = {
        {0,0},
        {31,31},
        {28,29},
        {31,31},
        {30,30},
        {31,31},
        {30,30},
        {31,31},
        {31,31},
        {30,30},
        {31,31},
        {30,30},
        {31,31}
};
// 闰年返回 1 平年返回 0
int isLeap(int year){
    if ((year%4 == 0 && year%100 != 0) || (year%400 == 0))
        return 1;
    else
        return 0;
}
Date getDate(int inputDate,Date date){
    date.year = inputDate/10000;
    date.month = inputDate%10000/100;
    date.day = inputDate%100;
    return date;
}
int calculateDays(int temp1,int temp2,Date date1,Date date2){
    if (temp1 > temp2){
        int temp = temp1;
        temp1 = temp2;
        temp2 = temp;
    }
    date1 = getDate(temp1,date1);
    date2 = getDate(temp2,date2);
    int days = 1;
    while (date1.year<date2.year || date1.month < date2.month || date1.day < date2.day){
        date1.day++;
        if (date1.day == months[date1.month][isLeap(date1.year)]+1){
            date1.month++;
            date1.day = 1;
        }
        if (date1.month == 13){
            date1.year++;
            date1.month = 1;
        }
        days++;
    }
    return days;
}
int main(){
    int temp1,temp2;
    Date date1{},date2{};
    while (cin >> temp1 >> temp2){
        cout << calculateDays(temp1,temp2,date1,date2) << endl;
    }
    return 0;
}
