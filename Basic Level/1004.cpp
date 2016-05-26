#include <iostream>
#include <string>
using namespace std;
struct Student
{
	string name;
	int grade;
	string cnumber;
	void SetAttr (string Name, int Grade, string CNumber) 
	{
		name = Name;
		grade = Grade;
		cnumber = CNumber;
	}
};
int main () 
{
	int n;
	cin>>n;
	Student high, low;
	high.SetAttr("", -1,"");
	low.SetAttr("", 101, "");
	while (n--)
	{
		Student stu;
		cin>>stu.name>>stu.cnumber>>stu.grade;
		if (stu.grade > high.grade) 
		{
			high.SetAttr(stu.name, stu.grade, stu.cnumber);
		}
		if (stu.grade < low.grade)
		{
			low.SetAttr(stu.name, stu.grade, stu.cnumber);
		}
	}
	cout<<high.name<<" "<<high.cnumber<<endl;
	cout<<low.name<<" "<<low.cnumber<<endl;
	return 0;
}