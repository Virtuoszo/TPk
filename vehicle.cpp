#include "vehicle.h"

vehicle::vehicle()
{
	price = ET = EV = year = size = fuel = steering_type = fuel_cons = trunkV = 0.0;
}
//здесь пошли сеты для свойств объекта vehicle
void vehicle::setColor(string c)
{
	color = c;
}

void vehicle::setPrice(float p)
{
	price = p;
}

void vehicle::setET(int in)
{
	ET = in;
}

void vehicle::setEV(float in)
{
	EV = in;
}

void vehicle::setYear(int in)
{
	year = in;
}

void vehicle::setBrand(string in)
{
	brand = in;
}

void vehicle::setModel(string in)
{
	model = in;
}

void vehicle::setSize(float in)
{
	size = in;
}

void vehicle::setFuel(int in)
{
	fuel = in;
}

void vehicle::setST(int in) //steering_type
{
	steering_type = in;
}

void vehicle::setFuelcons(float in)
{
	fuel_cons = in;
}

void vehicle::setTrunkV(float in)
{
	trunkV = in;
}

void vehicle::getVehicle(ostream& out)
{
	out << "Информация по ТС:" << endl;
	out << "Цвет: " + color << endl;
	out << "Цена: " << price << "$" << endl;
	out << "Тип двигателя: " << ET << "-х тактный" << endl;
	out << "Объем двигателей: " << EV << " (см3)" << endl;
	out << "Год выпуска: " << year << "г." << endl;
	out << "Марка: " << brand << endl;
	out << "Модель: " << model << endl;
	out << "Габариты: " << size << "(см3)" << endl;
	out << "Требования по топливу: ";
	if (fuel != 0)
	{
		out << fuel;
	}
	else { out << ("ДТ"); };
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
	default:
		cerr << "Некорректный тип пулевого управления." << endl;
	}


	out << "Расход топлива по городу: " << fuel_cons << "л/100км" << endl;
	out << "Объем багажника: " << trunkV << " (см3)" << endl;
}

// ===================================== методы построения motorbikeBuilder ======================

void motorbikeBuilder::BuilderColor()
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

void motorbikeBuilder::BuilderPrice() 
{
point: try {
	int in;
	cout << "Введите цену мотоцикла в ($): ";
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

void motorbikeBuilder::BuilderET()  {


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

void motorbikeBuilder::BuilderEV()  {


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

void motorbikeBuilder::BuilderYear()  {


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

void motorbikeBuilder::BuilderBrand()  {


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

void motorbikeBuilder::BuilderModel()  {


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

void motorbikeBuilder::BuilderSize()  {


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

void motorbikeBuilder::BuilderFuel()  {


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

void motorbikeBuilder::BuilderST()  {


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

void motorbikeBuilder::BuilderFuelcons()  {
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

void motorbikeBuilder::BuilderTrunkV()  {
	cout << "У мотоциклов багажник отсутствует. " << endl;
	v->setTrunkV(0);

}
// ===================================== методы построения quadbikeBuilder ======================
void quadbikeBuilder::BuilderColor() 
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

void quadbikeBuilder::BuilderPrice()  {


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

void quadbikeBuilder::BuilderET()  {


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

void quadbikeBuilder::BuilderEV()  {


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

void quadbikeBuilder::BuilderYear()  {


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

void quadbikeBuilder::BuilderBrand()  {


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

void quadbikeBuilder::BuilderModel()  {


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

void quadbikeBuilder::BuilderSize()  {


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

void quadbikeBuilder::BuilderFuel()  {


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

void quadbikeBuilder::BuilderST()  {


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

void quadbikeBuilder::BuilderFuelcons()  {
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


void quadbikeBuilder::BuilderTrunkV()  {
	cout << "У квадроциклов багажник отсутствует. " << endl;
	v->setTrunkV(0);
}

// ===================================== методы построения carBuilder ======================

void carBuilder::BuilderColor() 
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

void carBuilder::BuilderPrice()  {


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

void carBuilder::BuilderET()  {


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

void carBuilder::BuilderEV()  {


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

void carBuilder::BuilderYear()  {


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

void carBuilder::BuilderBrand()  {


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

void carBuilder::BuilderModel()  {


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

void carBuilder::BuilderSize()  {


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

void carBuilder::BuilderFuel()  {


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

void carBuilder::BuilderST()  {


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

void carBuilder::BuilderFuelcons()  {
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

void carBuilder::BuilderTrunkV()  {


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
