#include <iostream>
#include <string>
#include <vector>
#include <ctime> 
#include <cstdlib> 
#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>

//Uses the vector created to print out the time that starts as seconds and prints it into minutes, seconds, and thousandths of a second
void printTimes(std::vector<double> times)
{
    int count = 0;
    for(double n : times)
    {   
        count++;
        int dropped_decimal = std::floor(n);
        
        //check for terminal damage code
        if(n == 1000)
        {
            std::cout << count << ". Terminal Damage\n";
            continue;
        }
       
       //outputs the place, then calculates mintues
        std::cout << count << ". " << std::floor(n / 60) << ".";

        //takes outputs the seconds
        std::cout << std::setw(2) << std::setfill('0') << dropped_decimal%60 << "."; 

        //makes it always have 3 spots, original - only the whole numbers, then *1000 to get whole number of the decimals (123.123 - 123) * 1000 =123
        std::cout << std::setw(3) << std::setfill('0') << (n - dropped_decimal) * 1000<< "\n";
    }
}

//creates a vector of times that are randomly generated around the specific default time
std::vector<double> createTimes(double def_time)
{
    std::srand((unsigned)time(0));
    std::vector<double> times;
    
    for(int i = 0; i < 11; i++)
    {


        //TERMINAL DAMAGE
        //gives code if 1 in 150 chance
        int terminal_damage = rand()%151;
        if(terminal_damage == 150)
        {
            times.push_back(1000);
            continue;
        }

        //MAIN CALCULATION
        //average time plus or minus 10 seconds then a random thousands of a seconds value
        double time_calc = def_time + ((rand()%21) - 10) + (rand()%1000)/1000.0;

        
        //MISTAKES
        //makes a 50% chanch of making a mistake then another 50% chance of making a mistake until it doesn't roll a 1
         int mistake = rand()%2;
        while(mistake == 1){
            time_calc += 1.5;
            mistake = rand()%2;
            
        }

        //FLAT
        int flat = rand()%36;
        if(flat == 1)
        {
            time_calc += rand()%46;
            
        }

        //SUSPENSION FAILURE
        int sus_fail = rand()%70;
        if(sus_fail == 1)
        {
            time_calc += rand()%6;
            
        }

        //ENGINE MALFUNCTION
        int eng_mal = rand()%101;
        if(eng_mal == 1)
        {
            time_calc += rand()%90 - 1;
            
        }

        //BRAKE ISSUES
        int brake_issue = rand()%81;
        if(brake_issue == 1)
        {
            time_calc += rand()%61;
            
        }

        //TRANSMISSION ISSUES
        int trans_issues = rand()%61;
        if(trans_issues == 1)
        {
            time_calc += rand()%21;
            
        }
        
        times.push_back(time_calc);
       
    }
    std::sort(times.begin(), times.end());
    return times;
}

//takes input for track, car, and difficulty
void pickMap(int& carInput, int& trackInput, int& difficultyInput)
{
    //Track choosing
    std::cout << "Please pick one of the courses down below, just enter the number.\n\n";
    std::cout << "East Coast:\n" << "\t1. Lumber Field Forward\n" << "\t2. Lumber Field Reverse\n" << "\t3. Coastal Pass\n";
    std::cout << "Italy:\n" << "\t4. Castalletto Uphill\n" << "\t5. Castalletto Downhill\n";
    std::cin >> trackInput;

    //Car choosing
    std::cout << "Please pick a car, enter the number corresponding to the car.\n\n";
    std::cout << "\t1. Ibishu Covet, Rally-Gravel\n" << "\t2. ETK I-Series, Rally-Gravel\n" << "\t3. Cherrier Rally Gravel\n";
    std::cin >> carInput;

    //Difficulty choosing
    std::cout << "Please choose a difficulty:\n";
    std::cout << "\t1. Easy\n" << "\t2. Medium\n" << "\t3. Hard\n";
    std::cin >> difficultyInput;
}
