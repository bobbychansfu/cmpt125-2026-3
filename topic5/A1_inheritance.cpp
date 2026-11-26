#include<iostream>
using namespace std;

class Shape {
        double x, y;
    public:
        Shape(double px, double py) : x(px), y(py) {}
        void moveTo(double px, double py) {
            x = px;
            y = py;
        }
        double area() {
            return 0;
        }   
    
};

class Circle : public Shape {
    double r;
    public:
    Circle(double px, double py, double pr) : Shape(px, py), r(pr) {}
    double area() {
        return 3.14 * r * r;
    }
};

int main() {
    Circle c(0, 0, 5);
    c.moveTo(10, 10);
    cout << "Area of circle from Circle: " << c.area() << "<-- CORRECT \n";
    Shape*cp = &c;
    cout << "Area of circle from Shape: " << cp->area() << "<-- WRONG \n";
    return 0;
}