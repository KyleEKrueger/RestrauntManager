//
// Created by kylekrueger on 4/14/23.
//
#include "employee.h"
#ifndef KITCHENMANAGER_OWNER_H
#define KITCHENMANAGER_OWNER_H
class owner : public employee{
    public:
    owner(string name){
//There is only one owner. Owner will always be id #1
        myName = name;
        myProfitPercent = 0.6;
        myId = 1;
        myDepartment = 'O';
        mySalary = 15000;
    }
    int calculateSalary(int profit) override{
        if (profit > 0) {
            return (profit * myProfitPercent) + mySalary;
        }
        else return mySalary;
    }

};
#endif //KITCHENMANAGER_OWNER_H
