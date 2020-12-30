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
	vehicle();
	//здесь пошли сеты для свойств объекта
	void setColor(string c);

	void setPrice(float p);

	void setET(int in);

	void setEV(float in);

	void setYear(int in);

	void setBrand(string in);

	void setModel(string in);

	void setSize(float in);

	void setFuel(int in);

	void setST(int in);

	void setFuelcons(float in);
	void setTrunkV(float in);

	void getVehicle(ostream& out);
	friend class VehicleBuilder;
};

class VehicleBuilder // строитель основного объекта
{
	vehicle * v; // экземпляр основного объекта

public:
	vehicle* createVehicle();
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

	vehicle* getVehicle();
	friend class motorbikeBuilder;
	friend class carBuilder;
	friend class quadbikeBuilder;

	~VehicleBuilder()
	{
		delete v;
	}
};

class motorbikeBuilder :
	public VehicleBuilder
{
    void BuilderColor() override;

	void BuilderPrice() override;

	void BuilderET() override;

	void BuilderEV() override;

	void BuilderYear() override ;

	void BuilderBrand() override;

	void BuilderModel() override;

	void BuilderSize() override;

	void BuilderFuel() override;

	void BuilderST() override ;

	void BuilderFuelcons() override ;

	void BuilderTrunkV() override ;
};

class quadbikeBuilder :
	public VehicleBuilder
{
	void BuilderColor() override;

	void BuilderPrice() override ;

	void BuilderET() override ;

	void BuilderEV() override ;

	void BuilderYear() override ;

	void BuilderBrand() override ;

	void BuilderModel() override ;

	void BuilderSize() override ;

	void BuilderFuel() override;

	void BuilderST() override;

	void BuilderFuelcons() override ;


	void BuilderTrunkV() override;
};

class carBuilder :
	public VehicleBuilder
{
	void BuilderColor() override;

	void BuilderPrice() override ;

	void BuilderET() override ;

	void BuilderEV() override ;

	void BuilderYear() override ;

	void BuilderBrand() override ;

	void BuilderModel() override ;

	void BuilderSize() override ;

	void BuilderFuel() override ;

	void BuilderST() override ;

	void BuilderFuelcons() override;

	void BuilderTrunkV() override ;
};

class Director
{
	VehicleBuilder * builder;

public:
	void setBuilder(VehicleBuilder* b)
	{
		builder = b;
	}

	vehicle* buildVehicle();
	~Director()
	{
		delete builder;
	}
};
