/*【实验目的】
利用面向对象思想完成简单的信息系统：学生管理；
【实验内容】
1、设计学生类，专业类。注意二者之间关系。
2、以成员函数实现专业资料的输入、显示, 学生的增加、删除等。
3、以成员函数实现学生资料的录入、显示、修改。
4、实现资料写入文件和从文件读出。
5、命令行设计总目录，实现通过输入数字启动相应功能。*/

#include<iostream>
#include<fstream>
#include<string>
#define maxsize 100
using  namespace std;
class Student {
public:
	string name;
	string subject;
};
class Subject {
public:
	string subject_name;
	string student_names[maxsize];
};

class Subject_Stuent {
public:
	Student students[maxsize];
	Subject subjects[maxsize];
	int subject_number = 0;
	int subject_number1 = 0;
	int student_number = 0;
	int student_number1 = 0;
public:
	void subject_input()
	{
		cout << "输入专业: ";
		cin >> subjects[subject_number1].subject_name;
		subject_number1++;
	}
	void subject_disp()
	{
		for (int i = 0; i <= subject_number1; i++)
		{
			cout << endl << subjects[i].subject_name << endl;
		}
	}
	void subject_student_add()
	{
		string temp_subject_name;
		int temp_add_name_number;
		cout << "输入增加学生的专业:" << endl;
		cin >> temp_subject_name;
		for (int i = 0; i < subject_number1; i++)
		{
			if (subjects[i].subject_name == temp_subject_name)
			{
				cout << "输入增加学生的姓名：";
				cin >> subjects[i].student_names[student_number1];
				cout << "已增加" << subjects[i].student_names[student_number1++] << "到" << subjects[i].subject_name << "专业中";
			}

		}
	}
	void subject_student_delete()
	{
		string temp_subject_name;
		string temp_delete_student_name;
		cout << "输入删除学生的专业:" << endl;
		cin >> temp_subject_name;
		for (int i = 0; i < subject_number1; i++)
		{
			if (subjects[i].subject_name == temp_subject_name)
			{
				cout << "输入删除学生的姓名：" << endl;
				cin >> temp_delete_student_name;
				for (int j = 0; j < student_number1; j++)
				{
					if (subjects[i].student_names[j] == temp_delete_student_name)
					{
						subjects[i].student_names[j] = {}; cout << endl << "找到并成功删除" << endl;
					}

				}
			}
		}
	}
	void admitted_student()
	{
		cout << endl << "输入录取学生的姓名：";
		cin >> students[student_number].name;
		cout << endl << "输入录取学生的专业:";
		cin >> students[student_number++].subject;
	}
	void  disp_student()
	{
		for (int i = 0; i < student_number; i++)
		{
			cout << endl << "录取学生" << i + 1 << "号的姓名:";
			cout << students[i].name << endl;
			cout << "录取学生" << i + 1 << "号的专业:";
			cout << students[i].subject << endl;

		}
	}
	void change_student()
	{
		string temp_name;
		cout << endl << "输入修改学生的姓名:";
		cin >> temp_name;
		for (int i = 0; i < student_number; i++)
		{
			if (students[i].name == temp_name)
			{
				cout << endl << "找到" << students[i].name << ",输入要修改后的专业:";
				cin >> students[i].subject;
				cout << endl << "成功修改" << students[i].name << "的专业为" << students[i].subject << endl;
			}
		}
	}
	void write_in_student()
	{

		fstream file;
		file.open("D:\\1.txt", ios_base::out);
		for (int i = 0; i < student_number; i++)
		{
			file << "姓名：";
			file << students[i].name;
			file << " " << "专业:";
			file << students[i].subject;
			file << endl;

		}
		file.close();
		cout << "写入成功" << endl;

	}
	void read_out_student()
	{
		string temp_string[100];
		fstream file;
		file.open("D:\\1.txt", ios_base::in);
		for (int i = 1; i < 100; i++)
		{
			file >> temp_string[i];
			cout << temp_string[i];
		}

		file.close();
		cout << endl << "读取成功" << endl;

	}

};
class UseFunction {
public:
	int num;
	Subject_Stuent S;
public:
	void cout_message()
	{
		cout << "0.退出" << endl;
		cout << "1.专业资料的输入" << endl;
		cout << "2.专业资料的显示" << endl;
		cout << "3.学生资料的增加" << endl;
		cout << "4.学生资料的删除" << endl;
		cout << "5.学生资料的录入" << endl;
		cout << "6.学生资料的显示" << endl;
		cout << "7.学生资料的修改" << endl;
		cout << "8.资料写入文件" << endl;
		cout << "9.资料读出文件" << endl;
	}
	void judge_use_continue_function()
	{

		int num;
		cout << endl << "请输入一个数字，确定功能:";
		cin >> num;
		if (num == 0) { exit(0); }
		if (num == 1) { S.subject_input(); }
		if (num == 2) { S.subject_disp(); }
		if (num == 3) { S.subject_student_add(); }
		if (num == 4) { S.subject_student_delete(); }
		if (num == 5) { S.admitted_student(); }
		if (num == 6) { S.disp_student(); }
		if (num == 7) { S.change_student(); }
		if (num == 8) { S.write_in_student(); }
		if (num == 9) { S.read_out_student(); }
		judge_use_continue_function();


	}
};
int main()
{
	UseFunction U;
	U.cout_message();
	U.judge_use_continue_function();
}

