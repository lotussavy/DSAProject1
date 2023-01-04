/*
Name: Kamal Acharya
UID:U00997907
Project Name: Simulating Dice Rolls
Description:
This is the program that prompt the user for the number of rolls to make in two dice. 
It then simulate two (6-sided) dice tosses per roll using the C++ rand() function for each individual dice toss.
Arrays are used to keep the numbers that appeared on two dices as well as the sum of the numbers.
The number of times each total was rolled is then printed. The random number generator is seeded with the time 
to ensure that we get new random outputs each time we run the program.
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
    //Defining local Variables used in the program
    int result[12]={0,0,0,0,0,0,0,0,0,0,0},count;


    //Code to prompt the user input for the number of simulation
    cout<<"How many rolls? ";
    cin>>count;

    //Code for allocating memory to dices and their sum
    int *dice1 = new int(count);
    int *dice2 = new int(count);
    int *sum = new int(count);

    //Function to generate random number seeded with time
    srand(time(NULL));


    // Code to simulate the dice and sum
    for ( int i = 0; i < count; i++)
    {
        dice1[i]= (rand()%6) +1;
        dice2[i]= (rand()%6) +1;
        sum[i]= dice1[i] + dice2[i];   
        //cout<< sum[i] <<endl;
    }


    //Code to find the number of times each sum appeared in the simulation
    for (int i = 0; i < count; i++)
    {
        for (int j = 2; j < 13; j++)
        {
            if(sum[i] == j)
            {
                result[j-2]++;
            }
        }
        
    }


    //Code to print the result
    cout<<"Simulating "<< count  <<" rolls..."<<endl;
    cout<<"Resutls:"<<endl;
    for (int i = 0; i < 11; i++)
    {
        cout<< i+2 <<" was rolled " << result[i] <<" times" <<endl;
    }

    // Code to delete the memory allocated
    delete [] dice1;
    delete [] dice2;
    delete [] sum;
    
    return 0;
    
}