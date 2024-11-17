//logic code
#include "BasePlusCommissionEmployee.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last,
    const string& ssn, double sales, double rate, double baseSalary)
    : CommissionEmployee(first, last, ssn, sales, rate), baseSalary(baseSalary) {}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    if (salary >= 0.0) {
        baseSalary = salary;
    } else
    {
        throw invalid_argument("Base salary must be >= 0.0");
    }
    
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const {
    CommissionEmployee::print();
    cout << "Base Salary: " << baseSalary;
}