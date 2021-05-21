#include <bits/stdc++.h>
using namespace std;

/* PROGRAM TO DO LIST 
Anggota Kelompok :
1. Ervan Chodry				2017051001
2. Aullya Hannan Wulandari	2017051079*/


struct node{
	char task[51];
	int id;
	node *link;
};

class Mylist{
	public:
		
		node *head;
		Mylist(){
			head = NULL;
		}

		bool ifEmpty(){
			return head == NULL;
		}

		void addLast(int n){
			node *temp = new node;
			temp->id = n;
			cin >> temp->task;
			temp->link = NULL;
			
			if(ifEmpty()){
				head = temp;
			}else{
				node *tail = head;
				while(tail->link != NULL){
					tail = tail->link;
				}
				tail->link = temp;
			}
			cout << "Tugas telah ditambahkan" << endl;
		}

		void print(){
			system("cls");
			node *tail = head;
			if(ifEmpty()){
				cout << "Belum ada tugas yang harus diselesaikan!" << endl;
			}else{
				cout << "Tugas yang harus segera anda selesaikan : " << endl;
				while(tail != NULL){
					cout << "id \t: " << tail->id + 1 << endl;
					cout << "Tugas \t: " << tail->task << endl << endl;
					tail = tail->link;
				}
			}
		}
};

void menu();


int main(){
	Mylist tugas;
	int pilih;
	int index = 0;

	while(true){
		pilih = 1;
		system("cls");
		menu();
		cin >> pilih;

		switch(pilih){
			case 1:
				tugas.print();
				system("pause");
				break;

			case 2:
				cout << "Masukkan tugas yang ingin ditambahkan : ";
				// word = input();
				tugas.addLast(index);
				index++;
				system("pause");
				break;

			case 4:
				exit(1);

			default:
				cout << "Input yang anda masukkan tidak valid" << endl;
				system("pause");
		}
	}

}


void menu(){
	cout<<"Pilih Menu : "<<endl;
	cout<<"\t1. Display task"<<endl;
	cout<<"\t2. Add Task"<<endl;
	cout<<"\t3. Finish Task"<<endl;
	cout<<"\t4. Exit"<<endl;
	cout<<"Masukkan pilihan : ";
}


