//
//  main.cpp
//  bsr160130_Project5
//  CS 1337.503
//
//  Created by Bradley Ritschel on 11/29/17.
//  Copyright © 2017 Bradley Ritschel. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>

using namespace std;

string eraseSpace(string str) {
    string::iterator end_pos = remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
    return str;
}

int validateInput(int &input, const int min, const int max) { //input is passed and interval of acceptable numerical input must be given
    //We are taking a string in for ease of use and so that 1,000 with a comma is acceptable
    cin >> input;
    
    while (cin.fail() || input < min || input > max) {
        cout << "You must enter a number between " << min << " and " << max << " " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> input;
    }
    return input;
}


class planet {
    public:
        string name;
        int distanceFromSun;
        double surfaceGravityFactor;
};

class shuttle {
    public:
        string cargoType;
        string pickupPlanet;
        string deliveryPlanet;
        int speedMillionsMPH;
        int millionsOfMilesToTravel;
        int weightPickupPlanetPounds;
        int weightDeliveryPlanetPounds;
        int weightEarthPounds;
        int travelTimeHours;
        int travelTimeDays;
        int travelTimeYears;
};

void runShipment() {
    ifstream file("Planet_Data.txt");
    string planetDataString;
    getline(file, planetDataString);
    cout << planetDataString << endl;
    
    planet Mercury;
    Mercury.name = planetDataString.substr(0,8);
    planetDataString.erase(0,8);
    
    Mercury.name = eraseSpace(Mercury.name);
    cout << Mercury.name << endl;

    Mercury.distanceFromSun = stoi(planetDataString.substr(0,5));
    planetDataString.erase(0,5);
    cout << Mercury.distanceFromSun << endl;
    
    Mercury.surfaceGravityFactor = stod(planetDataString.substr(0,4));
    planetDataString.erase(0,4);
    cout << Mercury.surfaceGravityFactor << endl;
    
    planet Venus;
    Venus.name = planetDataString.substr(0,8);
    planetDataString.erase(0,8);
    
    Venus.name = eraseSpace(Venus.name);
    cout << Venus.name << endl;
    
    Venus.distanceFromSun = stoi(planetDataString.substr(0,5));
    planetDataString.erase(0,5);
    cout << Venus.distanceFromSun << endl;
    
    Venus.surfaceGravityFactor = stod(planetDataString.substr(0,4));

    planetDataString.erase(0,4);
    cout << Venus.surfaceGravityFactor << endl;
    
    planet Earth;
    Earth.name = planetDataString.substr(0,8);
    planetDataString.erase(0,8);
    
    Earth.name = eraseSpace(Earth.name);
    cout << Earth.name << endl;
    
    Earth.distanceFromSun = stoi(planetDataString.substr(0,5));
    planetDataString.erase(0,5);
    cout << Earth.distanceFromSun << endl;
    
    Earth.surfaceGravityFactor = stod(planetDataString.substr(0,4));
    
    planetDataString.erase(0,4);
    cout << Earth.surfaceGravityFactor << endl;
    
    planet Mars;
    Mars.name = planetDataString.substr(0,8);
    planetDataString.erase(0,8);
    
    Mars.name = eraseSpace(Mars.name);
    cout << Mars.name << endl;
    
    Mars.distanceFromSun = stoi(planetDataString.substr(0,5));
    planetDataString.erase(0,5);
    cout << Mars.distanceFromSun << endl;
    
    Mars.surfaceGravityFactor = stod(planetDataString.substr(0,4));
    planetDataString.erase(0,4);
    cout << Mars.surfaceGravityFactor << endl;
    
    planet Jupiter;
    Jupiter.name = planetDataString.substr(0,8);
    planetDataString.erase(0,8);
    
    Jupiter.name = eraseSpace(Jupiter.name);
    cout << Jupiter.name << endl;
    
    Jupiter.distanceFromSun = stoi(planetDataString.substr(0,5));
    planetDataString.erase(0,5);
    cout << Jupiter.distanceFromSun << endl;
    
    Jupiter.surfaceGravityFactor = stod(planetDataString.substr(0,4));
    planetDataString.erase(0,4);
    cout << Jupiter.surfaceGravityFactor << endl;
    
    planet Saturn;
    Saturn.name = planetDataString.substr(0,8);
    planetDataString.erase(0,8);
    
    Saturn.name = eraseSpace(Saturn.name);
    cout << Saturn.name << endl;
    
    Saturn.distanceFromSun = stoi(planetDataString.substr(0,5));
    planetDataString.erase(0,5);
    cout << Saturn.distanceFromSun << endl;
    
    Saturn.surfaceGravityFactor = stod(planetDataString.substr(0,4));

    planetDataString.erase(0,4);
    cout << Saturn.surfaceGravityFactor << endl;
    
    planet Uranus;
    Uranus.name = planetDataString.substr(0,8);
    planetDataString.erase(0,8);
    
    Uranus.name = eraseSpace(Uranus.name);
    cout << Uranus.name << endl;
    
    Uranus.distanceFromSun = stoi(planetDataString.substr(0,5));
    planetDataString.erase(0,5);
    cout << Uranus.distanceFromSun << endl;
    
    Uranus.surfaceGravityFactor = stod(planetDataString.substr(0,4));
    planetDataString.erase(0,4);
    cout << Uranus.surfaceGravityFactor << endl;
    
    planet Neptune;
    Neptune.name = planetDataString.substr(0,8);
    planetDataString.erase(0,8);
    
    Neptune.name = eraseSpace(Neptune.name);
    cout << Neptune.name << endl;
    
    Neptune.distanceFromSun = stoi(planetDataString.substr(0,5));
    planetDataString.erase(0,5);
    cout << Neptune.distanceFromSun << endl;
    
    Neptune.surfaceGravityFactor = stod(planetDataString.substr(0,4));
    cout << Neptune.surfaceGravityFactor << endl;
    
    planet * planets[8];
        
    planets[0] = &Mercury;
    planets[1] = &Venus;
    planets[2] = &Earth;
    planets[3] = &Mars;
    planets[4] = &Jupiter;
    planets[5] = &Saturn;
    planets[6] = &Uranus;
    planets[7] = &Neptune;

    shuttle currentShuttle;
    
    string cargo;
    cout << "Please enter the cargo type: ";
    cin >> cargo;
    currentShuttle.cargoType = cargo;
    
    string pickupPlanet;
    do {
        cout << "Your options are Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, and Neptune. Enter the pickup planet: ";
        cin >> pickupPlanet;
        currentShuttle.pickupPlanet = pickupPlanet;
    } while ((pickupPlanet != "Mars")
             &&(pickupPlanet != "Saturn")
             &&(pickupPlanet != "Jupiter")
             &&(pickupPlanet != "Earth")
             &&(pickupPlanet != "Venus")
             &&(pickupPlanet != "Mercury")
             &&(pickupPlanet != "Uranus")
             &&(pickupPlanet != "Neptune"));
    
    string deliveryPlanet;
    do {
        cout << "Your options are Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, and Neptune. Enter the delivery planet: ";
        cin >> deliveryPlanet;
        currentShuttle.deliveryPlanet = deliveryPlanet;
    }
    while (((deliveryPlanet != "Mars")
           &&(deliveryPlanet != "Saturn")
           &&(deliveryPlanet != "Jupiter")
           &&(deliveryPlanet != "Earth")
           &&(deliveryPlanet != "Venus")
           &&(deliveryPlanet != "Mercury")
           &&(deliveryPlanet != "Uranus")
           &&(deliveryPlanet != "Neptune"))
           ||(currentShuttle.pickupPlanet == currentShuttle.deliveryPlanet));
    
    int speed;
    cout << "Please enter the speed of the shuttle in millions of MPH: ";
    currentShuttle.speedMillionsMPH = validateInput(speed, 0, 670);
    
    int pickupLocationFromSun = 0;
    int deliveryLocationFromSun = 0;
    
    double pickupSurfaceGravityFactor = 0;
    double deliverySurfaceGravityFactor = 0;
    
    for (int i=0; i<8; i++){
        if (planets[i]->name == currentShuttle.pickupPlanet) {
            pickupLocationFromSun = planets[i]->distanceFromSun;
            pickupSurfaceGravityFactor = planets[i]->surfaceGravityFactor;
            cout << "Pickup location distance from sun: " << pickupLocationFromSun << endl;
            cout << "Pickup surface gravity factor: " << pickupSurfaceGravityFactor << endl;
        }
        if (planets[i]->name == currentShuttle.deliveryPlanet) {
            deliveryLocationFromSun = planets[i]->distanceFromSun;
            deliverySurfaceGravityFactor = planets[i]->surfaceGravityFactor;
            cout << "Delivery location distance from sun: " << deliveryLocationFromSun << endl;
            cout << "Delivery surface gravity factor: " << deliverySurfaceGravityFactor << endl;
        }
    }
    currentShuttle.millionsOfMilesToTravel = abs(pickupLocationFromSun - deliveryLocationFromSun);
    cout << "For this delivery, the shuttle must travel " << currentShuttle.millionsOfMilesToTravel << " million miles." << endl;

    cout << "Please enter the weight of the cargo in pickup planet pounds: ";
    currentShuttle.weightPickupPlanetPounds = validateInput(currentShuttle.weightPickupPlanetPounds, 0, 200000);
    
    currentShuttle.weightEarthPounds = (currentShuttle.weightPickupPlanetPounds * (Earth.surfaceGravityFactor / pickupSurfaceGravityFactor));
    currentShuttle.weightDeliveryPlanetPounds = (currentShuttle.weightPickupPlanetPounds * (deliverySurfaceGravityFactor/pickupSurfaceGravityFactor));
    
    while (cin.fail() || currentShuttle.weightEarthPounds < 0 || currentShuttle.weightEarthPounds > 20000) {
        cout << "You must enter a number between " << 0 << " and " << 20000 << " " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> currentShuttle.weightPickupPlanetPounds;
        currentShuttle.weightEarthPounds = (currentShuttle.weightPickupPlanetPounds * (Earth.surfaceGravityFactor/pickupSurfaceGravityFactor));
        currentShuttle.weightDeliveryPlanetPounds = (currentShuttle.weightPickupPlanetPounds * (deliverySurfaceGravityFactor/pickupSurfaceGravityFactor));
    }
    cout << "The weight in pickup planet pounds is " << currentShuttle.weightPickupPlanetPounds << endl;
    cout << "The weight in delivery planet pounds is " << currentShuttle.weightDeliveryPlanetPounds << endl;
    cout << "The weight in earth pounds is " << currentShuttle.weightEarthPounds << endl;
    
    int totalHoursToTravel = currentShuttle.millionsOfMilesToTravel/currentShuttle.speedMillionsMPH;
    cout << "The shuttle must travel " << totalHoursToTravel << " total hours." << endl;
    
    currentShuttle.travelTimeHours = totalHoursToTravel % 24;
    int totalDaysToTravel = totalHoursToTravel/24;
    currentShuttle.travelTimeDays = totalDaysToTravel % 365;
    currentShuttle.travelTimeYears = currentShuttle.travelTimeDays/365;
    cout << "In other words, the shuttle must travel " << currentShuttle.travelTimeHours << " hours, " << currentShuttle.travelTimeDays << " days, and " << currentShuttle.travelTimeYears << " years." << endl;
    

    ofstream deliveryReport("Delivery_Report.txt", ios_base::app);
    if (deliveryReport.is_open()) {
        deliveryReport << "Cargo: " << currentShuttle.cargoType << endl
        << "Weight (lbs) of the cargo on Earth: " << currentShuttle.weightEarthPounds << endl
        << "Weight (lbs) of the cargo on the pickup planet: " << currentShuttle.weightPickupPlanetPounds << endl
        << "Weight (lbs) of the cargo on the delivery planet: " << currentShuttle.weightDeliveryPlanetPounds << endl
        << "Distance (millions of miles) the shipment will travel: " << currentShuttle.millionsOfMilesToTravel << endl
        << "The time it will take to deliver the cargo: " << currentShuttle.travelTimeHours << " hours, " << currentShuttle.travelTimeDays << " days, and " << currentShuttle.travelTimeYears << " years." << endl
        << "——————————" << endl;
        deliveryReport.close();
    }
    else
        cout << "Unable to open file";
    
}

bool askAnotherShipment() {
    cout << "Would you like to enter another shipment? (Y/N): ";
    char answer;
    cin >> answer;
    if (toupper(answer) == 'Y')
        return true;
    else if (toupper(answer) == 'N')
        return false;
    else
        cout << "ERROR: Please enter 'Y' or 'N'" << endl;
    return askAnotherShipment();
}

int main() {
    do {
        runShipment();
    } while (askAnotherShipment());
    cout << "Your shipments have been saved. The program will now close." << endl;
    return 0;
}
