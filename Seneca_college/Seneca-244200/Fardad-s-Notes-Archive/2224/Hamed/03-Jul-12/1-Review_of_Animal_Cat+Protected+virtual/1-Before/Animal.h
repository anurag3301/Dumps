#ifndef SDDS_ANIMAL_H
#define SDDS_ANIMAL_H


namespace sdds {
	// define a class animal
	class Animal {
		// That has a static name
		char m_name[41]{};

	public:
		// Has a default constructor
		Animal(const char* name = "noName");

		//Has a query for name
		const char* getName() const;

		// Has a setter for name
		Animal& setName(const char* name);


		// Has and act

		Animal& act();

		// Has a move
		Animal& move(); // move doesn't exist in Cat so virtual doesn' affect it

		//Has a sound
		Animal& sound();

		// has a destructor
		 ~Animal();
		// From now on a destructor should always be virtual 
		// so if inheritance happens memroy leak can be avoided

	};

	// Debug messages can be activated or deactivated in the project scope
	extern bool debug;

}

#endif // !SDDS_ANIMAL_H


