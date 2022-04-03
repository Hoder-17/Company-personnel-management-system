#pragma once
#include "employee.h"

class technician : public employee
{
public:
	technician();
	technician(int,int,string,string);
	~technician();
	technician &operator=(technician &per);//重载赋值运算符
	friend ostream& operator<<(ostream&, technician&);
	friend istream& operator>>(istream&, technician&);
	virtual void print();
	void set_month_workhours(int);
	void set_wage(int);
	int get_wage() { return wage; };
	int get_month_workhours() { return month_workhours; };
	virtual bool promote(int) ;
	virtual int pay();
	virtual void update_info();
	virtual void f_scan(FILE*);
	virtual void f_print(FILE*);
	void input();
private:
	int month_workhours;//月工作时间
	int wage;//工资
};
