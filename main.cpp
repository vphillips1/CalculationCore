#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include "physics.h"


using namespace std;

/*
   math library
   fstream
   sstream


*/ 

int main()
{
	//READ IN FROM A FILE THE VALUES TO BE CALCULATED
	ifstream infile("uncalculated-physics.txt");
	ofstream outfile("calculated-physics.txt");

	if (!infile.is_open()) {
		cerr << "Error: Could not open uncalculated-physics.txt\n";
		return 1;
	}
	if (!outfile.is_open()) {
		cerr << "Error: Could not open calculated-physics.txt\n";
		return 1;
	}
	
	Physics physicsCalculator;
	string readLine;

	while(getline(infile, readLine)) 
	{
		if (readLine.empty())
		{
			continue;
		}
			
		istringstream iss(readLine);
		string calculationType;
		iss >> calculationType;

		// Average Velocity
		if (calculationType == "AverageVelocity") 
		{
			double initPosition, finalPosition, initTime, finalTime;
			iss >> initPosition >> finalPosition >> initTime >> finalTime;
			double result = physicsCalculator.findAverageVelocity(initPosition, finalPosition, initTime, finalTime);
			physicsCalculator.printAverageVelocityCalc(initPosition, finalPosition, initTime, finalTime);				outfile << "Average Velocity: " << result << " km/hr\n";
		}
		// Average Speed
		else if (calculationType == "AverageSpeed")
		{
			double initPosition, finalPosition, initTime, finalTime;
			iss >> initPosition >> finalPosition >> initTime >> finalTime;				double result = physicsCalculator.findAverageSpeed(initPosition, finalPosition, initTime, finalTime);
			physicsCalculator.printAverageSpeedCalc(initPosition, finalPosition, initTime, finalTime);
			outfile << "Average Speed: " << result << " km/hr\n";			
		}
		// Average Acceleration
		else if (calculationType == "AverageAcceleration") 
		{
			double initVelocity, finalVelocity, initTime, finalTime;
			iss >> initVelocity >> finalVelocity >> initTime >> finalTime;
			double result = physicsCalculator.findAverageAcceleration(initVelocity, finalVelocity, initTime, finalTime);
			outfile << "Average Acceleration: " << result << " m/s^2\n";
		}
		// Force Calculations
		else if (calculationType == "Force") 
		{
			double mass, acceleration;
			iss >> mass >> acceleration;
			double result = physicsCalculator.findForce(mass, acceleration);
			outfile << "Force: " << result << " N\n";
		}
		else if (calculationType == "Mass") 
		{
			double force, acceleration;
			iss >> force >> acceleration;
			double result = physicsCalculator.findMass(force, acceleration);
			outfile << "Mass: " << result << " kg\n";
		}
		else if (calculationType == "Acceleration") 
		{
			double force, mass;
			iss >> force >> mass;
			double result = physicsCalculator.findAcceleration(force, mass);
			outfile << "Acceleration: " << result << " m/s^2\n";
		}
	}
	
	return 0;
}
