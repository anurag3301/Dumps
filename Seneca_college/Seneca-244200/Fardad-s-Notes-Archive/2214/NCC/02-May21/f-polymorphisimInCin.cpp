
#include <iostream>
using namespace std;

int main() {
   int age;
   double money;
   cout << "How old are you? ";
   cin >> age;
   if (age < 13) {
      cout << "Isn't " << age << " years old a bit to young for college" << endl;
   }
   else {
      cout << "Welcome to oop244NCC" << endl;
   }
   cout << "How much money you got?";
   cin >> money;
   return 0;
}