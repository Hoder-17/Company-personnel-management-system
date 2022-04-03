#pragma once
#include "technician.h"
void technician::print() {

}
technician::technician():employee(1,0,"\0","\0")
{
	month_workhours = 0;
	wage = technician_wage;
}
technician::technician(int gra,int workhours,string na,string pass): employee(gra, 0,na,pass)
{
	month_workhours = workhours;
	wage = technician_wage;
	set_accumPay(workhours * wage);
}
technician::~technician() {

}
void technician::set_month_workhours(int hours) {
	month_workhours = hours;
}
void technician::set_wage(int wa) {
	wage = wa;
}
ostream& operator<<(ostream&output, technician&a) {
	output << "技术员编号为" << a.get_individualEmpNo() << "  " << "等级为" << a.get_grade() << "  " << "月薪为" << a.get_accumPay() << "  " << "时薪为" << a.wage << "  " << "月工作时间为" << a.month_workhours << " " << "姓名为" << a.get_name() << "  " << "密码为" << a.get_password()<< endl;
	return output;
}
istream& operator>>(istream&input, technician&a) {
	cout << "请输入编号" << a.get_individualEmpNo() << "技术员的等级，姓名，密码，工作时间" << endl;
	int gra; string na, pass;
	input >>gra  >> na >> pass >> a.month_workhours;
	a.set_grade(gra);
	a.set_accumPay(a.month_workhours*a.wage);
	a.set_name(na);
	a.set_password(pass);
	a.wage = technician_wage;
	a.promote(gra - 1);;
	return input;
}
void technician::f_scan(FILE* pFile) {
	int gra=0; char na[256], pass[256];
	fscanf(pFile, "%d", &gra);
	fscanf(pFile, "%s", na);
	fscanf(pFile, "%s", pass);
	fscanf(pFile, "%d", &month_workhours);
	set_grade(gra);
	set_name(na);
	set_password(pass);
	wage = technician_wage;
	promote(gra - 1);;
}
void technician::f_print(FILE* pFile) {
	fprintf(pFile, "%d\t", get_individualEmpNo());
	fprintf(pFile, "%d\t", get_grade());
	char tmp_name[256];
	strcpy(tmp_name, get_name().c_str());
	fprintf(pFile, "%s\t",tmp_name);
	char tmp_pass[256];
	strcpy(tmp_pass, get_password().c_str());
	fprintf(pFile, "%s\t", tmp_pass);
	fprintf(pFile, "%d\t", get_accumPay());
	fprintf(pFile, "%d\t", month_workhours);
	fprintf(pFile, "%d\n", wage);
}
void technician::input(){
	cout << "请输入编号" << get_individualEmpNo() << "技术员的等级，姓名，密码" << endl;
	int gra; string na, pass;
	cin >> gra >> na >> pass ;
	set_grade(gra);
	set_name(na);
	set_password(pass);
	wage = technician_wage;
	promote(gra - 1);
}
int technician::pay() {
	int pay;
	pay = month_workhours* wage;
	set_accumPay(pay);
	return pay;
}

bool technician::promote(int grade_up) {
	int grade_tmp = get_grade();
	int wage_tmp;
	if (grade_tmp + grade_up > 0)
	{
		grade_tmp += grade_up;
		wage_tmp = technician_wage + technician_promotion_wage * (grade_tmp - 1);
		set_grade(grade_tmp);
		set_wage(wage_tmp);
		pay();
		return true;
	}
	return false;
}//1级默认固定工资，每升一级，工资增加固定值
void technician::update_info() {
	cout << "请输入编号" << get_individualEmpNo() << "技术员的等级，月工作时间" << endl;
	int gra;
	cin >> gra >> month_workhours;
	set_grade(gra);
	promote(gra - get_grade());
}
technician &technician::operator =(technician &per) //赋值运算符重载
{
	set_name(per.get_name());
	set_accumPay(per.get_accumPay());
	set_grade(per.get_grade());
	set_individualEmpNo(per.get_individualEmpNo());
	set_password(per.get_password());
	month_workhours = per.month_workhours;
	wage = per.wage;
	return *this;   //实现可连续赋值
}