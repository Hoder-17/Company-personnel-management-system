#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<assert.h>
#include<strstream>
#include <exception>
#pragma once
using namespace std;
#define NULL 0
extern int manager_pay;
extern int manager_promotion_pay;
extern double salesman_rate;
extern double salesman_promotion_rate;
extern double salesmanager_rate;
extern int salesmanager_pay;
extern int salesmanager_prmotion_pay;
extern double salesmanager_promotion_rate;
extern int technician_wage ;
extern int technician_promotion_wage ;
class employee
{
private:
	int individualEmpNo, grade, accumPay;
	string name;
	string password;
public:
	static int current_no;
	employee();
	employee(int, int,string,string);
	~employee();
	void set_grade(int);
	string get_password() { return password; };
	void set_password(string);
	void set_accumPay(int);
	void set_individualEmpNo(int);
	int get_grade();
	int get_accumPay();
	int get_individualEmpNo();
	friend ostream& operator<<(ostream&, employee&);
	friend istream& operator>>(istream&, employee&);
	virtual void print()=0;
	virtual bool promote(int) = 0;
	virtual int pay() = 0;
	virtual void update_info()=0;
	virtual void f_scan(FILE*) = 0;
	virtual void f_print(FILE*)=0;
	void set_name(string);
	string get_name() { return name; }
	bool verify(int, string);
};
