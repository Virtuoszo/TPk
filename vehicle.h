#pragma once
#include<iostream>
using namespace std;
/*
* основной объект, содержащий следующие свойства:
цвет, цена, тип двигателя, объем двигателя,год выпуска, марка, модель, размеры, требования к топливу, тип рулевого управления, расход топлива по городу, объем багажника */
class vehicle 
{
	string color;	// цвет будущего транспортного средства
	float price;	//цена
	int ET;		//тип двигателя соответственноу 2 или 4 (двухтактные и 4-х тактные)
	float EV;		//объем двигателя
	int year;		//год выпуска
	string brand;	//марка\бренд
	string model;	// модель
	float size;		// размеры, видимо, имеется ввиду габариты, для простоты будет объем ТС
	int fuel;		// требования к топливу, 92 95 98 ДТ(0)
	int steering_type; //выделяют червячный, реечный и винтовой тип виды механизмов соответственно у нас это будет 0,1 и 2 типы
	float fuel_cons; //расход топлива по городу
	float trunkV;	// объем багажника
public:
	vehicle()
	{
		price = ET = EV = year = size = fuel = steering_type = fuel_cons = trunkV = 0.0;
	}
	//здесь пошли сеты для свойств объекта
	void setColor(string c)
	{
		color = c;
	}

	void setPrice(float p)
	{
		price = p;
	}

	void setET(int in)
	{
		ET = in;
	}

	void setEV(float in)
	{
		EV = in;
	}

	void setYear(int in)
	{
		year = in;
	}

	void setBrand(string in)
	{
		brand = in;
	}

	void setModel(string in)
	{
		model = in;
	}

	void setSize(float in)
	{
		size = in;
	}

	void setFuel(int in)
	{
		fuel = in;
	}

	void setST(int in) //steering_type
	{
		steering_type  = in;
	}

	void setFuelcons(float in)
	{
		fuel_cons = in;
	}

	void setTrunkV(float in)
	{
		trunkV = in;
	}

	void getVehicle(ostream& out)
	{
		out << "Информация по ТС:" << endl;
		out << "Цвет: "+color << endl;
		out << "Цена: " << price <<"$" <<endl;
		out << "Тип двигателя: " << ET << "-х тактный" << endl;
		out << "Объем двигателей: " << EV << " (см3)" << endl;
		out << "Год выпуска: " << year << "г." << endl;
		out << "Марка: " << brand << endl;
		out << "Модель: " << model << endl;
		out << "Габариты: " << size <<"(см3)"<< endl;
		out << "Требования по топливу: "; 
		if (fuel != 0)
		{
			out << fuel;
		}
		else { out<<("ДТ"); };
		out << endl;
		out << "Тип рулевого управления: ";
		switch (steering_type)
		{
			case 0:
			{
				out << "Червячный" << endl;
				break;
			}
			case 1:
				out << "Реечный" << endl;
				break;
			case 2:
				out << "Винтовой" << endl;
				break;
			default :
				cerr << "Некорректный тип пулевого управления." << endl;
		}


		out << "Расход топлива по городу: " << fuel_cons << "л/100км" << endl;
		out << "Объем багажника: " << trunkV << " (см3)" << endl;
	}
	friend class VehicleBuilder;
};

class VehicleBuilder // строитель основного объекта
{
	vehicle * v; // экземпляр основного объекта

public:
	vehicle* createVehicle()
	{
		v = new vehicle();
		return v;
	}

	virtual void BuilderColor()=0;

	virtual void BuilderPrice()=0;

	virtual void BuilderET()=0;

	virtual void BuilderEV()=0;

	virtual void BuilderYear() = 0;

	virtual void BuilderBrand() = 0;

	virtual void BuilderModel() = 0;

	virtual void BuilderSize() = 0;

	virtual void BuilderFuel() = 0;

	virtual void BuilderST() = 0; //steering_type

	virtual void BuilderFuelcons() = 0;

	virtual void BuilderTrunkV() = 0;

	vehicle* getVehicle()
	{
		return v;
	}
	friend class motorbikeBuilder;
	friend class carBuilder;
	friend class quadbikeBuilder;

	~VehicleBuilder()
	{
		delete v;
	}
};
