//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: hospital_room.cpp                       Class: CS 1570, Section D
//Purpose: Body file for hospital_room class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hospital_room.h"
#include "x_rayer.h"


using namespace std;

const short MAXSCHRAUT=3;
const short MINSCHRAUT=1;
template <class T_machine>
void hospital_room<T_machine>::admit(patient & p,Doctor & d)
{
  short oz_schraut;
  short numApps;
  bool drankSchraut=false;
  if(p.getCondition()!=0 && p.getMoney()>=
    m_the_machine.getCost())
  {
    m_the_machine.charge_patient(p);
    oz_schraut=rand()%(MAXSCHRAUT-MINSCHRAUT+1)+MINSCHRAUT;
    if(oz_schraut>m_schrautOz)
      oz_schraut=m_schrautOz;
    if(oz_schraut>0)
    {
      d.drink_schraut(oz_schraut);
      numApps=d.get_oz_schraut()-5;
      if(numApps<0)
        numApps=0;
    }
    else
    {
      numApps=(d.get_oz_schraut()-5)*2;
      if(numApps<0)
        numApps=0;
    }
    for(int i=0;i<numApps;i++)
    {
      m_the_machine.apply(p);
    }
  }
  return;
}

template <class U_machine>
ostream& operator <<(ostream& o,const hospital_room <U_machine> & h)
{
  o<<h.m_the_machine<<"    Ounces of Schraut!: "<<h.m_schrautOz;
  return o;
}
