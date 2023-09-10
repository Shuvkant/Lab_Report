/*Write a program to compare two objects of a class that contains an integer
 * value as its data member. Make overloading functions to overload
 * equality(==), less than(<), greater than(>), not equal (!=), greater than or
 * equal to (>=), and less than or equal to(<=) operators using member operator
 * functions.*/
#include <iostream>
using namespace std;
class Integer {
private:
  int value;

public:
  Integer(int value = 0) : value(value) {}

  // Overloaded comparison operators
  bool operator==(const Integer &other) const { return value == other.value; }

  bool operator<(const Integer &other) const { return value < other.value; }

  bool operator>(const Integer &other) const { return value > other.value; }

  bool operator!=(const Integer &other) const { return !(*this == other); }

  bool operator>=(const Integer &other) const {
    return (*this > other) || (*this == other);
  }

  bool operator<=(const Integer &other) const {
    return (*this < other) || (*this == other);
  }

  // Display function to print the value
  void display() const { std::cout << value << std::endl; }
};

int main() {
  Integer a(5), b(10);

  cout << "a: ";
  a.display();
  cout << "b: ";
  b.display();

  cout << "a == b: " << (a == b) << endl;
  cout << "a < b: " << (a < b) << endl;
  cout << "a > b: " << (a > b) << endl;
  cout << "a != b: " << (a != b) << endl;
  cout << "a >= b: " << (a >= b) << endl;
  cout << "a <= b: " << (a <= b) << endl;

  return 0;
}
