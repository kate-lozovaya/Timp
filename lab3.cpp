#include "lab3.h"

int main()
{
	List list;
	Stack stack;
	Queue queue;
	int a = 0;
	int position = 0, value = 0, number = 0;

	cout << "LIST\n\n";
	cout << "Enter number of command ";
	cin >> number;
	for (int i = 0; i < number; ++i)
		{
		cout << "\nChoose command:\n1 - add\n2 - del\n3 - get\n4 - print\n\n";
		cin >> a;
		switch (a)
		{
			case 1:
			{
					  cout << "Enter position and value ";
					  cin >> position >> value;
					  list.add(position, value);
					  break;
			}
			case 2:
			{
					  cout << "Enter position ";
					  cin >> position;
					  list.del(position);
					  break;
			}
			case 3:
			{
					  cout << "Enter position ";
					  cin >> position;
					  list.print(list.get(position));
					  break;
			}
			case 4: 
			{
					  list.print();
					  break;
			}
			default: break;
		}
	}

	cout << "STACK\n\n";
	cout << "Enter number of command ";
	cin >> number;
	for (int i = 0; i < number; ++i)
	{
		cout << "\nChoose command:\n1 - add\n2 - del\n3 - get\n4 - print\n\n";
		cin >> a;
		switch (a)
		{
			case 1:
			{
					  cout << "Enter value ";
					  cin >> value;
					  stack.add(value);
					  break;
			}
			case 2:
			{
					  stack.del();
					  break;
			}
			case 3:
			{
					  stack.print(stack.get());
					  break;
			}
			case 4:
			{
					  stack.print();
					  break;
			}
			default: break;
		}
	}


	cout << "QUEUE\n\n";
	cout << "Enter number of command ";
	cin >> number;
	for (int i = 0; i < number; ++i)
	{
		cout << "\nChoose command:\n1 - add\n2 - del\n3 - get\n4 - print\n\n";
		cin >> a;
		switch (a)
		{
			case 1:
			{
					  cout << "Enter value ";
					  cin >> value;
					  queue.add(value);
					  break;
			}
			case 2:
			{
					  queue.del();
					  break;
			}
			case 3:
			{
					  queue.print(queue.get());
					  break;
			}
			case 4:
			{
					 queue.print();
					  break;
			}
			default: break;
		}
	}
	system("pause");
	return 0;
}