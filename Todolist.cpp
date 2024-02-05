#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct todolist
{
	int id;
	string task;
};

int ID;
void banner();
void addTask();
void showTask();
int searchTask();
void deleteTask();
void updateTask();

int main(){
	while(true){
		banner();
		cout<<"\n t1. Add task";
		cout<<"\n t2. Show task";
		cout<<"\n t3. Search task";
		cout<<"\n t4. Delete task";
		cout<<"\n t5. Update task";
		
		int choice;
		cout<<"\n\t Enter Choice: ";
		cin>>choice;
		switch(choice){
			case 1:
		    	addTask();
			    break;
			case 2:
			    showTask();
			    break;
			case 3:
			    searchTask();
			    break;
			case 4:
			    deleteTask();
			     break;
			case 5:
			//updateTask();
			break;
			default:
				break;
				
		}
		
	}
	    return 0;
}

void banner(){
	cout<<"...............................\n";
	cout<<"\t My Todo \n";
	cout<<"...............................\n";
}

void addTask(){
	system("cls");
	banner();
	todolist todo;
	cout<<"Enter new task: \n";
	cin.get();
	getline(cin, todo.task);
	char save;
	cout<<"Save? (Y/N):";
	cin>>save;
	if(save == 'y'){
		ID++;
		ofstream fout;
		fout.open("todo.txt", ios::app);
		fout<<"\n"<<ID;
		fout<<"\n"<<todo.task;
		fout.close();
		
		char more;
		cout<<"Add More Task? (Y/N): ";
		cin>>more;
		
		if(more == 'y'){
			addTask();
		}else{
			system("cls");
			cout<<"Add Successfully";
			return;
		}
	}
	 system("cls");
}

void showTask(){
	system("cls");
	banner();
	todolist todo;
	ifstream fin;
	fin.open("todo.txt");
	cout<<" task: \n";
	
	while(!fin.eof()){
		fin>>todo.id;
		fin.ignore();
		getline(fin, todo.task);
		if(todo.task != ""){
			cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
		}else{
			cout<<"\tEmpty!";
		}
	     fin.close();
		char exit;
		cout<< "Exit? (Y/N): ";
		cin>>exit;
		if(exit != 'y'){
			showTask();
		}
		 system("cls");
	}
}

int searchTask(){
	system("cls");
	banner();
	int id;
	cout<<" Enter task id: ";
	cin>>id;
	todolist todo;
	ifstream fin("todo.txt");
	while(!fin.eof()){
		fin>>todo.id;
		fin.ignore();
		getline(fin, todo.task);
		if(todo.id == id){
			system("cls");
			cout<<"\t"<<todo.id<<":"<<todo.task;
			return;
		}
	}
	system("cls");
	cout<<"Not Found";
	return 0;
}

void deleteTask(){
	system("cls");
	int id = searchTask();
	if(id != 0){
		char del;
		cout<<"\n\t Delete? (y/n): ";
		cin>>del;
		if(del == 'y'){
			tololist todo;
			ofstream tempFile;
			tempFile.open("temp.txt");
			ifstream fin;
			fin.open("todo.txt");
			int index = 1;
			while(!fin.eof()){
				fin >> todo.id;
				fin.ignore();
				getline(fin, todo.task);
				if(todo.id != id){
					tempfile<<"\n"<<index;
					tempfile<<"\n"<<todo.task;
					index++;
					ID--;
					
				}
			}
			  fin.close();
			  tempFile.close();
			  remove("todo.txt");
			  rename("temp.txt","todo.txt");
			  system("cls");
			  cout<<"\n\t Delete Successfully! \n";
		}else{
			system("cls");
			cout<<"Not Deleted \n";
		}
	}
	
}
