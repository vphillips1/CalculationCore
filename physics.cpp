#include "physics.h"
#include <iostream>
using namespace std;

Physics::Physics()
{
	force = 0.0;
	mass = 0.0;
	acceleration = 0.0;
	initPosition = 0.0;
	finalPosition = 0.0;
	initTime = 0.0;
	finalTime = 0.0;
	finalPosition = 0.0;
}

Physics::~Physics()
{
}

double Physics::findAverageVelocity(double initPosition, double finalPosition, double initTime, double finalTime)
{
	if (finalTime - initTime != 0)
	{
		return (finalPosition - initPosition) / (finalTime - initTime);
	}
	return 0.0;
}

void Physics::printAverageVelocityCalc(double initPosition, double finalPosition, double initTime, double finalTime)
{
	double avgVelocity = findAverageVelocity(initPosition, finalPosition, initTime, finalTime);
	cout << "Numbers given were: " << endl;
	cout << "Initial Position: " << initPosition << " km" << endl;
	cout << "Final Position: " << finalPosition << " km" << endl;
	cout << "Initial Time: " << initTime << " hr" << endl;
	cout << "Final Time: " << finalTime << " hr" << endl;
	cout << "Calculated Average Velocity: " << avgVelocity << " km/hr" << endl;
}

double Physics::findAverageSpeed(double initPosition, double finalPosition, double initTime, double finalTime)
{
	if (finalTime - initTime != 0)
	{
		return abs(finalPosition - initPosition) / (finalTime - initTime);
	}
	return 0.0;
}

void Physics::printAverageSpeedCalc(double initPosition, double finalPosition, double initTime, double finalTime)
{
	double avgSpeed = findAverageSpeed(initPosition, finalPosition, initTime, finalTime);
	cout << "Numbers given were: " << endl;
	cout << "Initial Position: " << initPosition << " km" << endl;
	cout << "Final Position: " << finalPosition << " km" << endl;
	cout << "Initial Time: " << initTime << " hr" << endl;
	cout << "Final Time: " << finalTime << " hr" << endl;
	cout << "Calculated Average Speed: " << avgSpeed << " km/hr" << endl;
}

double Physics::findAverageAcceleration(double initVelocity, double finalVelocity, double initTime, double finalTime)
{
	if (finalTime - initTime != 0)
	{
		return (finalVelocity - initVelocity) / (finalTime - initTime);
	}
	return 0.0;
}

void Physics::printAverageAccelerationCalc(double initVelocity, double finalVelocity, double initTime, double finalTime)
{
	double avgAcceleration = findAverageAcceleration(initVelocity, finalVelocity, initTime, finalTime);
	cout << "Numbers given were: " << endl;
	cout << "Initial Velocity: " << initVelocity << " km/hr" << endl;
	cout << "Final Velocity: " << finalVelocity << " km/hr" << endl;
	cout << "Initial Time: " << initTime << " s" << endl;
	cout << "Final Time: " << finalTime << " s" << endl;
	cout << "Calculated Average Acceleration: " << avgAcceleration << " m/s^2" << endl;
}

double Physics::findForce(double mass, double acceleration)
{
	return mass * acceleration;
}

double Physics::findMass(double force, double acceleration)
{
	if (acceleration != 0)
	{
		return force / acceleration;
	}
	return 0;
}

double Physics::findAcceleration(double force, double mass)
{
	if (mass != 0)
	{
		return force / mass;
	}	
	return 0.0;
}

void Physics::printForceCalc(double force, double mass, double acceleration)
{
	cout << "Numbers given were: " << endl;
	cout << "Mass: " << mass << " kg" << endl;
	cout << "Acceleration: " << acceleration << " m/s^2" << endl;
	cout << "Calculated Force: " << force << " N" << endl;
}

void Physics::printMassCalc(double force, double mass, double acceleration)
{
	cout << "Numbers given were: " << endl;
	cout << "Force: " << force << " N" << endl;
	cout << "Acceleration: " << acceleration << " m/s^2" << endl;
	cout << "Calculated Mass: " << mass << " kg" << endl;
}

void Physics::printAccelerationCalc(double force, double mass, double acceleration)
{
	cout << "Numbers given were: " << endl;
	cout << "Force: " << force << " N" << endl;
	cout << "Mass: " << mass << " kg" << endl;
	cout << "Calculated Acceleration: " << acceleration << " m/s^2" << endl;
}
