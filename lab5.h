#include <iostream>
using namespace std;

/*
	Реализация очереди с приоритетами

	Задача: 
	Реализовать очередь с приоритетами с операциями:
	add <значение> - добавление элемента с указанным значением
	get - получение минимального значения
	del - удаление минимального элемента

	Входные данные:
	N - количество команд
	<команды работы с очередью с приоритетами (add, get, del)>
	...
	...
	...

	Выходные данные:
	результат выполнения команд

	Пример:
	Входные данные:
	5
	add 3
	add 4
	add 1
	del
	get

	Выходные данные:
	3
*/

struct link
{
	link * next;
	int value;
	link(const int & val)
	{
		value = val;
		next = nullptr;
	}
};

class Queue
{
private:
	link * front;
	link * back;
public:
	Queue()
	{
		front = nullptr;
		back = nullptr;
	}
	~Queue()
	{
		delete[] front;
		delete[] back;
	}
	void add(const int & value)
	{
		link * new_link = new link(value);
		if (front == nullptr)
		{
			front = new_link;
			front->next = back;
		}
		else if (front->next == nullptr)
		{
			if (front->value < new_link->value)
			{
				back = new_link;
				front->next = back;
			}
			else
			{
				back = front;
				front = new_link;
				front->next = back;
			}
		}
		else
		{
			link * cur = front;
			if (cur->value < new_link->value)
			{
				while ((cur != back) && (cur->next->value < new_link->value))
					cur = cur->next;
				if (cur == back)
				{
					cur->next = new_link;
					back = new_link;
				}
				else
				{
					link * f = cur->next;
					cur->next = new_link;
					cur->next->next = f;
				}
			}
			else 
			{
				front->next = cur;
				front = new_link;
			}
		}
	}
	void del()
	{
		if (front)
		{
			link * f = front->next;
			delete[] front;
			front = f;
		}
	}
	link * get()
	{
		return front;
	}
	void print(link * link)
	{
		if (link->value)
			cout << link->value << endl;
		else cout << "The queue is link->value";
	}
	void print()
	{
		link * link = front;
		while (link)
		{
			cout << link->value << " ";
			link = link->next;
		}
		cout << endl;
	}
};