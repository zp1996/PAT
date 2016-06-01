#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
struct Student
{
	int cno, dGrade, cGrade, temp;
};
bool order (Student & stu1, Student & stu2) 
{
	if (stu1.temp > stu2.temp) 
	{
		return true;
	}
	if (stu1.temp == stu2.temp)
	{
		if (stu1.cno < stu2.cno) return true;
	}
	return false;
}
int main () 
{
	int N, min, great;
	cin>>N>>min>>great;
	vector<Student> dcAll, dsc, dscn, mo;
	for (int i = 0; i < N; i++) 
	{
		int a, b, c;
		cin>>a>>b>>c;
		if (b >= min && c >= min) 
		{
			Student stu;
			stu.cno = a;
			stu.dGrade = b;
			stu.cGrade = c;
			stu.temp = (b + c) * 1000 + b;
			if (b >= great) 
			{
				if (c >= great) 
					dcAll.push_back(stu);
				else 
					dsc.push_back(stu);
			} 
			else
			{
				if (b >= c)  
					dscn.push_back(stu);
				else 
					mo.push_back(stu);
			}
		}
	}

	sort(dcAll.begin(), dcAll.end(), order);
	sort(dsc.begin(), dsc.end(), order);
	sort(dscn.begin(), dscn.end(), order);
	sort(mo.begin(), mo.end(), order);

	cout<<dcAll.size() + dsc.size() + dscn.size() + mo.size()<<endl;

	for(vector<Student>::iterator iter = dcAll.begin(); iter != dcAll.end(); iter++) 
		cout<<iter->cno<<' '<<iter->dGrade<<' '<<iter->cGrade<<'\n';
	for(vector<Student>::iterator iter = dsc.begin(); iter != dsc.end(); iter++) 
		cout<<iter->cno<<' '<<iter->dGrade<<' '<<iter->cGrade<<'\n';
	for(vector<Student>::iterator iter = dscn.begin(); iter != dscn.end(); iter++) 
		cout<<iter->cno<<' '<<iter->dGrade<<' '<<iter->cGrade<<'\n';
	for(vector<Student>::iterator iter = mo.begin(); iter != mo.end(); iter++) 
		cout<<iter->cno<<' '<<iter->dGrade<<' '<<iter->cGrade<<'\n';
	return 0;
}