#pragma once
#include "employee.h"
class salesmanager;
class salesman :virtual public employee
{
public:
	salesman();
	salesman(int,int , salesmanager*,string,string);
	~salesman();
	salesman &operator=(salesman &per);//���ظ�ֵ�����
	friend ostream& operator<<(ostream&, salesman&);
	friend istream& operator>>(istream&, salesman&);
	virtual void print();
	void set_month_sales(int);
	void set_boss(salesmanager*);
	void set_commission_rate(double);
	int get_month_sales();
	double get_commission_rate();
	salesmanager* get_boss();
	virtual void f_scan(FILE*);
	virtual void f_print(FILE*);
	virtual bool promote(int);
	virtual int pay();
	virtual void update_info();
	void input();
private:
	int month_sales;//�����۶�
	double commission_rate;//�����
	salesmanager *boss;
};
