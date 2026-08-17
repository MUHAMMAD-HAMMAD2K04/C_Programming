#include <iostream>
#include <string>
using namespace std;

/*
------------------------------------------------------
Base Class: CommissionEmployee
Now earnings() is declared virtual for polymorphism
------------------------------------------------------
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
                       double sales, double rate)
        : firstName(fName), lastName(lName),
          socialSecurityNumber(ssn),
          grossSales(sales), commissionRate(rate) {}

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

    /*
    ------------------------------------------------------
    Virtual Function
    Enables runtime polymorphism (dynamic binding)
    ------------------------------------------------------
    */
    virtual double earnings() const {
        cout << "Base Class earnings() called" << endl;
        return grossSales * commissionRate;
    }

    // Virtual destructor (good OOP practice)
    virtual ~CommissionEmployee() {}
};

/*
------------------------------------------------------
Derived Class: BasePlusCommissionEmployee
Overrides the virtual earnings() function
------------------------------------------------------
*/
class BasePlusCommissionEmployee : public CommissionEmployee {
private:
    double baseSalary;

public:
    // Constructor using base class constructor
    BasePlusCommissionEmployee(string fName, string lName, string ssn,
                               double sales, double rate, double salary)
        : CommissionEmployee(fName, lName, ssn, sales, rate),
          baseSalary(salary) {}

    void setBaseSalary(double salary) { baseSalary = salary; }
    double getBaseSalary() const { return baseSalary; }

    /*
    ------------------------------------------------------
    Overridden Function
    This will be called at runtime due to virtual keyword
    ------------------------------------------------------
    */
    double earnings() const override {
        cout << "Derived Class earnings() called" << endl;
        return baseSalary +
               (getGrossSales() * getCommissionRate());
    }
};

/*
------------------------------------------------------
Main Function (Demonstrates Runtime Polymorphism)
------------------------------------------------------
*/
int main() {

    // Creating derived class object
    BasePlusCommissionEmployee basePlusEmp(
        "Ahmed", "Raza", "123-45-6789",
        10000, 0.10, 2000
    );

    /*
    ------------------------------------------------------
    Base class reference pointing to derived object
    This is the key requirement of Task 02
    ------------------------------------------------------
    */
    CommissionEmployee &empRef = basePlusEmp;

    // Calling earnings using base class reference
    cout << "Earnings using base class reference: "
         << empRef.earnings() << endl;

    return 0;
}
