#include <bits/stdc++.h>
using namespace std;

/* PROGRAM TO DO LIST 
Anggota Kelompok :
1. Ervan Chodry				2017051001
2. Aullya Hannan Wulandari	2017051079
*/


struct node{
	char task[51];
	int id;
	node *link;
};

class Mylist{
	public:
		
		node *head;	//inisialisasi link lis pertama
		Mylist(){
			head = NULL;
		}

		bool ifEmpty(){		//Mengecek NULL berisi NULL atau bukan
			return head == NULL;	
		}

		void addLast(int n){		//berisi parameter int n untuk id
			node *temp = new node;	//mengalokasikan tipe data node
			temp->id = n;
			cin >> temp->task;	//memasukkan  variabel temp di poin task
			temp->link = NULL;	//link list akhir berisi NULL
			
			if(ifEmpty()){	
				head = temp;	//nilai head diisi dengan nilai temp
			}else{
				node *tail = head;	//node *tail berisi head 
				while(tail->link != NULL){
					tail = tail->link;
				}
				tail->link = temp;
			}
			cout << "Tugas telah ditambahkan" << endl;
		}

		void delTask(){
			system("cls");
			static int del;
			print();
			node *temp;
			node *cek = head;
			cout << "Masukkan ID task yang telah selesai : ";
			cin >> del;	
			if(cek->id == del){
				node *temp = head;
				head = head->link;
				delete temp;
			}else{
				while(cek->link->id != del){
						cek = cek->link;
				}
				if(cek->link->id == del){
					temp = cek->link;
					cek->link = temp->link;
					delete temp;
					cout << "Tugas berhasil dihapus!" << endl;
				}else{
					cout << "Id tidak dimtemukkan!" << endl;
				}
			}
		}

		void print(){
			system("cls");
			node *tail = head;
			if(ifEmpty()){
				cout << "Belum ada tugas yang harus diselesaikan!" << endl;
			}else{
				cout << "Tugas yang harus segera anda selesaikan : " << endl;
				while(tail != NULL){
					cout << "id \t: " << tail->id << endl;
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
		cin >> pilih;	//memilih menu task

		switch(pilih){
			case 1:
				tugas.print();		//memanggil fungsi void print
				system("pause");
				break;

			case 2:
				cout << "Masukkan tugas yang ingin ditambahkan : ";
				// word = input();
				index++;
				tugas.addLast(index);	//Memanggil fungsi void addLast

				system("pause");
				break;

			case 3:
				tugas.delTask();	//Memanggil fungsi delTask
				system("pause");
				break;

			case 4:
				exit(1);	//keluar program

			default:
				cout << "Input yang anda masukkan tidak valid" << endl;	//output yang ditampilkan ketika user menginputkan selain case
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


