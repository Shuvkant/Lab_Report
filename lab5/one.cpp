/*Write a class for instantiating the objects that represent the two-dimensional
Cartesian coordinate system. A. Make a particular member function of one class
as a friend function of another class for addition. B. Make the other three
functions to work as a bridge between the classes for multiplication, division,
and subtraction. C. Also write a small program to demonstrate that all the
member functions of one class are the friend functions of another class if the
former class is made friend to the latter. Make least possible classes to
demonstrate all the above in a single program without conflict.*/
#include <iostream>
using namespace std;
class CartesianCoord;
class CoordBridge {
public:
  static CartesianCoord add(const CartesianCoord &coord1,
                            const CartesianCoord &coord2);
  static CartesianCoord subtract(const CartesianCoord &coord1,
                                 const CartesianCoord &coord2);
  static CartesianCoord multiply(const CartesianCoord &coord1,
                                 const CartesianCoord &coord2);
  static CartesianCoord divide(const CartesianCoord &coord1,
                               const CartesianCoord &coord2);
};
class CartesianCoord {
private:
  double x, y;

public:
  CartesianCoord(double x = 0, double y = 0) : x(x), y(y) {}
  friend CartesianCoord CoordBridge::add(const CartesianCoord &coord1,
                                         const CartesianCoord &coord2);
  friend CartesianCoord CoordBridge::subtract(const CartesianCoord &coord1,
                                              const CartesianCoord &coord2);
  friend CartesianCoord CoordBridge::multiply(const CartesianCoord &coord1,
                                              const CartesianCoord &coord2);
  friend CartesianCoord CoordBridge::divide(const CartesianCoord &coord1,
                                            const CartesianCoord &coord2);
  void display() const { cout << "(" << x << ", " << y << ")" << endl; }
};

CartesianCoord CoordBridge::add(const CartesianCoord &coord1,
                                const CartesianCoord &coord2) {
  CartesianCoord result;
  result.x = coord1.x + coord2.x;
  result.y = coord1.y + coord2.y;
  return result;
}

CartesianCoord CoordBridge::subtract(const CartesianCoord &coord1,
                                     const CartesianCoord &coord2) {
  CartesianCoord result;
  result.x = coord1.x - coord2.x;
  result.y = coord1.y - coord2.y;
  return result;
}

CartesianCoord CoordBridge::multiply(const CartesianCoord &coord1,
                                     const CartesianCoord &coord2) {
  CartesianCoord result;
  result.x = coord1.x * coord2.x;
  result.y = coord1.y * coord2.y;
  return result;
}

CartesianCoord CoordBridge::divide(const CartesianCoord &coord1,
                                   const CartesianCoord &coord2) {
  CartesianCoord result;
  result.x = coord1.x / coord2.x;
  result.y = coord1.y / coord2.y;
  return result;
}

int main() {
  CartesianCoord coord1(2, 3), coord2(4, 5);

  cout << "Coord1: ";
  coord1.display();
  cout << "Coord2: ";
  coord2.display();

  cout << "Addition: ";
  CartesianCoord sum = CoordBridge::add(coord1, coord2);
  sum.display();

  cout << "Subtraction: ";
  CartesianCoord diff = CoordBridge::subtract(coord1, coord2);
  diff.display();

  cout << "Multiplication: ";
  CartesianCoord prod = CoordBridge::multiply(coord1, coord2);
  prod.display();

  cout << "Division: ";
  CartesianCoord quot = CoordBridge::divide(coord1, coord2);
  quot.display();

  return 0;
}
