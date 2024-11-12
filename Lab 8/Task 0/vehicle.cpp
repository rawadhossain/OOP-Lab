#include <iostream>
#include <string>
#include <vector>

class Vehicle
{
protected:
    std::string license_plate;
    std::string manufacturer;
    int carriage_size_limit;

public:
    Vehicle(const std::string &license_plate, const std::string &manufacturer, int carriage_size_limit)
        : license_plate(license_plate), manufacturer(manufacturer), carriage_size_limit(carriage_size_limit) {}

    virtual void performMaintenance()
    {
        std::cout << this->license_plate << " - Maintenance" << std::endl;
    }
};

class GasolineVehicle : public Vehicle
{
protected:
    std::string fuel_type;
    int fuel_tank_capacity;

public:
    GasolineVehicle(const std::string &license_plate, const std::string &manufacturer, int carriage_size_limit, const std::string &fuel_type, int fuel_tank_capacity)
        : Vehicle(license_plate, manufacturer, carriage_size_limit), fuel_type(fuel_type), fuel_tank_capacity(fuel_tank_capacity) {}

    void performMaintenance() override
    {
        std::cout << this->license_plate << " - Gasoline Vehicle Maintenance" << std::endl;
    }
};

class ElectricVehicle : public Vehicle
{
protected:
    int battery_capacity;
    int charging_time;

public:
    ElectricVehicle(const std::string &license_plate, const std::string &manufacturer, int carriage_size_limit, int battery_capacity, int charging_time)
        : Vehicle(license_plate, manufacturer, carriage_size_limit), battery_capacity(battery_capacity), charging_time(charging_time) {}

    void performMaintenance() override
    {
        std::cout << this->license_plate << " - Electric Vehicle Maintenance" << std::endl;
    }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle
{
protected:
    double energy_regeneration_efficiency;

public:
    HybridVehicle(const std::string &license_plate, const std::string &manufacturer, int carriage_size_limit, const std::string &fuel_type, int fuel_tank_capacity, int battery_capacity, int charging_time, double energy_regeneration_efficiency)
        : GasolineVehicle(license_plate, manufacturer, carriage_size_limit, fuel_type, fuel_tank_capacity), ElectricVehicle(license_plate, manufacturer, carriage_size_limit, battery_capacity, charging_time), energy_regeneration_efficiency(energy_regeneration_efficiency) {}

    void performMaintenance() override
    {
        std::cout << this->license_plate << " - Hybrid Vehicle Maintenance" << std::endl;
    }
};

class Branch
{
private:
    std::vector<Vehicle *> vehicles;
    std::vector<Employee *> employees;

public:
    Branch()
    {
        for (int i = 0; i < 10; i++)
        {
            vehicles.push_back(new Motortruck("TR" + std::to_string(i), "Motortruck", 1000, "Petrol", 50));
            vehicles.push_back(new Car("C" + std::to_string(i), "Car", 500, "Petrol", 50, 4));
            vehicles.push_back(new Truck("T" + std::to_string(i), "Truck", 2000, "Petrol", 100));
            vehicles.push_back(new ElectricVehicle("EV" + std::to_string(i), "Electric Vehicle", 500, 100, 30));
            vehicles.push_back(new HybridVehicle("HV" + std::to_string(i), "Hybrid Vehicle", 500, "Petrol", 50, 100, 30, 0.8));
            employees.push_back(new Manager("M" + std::to_string(i)));
            for (int j = 0; j < 3; j++)
            {
                employees.push_back(new Driver("D" + std::to_string(i) + "_" + std::to_string(j)));
            }
        }
    }

    void introduceManagers()
    {
        for (const auto &employee : employees)
        {
            if (dynamic_cast<Manager *>(employee))
            {
                std::cout << "Mr. " << employee->getName() << std::endl;
            }
        }
    }

    void introduceDrivers()
    {
        for (const auto &employee : employees)
        {
            if (dynamic_cast<Driver *>(employee))
            {
                std::cout << employee->getName() << std
