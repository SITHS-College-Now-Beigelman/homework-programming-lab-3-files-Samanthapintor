//Samantha Pintor
//Homework 3 Part 2 
//10-20-24

#include <iostream>
#include <fstream> 
#include <iomanip>

using namespace std; 

int main () 
{ 
    ifstream inFile; //input file stream variable
    ofstream outFile; //output file stream variable

    //creating variables 
    int totalMoney; //variable for starting amount  
    int numberWithdrawal = 0, numberDeposit = 0, numberTransactions = 0; //variables for number of withdrawals and deposits and transactions
    char transactionType = 0; //variable for transaction type
    float transactionAmount = 0, totalWithdrawalValue = 0.0, totalDepositValue = 0.0; 

    //open the files 
    inFile.open("inData.txt");
    outFile.open("outData.txt");

    //read the starting amount 
    inFile >> totalMoney; 

    outFile  << totalMoney << endl; //cout starting amount

    outFile << "TYPE......AMOUNT......BALANCE" << endl; //setting up the format

    setfill ('.'); //setting fill to periods

    //run the code for 7 transactions 
    while (!inFile.eof()) //variables for inputs    
    {
        inFile >> transactionType >> transactionAmount; //reads transaction type and amount
        numberTransactions ++; //number of transactions increases

    
        //when transaction is withdrawal
        if (transactionType == 'W')
        {
            numberWithdrawal ++; 
            totalMoney -= transactionAmount; //updatting the balance
            totalWithdrawalValue += transactionAmount; //updatting withdrawal amount
            outFile << "W" << "......"<< -transactionAmount << "......" << totalMoney << endl; 
        }
    
        //when transaction is deposit 
        else if (transactionType == 'D')
        {
            numberDeposit ++; 
            totalMoney += transactionAmount; //updatting the balance
            totalDepositValue += transactionAmount; //updatting withdrawal amount
            outFile << "D" << "......" << transactionAmount << "......" << totalMoney << endl;
    
        }
        }
    
    //calculation for balance at the end of the day 
    outFile << "Ending Balance = $" << totalMoney << endl; 
    outFile << "Number of total transactions = " << numberTransactions << endl;
    outFile << "Total Withdrawals = $" << totalWithdrawalValue << endl; 
    outFile << "Number of Withdrawals = " << numberWithdrawal << endl;
    outFile << "Total Deposits = $" << totalDepositValue << endl; 
    outFile << "Number of Deposits = " << numberDeposit << endl;

    //close the files
    inFile.close();
    outFile.close();

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
Ending Balance = $5130
Number of total transactions = 7
Total Withdrawals = $1060
Number of Withdrawals = 4
Total Deposits = $1190
Number of Deposits = 3
*/


