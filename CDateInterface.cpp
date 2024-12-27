#include "pch.h"
#include "CDataInterface.h"

bool CDataInterface::Open(CString FilePath)
{
	ifstream in(FilePath, ios::in);

	if (in.is_open())
	{
		int num;	
		in >> num;
		for (int i = 0; i < num; i++)
		{
			Cinf MyInfo;
			MyInfo.Load(in);
			Info.push_back(MyInfo);
		}
		return true;
	}

	return false;
}

void CDataInterface::Add(Cinf MyInfo)
{
	Info.push_back(MyInfo);
}

void CDataInterface::Del(int index)
{
	Info.erase(Info.begin()+index);
}

void CDataInterface::Amend(int index, Cinf MyInfo)
{
	Info[index] = MyInfo;
}

Cinf CDataInterface::Find(CString id)
{
	for (int i = 0; i < Info.size(); i++)
	{
		CString str;
		str.Format(TEXT("%s"), Info[i].m_id.c_str());
		if ( str== id) return Info[i];
	}
	return Cinf(TEXT(""), TEXT(""), TEXT(""), TEXT(""), 
		TEXT(""), TEXT(""), TEXT(""), TEXT(""), TEXT(""));
}

bool CDataInterface::Save(CString FilePath)
{
	ofstream out(FilePath, ios::out);
	if (out.is_open())
	{
		out << Info.size() << endl;
		for (int i = 0; i < Info.size(); i++)
		{
			Info[i].Save(out);
		}
		out.close();
		return true;
	}
	return false;
}

