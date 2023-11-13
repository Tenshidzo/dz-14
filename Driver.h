#pragma once
#include "Violation.h"
struct Driver {
    string name;
    vector<Violation> violations;
    
   
}; void addViolation(vector<Driver>& drivers, string driverName, string violationDate, string violationType, double fineAmount) {
        for (Driver& driver : drivers) {
            if (driver.name == driverName) {
                Violation newViolation = { violationDate, violationType, fineAmount };
                driver.violations.push_back(newViolation);
                return;
            }
        }
        Driver newDriver;
        newDriver.name = driverName;
        Violation newViolation = { violationDate, violationType, fineAmount };
        newDriver.violations.push_back(newViolation);
        drivers.push_back(newDriver);
    }
    void removeViolation(vector<Driver>& drivers, string driverName, string violationDate, string violationType) {
        for (Driver& driver : drivers) {
            if (driver.name == driverName) {
                for (auto it = driver.violations.begin(); it != driver.violations.end(); ++it) {
                    if (it->date == violationDate && it->type == violationType) {
                        driver.violations.erase(it);
                        return;
                    }
                }
            }
        }
    }
    void displayViolationsByDriver(const vector<Driver>& drivers, string driverName) {
        for (const Driver& driver : drivers) {
            if (driver.name == driverName) {
                cout << "Violations for Driver " << driverName << ":" << endl;
                for (const Violation& violation : driver.violations) {
                    cout << "Date: " << violation.date << ", Type: " << violation.type << ", Fine: " << violation.fine << endl;
                }
                return;
            }
        }
        cout << "Driver " << driverName << " not found." << endl;
    }
    void displayViolationsByPeriod(const vector<Driver>& drivers, string startDate, string endDate) {
        cout << "Violations between " << startDate << " and " << endDate << ":" << endl;
        for (const Driver& driver : drivers) {
            for (const Violation& violation : driver.violations) {
                if (violation.date >= startDate && violation.date <= endDate) {
                    cout << "Driver: " << driver.name << ", Date: " << violation.date << ", Type: " << violation.type << ", Fine: " << violation.fine << endl;
                }
            }
        }
    }