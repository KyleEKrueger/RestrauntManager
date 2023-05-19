//
// Created by Kyle Krueger on 4/11/23.
//
//Variables that each employee should have: Name, EmployeeId, Employee Department, Salary, Profit sharing percentage
#include <iostream>
using namespace std;
#ifndef KITCHENMANAGER_EMPLOYEE_H
#define KITCHENMANAGER_EMPLOYEE_H
class employee{
    public:
        //Constructor with default variables
        explicit employee(short int id = 0, string name = "", char department = ' ', float profitPercent = 0, double salary = 0);
        //Display function to print out employee information.
        virtual int calculateSalary(int profit);
        virtual int getServiceYears();
        virtual string getChefSpecialty();
        int getID(){
            return myId;
        }
        string getName(){
            return myName;
        }
        char getDepartment(){
            return myDepartment;
        }
    protected:
        //Data that should be shared by all children
        short int myId;         //Employee Id
        string myName;          //Employee Name
        char myDepartment;      //Employee Type 'O' -Owner 'C' - Chef 'W' Waiter
        float myProfitPercent;  //Employee Profit sharing percentage (Float between 0-1)
        double mySalary;        //Employee Monthly Salary
};

inline employee::employee(short int id, string name, char department, float profitPercent, double salary )
    : myId(id), myName(name),myDepartment(department), myProfitPercent(profitPercent), mySalary(salary){}

int employee::calculateSalary(int profit) {
    //To be overridden in child classes
    return 0;
}

int employee::getServiceYears() {
    //To be overridden in child classes
    return 0;
}

string employee::getChefSpecialty() {
    //To be overridden in child classes
    return {};
}


//inline void employee::display (ostream & out) const {
//    out<< myId << ' ' << myName << ", " << myDepartment << endl;
//}
#endif //KITCHENMANAGER_EMPLOYEE_H

