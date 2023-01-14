#include <iostream>
#include <string>
#include <vector>
#include <ctime> 
#include <cstdlib> 
#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>

#include "func.hpp"

struct Track{
    //full name of the track
    std::string name;

    //track times should go: Covet, ETKI, Cherrier
    std::vector<int> times;
};

int main()
{
    //Creating the track objects: declare, name, times(covet, etki, cherrier)
    Track lumber_field_forward;
    lumber_field_forward.name = "Lumber Field Forward";
    lumber_field_forward.times = {202, 195, 180};

    Track lumber_field_reverse;
    lumber_field_reverse.name = "Lumber Field Reverse";
    lumber_field_reverse.times = {202, 195, 180};

    Track coastal_pass;
    coastal_pass.name = "Coastal Pass";
    coastal_pass.times = {180, 176, 165};

    Track castalleto_uphill;
     castalleto_uphill.name = "Castalleto Uphill";
     castalleto_uphill.times = {288, 264, 252};

    Track castalleto_downhill;
    castalleto_downhill.name = "Castalleto Downhill";
    castalleto_downhill.times = {266, 257, 244};

    Track portino_uphill;
    portino_uphill.name = "Portino Uphill";
    portino_uphill.times = {};

    Track portino_downhill;
    portino_downhill.name = "Portion Downhill";
    portino_uphill.times = {};

    int carInput;
    int trackInput;
    int difficultyInput;

    std::vector<std::string> track_names = {"Lumber Field Forward", "Lumber Field Reverse", "Coastal Pass", "Castalleto Uphill", "Castalletto Downhill", "Portino Uphill", "Portino Downhill"};
    std::vector<std::string> car_names = {"Ibishu Covet, Rally-Gravel", "ETK I-Series, Rally Gravel", "Cherrier, Rally Gravel"};
    std::vector<std::string> difficulty_names = {"Easy", "Medium", "Hard"};
    std::vector<double> difficulty_multiplyers = {1.08, 1.0, 0.96};

    std::vector<Track> track_objects = {lumber_field_forward, lumber_field_reverse, coastal_pass, castalleto_uphill, castalleto_downhill, portino_uphill, portino_downhill};
    
   pickMap(carInput, trackInput, difficultyInput);

   std::cout << "Track: " << track_names[trackInput - 1] << "\nCar: " << car_names[carInput -1] << "\nDifficulty: " << difficulty_names[difficultyInput -1] << std::endl;

   double average_time_selected = track_objects[trackInput -1].times[carInput - 1] * difficulty_multiplyers[difficultyInput - 1];

   printTimes(createTimes(average_time_selected));
}
