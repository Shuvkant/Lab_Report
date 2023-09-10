#include <iostream>
using namespace std;
class sum {
private:
  int num1;
  int num2;

public:
  void add(int n1, int n2) {
    int num3;
    num1 = n1;
    num2 = n2;
    num3 = num1 + num2;
    cout << "\nThe sum of " << num1 << " and " << num2 << " is: " << num3;
  }
};
int main() {
  sum s1, s2;
  s1.add(2, 3);
  s2.add(3, 4);
}
