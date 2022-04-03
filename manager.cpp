#pragma once
#include "manager.h"
void manager::print() {

}
manager::manager() :employee(1, 0,"\0","\0")
{
	pay();
}
manager::manager(int gra,string na,string pass) : employee(gra, 0,na,pass)
{
	promote(gra - 1);
}
manager::~manager() {
}
manager &manager::operator =(manager &per) //赋值运算符重载
{
	set_name(per.get_name());
	set_accumPay(per.get_accumPay());
	set_grade(per.get_grade());
	set_individualEmpNo(per.get_individualEmpNo());
	set_password(per.get_password());
	fix_pay = per.fix_pay;
	return *this;   //实现可连续赋值
}

ostream& operator<<(ostream&output, manager&a) {
	output << "经理编号为" << a.get_individualEmpNo() << "  " << "等级为" << a.get_grade() << "  " << "月薪为" << a.get_accumPay()<<" " << "姓名为" << a.get_name() << "  " << "密码为" << a.get_password()<<endl;
	return output;
}
istream& operator>>(istream&input, manager&a) {
	cout << "请输入编号" << a.get_individualEmpNo() << "经理的等级,姓名，密码" << endl;
	int gra; string na, pass;
	input >> gra>>na>>pass;
	a.set_grade(gra);
	a.set_name(na);
	a.set_password(pass);
	a.fix_pay = manager_pay;
	a.promote(gra - 1);;
	return input;
}
void manager::set_fix_pay(int pay) {
	fix_pay = pay;
};
int manager::get_fix_pay() {
	return fix_pay;
};
int manager::pay() {
	set_accumPay(fix_pay);
	return fix_pay;
}

bool manager::promote(int grade_up) {
	int grade_tmp = get_grade();
	if (grade_tmp+grade_up>0)
	{
		grade_tmp += grade_up;
		fix_pay = manager_pay + manager_promotion_pay * (grade_tmp - 1);
		set_grade(grade_tmp);
		pay();
		return true;
	}
	return false;
}//1级默认固定工资，每升一级，工资增加固定值
void manager::update_info() {
	cout << "请输入编号" << get_individualEmpNo() << "经理的等级" << endl;
	int gra;
	cin >> gra;
	set_grade(gra);
	promote(gra - get_grade());
}
void manager::f_scan(FILE* pFile) {
	int tmp_grade=0;
	fscanf(pFile, "%d", &tmp_grade);
	set_grade(tmp_grade);
	char tmp_name[256];
	fscanf(pFile, "%s", tmp_name);
	set_name(tmp_name);
	char tmp_pass[256];
	fscanf(pFile, "%s", tmp_pass);
	set_password(tmp_pass);
	fix_pay = manager_pay;
	promote(tmp_grade - 1);
}
void manager::f_print(FILE* pFile) {
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
	fprintf(pFile, "%d\n", get_accumPay());
}