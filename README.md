//Samantha Pintor
//HW 3 
//10-15-24
#include <iostream> 
#include <iomanip>
#include <string> 
#include <fstream> 

using namespace std; 

int main ()
{ 
    ifstream inFile; //input file stream variable 
    ofstream outFile; //output file stream variable

    //creating variables 
    int startingAmount; //variable for starting amount  
    int amountOne, amountTwo, amountThree, amountFour, amountFive, amountSix, amountSeven; //variable for the seven amounts 
    char W; //variable for withdrawal
    char D; //variable for deposit 
    int balance; //variable for balance at the end of the day
    
    //open the files 
    inFile.open("inData.txt");
    outFile.open("outData.txt");

    //input
    inFile >> startingAmount >> W >> amountOne >> W >> amountTwo >> W >> amountThree >> D >> amountFour >> D >> amountFive >> D >> amountSix >> W >> amountSeven; //input the starting amount, withdrawal/deposit and seven values 
    
    //calculation
    int balance = startingAmount - amountOne - amountTwo - amountThree + amountFour + amountFive + amountSix - amountSeven; //calculating the balance at the end of the transactions

    //output 
    outFile << startingAmount << endl << W << " " << amountOne << endl << W << " " << amountTwo << endl << W << " " << amountThree << endl << D << " " << amountFour << endl 
            << D << " " << amountFive << endl << D << " " << amountSix << endl << W << " " << amountSeven << endl << balance; //output starting amount, seven numbers and withdrawal/deposit, and finally the balance
    
    //close the files
    inFile.close();
    outFile.close();

    return 0; 
}

/*
Input: 
5000
W 200
W 800
W 40
D 90
D 100
D 1000
W 20

Output: 
5000
W 200
W 800
W 40
D 90
D 100
D 1000
W 20
5130
*/
