#include <iostream>
#include <fstream>
#include "owner.h"
#include "chef.h"
#include "waiter.h"

void loadPriorMonth();
void saveCurrentMonth();
void inputCurrentMonth();
void displayEmployeeInfo(employee* currentEmployee, int tips);
void displayAllEmployees();
bool fileExists(string filename);
const int EMPLOYEECOUNT = 6; //Global variable of how many employees the company has
const int WAITERCOUNT = 3;
int thisMonthProfit = 0;
int waiterTips[WAITERCOUNT];
employee *employeeData[EMPLOYEECOUNT] = {
        new owner("Kyle"), new chef("Katie",2,"Indian"), new chef ("Marcus",3,"Italian"),
        new waiter("James",4,3), new waiter("Noah",5,5), new waiter ("Brett",6,7)
};
int main() {
    //Declarations
    char menuSelection = 'M'; // Menu selection variable, M for menu, E for exit, L for load month, I for input month, S for save month
    string menuPrompt = "\n-----Pho-ache Dining Experience-----\nI - Input current month's statistics\nS - Save current month's statistics\nL - Load previously saved month\nD - Display current entered month (Recommended before saving)\nE- Exit application\n---------------------\n";
    int j = 0;
    //Employee List Instantiation


    //---MENU LOOP---
    while (menuSelection != 'E'){
        cout << menuPrompt;
        cin >> menuSelection;
        //Loading previous month
        if (menuSelection == 'L' || menuSelection == 'l') loadPriorMonth();
        //Saving current month
        if (menuSelection == 'S' || menuSelection == 's') saveCurrentMonth();
        //Inputting current month
        if (menuSelection == 'I' || menuSelection == 'i') inputCurrentMonth();
        //Displaying current month
        if (menuSelection == 'D' || menuSelection == 'd') displayAllEmployees();
    }
    return 0;
}

void loadPriorMonth(){
    //Variables
    string loadDate;
    string line;
    //Get the file name from user
    cout<<"Input the date of the month you would like to load (format mmyyyy, ie April 1992 is 041992)";
    cin >> loadDate;
    //Open file, display file contents, close file
    if (fileExists(loadDate)){
        ifstream file(loadDate);
        while (getline(file,line)){
            cout<<line<<endl;
        }
        file.close();
    }
}
void saveCurrentMonth(){
    //Ask for month and year, then make a file if one does not exist. If one exists, ask to overwrite
    string currentDate;
    string answer;
    std::streambuf* coutbuf = std::cout.rdbuf(); //Save default cout buffer
    //Gather file name
    cout<<"Input current month and year (ie April 1992 would be '041992') "<<endl;
    cin>>currentDate;
    //Check if the filename exists
    if (fileExists(currentDate)){
        //File Exists, ask to overwrite
        cout<<endl<<"The file currently exists. Overwrite it? (yes or no)";
        while (answer != "yes" || answer != "no"){
            cin >> answer;
        }
        if (answer == "no"){
            cout<<"Data not saved, exiting to menu...\n";
            return;
        }
    }
    else{
        //File doesn't exist, create and output current month's data to file
        std::ofstream file(currentDate);
        if (file.is_open()){
            std::cout << "File created. Writing data\n";
            std::cout.rdbuf(file.rdbuf()); //Change cout to the file
            cout<<currentDate<<endl;
            displayAllEmployees();
            std::cout.rdbuf(coutbuf); // Return cout to original
            file.close();
            cout<<"File saved successfully.";
        }
        else{
            std::cerr<<"Error opening file\n";
        }
    }
}
void inputCurrentMonth(){
    //Function will gather information about the month's data including profit, and tips
    cout<<"Enter this month's profit: ";
    cin >> thisMonthProfit;
    cout <<endl;

    int j = 0;
    for (int i=0;i<EMPLOYEECOUNT; i++){
        //Loop through each employee and check if it is a waiter, then ask to input tips for the waiter
        if(employeeData[i]->getDepartment()== 'W'){
            cout<<"Enter tips for "<<employeeData[i]->getName()<<endl;
            cin>>waiterTips[j];
            j++;
        }
    }

}
void displayEmployeeInfo(employee* currentEmployee, int tips){
    cout<<"Employee: " << currentEmployee->getName() << " id: " << currentEmployee->getID() << " salary: ";
    //Salary Calculations
    if (currentEmployee-> getDepartment() == 'W'){
        //Waiter
        cout << currentEmployee->calculateSalary(thisMonthProfit) + tips << " Job Title: Waiter for "<<currentEmployee->getServiceYears()<<" years.";
    }
    else{
        //Owner and Chefs
        cout << currentEmployee->calculateSalary(thisMonthProfit)<< " Job Title: ";
        if (currentEmployee->getDepartment() == 'C'){
            //Chefs
            cout<<currentEmployee->getChefSpecialty()<<" Chef";
        }
        else{
            //Owner
            cout<<"Owner";
        }
    }
    cout<<endl;
}
bool fileExists(string filename){
    //Checks if a file exists
    ifstream file(filename);
    return file.good();
}

void displayAllEmployees(){
    //Loops through all employees, passes tips along with the waiter who receieved the tips.
    int j = 0;
    for (int i = 0; i < EMPLOYEECOUNT; i++){
        if(employeeData[i]->getDepartment() == 'W'){
            displayEmployeeInfo(employeeData[i],waiterTips[j]);
            j++;
        }
        else{
            displayEmployeeInfo(employeeData[i],0);
        }
    }
}

