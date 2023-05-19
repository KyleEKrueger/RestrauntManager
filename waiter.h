//
// Created by kylekrueger on 4/14/23.
//
#include "employee.h"
#ifndef KITCHENMANAGER_WAITER_H
#define KITCHENMANAGER_WAITER_H
class waiter : public employee{
public:
    waiter(string name,int id, int serviceYears){
        //Waiter should take in a name, an id, and years of service when creating a new waiter
        myName = name;
        myProfitPercent = 0;
        myId = id;
        myDepartment = 'W';
        mySalary = 3000;
        myServiceYears = serviceYears;
    }
    int calculateSalary(int profit) override{
        if (profit > 0) {
            return (profit * myProfitPercent) + mySalary;
        }
        else return mySalary;
    }
    int getServiceYears(){
        return myServiceYears;
    }
protected:
    int myServiceYears;
};
#endif //KITCHENMANAGER_WAITER_H
