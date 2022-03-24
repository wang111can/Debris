#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>

using namespace std;
class Earth {

private:
	int people;
	string EartnName;
public:
	Earth(int x=0, string y = "NULL") :people(x), EartnName(y) {}
	void Show() { cout << EartnName << "'s People" << people << endl; }
};



int main()
{
	Earth earth;
	fstream fio;
	fio.open("Cpp_17.txt", ios_base::app | ios_base::in | ios_base::out|ios_base::binary);
	if (fio.is_open())
	{
		while (fio.read((char*)&earth, sizeof(earth)))
		{
			cout << " Earths this is :";
			earth.Show();
		}
		if (fio.eof())
		{
			fio.clear();
		}
		else
		{
			cerr << " Error in reading" << endl;
		
		}
	}
	else{
		cerr << "Cpp_17.txt " << "could not be opened! " << endl;
		
	}
	
	cout << " Enter you want to world(enter quit to quit  enter anything to agin):";
	string exits;
	
	while (cin >> exits && exits != "quit")
	{
		string name;
		int people;
		cout << " Enter you earth's name:";
		cin >> name;
		cout << "Enter you earth's people:";
		cin >> people;
		Earth *newworld = new Earth(people, name);
		fio.write((char*)newworld, sizeof(newworld));
		cout << " Enter you want to world(enter quit to quit  enter anything to agin):";

	}
	


	
	return 0;
}