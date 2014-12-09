//Programmer: Peter Dolan      ID: 12410657
//Instructor: Price     Section: A    Date: 11/17/2014
//File: hospital_room_fncts.hpp    Description: Functions for the hospital_room
using namespace std;

template <class T>
Hospital<T>::Hospital()
{
  m_schraut = INITIAL_SCHRAUT_AMT;
  m_doctor_payout = m_the_machine.getCost() * PAYOUT_PORTION;
}

template <class T_machine>
bool Hospital<T_machine>::admit(Patient &p, Doctor &d)
{
  bool admitted = false;
//---------Admits patient if he/she has enough money and is alive------------//
  if(m_the_machine.charge_patient(p) && p.getCondition() > DEAD)
  {
    int num_apps = 0;
    d.modifyMoney(m_doctor_payout);
    admitted = true;
//------Determines number of applications if doctor consumed Schraut---------//
    if(d.consume_schraut(m_schraut))
    {
      num_apps = d.getSchraut() + DRUNK_APPS;
      num_apps = ((num_apps < 1) ? 1 : num_apps);     //Prevent negative apps
      for(int i = 0; i < num_apps; i++)
      {
        m_the_machine.apply(p);
      }
    }

//------Determines number of applications if doctor consumed NO Schraut------//
    else
    {
      num_apps = (d.getSchraut() + DRUNK_APPS) * ANGRY_APPS;
      for(int i = 0; i < num_apps; i++)
      {
        m_the_machine.apply(p);
      }
    }

  }
  return admitted;
}

template <typename T>
ostream& operator << (ostream& o, const Hospital<T> &h)
{
  o << "Machine:  " << h.m_the_machine;
  o << "Ounces of Schraut!: " << h.m_schraut;
  return o;
}
