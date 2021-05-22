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
		
		node *head;											//inisialisasi linkedlist pertama
		Mylist(){
			head = NULL;
		}

		bool ifEmpty(){										//Mengecek head berisi NULL atau bukan
			return head == NULL;	
		}

		void addLast(int n){								//berisi parameter int n untuk id
			node *temp = new node;							//mengalokasikan memori untuk tipe data node
			temp->id = n;									//mengisi id dengan nilai dari parameter n
			char word[51];
			cin >> word;
			
			for(int i = 0; i < 50; i++){
				temp->task[i] = toupper(word[i]);			//Proses merubah menjadi huruf besar
			}
			temp->link = NULL;								//link list akhir berisi NULL
			
			if(ifEmpty()){	
				head = temp;								//nilai head diisi dengan nilai temp
			}
			else{
				node *tail = head;							//node *tail berisi head 
			
				while(tail->link != NULL){
					tail = tail->link;						//Tail berpindah dari satu list ke list yang lain hingga list terakhir
				}
			
				tail->link = temp;
			}
			cout << "Tugas telah ditambahkan" << endl;
		}

		void delTask(){											//fungsi untuk menghapus list sesuai id-nya
			system("cls");
			static int del;
			print();
			node *temp;
			node *cek = head;
			
			cout << "Masukkan ID task yang telah selesai : ";
			cin >> del;											//Memasukkan ID dari list yang ingin dihapus
			
			if(cek->id == del){									//Jika id dari list pertama sama dengan yang ingin dihapus
				node *temp = head;		
				head = head->link;
				delete temp;									//List dihapus
			}
			else{
			
				while(cek->link->id != del){					//id satu list berikutnya dari list saat ini tidak sama dengan del
						cek = cek->link;						//cek akan bergeser ke list berikutnya
				}
			
				if(cek->link->id == del){						//jika id list berikutnya dari list saat ini sama dengan del
					temp = cek->link;
					cek->link = temp->link;
					delete temp;								//list dihapus
					cout << "Tugas berhasil dihapus!" << endl;
				}
				else{											//jika id tidak sama maka list tidak ditemukan
					cout << "Id tidak dimtemukkan!" << endl;
				}
			}
		}

		void print(){
			//FUNGSI UNTUK MENAMPILKAN LINKED LIST
			system("cls");
			node *tail = head;

			if(ifEmpty()){										//Jika Linkedlist Kosong
				cout << "Belum ada tugas yang harus diselesaikan!" << endl;
			}
			else{												//Jika linked list telah ada isinya
				cout << "Tugas yang harus segera anda selesaikan : " << endl;
			
				while(tail != NULL){
					cout << "id \t: " << tail->id << endl;					//Menampilkan ID dari list
					cout << "Tugas \t: " << tail->task << endl << endl;		//Menampilkan isi task dari list
					tail = tail->link;										//tail berpindah ke list berikutnya
				}
			}
		}
};

//PROSEDUR UNTUK MENAMPILKAN PILIHAN MENU
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
	//PROSEDUR UNTUK MENAMPILKAN PILIHAN MENU
	cout<<"Pilih Menu : "<<endl;
	cout<<"\t1. Display task"<<endl;
	cout<<"\t2. Add Task"<<endl;
	cout<<"\t3. Finish Task"<<endl;
	cout<<"\t4. Exit"<<endl;
	cout<<"Masukkan pilihan : ";
}


