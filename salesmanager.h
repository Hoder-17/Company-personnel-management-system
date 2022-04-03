#pragma once
#include "manager.h"
#include "salesman.h"
#include "mylist.h"

class salesmanager :public manager,public salesman
{
public:
	salesmanager();
	salesmanager(int,int,mylist<int>&,string,string);
	~salesmanager();
	salesmanager &operator=(salesmanager &per);//重载赋值运算符
	friend ostream& operator<<(ostream&, salesmanager&);
	friend istream& operator>>(istream&, salesmanager&);
	virtual void print();
	void change_sales(int);
	bool add_salesman(int);
	bool remove_salesman(int);
	virtual int pay();
	virtual bool promote(int);
	virtual void update_info();
	virtual void f_scan(FILE*);
	virtual void f_print(FILE*);
	mylist <int> salesman_no;//使用链表保存经理管理的销售员编号
};
