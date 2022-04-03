#pragma once
#include "technician.h"
#include "manager.h"
#include "salesman.h"
#include "salesmanager.h"
#include "mylist.h"
class menu
{
public:
	menu();
	~menu();
	void main_menu();
	template<class T>
	void verify(T *, int*);
	void boss_menu();
	void salesmanager_menu();
	void common_menu();
	void boss_add();
	template<class T>
	void boss_add(T *, int*);
	void boss_remove();
	template<class T>
	void boss_remove_no(T *,int*);
	template<class T>
	void boss_remove_name(T *, int*);
	void boss_search();
	template<class T>
	void boss_search_name(T *, int*);
	template<class T>
	void boss_search_no(T *, int*,int);
	void boss_revise();
	template<class T>
	void boss_revise_name(T *, int*);
	template<class T>
	void boss_revise_no(T *, int*);
	void boss_export();
	template<class T>
	void boss_export_name(T *, int*);
	template<class T>
	void boss_export_no(T *, int*,int);
	void boss_adjust();
	template<class T>
	void boss_adjust_no(T *, int*);
	template<class T>
	void boss_adjust_name(T *, int*);
	void boss_adjust_std();
	void boss_statistic();
	template<class T>
	void boss_statistic(T *, int*);
	void boss_promote();
	template<class T>
	void boss_promote_no(T *, int*);
	template<class T>
	void boss_promote_name(T *, int*);
	void boss_adjust_relation();
private:
	manager	manager_list[100];
	salesman salesman_list[100];
	technician technician_list[100];
	salesmanager salesmanager_list[100];//数据库
	int scan_no;
	string scan_pass;
	string scan_name;//输入的数据
	int verify_amount;
	int manager_amount;
	int salesman_amount;
	int technician_amount;
	int salesmanager_amount;//计数
	bool verify_judge;
	bool return_main_judge;
	bool return_judge;
	bool exit_judge;
	bool operate_judge;//判断
	int option_main_menu;
	int option_boss_menu;
	int option_salesmanager_menu;
	int option_common_menu;
	int option;//菜单选择
	FILE *pFile;//文件操作
	string filename;
	string boss_password;
	int sum_up, min, max;
	int sum_up_all, min_all , max_all;
	int statistic_amount;
	salesman salesman_statistic[100];//统计数据
	int grade_up;
	int tmp_no;
	int tmp_data;
};
template<class T>
void menu::boss_add(T *tmp, int *amount) {
	if ((pFile = fopen(filename.c_str(), "r+t")) != NULL) {
		cout << "open file succeed" << endl;
		while (!feof(pFile)) {
			tmp[*amount].f_scan(pFile);
			(*amount)++;
		};
		fclose(pFile);
	}
	else
	{
		cout << "Fail to open file!" << endl;
	}
}
template<class T>
void menu::boss_remove_no(T *tmp,int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_individualEmpNo() == scan_no) {
			(*amount)--;
			for (int j = i; j < *amount; j++)
			{
				tmp[j] = tmp[j + 1];
			}
			operate_judge = true;
			cout << "删除成功" << endl;
		}
	};
}
template<class T>
void menu::boss_remove_name(T *tmp, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_name() == scan_name) {
			(*amount)--;
			for (int j = i; j < *amount; j++)
			{
				tmp[j] = tmp[j + 1];
			}
			operate_judge = true;
			cout << "删除成功" << endl;
		}
	};
}
template<class T>
void menu::verify(T *tmp, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].verify(scan_no, scan_pass))
		{
			verify_amount = i;
			verify_judge = true;
			common_menu();
			break;
		}
	}
}
template<class T>
void menu::boss_search_name(T *tmp, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_name() == scan_name) {
			operate_judge = true;
			cout << tmp[i];
		}
	};
}
template<class T>
void menu::boss_search_no(T *tmp, int *amount,int no) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_individualEmpNo() == no) {
			operate_judge = true;
			cout << tmp[i];
		}
	};
}
template<class T>
void menu::boss_revise_name(T *tmp, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_name() == scan_name) {
			operate_judge = true;
			cin>>tmp[i];
		}
	};
}
template<class T>
void menu::boss_revise_no(T *tmp, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_individualEmpNo() == scan_no) {
			operate_judge = true;
			cin >> tmp[i];
		}
	};
}
template<class T>
void menu::boss_export_name(T *tmp, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_name() == scan_name) {
			operate_judge = true;
			if ((pFile = fopen(filename.c_str(), "r+t")) != NULL) {
				cout << "open file succeed" << endl;
				tmp[i].f_print(pFile);
			}
			else
			{
				cout << "Fail to open file!" << endl;
			}
		}
	};
}
template<class T>
void menu::boss_export_no(T *tmp, int *amount,int no) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_individualEmpNo() == no) {
			operate_judge = true;
			if ((pFile = fopen(filename.c_str(), "r+t")) != NULL) {
				cout << "open file succeed" << endl;
				tmp[i].f_print(pFile);
			}
			else
			{
				cout << "Fail to open file!" << endl;
			}
		}
	};
}
template<class T>
void menu::boss_adjust_name(T *adjust, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (operate_judge == true)
		{
			break;
		}
		if (adjust[i].get_name() == scan_name) {
			operate_judge = true;
			T tmp = adjust[i];
			boss_remove_name(adjust, amount);
			cout << "请选择调整后的岗位1.销售经理；2.销售员；3.经理；4.技术员;5.返回" << endl;
			cin >> option;
			switch (option)
			{
			case 1:
				salesmanager_list[salesmanager_amount].set_name(tmp.get_name());
				salesmanager_list[salesmanager_amount].set_password(tmp.get_password());
				salesmanager_list[salesmanager_amount].set_individualEmpNo(tmp.get_individualEmpNo());
				salesmanager_list[salesmanager_amount].set_grade(tmp.get_grade());
				salesmanager_list[salesmanager_amount].promote(0);
				salesmanager_amount++;
				break;
			case 2:
				salesman_list[salesman_amount].set_name(tmp.get_name());
				salesman_list[salesman_amount].set_password(tmp.get_password());
				salesman_list[salesman_amount].set_individualEmpNo(tmp.get_individualEmpNo());
				salesman_list[salesman_amount].set_grade(tmp.get_grade());
				cout << "请输入月销售额" << endl;
				cin >> tmp_data;
				salesman_list[salesman_amount].set_month_sales(tmp_data);
				salesman_list[salesman_amount].promote(0);
				salesman_amount++;
				break;
			case 3:
				manager_list[manager_amount].set_name(tmp.get_name());
				manager_list[manager_amount].set_password(tmp.get_password());
				manager_list[manager_amount].set_individualEmpNo(tmp.get_individualEmpNo());
				manager_list[manager_amount].set_grade(tmp.get_grade());
				manager_list[manager_amount].promote(0);
				manager_amount++;
				break;
			case 4:
				technician_list[technician_amount].set_name(tmp.get_name());
				technician_list[technician_amount].set_password(tmp.get_password());
				technician_list[technician_amount].set_individualEmpNo(tmp.get_individualEmpNo());
				technician_list[technician_amount].set_grade(tmp.get_grade());
				cout << "请输入月工作时间" << endl;
				cin >> tmp_data;
				technician_list[technician_amount].set_month_workhours(tmp_data);
				technician_list[technician_amount].promote(0);
				technician_amount++;
				break;
			case 5:
				break;
			default:
				cout << "输入错误,请重新输入" << endl;
				break;
			}
			break;
		}
	};
}
template<class T>
void menu::boss_adjust_no(T *adjust, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (operate_judge == true)
		{
			break;
		}
		if (adjust[i].get_individualEmpNo() == scan_no) {
			operate_judge = true;
			T tmp = adjust[i];
			boss_remove_no(adjust, amount);
			cout << "请选择调整后的岗位1.销售经理；2.销售员；3.经理；4.技术员;5.返回" << endl;
			cin >> option;
			switch (option)
			{
			case 1:
				salesmanager_list[salesmanager_amount].set_name(tmp.get_name());
				salesmanager_list[salesmanager_amount].set_password(tmp.get_password());
				salesmanager_list[salesmanager_amount].set_individualEmpNo(tmp.get_individualEmpNo());
				salesmanager_list[salesmanager_amount].set_grade(tmp.get_grade());
				salesmanager_list[salesmanager_amount].promote(0);
				salesmanager_amount++;
				break;
			case 2:
				salesman_list[salesman_amount].set_name(tmp.get_name());
				salesman_list[salesman_amount].set_password(tmp.get_password());
				salesman_list[salesman_amount].set_individualEmpNo(tmp.get_individualEmpNo());
				salesman_list[salesman_amount].set_grade(tmp.get_grade());
				cout << "请输入月销售额" << endl;
				cin >> tmp_data;
				salesman_list[salesman_amount].set_month_sales(tmp_data);
				salesman_list[salesman_amount].promote(0);
				salesman_amount++;
				break;
			case 3:
				manager_list[manager_amount].set_name(tmp.get_name());
				manager_list[manager_amount].set_password(tmp.get_password());
				manager_list[manager_amount].set_individualEmpNo(tmp.get_individualEmpNo());
				manager_list[manager_amount].set_grade(tmp.get_grade());
				manager_list[manager_amount].promote(0);
				manager_amount++;
				break;
			case 4:
				technician_list[technician_amount].set_name(tmp.get_name());
				technician_list[technician_amount].set_password(tmp.get_password());
				technician_list[technician_amount].set_individualEmpNo(tmp.get_individualEmpNo());
				technician_list[technician_amount].set_grade(tmp.get_grade());
				cout << "请输入月工作时间" << endl;
				cin >> tmp_data;
				technician_list[technician_amount].set_month_workhours(tmp_data);
				technician_list[technician_amount].promote(0);
				technician_amount++;
				break;
			case 5:
				break;
			default:
				cout << "输入错误,请重新输入" << endl;
				break;
			}
			break;
		}
	};
}
template<class T>
void menu::boss_statistic(T *adjust, int *amount) {
	sum_up = 0;
	for (int j = 0; j < *amount; j++)
	{
		sum_up += adjust[j].get_accumPay();
	}
	
	max = adjust[0].get_accumPay(); min = adjust[0].get_accumPay();
	for (int j = 0; j <(*amount) - 1; j++)
	{
		if (max < adjust[j+1].get_accumPay()) {
			max = adjust[j + 1].get_accumPay();
		}
		if (min > adjust[j + 1].get_accumPay())
		{
			min = adjust[j + 1].get_accumPay();
		}
	}
}
template<class T>
void menu::boss_promote_no(T *tmp, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_individualEmpNo() == scan_no) {
			operate_judge = true;
			tmp[i].promote(grade_up);
			cout << "提拔成功" << endl;
			cout << tmp[i];
		}
	};
}
template<class T>
void menu::boss_promote_name(T *tmp, int *amount) {
	for (int i = 0; i < *amount; i++)
	{
		if (tmp[i].get_name() == scan_name) {
			operate_judge = true;
			tmp[i].promote(grade_up);
			cout << "提拔成功" << endl;
			cout << tmp[i];
		}
	};
}