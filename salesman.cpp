#pragma once
#include "salesman.h"
#include "salesmanager.h"
void salesman::print() {

}
salesman::salesman() :employee()
{
	month_sales = 0;
	commission_rate = salesman_rate;
	boss = NULL;
	pay();
}
salesman::salesman(int gra, int sales,salesmanager *bo,string na,string pass) : employee(gra, 0,na,pass)
{
	month_sales = sales;
	commission_rate = salesman_rate;
	set_accumPay(month_sales * commission_rate);
	boss = bo;
	if (boss!=NULL)
	{
		boss->change_sales(month_sales);
		boss->add_salesman(get_individualEmpNo());
	}
	promote(gra - 1);
}
salesman::~salesman() {
	if (boss != NULL)
	{
		boss->change_sales(-month_sales);
		boss->remove_salesman(get_individualEmpNo());
		boss->remove_salesman(get_individualEmpNo());
	}
}
void salesman::set_month_sales(int sales) {
	if (boss!=NULL)
	{
		boss->change_sales(sales - month_sales);
	}
	month_sales = sales;
	set_accumPay((int)(sales*commission_rate));
}
int salesman::get_month_sales() {
	return month_sales;
}
double salesman::get_commission_rate() {
	return commission_rate;
}
void salesman::set_commission_rate(double rate) {
	commission_rate = rate;
	set_accumPay((int)(month_sales*commission_rate));
}
salesmanager* salesman::get_boss() {
	return boss;
}
void salesman::set_boss(salesmanager *bo) {
	if (boss != NULL)
	{
		boss->change_sales(-month_sales);
		boss->remove_salesman(get_individualEmpNo());
	}
	if (bo != NULL)
	{
		boss = bo;
		boss->change_sales(month_sales);
		boss->add_salesman(get_individualEmpNo());
	}
}
ostream& operator<<(ostream&output, salesman&a) {
	output << "销售员编号为" << a.get_individualEmpNo() << "  " << "等级为" << a.get_grade() << "  " << "月薪为" << a.get_accumPay() << "  " << "销售额为" << a.month_sales << "  " << "提成率为" << a.commission_rate << "  " << "姓名为" << a.get_name() << "  " << "密码为" << a.get_password() << " ";
	if (a.boss!=NULL)
	{
		output<< "上司编号为" << a.boss->get_individualEmpNo() << " "<<endl;
	}
	else
	{
		output << "无上司" << endl;
	}
	return output;
}
istream& operator>>(istream&input, salesman&a) {
	cout << "请输入编号" << a.get_individualEmpNo() << "销售员的等级,姓名，密码,月销售额" << endl;
	int gra; string na, pass;
	input >> gra >> na >> pass >> a.month_sales;
	a.set_grade(gra);
	a.set_accumPay(a.month_sales*a.commission_rate);
	a.set_name(na);
	a.set_password(pass);
	a.commission_rate = salesman_rate;
	a.promote(gra - 1);;
	return input;
}
void salesman::f_scan(FILE* pFile) {
	int gra=0; char na[256], pass[256];
	fscanf(pFile, "%d", &gra);
	fscanf(pFile, "%s", na);
	fscanf(pFile, "%s", pass);
	fscanf(pFile, "%d", &month_sales);
	set_grade(gra);
	set_name(na);
	set_password(pass);
	promote(gra - 1);
}
void salesman::f_print(FILE* pFile) {
	fprintf(pFile, "%d\t", get_individualEmpNo());
	fprintf(pFile, "%d\t", get_grade());
	char tmp_name[256];
	strcpy(tmp_name, get_name().c_str());
	fprintf(pFile, "%s\t", tmp_name);
	char tmp_pass[256];
	strcpy(tmp_pass, get_password().c_str());
	fprintf(pFile, "%s\t", tmp_pass);
	fprintf(pFile, "%d\t", get_accumPay());
	fprintf(pFile, "%d\t", month_sales);
	fprintf(pFile, "%lf\t", commission_rate);
	fprintf(pFile, "%d\n", boss->get_individualEmpNo());
}
void salesman::input() {
	cout << "请输入编号" << get_individualEmpNo() << "销售员的等级,姓名，密码" << endl;
	int gra; string na, pass;
	cin >> gra >> na >> pass ;
	set_grade(gra);
	set_accumPay(month_sales*commission_rate);
	set_name(na);
	set_password(pass);
	commission_rate = salesman_rate;
	promote(gra - 1);
}
int salesman::pay() {
	int pay;
	pay = (int)(get_commission_rate()*get_month_sales());
	set_accumPay(pay);
	return pay;
}

bool salesman::promote(int grade_up) {
	int grade_tmp = get_grade();
	double rate_tmp;
	if (grade_tmp + grade_up > 0)
	{
		grade_tmp += grade_up;
		rate_tmp = salesmanager_rate + salesmanager_promotion_rate * (grade_tmp - 1);
		set_grade(grade_tmp);
		set_commission_rate(rate_tmp);
		pay();
		return true;
	}
	return false;
}//1级默认固定工资，每升一级，工资增加固定值
void salesman::update_info() {
	cout << "请输入编号" << get_individualEmpNo() << "销售员的等级,月销售额" << endl;
	int gra;
	cin >> gra >> month_sales;
	set_grade(gra);
	promote(gra - get_grade());
}
salesman &salesman::operator =(salesman &per) //赋值运算符重载
{
	set_name(per.get_name());
	set_accumPay(per.get_accumPay());
	set_grade(per.get_grade());
	set_individualEmpNo(per.get_individualEmpNo());
	set_password(per.get_password());
	month_sales = per.month_sales;
	commission_rate= per.commission_rate;
	boss = per.boss;
	return *this;   //实现可连续赋值
}