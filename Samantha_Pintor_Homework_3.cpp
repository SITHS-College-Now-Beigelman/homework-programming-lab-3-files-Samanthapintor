//Samantha Pintor
//HW 3 
//10-19-24

#include <iostream>
#include <fstream> 
#include <iomanip>

using namespace std; 

int main () 
{ 
    ifstream inFile; //input file stream variable

    //creating variables 
    int startingAmount; //variable for starting amount  
    char transactionType; //variable for transaction type
    float balance, numberOfTransactions, transactionAmount; 
   
    //open the files 
    inFile.open("inData.txt");

    //read the starting amount 
    inFile >> startingAmount; 
    balance = startingAmount; 
    
    //run the code for 7 transactions 
    for (numberOfTransactions = 0; numberOfTransactions < 7; numberOfTransactions ++)
        inFile >> transactionType >> transactionAmount; //variables for inputs 
    
    cout << "TYPE......AMOUNT......BALANCE" << endl; //setting up the format
    
    setfill ("."); //set fill to periods 
    
    //when transaction is withdrawal
    if (transactionType == 'W')
    {
        balance -= transactionAmount; //updatting the balance
        cout << "W" << setw (6) << "." << -transactionAmount << setw(6) << "." << balance << endl; 
    }
    
    //when transaction is deposit 
    else if (transactionType == 'D')
    {
        balance += transactionAmount; //updatting the balance
        cout << "D" << setw (6) << "." << transactionAmount << setw (6) << "." << balance << endl;

    }
    
    
    //calculation for balance at the end of the day 
    cout << "Total Balance = " << balance << endl; 

    //close the files
    inFile.close();


return 0; 
} 

