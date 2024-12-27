#pragma once
class Cinf
{
public:

	Cinf() : m_id(""), m_name(""), m_sex(""), m_sector(""), m_age("")
		, m_time(""), m_salary(""), m_jobt(""), m_cv("") {}
	Cinf(string id,string name,string sex,string sector,string age, 
		string time, string salary, string jobt, string cv);

	void Load(ifstream& in);
	void Save(ofstream& out);

	string m_id;
	string m_name;
	string m_sex;
	string m_sector;
	string m_age;
	string m_time;
	string m_salary;
	string m_jobt;
	string m_cv;
};

