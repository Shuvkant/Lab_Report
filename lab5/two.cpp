/*Write a class to store x, y, and z coordinates of a point in three-dimensional
 * space. Overload addition and subtraction operators for addition and
 * subtraction of two coordinate objects. Implement the operator functions as
 * non-member functions (friend operator functions).*/
#include <iostream>
using namespace std;
class Point3D {
private:
  double x, y, z;

public:
  Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

  // Overloaded operators as friend functions
  friend Point3D operator+(const Point3D &lhs, const Point3D &rhs);
  friend Point3D operator-(const Point3D &lhs, const Point3D &rhs);

  // Display function to print the coordinates
  void display() const {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
  }
};

// Overloaded addition operator
Point3D operator+(const Point3D &lhs, const Point3D &rhs) {
  Point3D result;
  result.x = lhs.x + rhs.x;
  result.y = lhs.y + rhs.y;
  result.z = lhs.z + rhs.z;
  return result;
}

// Overloaded subtraction operator
Point3D operator-(const Point3D &lhs, const Point3D &rhs) {
  Point3D result;
  result.x = lhs.x - rhs.x;
  result.y = lhs.y - rhs.y;
  result.z = lhs.z - rhs.z;
  return result;
}

int main() {
  Point3D p1(7, 8, 9), p2(2, 3, 4);

  cout << "p1: ";
  p1.display();
  cout << "p2: ";
  p2.display();

  cout << "Addition: ";
  Point3D sum = p1 + p2;
  sum.display();

  cout << "Subtraction: ";
  Point3D diff = p1 - p2;
  diff.display();

  return 0;
}
