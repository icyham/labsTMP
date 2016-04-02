/*
@mainpage Приложение для проверки работы стека
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef struct my_list{
/**
@brief Структура "Список"
@detailed Имеет данные и указатель на следующий элемент в списке
*/
	int data;
	struct my_list* next;
} MList;

int add(MList* phead, int index, int data)
{
/**
@brief Функция добавления элемента по индексу
@detailed Данная функция добавляет элемент начиная с 0 - перед начальным элементом списка
@param phead первый элемент списка
@param index индекс нового элемента списка
@param data данные нового элемента списка
*/
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
/**
@brief Функция удаления элемента по индексу
@detailed Данная функция удаляет элемент расположенного по заданному индексу
@param item первый элемент списка
@param index индекс удаляемого элемента списка
*/
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
/**
@brief Функция получения данных элемента по индексу
@detailed Данная функция получает данные элемента списка
@param phead первый элемент списка 
@param index индекс необходимого элемента списка
@param pdata адрес, куда попадут данные, полученные в результате работы программы
*/
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
