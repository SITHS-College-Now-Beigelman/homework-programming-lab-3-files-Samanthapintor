//Samantha Pintor
//Homework 3 Part 2 
//10-19-24

#include <iostream>
#include <fstream> 
#include <iomanip>

using namespace std; 

int main () 
{ 
    ifstream inFile; //input file stream variable
    ofstream outFile; //output file stream variable

    //creating variables 
    int startingAmount; //variable for starting amount  
    char transactionType; //variable for transaction type
    float balance, numberOfTransactions, transactionAmount, totalWithdrawalValue = 0.0, totalDepositValue = 0.0; 
   
    //open the files 
    inFile.open("inData.txt");
    outFile.open("outData.txt");

    //read the starting amount 
    inFile >> startingAmount; 
    balance = startingAmount; 
    
    cout << "TYPE......AMOUNT......BALANCE" << endl; //setting up the format
    
    setfill ("."); //set fill to periods 
    
    //when transaction is withdrawal
    while (inFile >> transactionType >> transactionAmount)
    {
        if (transactionType == 'W')
        {
            balance -= transactionAmount; //updatting the balance
            totalWithdrawalValue += transactionAmount; 
            cout << "W" << setw (6) << "." << -transactionAmount << setw(6) << "." << balance << endl; 
        }
        
        //when transaction is deposit 
        else if (transactionType == 'D')
        {
            balance += transactionAmount; //updatting the balance
            totalDepositValue += transactionAmount;
            cout << "D" << setw (6) << "." << transactionAmount << setw (6) << "." << balance << endl;
        }
    }    
    
    //close the files
    inFile.close(); 
    outFile.close(); 
    
    //calculation for balance at the end of the day 
    outFile << "Ending Balance = $" << balance << endl; 
    outFile << "Total Withdrawals = $" << totalWithdrawalValue << endl; 
    outFile << "Total Deposits = $" << totalDepositValue << endl; 


return 0; 
} 
