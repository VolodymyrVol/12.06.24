#include<iostream>
using namespace std;

class Car
{
	char* model;
	int year;
	double price;
public:
	Car()
	{
		model = nullptr;
		year = 0;
		price = 0.0;
	}
	Car(const char* mod)
	{
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
	}
	Car(const char* mod, int y, double pr): Car(mod)  // делегирование
	{		
		year = y;
		price = pr;
	}
	Car(const Car& obj):Car(obj.model,obj.year,obj.price) // 1
	{}
	Car& operator=(const Car& obj) // 2
	{
		if (this == &obj)
		{
			return *this;
		}
		if (model != nullptr)
		{
			delete[] model;
		}
		model = new char[strlen(obj.model) + 1];
		strcpy_s(model, strlen(obj.model) + 1, obj.model);
		year = obj.year;
		price = obj.price;

		return *this;
	}
	Car& operator++ ()
	{
		year += 1;
		return *this;
	}
	Car& operator-- ()
	{
		year -= 1;
		return *this;
	}
	Car& operator +=(double pr)
	{
		price += pr;
		return *this;
	}
	Car& operator -=(double pr)
	{
		price -= pr;
		return *this;
	}
	int operator- (const Car& obj)
	{
		double res;
		res = price - obj.price;
		return res;
	}
	int operator+ (const Car& obj)
	{
		double res;
		res = price + obj.price;
		return res;
	}
	~Car() // 3
	{
		delete[]model;
	}
	const char* getModel()
	{
		return model;
	}
	int GetYear()
	{
		return year;
	}
	double GetPrice()
	{
		return price;
	}
	void SetModel(const char* mod)
	{
		if(model!=nullptr)
			delete[] model;
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
	}
	void SetYear(int y)
	{
		year = y;
	}
	void SetPrice(double pr)
	{
		price = pr;
	}
};
ostream& operator<<(ostream& os, Car & obj)
{
	os << obj.getModel() << "\t" << obj.GetYear() <<"\t" << obj.GetPrice() << endl;
	return os;
}
istream& operator>>(istream& is, Car& obj)
{
	char buff[20];
	cout << "Enter model -> ";
	is >> buff;
	obj.SetModel(buff);
	int y;
	double pr;
	cout << "Enter year -> ";
	is >> y;
	obj.SetYear(y);
	cout << "Enter price -> ";
	is >> pr;
	obj.SetPrice(pr);
	return is;
}

int main()
{
	Car obj1("Audi A5", 2023, 50000);
	Car obj2("Audi A5", 2023, 40000);
	cout << obj1 << endl;
	cin >> obj1;
	cout << obj1;

	
	obj1 += 1000; // увеличиваем стоимость на 1000
	obj1 -= 1000;// уменьшаем стоимость на 1000

	++obj1; // увеличиваем год на 1
	--obj1; // уменьшаем год на 1

	int r = obj1 - obj2; // разность стоимости автомобилей
	int sum = obj1 + obj2; // сумма стоимости автомобилей , возвращается общая сумма

   

}