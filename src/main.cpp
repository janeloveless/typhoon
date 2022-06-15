// c++ standard library includes
#include <iostream>
#include <iomanip>

// project includes
#include "precision.h"
#include "core.h"
#include "particle.h"

using namespace std;

int main(int argc, char *argv[]) {
	cout << "Running test code for Typhoon physics engine..." << endl;

	// test some vector math!
	typhoon::real c = 1;
	typhoon::Vector3 X = typhoon::Vector3(1, 0, 0);
	typhoon::Vector3 Y = typhoon::Vector3(0, 1, 0);
	typhoon::Vector3 Z = typhoon::Vector3(0, 0, 1);

	typhoon::Vector3 v = c*(X % Y);

	cout << v.x << ", " << v.y << ", " << v.z << endl;

	return 0;
}
