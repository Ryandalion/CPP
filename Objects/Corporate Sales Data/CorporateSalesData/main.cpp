#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct CorpData
{
	string Division_name;
	double firstquarter;
	double secondquarter;
	double thirdquarter;
	double fourthquarter;
	double totalSales;
	double averageSales;

	CorpData();
	CorpData(string, double, double, double, double);
};

CorpData::CorpData()
{

}

CorpData::CorpData(string company, double q1, double q2, double q3, double q4)
{
	Division_name = company;
	firstquarter = q1;
	secondquarter = q2;
	thirdquarter = q3;
	fourthquarter = q4;
}

void DataCalculate(CorpData &company);
void DataDisplay(CorpData &company);

int main()
{
	CorpData C1, C2, C3, C4;

	string name;
	double q1, q2, q3, q4;


		cout << "Please enter the name for company 1: " << endl;
		getline(cin, C1.Division_name);
		cout << "Please enter the 1st Quarter Earnings: " << endl;
		cin >> C1.firstquarter;
		cout << "Please enter the 2nd Quarter Earnigns: " << endl;
		cin >> C1.secondquarter;
		cout << "Please enter the 3rd Quarter Earnings: " << endl;
		cin >> C1.thirdquarter;
		cout << "Please enter the 4th Quarter Earnings: " << endl;
		cin >> C1.fourthquarter;
		
		cin.ignore();
		cout << endl;
		cout << "Please enter the name for company 2: " << endl;
		getline(cin, C2.Division_name);
		cout << "Please enter the 1st Quarter Earnings: " << endl;
		cin >> C2.firstquarter;
		cout << "Please enter the 2nd Quarter Earnigns: " << endl;
		cin >> C2.secondquarter;
		cout << "Please enter the 3rd Quarter Earnings: " << endl;
		cin >> C2.thirdquarter;
		cout << "Please enter the 4th Quarter Earnings: " << endl;
		cin >> C2.fourthquarter;

		cin.ignore();
		cout << endl;
		cout << "Please enter the name for company 3: " << endl;
		getline(cin, C3.Division_name);
		cout << "Please enter the 1st Quarter Earnings: " << endl;
		cin >> C3.firstquarter;
		cout << "Please enter the 2nd Quarter Earnigns: " << endl;
		cin >> C3.secondquarter;
		cout << "Please enter the 3rd Quarter Earnings: " << endl;
		cin >> C3.thirdquarter;
		cout << "Please enter the 4th Quarter Earnings: " << endl;
		cin >> C3.fourthquarter;

		cin.ignore();
		cout << endl;
		cout << "Please enter the name for company 4: " << endl;
		getline(cin, C4.Division_name);
		cout << "Please enter the 1st Quarter Earnings: " << endl;
		cin >> C4.firstquarter;
		cout << "Please enter the 2nd Quarter Earnigns: " << endl;
		cin >> C4.secondquarter;
		cout << "Please enter the 3rd Quarter Earnings: " << endl;
		cin >> C4.thirdquarter;
		cout << "Please enter the 4th Quarter Earnings: " << endl;
		cin >> C4.fourthquarter;

		DataCalculate(C1);
		DataCalculate(C2);
		DataCalculate(C3);
		DataCalculate(C4);

		DataDisplay(C1);
		DataDisplay(C2);
		DataDisplay(C3);
		DataDisplay(C4);

		system("pause");
}

void DataCalculate(CorpData &company)
{
	company.totalSales = (company.firstquarter + company.secondquarter + company.thirdquarter + company.fourthquarter);
	company.averageSales = (company.totalSales / 4);
}

void DataDisplay(CorpData &company)
{
	cout << endl;
	cout << company.Division_name << " ANNUAL FISCAL REPORT" << endl;
	cout << "Q1: " << company.firstquarter << endl;
	cout << "Q2: " << company.secondquarter << endl;
	cout << "Q3: " << company.thirdquarter << endl;
	cout << "Q4: " << company.fourthquarter << endl;
	cout << "Average Sales: " << company.averageSales << endl;
	cout << "Total Sales: " << company.totalSales << endl;

}