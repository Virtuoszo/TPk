#include<fstream>
#include "vehicle.h"#include<fstream>
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
		}
		case 1:
		{
			
		}
		case 2:
		{
			
		}
		case 3:
		{
			
		}
		case 4:
		{
			
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
