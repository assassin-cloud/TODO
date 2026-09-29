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

struct tasks{
	string taskcompleted;
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
		cin.ignore(1000, '\n');
    	for(int i=numberoftask;i<size+numberoftask;i++){
			add[i].taskcompleted = "Incomplete";
			cout << "Enter Title:" << endl;
			getline(cin, add[i].title);
			cout << "Enter description:" << endl;
			getline(cin, add[i].description);
		}
		numberoftask += size;
	}
}

void taskmenu(int numberoftask, int numberoftaskscompleted){
	cout << "============" << endl;
	cout << "	TASKS    " << endl;
	cout << "============" << endl;
	cout << endl;
	cout << "Number of Tasks: " << numberoftask << endl;
	cout << "Number of Tasks completed: " << numberoftaskscompleted << endl;
	cout << endl;
	cout << "1. Show Tasks" << endl;
	cout << "2. Mark/Unmark task as completed" << endl;
	cout << "3. Go back" << endl;
	cout << "INPUT:" << endl;
}

void viewtask(int numberoftask){
	for(int i=0;i<numberoftask;i++){
		cout << "Task " << i+1 << endl;
		cout << add[i].taskcompleted << endl;
		cout << "Title:" << endl;
		cout << add[i].title << endl;
		cout << "description:" << endl;
		cout << add[i].description << endl;
		cout << endl;
	}
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

int main(){
	int numberoftask {};
	int size {};
	int numberoftaskscompleted {};
	while(true){
		welcome();
		int userinput {takeinputfromuser()};
		if(cin.fail()){
			cinfail();
		}
		else{
			if(userinput == 1){
				addtask(size,numberoftask);
				goback();
			}
			else if(userinput == 2){
				while(true){
					taskmenu(numberoftask, numberoftaskscompleted);
					int input {takeinputfromuser()};
					if(cin.fail()){
						cinfail();
					}
					else{
						if(input == 1){
							viewtask(numberoftask);
							goback();
						}
						else if(input == 2){
							cout << "Which task to mark/unmark:" << endl;
							int marktaskinput {takeinputfromuser()};
							marktaskinput--;
							if(marktaskinput > numberoftask || marktaskinput < 0){
								cout << "Invalid input" << endl;
								continue;
							}
							else{
								if(add[marktaskinput].taskcompleted != "Completed"){
									add[marktaskinput].taskcompleted = "Completed";
									numberoftaskscompleted++;
								}
								else{
									add[marktaskinput].taskcompleted = "Incomplete";
									numberoftaskscompleted--;
								}
							}
						}
						else if(input == 3){
							break;
						}
						else{
							cout << "Invalid Input!" << endl;
						}
					}
				}
			}
			else if(userinput == 3){
				deletetask(numberoftask, numberoftaskscompleted);
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
