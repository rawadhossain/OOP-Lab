#include <iostream>
#include <string>
using namespace std;

class AirTravel
{
private:
    int flightNumber;
    string destination;
    float distance;
    float maxFuelCapacity;

    float calFuel()
    {
        if (distance <= 1000)
            return 500;
        else if (distance > 1000 && distance <= 2000)
            return 1100;
        else
            return 2200;
    }

public:
    void feedInfo()
    {
        cout << "Flight number: ";
        cin >> flightNumber;

        cout << "Destination: ";
        cin >> destination;

        cout << "Distance: ";
        cin >> distance;

        cout << "Max fuel capacity: ";
        cin >> maxFuelCapacity;
    }

    void showInfo()
    {
        cout << "Flight number: " << flightNumber << endl;
        cout << "Destination: " << destination << endl;
        cout << "Distance: " << distance << endl;
        cout << "Max fuel capacity: " << maxFuelCapacity << endl;

        if (calFuel() <= maxFuelCapacity)
            cout << "Fuel capacity is fit for this flight distance." << endl;
        else
            cout << "Not sufficient fuel capacity for this flight." << endl;
    }
};

int main()
{
    AirTravel flight;
    flight.feedInfo();
    flight.showInfo();

    return 0;
}