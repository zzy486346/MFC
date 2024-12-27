#include "pch.h"
#include "Cinf.h"

Cinf::Cinf(string id, string name, string sex, string sector, 
string age, string time, string salary, string jobt, string cv)
{
    this->m_id = id;
    this->m_name = name;
    this->m_sex = sex;
    this->m_sector = sector;
    this->m_age = age;
    this->m_time = time;
    this->m_salary = salary;
    this->m_jobt = jobt;
    this->m_cv = cv;
}

void Cinf::Load(ifstream& in)
{
    in >> m_id;
    in >> m_name;
    in >> m_sex;
    in >> m_sector;
    in >> m_age;
    in >> m_time;
    in >> m_salary;
    in >> m_jobt;
    in >> m_cv;
}

void Cinf::Save(ofstream& out)
{
    out << m_id <<"\t";
    out << m_name << "\t";
    out << m_sex << "\t";
    out << m_sector << "\t";
    out << m_age << "\t";
    out << m_time << "\t";
    out << m_salary << "\t";
    out << m_jobt << "\t";
    out << m_cv << "\n";
}
