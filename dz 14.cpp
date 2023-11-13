
#include "Driver.h"
#include <iostream>

int main()
{
    vector<Driver> drivers;

   
    addViolation(drivers, "John", "2023-10-15", "Speeding", 100.0);
    addViolation(drivers, "John", "2023-11-02", "Parking", 50.0);
    addViolation(drivers, "Alice", "2023-09-20", "Red light", 150.0);

    displayViolationsByDriver(drivers, "John");
    displayViolationsByDriver(drivers, "Alice");
    cout << "------------------------\n";
    removeViolation(drivers, "John", "2023-10-15", "Speeding");
    displayViolationsByDriver(drivers, "John");
    cout << "---------------------------\n";
    displayViolationsByPeriod(drivers, "2023-09-01", "2023-09-30");

    return 0;
}

