#include <iostream>
#include <random>
#include <thread>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

class VehicleData {
    double speed;
    double engineTemp;
    int fuelLevel;

public:
    // Constructor to initialize vehicle data
    VehicleData(double a, double b, int c) {
        speed = a;
        engineTemp = b;
        fuelLevel = c;
    }

    // Getter methods to access private variables
    double getSpeed() const { return speed; }
    double getEngineTemp() const { return engineTemp; }
    int getFuelLevel() const { return fuelLevel; }
};

class Display {
public:
    void displayData(const VehicleData& data) {
        cout << "Speed: " << data.getSpeed() << " km/h" << endl;
        cout << "Fuel: " << data.getFuelLevel() << "%" << endl;
        cout << "Temperature: " << data.getEngineTemp() << " C" << endl;

        // Display warnings based on certain conditions
        if (data.getEngineTemp() > 100) {
            cout << "Warning! Temperature is exceeding..." << endl;
        }
        if (data.getFuelLevel() < 10) {
            cout << "Warning! Fuel is getting low..." << endl;
        }
    }
};

// Function to generate random data
VehicleData generateRandomData() {
    // Generate random values for speed, engine temperature, and fuel level
    double speed = rand() % 181;  // Random speed between 0 and 180 km/h
    double engineTemp = 50 + (rand() % 81); // Random engine temperature between 50 and 130 C
    int fuelLevel = rand() % 101; // Random fuel level between 0 and 100%

    // Create a VehicleData object with the random values
    return VehicleData(speed, engineTemp, fuelLevel);
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Create Display object
    Display d;

    // Generate random vehicle data
    VehicleData randomData = generateRandomData();

    // Display the random data
    d.displayData(randomData);

    return 0;
}
