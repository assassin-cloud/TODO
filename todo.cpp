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

int main(){
	tasks add[10000];
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
					goback();
				}
			}
			else if(userinput == 2){
				for(int i=0;i<numberoftask;i++){
					cout << "Task " << i+1 << endl;
					cout << "Title:" << endl;
					cout << add[i].title << endl;
					cout << "description:" << endl;
					cout << add[i].description << endl;
					cout << endl;
				}
				cout << "Number of tasks:" << numberoftask << endl;
				goback();
			}
			else if(userinput == 3){
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
