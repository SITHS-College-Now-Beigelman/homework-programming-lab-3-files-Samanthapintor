//Samantha Pintor
//HW 3 
//10-20-24


#include <iostream>
#include <fstream> 
#include <iomanip>

using namespace std; 

int main () 
{ 
    ifstream inFile; //input file stream variable

    //creating variables 
    int totalMoney; //variable for starting amount  
    char transactionType; //variable for transaction type
    float numberOfTransactions, transactionAmount; 

    //open the files 
    inFile.open("inData.txt");

    //read the starting amount 
    inFile >> totalMoney; 

    cout  << totalMoney << endl; //cout starting amount

    cout << "TYPE......AMOUNT......BALANCE" << endl; //setting up the format

    setfill ("."); //set fill to periods 

    //run the code for 7 transactions 
    for (numberOfTransactions = 0; numberOfTransactions < 7; numberOfTransactions ++)
    {
        inFile >> transactionType >> transactionAmount; //variables for inputs 

    //when transaction is withdrawal
    if (transactionType == 'W')
    {
        totalMoney -= transactionAmount; //updatting the balance
        cout << "W" << "......" << -transactionAmount << "......." << totalMoney << endl; 
    }

    //when transaction is deposit 
    else if (transactionType == 'D')
    {
        totalMoney += transactionAmount; //updatting the balance
        cout << "D" << "......" << transactionAmount << "......" << totalMoney << endl;

    }
    }

    //calculation for balance at the end of the day 
    cout << "Total Balance = " << totalMoney << endl; 

    //close the files
    inFile.close();

return 0; 
} 

/*
5000
TYPE......AMOUNT......BALANCE
W......-200......4800
W......-800......4000
W......-40......3960
D......90......4050
D......100......4150
D......1000......5150
W......-20......5130
Total Balance = 5130
*/
