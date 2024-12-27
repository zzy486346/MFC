#pragma once
#include"Cinf.h"

class CDataInterface
{
public:
	bool Open(CString FilePath);
	void Add(Cinf MyInfo);
	void Del(int index);
	void Amend(int index, Cinf MyInfo);
	Cinf Find(CString id);
	bool Save(CString FilePath);

	vector<Cinf> Info;
};

