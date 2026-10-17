#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void readTask () {
	
	cout << "Tasks: " << endl;
	
	ifstream file("tasks.txt");
	
	if(!file.is_open()){
		cout << "Could not open the file !";
		return;
	}
	
	int counter = 1;
	string line;
	
	while(getline(file, line)){
		cout << counter << " - " << line << endl;
		counter++;
	}
	
	file.close();
}

void writeTask(){
	string task;
	cout << "New Task: ";
	getline(cin, task);
	
	ofstream writeFile("tasks.txt", ios::app);
	
	if(!writeFile.is_open()){
		cout << "Could not open the file !";
		return;
	}
	
	writeFile << task << endl;
	writeFile.close();
	
	system("cls");
}

void deleteTask() {

	vector<string> tasks;
	
	int id;
	
	cout << "Enter the id: ";
	cin >> id;
	
	string line;
	ifstream file("tasks.txt");
	
	while(getline(file,line)){
		tasks.push_back(line);
	}
	
	tasks.erase(tasks.begin() + (id - 1));
	file.close();
	
	ofstream file_2("tasks.txt", ios::trunc);
	 
	for(int i = 0; i <= tasks.size() - 1; i++){
		file_2 << tasks[i] << endl;	
	}
	file_2.close();
	cout << "task " << id << " " << "deleted successfully !";
	
}

int UI(){
	int option;
	cout << "======= TO DO APP =======" << endl;
	cout << "1 - Show Tasks" << endl;
	cout << "2 - Add Task" << endl;
	cout << "3 - Delete Task" << endl;
	cout << "4 - EXIT" << endl;
	cout << "Choose an option: ";
	cin >> option;
	cin.ignore();
	return option;
}



int main () {
	
	while(true) {
		int option = UI();
		
		switch (option) {
			case 1:
				readTask();
				break;
			case 2:
				writeTask();
				break;
			case 3: 
				deleteTask();
				break;
			case 4: 
				return 0;
		}
	}
//	while(true){
//		readTask();
//		writeTask();
//	}
}
