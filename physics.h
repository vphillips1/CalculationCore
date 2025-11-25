#ifndef PHYSICS_H
#define PHYSICS_H
#include <string>

using namespace std;

class Physics {

public:
	// Constructor
	Physics();

	// Destructor
	~Physics();

	//Average Velocity
	double findAverageVelocity(double initPosition, double finalPosition, double initTime, double finalTime);
	void printAverageVelocityCalc(double initPosition, double finalPosition, double initTime, double finalTime);
	
	//Average Speed
	double findAverageSpeed(double initPosition, double finalPosition, double initTime, double finalTime);
	void printAverageSpeedCalc(double initPosition, double finalPosition, double initTime, double finalTime);

	//Average Acceleration
	double findAverageAcceleration(double initVelocity, double finalVelocity, double initTime, double finalTime);
	void printAverageAccelerationCalc(double initVelocity, double finalVelocity, double initTime, double finalTime);

	// Force Functions
	double findForce(double mass, double acceleration);	
	double findMass(double force, double acceleration);
	double findAcceleration(double force, double mass);
	void printForceCalc(double force, double mass, double acceleration);
	void printMassCalc(double force, double mass, double acceleration);
	void printAccelerationCalc(double force, double mass, double acceleration);



private:
	double force;
	double mass;	
	double acceleration;
	double initTime;
	double finalTime;
	double initPosition;
	double finalPosition;

};

/*
. Average velocity
. Average speed
. Average accelerator
. Force calculator

*/

#endif
