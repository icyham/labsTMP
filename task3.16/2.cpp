//Для стека:
//1. Функция добавления элемента
//2. Функция удаления элемента
//3. Получение значения верхнего элемента
//Для стека задаются N - количество действий со стеком, действия в формате:
//add <data>
//del
//get(вывод значения)
//
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef struct my_list{
	int data;
	struct my_list* next;
} MList;

int add(MList* phead, int index, int data)
{
	MList *item = new MList;
	MList *tmp = NULL;
	int i;

	item->data = data;
	item->next = NULL;

	tmp = phead;
	i = 0;
	while (tmp->next != NULL && i<index) {
		i++;
		tmp = tmp->next;
	}
	item->next = tmp->next;
	tmp->next = item;
	return 0;
}


int del(MList* item, int index)
{
	MList *tmp = NULL;
	int i;
	if (index == 0)
	{
		tmp = item->next;
		item->data = item->next->data;
		item->next = item->next->next;
		delete tmp;
	}
	else
	{
		tmp = item;
		i = 0;
		while (tmp->next != NULL && i < index - 1) {
			i++;
			tmp = tmp->next;
		}
		tmp->next = tmp->next->next;
		delete tmp->next;
	}
	return 0;
}

int get(MList* phead, int index, int* pdata)
{
	MList *tmp = phead;
	int i = 0;
	while (tmp->next != NULL && i <= index) {
		tmp = tmp->next;
		i++;
	}
	*pdata = tmp->data;
	cout << tmp->data << endl;
	return 0;
}

int main()
{
	MList head;
	head.next = NULL;
	string command;
	int data, ncommand;
	cin >> ncommand;
	for (int i = 0; i<ncommand; i++) {
		cin >> command;
		if (!command.compare(0, 3, "add")) {
			int dat;
			cin >> dat;
			add(&head, 0, dat);
		}
		else if (!command.compare(0, 3, "del")) {
			del(&head, 0);
		}
		if (!command.compare(0, 3, "get")) {
			int *dat = new int;
			get(&head, 0, dat);
			delete dat;
		}
	}
	system("pause");
	return 0;
}
