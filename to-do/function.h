#pragma once
#include<string>

void welcome();
int takeinputfromuser();
void cinfail();
void goback();
struct tasks{
	std::string taskcompleted;
	std::string title;
	std::string description;
};
extern tasks add[];
void addtask(int&size, int&numberoftask);
void viewtask(int numberoftask, int numberoftaskscompleted);
void deletetask(int& numberoftask, int& numberoftaskscompleted);
