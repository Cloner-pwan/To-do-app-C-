#include <iostream>
#include <fstream>
using namespace std;
void readTask (){
	
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

int main () {
	readTask();
	writeTask();
	main();
}