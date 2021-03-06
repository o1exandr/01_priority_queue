/*
Завдання 1(завершити завдання з класної роботи).
Створити клас PriorityQueue(Черга з пріоритетами), де кожен елемент черги має тип Element
struct Element
{
string data;
int priority;
Element(const string & data = "Unknown", int pri = 0);
void print() const;
};
class PriorityQueue
{
static const int MAX_SIZE = 10;
Element queue[MAX_SIZE];
.....................
};
Вважати, що елемент з більшим значенням поля  priority має більший пріоритет.
Визначити методи для роботи з чергою
•	Конструктор(черга спочатку пуста)
•	Вивід елементів черги
•	Додавання елемента до черги void add(const Element & element). Вилучення елемента з черги(вилучається елемент з найвищим пріоритетом). Можливі прототипи методу
void extract();
bool extract(Element & element);
Element extract();
•	 Повернути елемент на початку черги(з найвищим пріоритетом)
Element front() const;

Перевірити роботу черги з пріоритетами.


 */


#include "stdafx.h"
#include <iostream> 
#include <string>

	using namespace std;

struct Element
{
	string name;
	int pri;
};

class PriQueue
{
	
	enum size { MAXSIZE = 10, EMPTY = -1 };
private:
	Element queue[MAXSIZE];
	int size;

public:

	PriQueue()
	{
		size = -1;
	}

	~PriQueue()
	{
	}

	bool isEmpty()const
	{
		if (size == EMPTY)
			return 1;
		else
			return 0;
	}

	bool isFull()const
	{
		if (size == MAXSIZE - 1)
			return 1;
		else
			return 0;
	}

	void add(string elem, int p)
	{
		if (isEmpty())
		{
			++size;
			queue[size].name = elem;
			queue[size].pri = p;
		}
		else
			if (isFull())
				cerr << "Queue iz Full!\n";
			else
			{
				for (int i = 0; i <= size; i++)
					if (p > queue[i].pri)
					{
						++size;
						for (int j = size; j > i; j--)
						{
							queue[j].name = queue[j - 1].name;
							queue[j].pri = queue[j - 1].pri;
						}
						queue[i].name = elem;
						queue[i].pri = p;
						break;
					}
				if (queue[size].pri >= p)
				{
					++size;
					queue[size].name = elem;
					queue[size].pri = p;
				}
			}


	}

	Element extract()
	{
		Element MIN;
		MIN.name = "-";
		MIN.pri = 0;

		if (isEmpty())
		{
			cerr << "Empty!\n";
			return MIN;
		}
		else
		{
			Element first = front();
			for (int i = 0; i < size; i++)
				queue[i] = queue[i + 1];
			--size;
			return 	first;
		}
	}

	Element front()
	{
		if (isEmpty())
		{
			Element MIN;
			MIN.name = "-";
			MIN.pri = 0;
			cerr << "Empty!\n";
			return MIN;
		}
		else
			return queue[0];
	}

	Element back()
	{
		if (isEmpty())
		{
			Element MIN;
			MIN.name = "-";
			MIN.pri = 0;
			cerr << "Empty!\n";
			return MIN;
		}
		else
			return queue[size];
	}

	void print()const
	{
		if (isEmpty())
			cout << "Empty\n";
		else
		{
			cout << endl;
			for (int i = 0; i <= size; i++)
				cout << queue[i].name << " (" << queue[i].pri << ")   ";
			cout << endl;
		}
	}


};

int main()
{

	PriQueue qu;
	cout << "Is empty? " << qu.isEmpty() << endl;
	qu.add("sugar", 1);
	qu.add("milk", 3);
	qu.add("water", 4);
	qu.add("coffee", 2);
	qu.add("tea", 4);
	qu.add("cup", 1);

	qu.print();

	cout << "Extract: " << qu.extract().name;
	qu.print();
	cout << "Front: " << qu.front().name << endl;
	cout << "Back: " << qu.back().name << endl;
	cout << "Is empty? " << qu.isEmpty() << endl;
	cout << "Is full? " << qu.isFull() << endl;




	cout << endl;
	system("pause");
	return 0;
}