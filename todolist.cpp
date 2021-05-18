#include <bits/stdc++.h>
using namespace std;

/* PROGRAM TO DO LIST 
Anggota Kelompok :
1. Ervan Chodry				2017051001
2. Aullya Hannan Wulandari	2017051079*/

struct node{
	char *task;
	node *address;
};

void print(node *point);
void menu();
char *input();
node *addnewtask(node *start, char *newTask);


int main(){
	node *job = NULL;
	int pilih = 1;
	char *word;

	while(true){
		system("cls");
		switch(pilih){
			case 1:
				cin >> pilih;
				break;

			case 2:
				cout << "Masukkan tugas yang ingin ditambahkan : ";
				// word = input
				cin.getline(word, 100);
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
	temp->task = newTask;
	temp->address = start;
	start = temp;
	return start;
}