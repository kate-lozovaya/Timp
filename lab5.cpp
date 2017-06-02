#include "lab5.h"

int main()
{
	Queue queue;
	int number, a, value;
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