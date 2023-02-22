#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace  std;
//метод добавления элемента в конец массива
//счётчик количесва долбавленных элементов
//количество зарезервированных ячеек
//метод для изъятия элемента
//метод для проверки пуст ли стек
//метод для проверки есть ли ещё место для добавления новых элементов
template<typename sample>
class Palata
{
	enum { length = 10 };
	sample mas[length];
	int iter = -1;//счетчик добавленных элементов
	bool isEmpty()//если массив пуст
	{
		return iter == -1;
	}
	bool isFull()//если массив полон
	{
		return iter == length - 1;
	}
public:
	int getIter()//возвращение счетчика
	{
		return iter + 1;
	}
	void insElem(sample var)//добавление элемента в конец массива
	{
		if (!isFull())
			mas[++iter] = var;
	}
	sample retInd()//изъятие последнего элемента из массива
	{
		if (!isEmpty())
			return mas[iter--];
		//throw new exception("пусто");
		else return -1;
	}
	void Show()
	{
		for (int i = 0; i < getIter(); i++)
		{
			cout << mas[i] << "\t";
		}
	}
};


//>добавляем в хвост
//>изымаем нулевой элемент, после чего вся очередь смещается к началу
//5 7 8 9 6
//добавление элемента в очередь
//>проверка не пуста ли
//>проверка есть ли место для добавления нового элемента
//>вернуть размер
//>вернуть текущее количество элементов
//>просмотр очереди

//очередь с приоритетом
struct Data
{
	int data = 0;
	int priority = 0;
};
template<typename MyType>
class Queue
{	
	enum { length = 10 };
	Data mas[length];
	int index = -1;
	bool isEmpty()//если массив пуст
	{
		return index == -1;
	}
	bool isFull()//если массив полон
	{
		return index == length - 1;
	}
public:
	int getIndex()const // вернуть текущее кол-во элементов
	{
		return index + 1;
	}
	int getLength()const // вернуть размер
	{
		return length;
	}
	void insElement() // добавляем в хвост
	{
		Data someStruct;
		if (!isFull())
		{
			setStruct(someStruct);
			if (isEmpty())
			{
				mas[++index] = someStruct;
			}
			else
			{
				mas[++index] = someStruct;
				bool key;
				int kol = 0;
				do
				{
					key = false;
					for (size_t i = 0; i < index - kol; i++)
					{
						if (mas[i].priority < mas[i + 1].priority)
						{
							swap(mas[i], mas[i + 1]);
							key = true;
						}
					}
					kol++;
				} while (key);
			}
		}
	}
	void setStruct(Data &someStruct)
	{
		someStruct.data = rand() % 50;
		someStruct.priority = rand() % 5;
	}
	Data getElement() // изымаем нулевой элемент и сдвигаем очередь
	{
		Data temp;
		if (!isEmpty())
		{
			temp = mas[0];
			for (size_t i = 0; i < index; i++)
			{
				mas[i] = mas[i + 1];
			}
			index--;
			return temp;
		}
		return temp;
	}
	void show()const
	{
		for (size_t i = 0; i < index + 1; i++)
		{
			cout << "Элемент: " << mas[i].data << "\t" << "Приоритет: " << mas[i].priority << "\n";
		}
		cout << "\n";
	}
};
void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	//стек - кто первый прибыл, тот последний выбыл
	//Palata<int> obj;//создание массива
	//for (size_t i = 0; i < 5; i++)
	//{
	//	obj.insElem(10 + rand() % 45);//заполнение рандомом
	//}

	//obj.Show();
	//cout << "\nизъяли " << obj.retInd() << "\n";
	//cout << "изъяли " << obj.retInd() << "\n";
	//obj.Show();//отображение без пары элементов
	////посмотреть стандартный стек
	cout << "\n\n";
	Queue <int> obj2;
	for (size_t i = 0; i < 6; i++)
	{
		obj2.insElement();
	}
	obj2.show();
	Data var = obj2.getElement();
	obj2.show();
	obj2.insElement();
	obj2.show();
}
