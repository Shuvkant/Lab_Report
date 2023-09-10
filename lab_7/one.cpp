#include <iostream>
#include <string>

class Shape {
protected:
    std::string name;

public:
    Shape(const std::string& shapeName) : name(shapeName) {}

    virtual double area() const = 0;

    virtual void display() const {
        std::cout << "Shape: " << name << std::endl;
    }

    virtual ~Shape() {
        std::cout << "Destroying shape: " << name << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const std::string& shapeName, double circleRadius) : Shape(shapeName), radius(circleRadius) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        std::cout << "Shape: " << name << std::endl;
        std::cout << "Type: Circle" << std::endl;
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }

    ~Circle() override {
        std::cout << "Destroying Circle: " << name << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(const std::string& shapeName, double rectWidth, double rectHeight) : Shape(shapeName), width(rectWidth), height(rectHeight) {}

    double area() const override {
        return width * height;
    }

    void display() const override {
        std::cout << "Shape: " << name << std::endl;
        std::cout << "Type: Rectangle" << std::endl;
        std::cout << "Width: " << width << std::endl;
        std::cout << "Height: " << height << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }

    ~Rectangle() override {
        std::cout << "Destroying Rectangle: " << name << std::endl;
    }
};

class Trapezoid : public Shape {
private:
    double base1;
    double base2;
    double height;

public:
    Trapezoid(const std::string& shapeName, double trapBase1, double trapBase2, double trapHeight) : Shape(shapeName), base1(trapBase1), base2(trapBase2), height(trapHeight) {}

    double area() const override {
        return (base1 + base2) * height / 2.0;
    }

    void display() const override {
        std::cout << "Shape: " << name << std::endl;
        std::cout << "Type: Trapezoid" << std::endl;
        std::cout << "Base1: " << base1 << std::endl;
        std::cout << "Base2: " << base2 << std::endl;
        std::cout << "Height: " << height << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }

    ~Trapezoid() override {
        std::cout << "Destroying Trapezoid: " << name << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle("Circle 1", 5.0);
    Shape* shape2 = new Rectangle("Rectangle 1", 3.0, 4.0);
    Shape* shape3 = new Trapezoid("Trapezoid 1", 2.0, 4.0, 3.0);

    shape1->display();
    std::cout << std::endl;
    shape2->display();
    std::cout << std::endl;
    shape3->display();
    std::cout << std::endl;

    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}