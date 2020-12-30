#include<fstream>
#include "vehicle.h"#include<fstream>
#include "vehicle.h"
#include<Windows.h>
#include<fstream>
#include "vehicle.h"
#include<Windows.h>


using namespace std;
int main(void)
{
	setlocale(LC_ALL, "rus");
	Director* director = new Director();
	fstream f("save.txt", ios_base::in);
	bool fopen_error = false;
	if (!f.is_open())
	{
		cerr << "Файл с кешем прошлых запусков не был открыт, создан новый файл..." << endl;
	}
	while (1)
	{
		cout << "Введите требуемый для создания объект: " << endl;
		cout << "|1| - мотоцикл;" << endl;
		cout << "|2| - квадроцикл;" << endl;
		cout << "|3| - машина;" << endl;
		cout << "|4| - Загрузить последний сгенерированный объект" << endl;
		cout << "|0| - Выход;" << endl;
		int ans;
		cin >> ans;
		
		switch (ans)
		{
		case 0:
		{
			cout << "Работа успешно окончена, осуществляется выход из программы..." << endl;
			cin.get(); cin.get(); return 0;
		}
		case 1:
		{
			motorbikeBuilder* m = new motorbikeBuilder();
			director->setBuilder(m);
			vehicle* VehicleObj = director->buildVehicle();
			VehicleObj->getVehicle(cout);
			f.close();
			f.open("save.txt", ios_base::app);
			VehicleObj->getVehicle(f);
			delete VehicleObj;
			break;
		}
		case 2:
		{
			quadbikeBuilder* q = new quadbikeBuilder();
			director->setBuilder(q);
			vehicle* VehicleObj = director->buildVehicle();
			VehicleObj->getVehicle(cout);
			f.close();
			f.open("save.txt", ios_base::app);
			VehicleObj->getVehicle(f);
			delete VehicleObj;
			break;
		}
		case 3:
		{
			carBuilder* c = new carBuilder();
			director->setBuilder(c);
			vehicle* VehicleObj = director->buildVehicle();
			VehicleObj->getVehicle(cout);
			f.close();
			f.open("save.txt", ios_base::app);
			VehicleObj->getVehicle(f);
			delete VehicleObj;
			break;
		}
		case 4:
		{
			string fs;
			cout << endl;
			f.close();
			f.open("save.txt", ios_base::in);
			getline(f, fs);
			while (!fs.empty())
			{
				cout << fs<<endl;
				getline(f, fs);
			}
			cout << endl;
		}
		default:
			cerr << "Некорректный ввод." << endl;
		}
		cin.get(); 
		cin.get();
		system("cls");
	}
	return 0;
}
