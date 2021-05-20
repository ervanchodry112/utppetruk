#include <iostream>
#include <cstring>
using namespace std;

/* PROGRAM TO DO LIST 
Anggota Kelompok :
1. Ervan Chodry				2017051001
2. Aullya Hannan Wulandari	2017051079	*/

struct node{
	char task[101];
	node *address;
};

void print(node *point);	
void menu();
char *input();

int main(){
	node *job = NULL;
	int pilih = 1;
	
	do{
		// switch(pilih){
		// 	case 1:
		// 		cout << menu() << endl;
		// 		cout << "Masukkan pilihan : ";
		// 		cin >> pilih;
		// 		break;

		// }
	}while(pilih != 4);

}



void print(node *point){
	if (point == NULL)
	{
		cout << "Belum Ada Tugas yang harus diselesaikan!";
	}
}
void menu(){
	cout<<"Pilih Menu : "<<endl;
	cout<<"\t1. Add Task"<<endl;
	cout<<"\t2. Finish Task"<<endl;
	cout<<"\t3. Exit"<<endl;
}
char *input(){
	char *task = new char [101];

	cout<<"Masukkan pilihan anda : ";
	cin>>task;
	
	static char bantu[101];
	for(int i = 0; i < strlen(task); i++){
		bantu[i] = toupper(task[i]);
	}
	
	return bantu;
}
