#pragma once
#include "salesmanager.h"
void salesmanager::print() {

}
salesmanager::salesmanager() :manager(), salesman()
{
	set_commission_rate(salesmanager_rate);
	set_fix_pay(salesmanager_pay);
	pay();
	salesman_no.clear();
}
salesmanager::salesmanager(int gra, int sales, mylist<int>& salesman_list,string na,string pass) : manager(gra,na,pass),salesman(gra,sales,NULL,na,pass)
{
	salesman_no.clear();
	salesman_no = salesman_list;
	set_fix_pay(salesmanager_pay);
	set_commission_rate (salesmanager_rate);
	promote(gra - 1);
}
salesmanager::~salesmanager() {
	salesman_no.clear();
}
void salesmanager::change_sales(int newsales) {
	int tmp_monthsales = get_month_sales();
	tmp_monthsales += newsales;
	set_month_sales(tmp_monthsales);
	pay();
}
bool salesmanager::add_salesman(int no) {
	mynode<int>*p = salesman_no.find(no);
	if (p->data==no)
	{
		return false;
	}
	salesman_no.insert_rear(no);
	return true;
}
bool salesmanager::remove_salesman(int no) {
	int pos = salesman_no.position(no);
	int tmp_data;
	return salesman_no.remove(pos,tmp_data);
}
ostream& operator<<(ostream&output, salesmanager&a) {
	output << "销售经理编号为" << a.get_individualEmpNo() << "  " << "等级为" << a.get_grade() << "  " << "月薪为" << a.get_accumPay() << "  " << "销售额为" << a.get_month_sales() << "  " << "提成率为" << a.get_commission_rate()<<" " << "姓名为" << a.get_name() << "  " << "密码为" << a.get_password() << endl;
	output << "下属销售员编号:" << endl;
	if (a.salesman_no.print())
	{
		
	}
	else
	{
		output << "无下属销售员" << endl;
	}
	return output;
}
istream& operator>>(istream&input, salesmanager&a) {
	cout << "请输入编号" << a.get_individualEmpNo() << "销售经理的等级,姓名，密码" << endl;
	int gra; string na, pass;
	input >> gra >> na >> pass;
	a.set_grade(gra);
	a.set_name(na);
	a.set_password(pass);
	a.set_fix_pay(salesmanager_pay);
	a.set_commission_rate(salesmanager_rate);
	a.promote(gra - 1);
	return input;
}
int salesmanager::pay() {
	int pay;
	pay = get_fix_pay() + (int)(get_commission_rate()*get_month_sales());
	set_accumPay(pay);
	return pay;
}

bool salesmanager::promote(int grade_up) {
	int grade_tmp = get_grade();
	int fix_pay_tmp;
	double rate_tmp;
	if (grade_tmp + grade_up > 0)
	{
		grade_tmp += grade_up;
		fix_pay_tmp = salesmanager_pay + manager_promotion_pay * (grade_tmp - 1);
		rate_tmp=salesmanager_rate+salesmanager_promotion_rate* (grade_tmp - 1);
		set_grade(grade_tmp);
		set_fix_pay(fix_pay_tmp);
		set_commission_rate(rate_tmp);
		pay();
		return true;
	}
	return false;
}//1级默认固定工资，每升一级，工资增加固定值
void salesmanager::update_info() {
	cout << "请输入编号" << get_individualEmpNo() << "销售经理的等级" << endl;
	int gra;
	cin >> gra;
	set_grade(gra);
	promote(gra - get_grade());
}
salesmanager &salesmanager::operator =(salesmanager &per) //赋值运算符重载
{
	set_name(per.get_name());
	set_accumPay(per.get_accumPay());
	set_grade(per.get_grade());
	set_individualEmpNo(per.get_individualEmpNo());
	set_password(per.get_password());
	set_month_sales (per.get_month_sales());
	set_commission_rate (per.get_commission_rate());
	set_boss ( per.get_boss());
	set_fix_pay(per.get_fix_pay());
	return *this;   //实现可连续赋值
}
void salesmanager::f_scan(FILE* pFile) {
	int tmp_grade = 0;
	fscanf(pFile, "%d", &tmp_grade);
	set_grade(tmp_grade);
	char tmp_name[256];
	fscanf(pFile, "%s", tmp_name);
	set_name(tmp_name);
	char tmp_pass[256];
	fscanf(pFile, "%s", tmp_pass);
	set_password(tmp_pass);
	set_fix_pay (salesmanager_pay);
	set_commission_rate(salesmanager_rate);
	promote(tmp_grade - 1);
}
void salesmanager::f_print(FILE* pFile) {
	promote(0);
	fprintf(pFile, "%d\t", get_individualEmpNo());
	fprintf(pFile, "%d\t", get_grade());
	char tmp_name[256];
	strcpy(tmp_name, get_name().c_str());
	fprintf(pFile, "%s\t", tmp_name);
	char tmp_pass[256];
	strcpy(tmp_pass, get_password().c_str());
	fprintf(pFile, "%s\t", tmp_pass);
	fprintf(pFile, "%d\t", get_fix_pay());
	fprintf(pFile, "%d\t", get_accumPay());
	for (int i = 0; i < salesman_no.length(); i++)
	{
		int no;
		mynode<int> *p = new mynode<int>;
		if (salesman_no.get_head(p))
		{
			while (NULL != p->next)
			{
				p = p->next;
				fprintf(pFile, "%d\t", p->data);
			}
		};
	}
	fprintf(pFile, "%d\n", get_commission_rate());
	
}