//
// Created by kylekrueger on 4/14/23.
//
#include "employee.h"
#ifndef KITCHENMANAGER_CHEF_H
#define KITCHENMANAGER_CHEF_H
class chef : public employee{
public:
    chef(string name,int id, string cuisine){
        //Chef should take in a name, and id number, and a cuisine specialty when creating an employee
        myName = name;
        myProfitPercent = 0.2;
        myId = id;
        myDepartment = 'C';
        mySalary = 10000;
        myCuisine = cuisine;
    }
    int calculateSalary(int profit) override{
                if (profit > 0) {
                    return (profit * myProfitPercent) + mySalary;
                }
                else return mySalary;
        }
    string getChefSpecialty() override{
        return myCuisine;
    }
protected:
    string myCuisine;
};
#endif //KITCHENMANAGER_CHEF_H
