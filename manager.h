#pragma once
#include "employee.h"
class manager:virtual public employee
{
public:
	manager();
	manager(int,string,string);
	~manager();
	manager &operator=(manager &per);//ÖØÔØ¸³ÖµÔËËã·û
	friend ostream& operator<<(ostream&, manager&);
	friend istream& operator>>(istream&, manager&);
	virtual void print();
	void set_fix_pay(int);
	int get_fix_pay();
	virtual int pay();
	virtual bool promote(int);
	virtual void f_scan(FILE*);
	virtual void f_print(FILE*);
	virtual void update_info();
private:
	int fix_pay;
};
