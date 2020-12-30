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

class motorbikeBuilder :
	public VehicleBuilder
{
    void BuilderColor() override
	{
		
		point:
		try {
			string in;
			cout << "Введите цвет мотоцикла: ";
			cin >> in;
			cout << endl;
			v->setColor(in);
			for (int i = 0; i < in.length(); i++)
			{
				if (in[i] > 127 || in[i] < 0) throw "Были введены некорректные данные.";
			}
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
			goto point;
		}
	}

	void BuilderPrice() override {
		

		point: try {
			int in;
			cout << "Введите цену мотоцикла в ($): ";
			cin >> in;
			cout << endl;
			v->setPrice(in);
			if(in<0)throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderET() override {
		

		point: try {
			int in;
			cout << "Введите тип двигателя мотоцикла(2 если двухтактный, 4 если четырехтактный): ";
			cin >> in;
			cout << endl;
			v->setET(in);
			if (in != 2 && in != 4) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderEV() override {
		

		point: try {
			float in;
			cout << "Введите объем двигателя мотоцикла (см куб.): ";
			cin >> in;
			cout << endl;
			v->setEV(in);
			if (in < 0)throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderYear() override {
		

		point: try {
			int in;
			cout << "Введите год выпуска мотоцикла: ";
			cin >> in;
			cout << endl;
			v->setYear(in);
				if (in < 1950 || in > 2020) throw "Были введены некорректные данные.";	
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderBrand() override {
		

		point: try {
			string in;
			cout << "Введите марку мотоцикла: ";
			cin >> in;
			cout << endl;
			v->setBrand(in);
			for (int i = 0; i < in.length(); i++)
			{
				if (in[i] > 127 || in[i] < 0) throw "Были введены некорректные данные.";
			}
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderModel() override {
		

		point: try {
			string in;
			cout << "Введите модель мотоцикла: ";
			cin.get();
			cin >> in;
			cout << endl;
			v->setModel(in);
			for (int i = 0; i < in.length(); i++)
			{
				if (in[i] > 127 || in[i] < 0) throw "Были введены некорректные данные.";
			}
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderSize() override {
		

		point: try {
			float in;
			cout << "Введите размер мотоцикла (см.куб.): ";
			cin >> in;
			cout << endl;
			v->setSize(in);
			if (in < 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderFuel() override {
		

		point: try {
			int in;
			cout << "Введите требование к топливу (92,95,98 Бензин, 0 -дизель): ";
			cin >> in;
			cout << endl;
			v->setFuel(in);
				if (in != 92 && in != 95 && in != 98 && in != 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderST() override {
		

		point: try {
			int in;
			cout << "Введите тип рулевого механизма мотоцикла(червячный, реечный и винтовой тип виды механизмов соответственно у нас это будет 0,1 и 2 типы): ";
			cin >> in;
			cout << endl;
			v->setST(in);
			if (in != 0 && in != 1 && in != 2) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderFuelcons() override {
		point: try {
			float in;
			cout << "Введите расход топлива по городу мотоцикла(л): ";
			cin >> in;
			cout << endl;
			v->setFuelcons(in);
			if (in < 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderTrunkV() override {
		cout << "У мотоциклов багажник отсутствует. " << endl; 
		v->setTrunkV(0);

	}
};

class quadbikeBuilder :
	public VehicleBuilder
{
	void BuilderColor() override
	{


		point: try {
			string in;
			cout << "Введите цвет квадроцикла: ";
			cin >> in;
			cout << endl;
			v->setColor(in);
			for (int i = 0; i < in.length(); i++)
			{
				if (in[i] > 127 || in[i] < 0) throw "Были введены некорректные данные.";
			}
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl;
		}
	}

	void BuilderPrice() override {


		point: try {
			int in;
			cout << "Введите цену квадроцикла в ($): ";
			cin >> in;
			cout << endl;
			v->setPrice(in);
			if (in < 0)throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderET() override {


		point: try {
			int in;
			cout << "Введите тип двигателя квадроцикла(2 если двухтактный, 4 если четырехтактный): ";
			cin >> in;
			cout << endl;
			v->setET(in);
			if (in != 2 && in != 4) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderEV() override {


		point: try {
			float in;
			cout << "Введите объем двигателя квадроцикла (см куб.): ";
			cin >> in;
			cout << endl;
			v->setEV(in);
			if (in < 0)throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderYear() override {


		point: try {
			int in;
			cout << "Введите год выпуска квадроцикла: ";
			cin >> in;
			cout << endl;
			v->setYear(in);
			if (in < 1950 || in > 2020) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderBrand() override {


		point: try {
			string in;
			cout << "Введите марку квадроцикла: ";
			cin >> in;
			cout << endl;
			v->setBrand(in);
			for (int i = 0; i < in.length(); i++)
			{
				if (in[i] > 127 || in[i] < 0) throw "Были введены некорректные данные.";
			}
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderModel() override {


		point: try {
			string in;
			cout << "Введите модель квадроцикла: ";
			cin.get();
			cin >> in;
			cout << endl;
			v->setModel(in);
			for (int i = 0; i < in.length(); i++)
			{
				if (in[i] > 127 || in[i] < 0) throw "Были введены некорректные данные.";
			}
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderSize() override {


		point: try {
			float in;
			cout << "Введите размер квадроцикла (см.куб.): ";
			cin >> in;
			cout << endl;
			v->setSize(in);
			if (in < 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderFuel() override {


		point: try {
			int in;
			cout << "Введите требование к топливу (92,95,98 Бензин, 0 -дизель): ";
			cin >> in;
			cout << endl;
			v->setFuel(in);
			if (in != 92 && in != 95 && in != 98 && in != 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderST() override {


		point: try {
			int in;
			cout << "Введите тип рулевого механизма квадроцикла(червячный, реечный и винтовой тип виды механизмов соответственно у нас это будет 0,1 и 2 типы): ";
			cin >> in;
			cout << endl;
			v->setST(in);
			if (in != 0 && in != 1 && in != 2) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderFuelcons() override {
		point: try {
			float in;
			cout << "Введите расход топлива по городу квадроцикла(л): ";
			cin >> in;
			cout << endl;
			v->setFuelcons(in);
			if (in < 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}


	void BuilderTrunkV() override {
		cout << "У квадроциклов багажник отсутствует. "<<endl;
		v->setTrunkV(0);
	}
};

class carBuilder :
	public VehicleBuilder
{
	void BuilderColor() override
	{


		point: try {
			string in;
			cout << "Введите цвет машины: ";
			cin >> in;
			cout << endl;
			v->setColor(in);
			for (int i = 0; i < in.length(); i++)
			{
				if (in[i] > 127 || in[i] < 0) throw "Были введены некорректные данные.";
			}
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderPrice() override {


		point: try {
			int in;
			cout << "Введите цену машины в ($): ";
			cin >> in;
			cout << endl;
			v->setPrice(in);
			if (in < 0)throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderET() override {


		point: try {
			int in;
			cout << "Введите тип двигателя машины(2 если двухтактный, 4 если четырехтактный): ";
			cin >> in;
			cout << endl;
			v->setET(in);
			if (in != 2 && in != 4) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderEV() override {


		point: try {
			float in;
			cout << "Введите объем двигателя машины (см куб.): ";
			cin >> in;
			cout << endl;
			v->setEV(in);
			if (in < 0)throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderYear() override {


		point: try {
			int in;
			cout << "Введите год выпуска машины: ";
			cin >> in;
			cout << endl;
			v->setYear(in);
			if (in < 1950 || in > 2020) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderBrand() override {


		point: try {
			string in;
			cout << "Введите марку машины: ";
			cin >> in;
			cout << endl;
			v->setBrand(in);
			for (int i = 0; i < in.length(); i++)
			{
				if (in[i] > 127 || in[i] < 0) throw "Были введены некорректные данные.";
			}
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderModel() override {


		point: try {
			string in;
			cout << "Введите модель машины: ";
			cin.get();
			cin >> in;
			cout << endl;
			v->setModel(in);
			for (int i = 0; i < in.length(); i++)
			{
				if (in[i] > 127 || in[i] < 0) throw "Были введены некорректные данные.";
			}
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderSize() override {


		point: try {
			float in;
			cout << "Введите размер машины (см.куб.): ";
			cin >> in;
			cout << endl;
			v->setSize(in);
			if (in < 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderFuel() override {


		point: try {
			int in;
			cout << "Введите требование к топливу (92,95,98 Бензин, 0 -дизель): ";
			cin >> in;
			cout << endl;
			v->setFuel(in);
			if (in != 92 && in != 95 && in != 98 && in != 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderST() override {


		point: try {
			int in;
			cout << "Введите тип рулевого механизма машины(червячный, реечный и винтовой тип виды механизмов соответственно у нас это будет 0,1 и 2 типы): ";
			cin >> in;
			cout << endl;
			v->setST(in);
			if (in != 0 && in != 1 && in != 2) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderFuelcons() override {
		point: try {
			float in;
			cout << "Введите расход топлива по городу машины(л): ";
			cin >> in;
			cout << endl;
			v->setFuelcons(in);
			if (in < 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}

	void BuilderTrunkV() override {
		

		point: try {
			float in;
			cout << "Объем багажника: "; cin >> in; cout << endl;
			v->setTrunkV(in);
			if (in < 0) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
	}
};

class Director
{
	VehicleBuilder * builder;

public:
	void setBuilder(VehicleBuilder* b)
	{
		builder = b;
	}

	vehicle* buildVehicle()
	{
		builder->createVehicle();
		builder->BuilderColor();
		builder->BuilderBrand();
		builder->BuilderET();
		builder->BuilderEV();
		builder->BuilderFuel();
		builder->BuilderFuelcons();
		builder->BuilderModel();
		builder->BuilderPrice();
		builder->BuilderSize();
		builder->BuilderST();
		builder->BuilderTrunkV();
		builder->BuilderYear();
		vehicle* v = builder->getVehicle();
		return v;
		
	}
	~Director()
	{
		delete builder;
	}
};
