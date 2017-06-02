#include <iostream>
using namespace std;

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

class List
{
private:
	int * list;
	int size;
public:
	List()
	{
		list = nullptr;
		size = 0;
	}
	~List()
	{
		delete[] list;
		size = 0;
	}
	void add(const int & position, const int & value)
	{
		if (position >= size)
		{
			int * ptr = new int[position + 1]();
			for (int i = 0; i < size; ++i)
				ptr[i] = list[i];
			delete[] list;
			list = ptr;
			size = position + 1;
		}
		list[position] = value;
	}
	void del(const int & position)
	{
		if (position < size && list[position])
		{
			int * ptr = new int[size - 1]();
			for (int i = 0; i < position; ++i)
				ptr[i] = list[i];
			for (int i = position; i < size - 1; ++i)
				ptr[i] = list[i + 1];
			delete[] list;
			list = ptr;
			size--;
		}
	}
	const int & get(const int & position)
	{
		return list[position];
	}
	void print(const int & value)
	{
		if (value)
			cout << value << endl;
		else cout << "This position is empty\n";
	}
	void print()
	{
		for (int i = 0; i < size; ++i)
			cout << list[i] << " ";
		cout << endl;
	}
};

class Stack
{
private:
	link * top_of_stack;
public:
	Stack()
	{
		top_of_stack = nullptr;
	}
	~Stack()
	{
		delete[] top_of_stack;
	}
	void add(const int & value)
	{
		link * new_link = new link(value);
		new_link->next = top_of_stack;
		top_of_stack = new_link;
	}
	void del()
	{
		if (top_of_stack)
		{
			link * f = top_of_stack->next;
			delete[] top_of_stack;
			top_of_stack = f;
		}
	}
	link * get()
	{
		return top_of_stack;
	}
	void print(link * link)
	{
		if (link->value)
			cout << link->value << endl;
		else cout << "The stack is empty\n";
	}
	void print()
	{
		link * link = top_of_stack;
		while (link)
		{
			cout << link->value << " ";
			link = link->next;
		}
		cout << endl;
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
			back = new_link;
			front->next = back;
		}
		else
		{
			back->next = new_link;
			back = new_link;
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
