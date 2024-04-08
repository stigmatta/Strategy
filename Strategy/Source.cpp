#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

	/*
	������� ��������� ��������� ������� �������� ��������� ������� �� ��� �������.
	��� ������� �������� �������� ����� ���� ������������ ��������� ����������.
	���������������� ���� ���������� ������ ������-��������� ������ �������������� ����
	� ����������� ����������� ���������� ������ ������,  � ������ ���������� �������������� ����������.
	� ��� ������ ��������� ������ ����� ��������, ����� �������� ��������� ������� ��� ���������.
	*/

class TripStrategy abstract
{
protected:
	int price, time;
public:
	TripStrategy(int price, int time)
	{
		this->price = price;
		this->time = time;
	}

	virtual void Trip() abstract;
};

class Bicycle: public TripStrategy
{
public:
	Bicycle() :TripStrategy(0, 60){}

	void Trip() override
	{
		printf_s("On the bicycle you`ll arrive to your point at %d minutes with a cost of %d  \n\n", time, price);
	}
};

class PublicTransport: public TripStrategy
{
public:
	PublicTransport() :TripStrategy(20, 30) {}

	void Trip() override
	{
		printf_s("On the public transport you`ll arrive to your point at %d minutes with a cost of %d hrn \n\n", time, price);
	}
};

class Taxi: public TripStrategy
{
public:
	Taxi() :TripStrategy(100, 10) {}

	void Trip() override
	{
		printf_s("On the taxi you`ll arrive to your point at %d minutes with a cost of %d hrn \n\n", time, price);
	}
};

class ConcreteTrip
{
	TripStrategy* strategy;

public:
	void SetStrategy(TripStrategy* strategy)
	{
		this->strategy = strategy;
		
	}
	void Trip()
	{
		strategy->Trip();
	}
};

int main()
{
	ConcreteTrip ar;
	PublicTransport pt;
	ar.SetStrategy(&pt);
	ar.Trip();

	Bicycle bike;
	ar.SetStrategy(&bike);
	ar.Trip();

	Taxi taxi;
	ar.SetStrategy(&taxi);
	ar.Trip();

	system("pause");
	return 0;
}
	
