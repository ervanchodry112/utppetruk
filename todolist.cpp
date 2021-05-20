#include <bits/stdc++.h>
using namespace std;

/* PROGRAM TO DO LIST 
Anggota Kelompok :
1. Ervan Chodry				2017051001
2. Aullya Hannan Wulandari	2017051079*/

struct node{
	// char *task;
	char *task;
	node *address;
};

void print(node *point);
void menu();
char *input();
node *addnewtask(node *start, char *newTask);


int main(){
	node *job = NULL;
	char *word;
	int pilih = 1;

	while(true){
		system("cls");
		cin >> pilih;

		switch(pilih){
			case 1:
				print(job);
				system("pause");
				break;

			case 2:
				cout << "Masukkan tugas yang ingin ditambahkan : ";
				// word = input
				cin >> word;
				job = addnewtask(job, word);
				break;

			case 4:
				exit(1);

			default:
				cout << "Input yang anda masukkan tidak valid" << endl;
				system("pause");
		}
	}

}



void print(node *point){
	node *p;
	if (point == NULL)
	{
		cout << "Belum Ada Tugas yang harus diselesaikan!";
	}

	p = point;

	while(p != NULL){
		cout << p->task << endl;
		p = p->address;
	}

}

node *addnewtask(node *start, char *newTask){
	node *temp = new node;
	strcpy(temp->task, newTask);
	temp->address = start;
	start = temp;
	return start;
}

// void tambahBelakang(node *baru){
// 	nodeLingkaran *tail;
// 	baru->next = NULL;
// 	tail = head;
// 	while(tail->next != NULL){
// 		tail = tail->next;
// 	}
// 	tail->next = baru:
// }