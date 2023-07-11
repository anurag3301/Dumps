#ifndef SICT_CAT_H__
#define SICT_CAT_H__
#include "pet.h"
namespace sict{
  class Cat:public Pet{           
    int m_numOfLives;
  public:
    Cat(const char* name = "Garfiled", 
       int numOfLives = 9);
    void act()const;
    void move()const;
    void sound()const;
    ~Cat();
  };
}
#endif