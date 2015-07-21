/* OOP244 - W3
 * Date: 31/05/2015
 * Created by: Franz Newland
 * Edited by: Larissa Voigt
 * Description: Source code - Dynamic memory workshop*/

#include <iostream>
#include "Weather.h"
using namespace std;

int main(){
    int n; //the count of days worth of weather

    //static memory

    cout << "Weather Data\n";
    cout << "=====================" << endl;
    cout << "Days of Weather: ";
    cin >> n;
    cin.ignore();
    //dynamic memory

    Weather *weather = new Weather[n];

    for(int i = 0; i < n; i++){
        char date_description[31];
        double high, low;

        Weather *w = new Weather;

        cout << "Enter date: ";
        cin.getline(date_description, SIZE);

        cout << "Enter high: ";
        cin >> high;
        cin.ignore();

        cout << "Enter low: ";
        cin >> low;
        cin.ignore();

        w->set(date_description, high, low);

        weather[i] = *w;

    }
    cout << endl;
    cout << "Weather report:\n";
    cout << "==================" << endl;

    for(int i = 0; i < n; i++){
        weather[i].display();
        cout << endl;
    }

    delete [] weather;

    return 0;

}
