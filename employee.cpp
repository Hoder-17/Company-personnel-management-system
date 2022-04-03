#pragma once
#include "employee.h"
using namespace std;
extern int manager_pay = 12000;
extern int manager_promotion_pay = 4000;
extern double salesman_rate = 0.05;
extern double salesman_promotion_rate = 0.01;
extern double salesmanager_rate = 0.04;
extern int salesmanager_pay = 8000;
extern int salesmanager_prmotion_pay = 2000;
extern double salesmanager_promotion_rate = 0.005;
extern int technician_wage = 260;
extern int technician_promotion_wage = 20;
int employee::current_no = 1001001;
employee::employee() {
	individualEmpNo = current_no;
	current_no++;
	grade = 1;
	accumPay = 3000;
	name = "\0";
	password = "\0";
}
employee::employee(int gra, int pay,string na,string pass) {
	grade = gra;
	accumPay = pay;
	name = na;
	password = pass;
	individualEmpNo = current_no;
	current_no++;
}
void employee::set_password(string pass) {
	password = pass;
}
void employee::set_individualEmpNo(int no) {
	individualEmpNo = no;
}
employee::~employee() {
	
}
void employee::set_name(string na) {
	name = na;
}
void employee::set_accumPay(int pay) {
	accumPay = pay;
}
void employee::set_grade(int gra) {
	grade = gra;
}
int employee::get_accumPay() {
	return accumPay;
}
int employee::get_grade() {
	return grade;
}
int employee::get_individualEmpNo() {
	return individualEmpNo;
}
ostream& operator<<(ostream&output, employee&a) {
	output << "���Ϊ"<<a.individualEmpNo << "  " << "�ȼ�Ϊ" << a.grade << "  " << "��нΪ" << a.accumPay << "  " << "����Ϊ" << a.name <<  "  " << "����Ϊ" << a.password<<endl;
	return output;
}
istream& operator>>(istream&input, employee&a) {
	cout << "��������"<< a.individualEmpNo<<"��Ա�ĵȼ�,��н,����������"<<endl;
	input >> a.grade >> a.accumPay>>a.name>>a.password;
	return input;
}
bool employee::verify(int no, string pass) {
	if (individualEmpNo == no && password == pass) {
		return true;
	}
	else
	{
		return false;
	}
}

