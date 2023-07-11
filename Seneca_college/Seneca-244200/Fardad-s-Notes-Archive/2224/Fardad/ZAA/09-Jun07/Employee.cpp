#include <iostream>
using namespace std;
#include "Employee.h"
namespace sdds {


   void Employee::display()
   {
      cout << "Name: " << m_name.get() << "(" << m_empId << "), Salary: " << m_salary << endl;
   }
   void Employee::hire() {
      cout << "Name: ";
      m_name.read();
      cout << "Salay: ";
      cin >> m_salary; // 123.45 \n in keyboard
      cin.ignore(1000, '\n'); // up to 1000 or \n, whichever comes first
      cout << "Employee ID: ";
      cin >> m_empId;
      cin.ignore(1000, '\n');
   }

}


