#include <iostream>
#include <string>
using namespace std;

/*
----------------------------------------------------------
Base Class: CommissionEmployee
Represents an employee who earns commission on sales only
----------------------------------------------------------
*/
class CommissionEmployee {
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;

public:
    // Constructor
    CommissionEmployee(string fName, string lName, string ssn,
                       double sales, double rate) {
        firstName = fName;
        lastName = lName;
        socialSecurityNumber = ssn;
        grossSales = sales;
        commissionRate = rate;
    }

    // Setters & Getters
    void setFirstName(string fName) { firstName = fName; }
    string getFirstName() const { return firstName; }

    void setLastName(string lName) { lastName = lName; }
    string getLastName() const { return lastName; }

    void setSocialSecurityNumber(string ssn) { socialSecurityNumber = ssn; }
    string getSocialSecurityNumber() const { return socialSecurityNumber; }

    void setGrossSales(double sales) { grossSales = sales; }
    double getGrossSales() const { return grossSales; }

    void setCommissionRate(double rate) { commissionRate = rate; }
    double getCommissionRate() const { return commissionRate; }

    // Calculate earnings
    double earnings() const {
        return grossSales * commissionRate;
    }

    // Display info
    void print() const {
        cout << "Commission Employee: "
             << firstName << " " << lastName << endl;
        cout << "Earnings: " << earnings() << endl;
    }
};

/*
----------------------------------------------------------
Derived Class: BasePlusCommissionEmployee
Adds base salary to commission earnings
----------------------------------------------------------
*/
class BasePlusCommissionEmployee : public CommissionEmployee {
private:
    double baseSalary;

public:
    // Constructor
    BasePlusCommissionEmployee(string fName, string lName, string ssn,
                               double sales, double rate, double salary)
        : CommissionEmployee(fName, lName, ssn, sales, rate) {
        baseSalary = salary;
    }

    void setBaseSalary(double salary) { baseSalary = salary; }
    double getBaseSalary() const { return baseSalary; }

    // Overriding earnings method
    double earnings() const {
        return getBaseSalary() +
               (getGrossSales() * getCommissionRate());
    }

    void print() const {
        cout << "Base Plus Commission Employee: "
             << getFirstName() << " " << getLastName() << endl;
        cout << "Earnings: " << earnings() << endl;
    }
};

int main() {
    CommissionEmployee emp1("Muhammad", "Haseeb", "123-45-6789", 10000, 0.1);
    emp1.print();

    cout << "----------------------" << endl;

    BasePlusCommissionEmployee emp2("Abdullah", "Shaikh",
                                    "987-65-4321", 10000, 0.1, 2000);
    emp2.print();

    return 0;
}
