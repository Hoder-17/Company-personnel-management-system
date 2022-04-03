#pragma once
#include "menu.h"
menu::menu()
{
	salesmanager_amount = 0;
	manager_amount = 0;
	technician_amount = 0;
	salesman_amount = 0;
	verify_judge = false;
	exit_judge = false;
	return_main_judge = false;
	return_judge = false;
	operate_judge = false;
	boss_password = "124567";
	sum_up = 0; sum_up_all = 0;
	max = 0; max_all = 0;
	min = 0; min_all = 0;
	statistic_amount = 0;
	grade_up = 0;
	tmp_no = 0;
	tmp_data = 0;
}
menu::~menu()
{
}
void menu::main_menu() {
	do
	{
		verify_judge = false;
		cout << "\n\t\t\t\t\t  ----------------欢迎使用xx公司管理系统----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t  ----------------请选择身份----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.系统管理员----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.销售经理----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.经理----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.技术员----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------5.销售员----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------6:退出系统----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              请选择序号(1-6)              \t\t\t\t\t\n" << endl;
		cin >> option_main_menu;
		cout << "请输入账号" << endl;
		cin >> scan_no;
		cout << "请输入密码" << endl;
		cin >> scan_pass;
		switch (option_main_menu)
		{
		case 1:
			if (scan_no==1001000&&scan_pass==boss_password)
			{
				verify_judge = true;
				boss_menu();
			}
			break;
		case 2:
			for (int i = 0; i < salesmanager_amount; i++)
			{
				if (salesmanager_list[i].verify(scan_no, scan_pass))
				{
					verify_judge = true;
					verify_amount = i;
					salesmanager_menu();
					break;
				}
			}
			break;
		case 3:
			verify(manager_list, &manager_amount);
			break;
		case 4:
			verify(technician_list, &technician_amount);
			break;
		case 5:
			verify(salesman_list, &salesman_amount);
			break;
		case 6:
			exit_judge = true;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
		if (verify_judge==false)
		{
			cout << "登录失败" << endl;
		}
	} while (exit_judge==false);
}
void menu::boss_menu() {
	return_main_judge = false;
	cout << "\n\t\t\t\t\t  ----------------登录成功----------------  \t\t\t\t\t\n" << endl;
	do
	{
		return_judge = false;
		cout << "\n\t\t\t\t\t  ----------------管理员界面----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.添加职工----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.删除职工----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.查询职工----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.修改职工----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------5.统计职工----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------6.导出职工----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------7.调整岗位----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------8.调整工资标准----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------9.调整关系----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------10.提拔职工----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------11.修改密码----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------12.返回上一菜单----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              请选择序号(1-12)              \t\t\t\t\t\n" << endl;
		cin >> option_boss_menu;
		switch (option_boss_menu)
		{
		case 1:
			boss_add();
			break;
		case 2:
			boss_remove();
			break;
		case 3:
			boss_search();
			break;
		case 4:
			boss_revise();
			break;
		case 5:
			boss_statistic();
			break;
		case 6:
			boss_export();
			break;
		case 7:
			boss_adjust();
			break;
		case 8:
			boss_adjust_std();
			break;
		case 9:
			boss_adjust_relation();
			break;
		case 10:
			boss_promote();
			break;
		case 11:
			cout << "请输入修改后的密码" << endl;
			cin >> boss_password;
			break;
		case 12:
			return_main_judge =true;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
	} while (return_main_judge==false);
	

}
void menu::salesmanager_menu() {
	return_main_judge = false;
	cout << "\n\t\t\t\t\t  ----------------登录成功----------------  \t\t\t\t\t\n" << endl;
	do
	{
		return_judge = false;
		cout << "\n\t\t\t\t\t  ----------------销售经理界面----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.查询个人信息----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.修改个人信息----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.查询下属销售员信息----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.统计下属销售员信息----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------5.导出下属销售员信息----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------6.修改密码----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------7.返回上一菜单----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              请选择序号(1-7)              \t\t\t\t\t\n" << endl;
		cin >> option_salesmanager_menu;
		switch (option_salesmanager_menu)
		{
		case 1:
			cout << salesmanager_list[verify_amount];
			break;
		case 2:
			cin>> salesmanager_list[verify_amount];
			break;
		case 3:
			for (int i = 0; i < salesmanager_list[verify_amount].salesman_no.length(); i++)
			{
				salesmanager_list[verify_amount].salesman_no.get_data(i+1, tmp_no);
				boss_search_no(salesman_list, &salesman_amount,tmp_no);
			}
			break;
		case 4:
			statistic_amount = 0;
			for (int i = 0; i < salesmanager_list[verify_amount].salesman_no.length(); i++)
			{
				salesmanager_list[verify_amount].salesman_no.get_data(i+1, tmp_no);
				for (int i = 0; i < salesman_amount; i++)
				{
					if (salesman_list[i].get_individualEmpNo() == tmp_no) {
						salesman_statistic[statistic_amount]= salesman_list[i];
						statistic_amount++;
					}
				};
			}
			boss_statistic(salesman_statistic, &statistic_amount);
			cout << "平均月薪为" << ((double)sum_up / (double)salesmanager_amount) << endl;//平均值
			cout << "最高月薪为" << max << endl;
			cout << "最低月薪为" << min << endl;
			break;
		case 5:
			cout << "请输入导出的文件名" << endl;
			cin >> filename; operate_judge = false;
			for (int i = 0; i < salesmanager_list[verify_amount].salesman_no.length(); i++)
			{
				salesmanager_list[verify_amount].salesman_no.get_data(i+1, tmp_no);
				boss_export_no(salesman_list, &salesman_amount, tmp_no);
			}
			fclose(pFile);
			if (operate_judge == false)
			{
				cout << "用户不存在" << endl;
			}
			break;
		case 6:
			cout << "请输入修改后的密码" << endl;
			cin >> scan_pass;
			salesmanager_list[verify_amount].set_password(scan_pass);
			break;
		case 7:
			return_main_judge = true;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
	} while (return_main_judge == false);
}
void menu::common_menu() {
	return_main_judge = false;
	cout << "\n\t\t\t\t\t  ----------------登录成功----------------  \t\t\t\t\t\n" << endl;
	do
	{
		return_judge = false;
		cout << "\n\t\t\t\t\t----------------1.查询个人信息----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.修改个人信息----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.修改密码----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.返回上一菜单----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              请选择序号(1-4)              \t\t\t\t\t\n" << endl;
		cin >> option_common_menu;
		switch (option_common_menu)
		{
		case 1:
			switch (option_main_menu)
			{
			case 3:
				cout<<manager_list[verify_amount];
				break;
			case 4:
				cout<<technician_list[verify_amount];
				break;
			case 5:
				cout << salesman_list[verify_amount];
				break;
			}
			break;
		case 2:
			switch (option_main_menu)
			{
			case 3:
				cin>> manager_list[verify_amount];
				break;
			case 4:
				technician_list[verify_amount].input();
				break;
			case 5:
				salesman_list[verify_amount].input();
				break;
			}
			break;
		case 3:
			cout << "请输入修改后的密码" << endl;
			cin >> scan_pass;
			switch (option_main_menu)
			{
			case 3:
				manager_list[verify_amount].set_password(scan_pass);
				break;
			case 4:
				technician_list[verify_amount].set_password(scan_pass);
				break;
			case 5:
				salesman_list[verify_amount].set_password(scan_pass);
				break;
			}
			salesmanager_list[verify_amount].set_password(scan_pass);
			break;
		case 4:
			return_main_judge = true;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
	} while (return_main_judge == false);
}

void menu::boss_add() {
	do
	{
		cout << "是否使用文件流添加：1.是；2.否;3.返回：" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "请输入文件名" << endl;
			cin >> filename;
			cout << "请选择添加的用户1.销售经理；2.经理；3.销售员；4.技术员;5.返回" << endl;
			cin >> option;
			switch (option)
			{
			case 1:
				boss_add(salesmanager_list, &salesmanager_amount);
				break;
			case 2:
				boss_add(manager_list, &manager_amount);
				break;
			case 3:
				boss_add(salesman_list, &salesman_amount);
				break;
			case 4:
				boss_add(technician_list, &technician_amount);
				break;
			case 5:
				break;
			default:
				cout << "输入错误,请重新输入" << endl;
				break;
			}
			break;
		case 2:
			cout << "请选择添加的用户1.销售经理；2.销售员；3.经理；4.技术员;5.返回" << endl;
			cin >> option;
			switch (option)
			{
			case 1:
				cin >> salesmanager_list[salesmanager_amount];
				salesmanager_amount++;
				break;
			case 2:
				cin >> salesman_list[salesman_amount];
				salesman_amount++;
				break;
			case 3:
				cin >> manager_list[manager_amount];
				manager_amount++;
				break;
			case 4:
				cin >> technician_list[technician_amount];
				technician_amount++;
				break;
			case 5:
				break;
			default:
				cout << "输入错误,请重新输入" << endl;
				break;
			}
			break;
		case 3:
			return_judge = true;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
	} while (return_judge == false);
}
void menu::boss_remove() {
	cout << "请选择输入1.编号；2.姓名" << endl;
	cin >> option;
	operate_judge = false;
	switch (option)
	{
	case 1:
		cout << "请输入编号" << endl;
		cin >> scan_no;
		boss_remove_no(salesmanager_list, &salesmanager_amount);
		boss_remove_no(salesman_list, &salesman_amount);
		boss_remove_no(manager_list, &manager_amount);
		boss_remove_no(technician_list, &technician_amount);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	case 2:
		cout << "请输入姓名" << endl;
		cin >> scan_name;
		boss_remove_name(salesmanager_list, &salesmanager_amount);
		boss_remove_name(salesman_list, &salesman_amount);
		boss_remove_name(manager_list, &manager_amount);
		boss_remove_name(technician_list, &technician_amount);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	default:
		cout << "输入错误,请重新输入" << endl;
		break;
	}
}
void menu::boss_search() {
	cout << "请选择输入1.编号；2.姓名" << endl;
	cin >> option;
	operate_judge = false;
	switch (option)
	{
	case 1:
		cout << "请输入编号" << endl;
		cin >> scan_no;
		boss_search_no(salesmanager_list, &salesmanager_amount,scan_no);
		boss_search_no(salesman_list, &salesman_amount, scan_no);
		boss_search_no(manager_list, &manager_amount, scan_no);
		boss_search_no(technician_list, &technician_amount, scan_no);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	case 2:
		cout << "请输入姓名" << endl;
		cin >> scan_name;
		boss_search_name(salesmanager_list, &salesmanager_amount);
		boss_search_name(salesman_list, &salesman_amount);
		boss_search_name(manager_list, &manager_amount);
		boss_search_name(technician_list, &technician_amount);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	default:
		cout << "输入错误,请重新输入" << endl;
		break;
	}
}
void menu::boss_revise() {
	cout << "请选择输入1.编号；2.姓名" << endl;
	cin >> option;
	operate_judge = false;
	switch (option)
	{
	case 1:
		cout << "请输入编号" << endl;
		cin >> scan_no;
		boss_revise_no(salesmanager_list, &salesmanager_amount);
		boss_revise_no(salesman_list, &salesman_amount);
		boss_revise_no(manager_list, &manager_amount);
		boss_revise_no(technician_list, &technician_amount);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	case 2:
		cout << "请输入姓名" << endl;
		cin >> scan_name;
		boss_revise_name(salesmanager_list, &salesmanager_amount);
		boss_revise_name(salesman_list, &salesman_amount);
		boss_revise_name(manager_list,& manager_amount);
		boss_revise_name(technician_list, &technician_amount);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	default:
		cout << "输入错误,请重新输入" << endl;
		break;
	}
}
void menu::boss_export() {
	return_judge = false;
	cout << "请输入导出的文件名" << endl;
	cin >> filename;
	do
	{
		cout << "请选择输入1.编号；2.姓名;3.返回" << endl;
		cin >> option;
		operate_judge = false;
		switch (option)
		{
		case 1:
			cout << "请输入编号" << endl;
			cin >> scan_no;
			boss_export_no(salesmanager_list, &salesmanager_amount, scan_no);
			boss_export_no(salesman_list, &salesman_amount, scan_no);
			boss_export_no(manager_list, &manager_amount, scan_no);
			boss_export_no(technician_list, &technician_amount, scan_no);
			if (operate_judge == false)
			{
				cout << "用户不存在" << endl;
			}
			break;
		case 2:
			cout << "请输入姓名" << endl;
			cin >> scan_name;
			boss_export_name(salesmanager_list, &salesmanager_amount);
			boss_export_name(salesman_list, &salesman_amount);
			boss_export_name(manager_list, &manager_amount);
			boss_export_name(technician_list, &technician_amount);
			if (operate_judge == false)
			{
				cout << "用户不存在" << endl;
			}
			break;
		case 3:
			return_judge = true;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
	} while (return_judge==false);
	fclose(pFile);
}
void menu::boss_adjust() {
	cout << "请选择输入1.编号；2.姓名；3.返回" << endl;
	cin >> option;
	operate_judge = false;
	switch (option)
	{
	case 1:
		cout << "请输入编号：" << endl;
		cin >> scan_no;
		boss_adjust_no(salesmanager_list, &salesmanager_amount);
		boss_adjust_no(salesman_list, &salesman_amount);
		boss_adjust_no(manager_list, &manager_amount);
		boss_adjust_no(technician_list, &technician_amount);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	case 2:
		cout << "请输入姓名" << endl;
		cin >> scan_name;
		boss_adjust_name(salesmanager_list, &salesmanager_amount);
		boss_adjust_name(salesman_list, &salesman_amount);
		boss_adjust_name(manager_list, &manager_amount);
		boss_adjust_name(technician_list, &technician_amount);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	case 3:
		break;
	default:
		cout << "输入错误,请重新输入" << endl;
		break;
	}
}
void menu::boss_adjust_std() {
	cout << "请选择调整1.经理固定月薪；2.经理提拔固定月薪；3.销售员提成率；4.销售员提拔提成率；5.技术员时薪;6.技术员提拔时薪；7.销售经理固定月薪；8.销售经理提拔固定月薪；9.销售经理提成率；10.销售经理提拔提成率；11.返回" << endl;
	cin >> option;
	cout << "请输入调整后的工资标准" << endl;
	switch (option)
	{
	case 1:
		cin >> manager_pay;
		for (int i = 0; i < manager_amount; i++)
		{
			manager_list[i].promote(0);
		}
		break;
	case 2:
		cin >> manager_promotion_pay;
		for (int i = 0; i < manager_amount; i++)
		{
			manager_list[i].promote(0);
		}
		break;
	case 3:
		cin >> salesman_rate;
		for (int i = 0; i < salesman_amount; i++)
		{
			salesman_list[i].promote(0);
		}
		break;
	case 4:
		cin >> salesman_promotion_rate;
		for (int i = 0; i < salesman_amount; i++)
		{
			salesman_list[i].promote(0);
		}
		break;
	case 5:
		cin >> technician_wage;
		for (int i = 0; i < technician_amount; i++)
		{
			technician_list[i].promote(0);
		}
		break;
	case 6:
		cin >> technician_promotion_wage;
		for (int i = 0; i < technician_amount; i++)
		{
			technician_list[i].promote(0);
		}
		break;
	case 7:
		cin >> salesmanager_pay;
		for (int i = 0; i < salesmanager_amount; i++)
		{
			salesmanager_list[i].promote(0);
		}
		break;
	case 8:
		cin >> salesmanager_prmotion_pay;
		for (int i = 0; i < salesmanager_amount; i++)
		{
			salesmanager_list[i].promote(0);
		}
		break;
	case 9:
		cin >> salesmanager_rate;
		for (int i = 0; i < salesmanager_amount; i++)
		{
			salesmanager_list[i].promote(0);
		}
		break;
	case 10:
		cin >> salesmanager_promotion_rate;
		for (int i = 0; i < salesmanager_amount; i++)
		{
			salesmanager_list[i].promote(0);
		}
		break;
	case 11:
		break;
	default:
		cout << "输入错误,请重新输入" << endl;
		break;
	}
}
void menu::boss_statistic() {
	cout << "请输入统计的职工：1.全体职工；2.销售经理；3.销售员；4.经理；5.技术员;6.返回" << endl;
	cin >> option;
	switch (option)
	{
	case 1:
		boss_statistic(salesmanager_list, &salesmanager_amount);
		sum_up_all += sum_up; max_all = max; min_all = min;
		boss_statistic(salesman_list, &salesman_amount);
		sum_up_all += sum_up;
		if (max_all<max)
		{
			max_all = max;
		}
		if (min_all>min)
		{
			min_all = min;
		}
		boss_statistic(manager_list, &manager_amount);
		sum_up_all += sum_up;
		if (max_all < max)
		{
			max_all = max;
		}
		if (min_all > min)
		{
			min_all = min;
		}
		boss_statistic(technician_list, &technician_amount);
		sum_up_all += sum_up;
		if (max_all < max)
		{
			max_all = max;
		}
		if (min_all > min)
		{
			min_all = min;
		}
		cout << "平均月薪为" << ((double)sum_up_all / (double)(salesmanager_amount+ salesman_amount+ manager_amount+ technician_amount)) << endl;//平均值
		cout << "最高月薪为" << max_all << endl;
		cout << "最低月薪为" << min_all << endl;
		break;
	case 2:
		boss_statistic(salesmanager_list, &salesmanager_amount);
		cout << "平均月薪为" << ((double)sum_up / (double)salesmanager_amount) << endl;//平均值
		cout << "最高月薪为" << max << endl;
		cout << "最低月薪为" << min << endl;
		break;
	case 3:
		boss_statistic(salesman_list, &salesman_amount);
		cout << "平均月薪为" << ((double)sum_up / (double)salesman_amount) << endl;//平均值
		cout << "最高月薪为" << max << endl;
		cout << "最低月薪为" << min << endl;
		break;
	case 4:
		boss_statistic(manager_list, &manager_amount);
		cout << "平均月薪为" << ((double)sum_up / (double)manager_amount) << endl;//平均值
		cout << "最高月薪为" << max << endl;
		cout << "最低月薪为" << min << endl;
		break;
	case 5:
		boss_statistic(technician_list, &technician_amount);
		cout << "平均月薪为" << ((double)sum_up / (double)technician_amount) << endl;//平均值
		cout << "最高月薪为" << max << endl;
		cout << "最低月薪为" << min << endl;
		break;
	case 6:
		break;
	default:
		cout << "输入错误,请重新输入" << endl;
		break;
	}
}
void menu::boss_promote() {
	cout << "请输入提拔的等级差" << endl;
	cin >> grade_up;
	cout << "请选择输入1.编号；2.姓名" << endl;
	cin >> option;
	operate_judge = false;
	switch (option)
	{
	case 1:
		cout << "请输入编号" << endl;
		cin >> scan_no;
		boss_promote_no(salesmanager_list, &salesmanager_amount);
		boss_promote_no(salesman_list, &salesman_amount);
		boss_promote_no(manager_list, &manager_amount);
		boss_promote_no(technician_list, &technician_amount);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	case 2:
		cout << "请输入姓名" << endl;
		cin >> scan_name;
		boss_promote_name(salesmanager_list, &salesmanager_amount);
		boss_promote_name(salesman_list, &salesman_amount);
		boss_promote_name(manager_list, &manager_amount);
		boss_promote_name(technician_list, &technician_amount);
		if (operate_judge == false)
		{
			cout << "用户不存在" << endl;
		}
		break;
	default:
		cout << "输入错误,请重新输入" << endl;
		break;
	}
}
void menu::boss_adjust_relation() {
	cout << "请输入需调整的销售员编号" << endl;
	cin >> scan_no;
	operate_judge = false;
	for (int i = 0; i < salesman_amount; i++)
	{
		if (salesman_list[i].get_individualEmpNo() == scan_no) {
			cout << "请输入新的上司编号" << endl;
			cin >> scan_no;
			for (int j = 0; j < salesmanager_amount; j++)
			{
				if (salesmanager_list[j].get_individualEmpNo() == scan_no) {
					salesman_list[i].set_boss(&salesmanager_list[j]);
					operate_judge = true;
					break;
				}
			};
			break;
		}
	};
	if (operate_judge == false)
	{
		cout << "调整关系失败" << endl;
	}
}