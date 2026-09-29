#include "function.h"
#include<iostream>
#include<string>
using namespace std;

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
				viewtask(numberoftask, numberoftaskscompleted);
				goback();
			}
			else if(userinput == 3){
				cout << "Which task to mark/unmark:" << endl;
				int marktaskinput {takeinputfromuser()};
				marktaskinput--;
				if(marktaskinput > numberoftask || marktaskinput < 0 || numberoftask == 0){
					cout << "Invalid input" << endl;
					continue;
				}
				else{
					if(add[marktaskinput].taskcompleted != "Completed"){
						add[marktaskinput].taskcompleted = "Completed";
						numberoftaskscompleted++;
						cout << "Successfully marked as completed" << endl;
						goback();
					}
					else{
						add[marktaskinput].taskcompleted = "Incomplete";
						numberoftaskscompleted--;
						cout << "Successfully marked as Incompleted" << endl;
						goback();
					}
				}
			}
			else if(userinput == 4){
				deletetask(numberoftask, numberoftaskscompleted);
				goback();
			}
			else if(userinput == 5){
				break;
			}
			else{
				cout << "Invalid input" << endl;
			}
		}
	}
}
