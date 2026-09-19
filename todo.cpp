#include<iostream>
#include<string>
using namespace std;

void welcome(){
	cout << "===============" << endl;
	cout << "	TODO APP    " << endl;
	cout << "===============" << endl;
	cout << "1. Add task" << endl;
	cout << "2. View tasks" << endl;
	cout << "3. Delete Task" << endl;
	cout << "4. Exit" << endl;
	cout << "Input:" << endl;
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

struct tasks{
	string title;
	string description;
};
tasks add[10000];

void addtask(int&size, int&numberoftask){
	cout << "How many tasks do you want to add:" << endl;
	cin >> size;
	if(size<=0 || size>10000 || size+numberoftask>10000){
		cout << "Invalid Input!" << endl;
		goback();
	}
	else{
		cin.ignore();
    	for(int i=numberoftask;i<size+numberoftask;i++){
			cout << "Task " << i+1 << endl;
			cout << "Enter Title:" << endl;
			getline(cin, add[i].title);
			cout << "Enter description:" << endl;
			getline(cin, add[i].description);
		}
		numberoftask += size;
	}
}

void viewtask(int numberoftask){
	for(int i=0;i<numberoftask;i++){
		cout << "Task " << i+1 << endl;
		cout << "Title:" << endl;
		cout << add[i].title << endl;
		cout << "description:" << endl;
		cout << add[i].description << endl;
		cout << endl;
	}
	cout << "Number of tasks:" << numberoftask << endl;
}

void deletetask(int numberoftask){
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
		goback();
	}
	else{
		cout << "Invalid task" << endl;
	}
}
int main(){
	int numberoftask {};
	int size {};
	while(true){
		welcome();
		int userinput {};
		cin >> userinput;
		if(cin.fail()){
			cinfail();
		}
		else{
			if(userinput == 1){
				addtask(size,numberoftask);
				goback();
			}
			else if(userinput == 2){
				viewtask(numberoftask);
				goback();
			}
			else if(userinput == 3){
				deletetask(numberoftask);
				goback();
			}
			else if(userinput == 4){
				break;
			}
			else{
				cout << "Invalid input" << endl;
				goback();
			}
		}
	}
}
