#include <iostream>
using namespace std;

class Rectangle {
private:
    int* width;
    int* height;

public:
    // Parameterized Constructor
    Rectangle(int w, int h) {
        width = new int(w);
        height = new int(h);
        cout << "Constructor called. Rectangle created.\n";
    }

    // Destructor
    ~Rectangle() {
        delete width;
        delete height;
        cout << "Destructor called. Rectangle destroyed.\n";
    }

    int area() {
        return (*width) * (*height);
    }

    int perimeter() {
        return 2 * ((*width) + (*height));
    }

    void display() {
        cout << "Width: " << *width << endl;
        cout << "Height: " << *height << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
        cout << "---------------------\n";
    }
};

int main() {
    Rectangle r1(5, 4);
    Rectangle r2(7, 3);

    r1.display();
    r2.display();

    return 0;
}
