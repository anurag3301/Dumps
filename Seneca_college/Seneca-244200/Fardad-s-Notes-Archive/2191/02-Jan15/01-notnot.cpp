#include <iostream>
using namespace std;
int main() {
   bool res = true;
   int a = 25;
   cout << res << endl;
   res = !a;
   cout << res << endl;
   res = !!a;
   cout << res << endl;
   res = a;  // better not to do, but compiler does res = (bool)a;
   cout << res << endl;

   return 0;
}