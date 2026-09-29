#include "function.h"
#include<iostream>
#include<string>
using namespace std;

tasks add[1000];
void welcome(){
	cout << "===============" << endl;
	cout << "	TODO APP    " << endl;
	cout << "===============" << endl;
	cout << "1. Add task" << endl;
	cout << "2. View tasks" << endl;
	cout << "3. Mark/Unmark tasks" << endl;
	cout << "4. Delete Task" << endl;
	cout << "5. Exit" << endl;
	cout << "Input:" << endl;
}

int takeinputfromuser(){
	int x;
	cin >> x;
	return x;
}

void cinfail(){
	cout << "Invalid Input!" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}

void goback(){
	cout << "Input anything to go back:" << endl;
	string anything;
	cin >> anything;
}

void addtask(int&size, int&numberoftask){
	cout << "How many tasks do you want to add:" << endl;
	cin >> size;
	if(size<=0 || size>10000 || size+numberoftask>10000){
		cout << "Invalid Input!" << endl;
		goback();
	}
	else{
		cin.ignore(1000, '\n');
    	for(int i=numberoftask;i<size+numberoftask;i++){
			add[i].taskcompleted = "Incomplete";
			cout << "Enter Title:" << endl;
			getline(cin, add[i].title);
			cout << "Enter description:" << endl;
			getline(cin, add[i].description);
		}
		numberoftask += size;
		cout << "Tasks successfully added" << endl;
	}
}

void viewtask(int numberoftask, int numberoftaskscompleted){
	for(int i=0;i<numberoftask;i++){
		cout << "Task " << i+1 << endl;
		cout << add[i].taskcompleted << endl;
		cout << "Title:" << endl;
		cout << add[i].title << endl;
		cout << "description:" << endl;
		cout << add[i].description << endl;
		cout << endl;
	}
	cout << "Number of Tasks: " << numberoftask << endl;
	cout << "Number of Tasks completed: " << numberoftaskscompleted << endl;
}

void deletetask(int& numberoftask, int& numberoftaskscompleted){
	cout << "Which task do you wanna delete:" << endl;
	int remove {};
	cin >> remove;
	remove--;
	if(remove>=0 && remove<numberoftask){
		for(int i=remove;i<numberoftask-1;i++){
			add[i] = add[i+1];
		}
		numberoftask--;
		cout << "Successfully deleted!" << endl;
		if(add[remove].taskcompleted == "Completed"){
			numberoftaskscompleted--;
		}
	}
	else{
		cout << "Invalid task" << endl;
	}
}
