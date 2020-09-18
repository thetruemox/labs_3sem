#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Дописать функцию busort, можно еще написать функцию которая будет возвращать указатель на Element по запросу с ключом и по этому указателю менять j объекта на соотв в остортированном массиве в busort

class Element
{
public:
	int i;
	int j;
	int key;
	Element* next;

	Element()
	{
		next = NULL;
	}
};

class Matrix
{
public:
	int size;
	Element** arr;

	Matrix(int size);
	void add(int key, int i, int j);
	int search(int it, int jt);
	void mx_out(int n, int m);
};

template <typename T>
T read(T* var);

int hash(int size, int key);
int find_max(Matrix* mx);
int busort(Matrix* mx, int it, int m);

int main()
{
	int n, m, temp;
	
	cout << "n: ";
	read(&n);
	cout << endl << "m: ";
	read(&m);
	cout << endl;

	Matrix mx(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (read(&temp) != 0)
			{
				mx.add(temp, i, j);
			}

		}
	}

	mx.mx_out(n, m);
	cout << endl;
	cout << find_max(&mx);


	return 0;
}

template<typename T>
T read(T *var)
{
	T temp;
	cin >> temp;
	
	while (!cin.good())
	{
		cout << endl << "Invalid input, try again" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> temp;
	}

	*var = temp;
	return temp;
}

int hash(int size, int key)
{
	return key % size;
}

int find_max(Matrix* mx)
{
	int max = 0, i_max;

	int* arr = new int[mx->size];
	for (int i = 0; i < mx->size; i++)
	{
		arr[i] = 0;
	}

	Element* cur_ptr;

	for (int i = 0; i < mx->size; i++)
	{
		cur_ptr = mx->arr[i];

		if (cur_ptr != NULL)
		{
			while (cur_ptr->next != NULL)
			{
				arr[cur_ptr->i] += cur_ptr->key;
				cur_ptr = cur_ptr->next;
			}
			arr[cur_ptr->i] += cur_ptr->key;
		}
	}

	for (int i = 0; i < mx->size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			i_max = i;
		}
	}

	delete(arr);
	return i_max;
}

int busort(Matrix* mx, int it, int m)
{
	int* arr = new int[m];
	int t_i = 0;
	for (int i = 0; i < m; i++)
	{
		arr[i] = 0;
	}

	Element* cur_ptr;

	for (int i = 0; i < mx->size; i++)
	{
		cur_ptr = mx->arr[i];

		if (cur_ptr != NULL)
		{
			while (cur_ptr->next != NULL)
			{
				if (cur_ptr->i == it)
				{
					arr[t_i] = cur_ptr->key;
				}
				cur_ptr = cur_ptr->next;
			}
			if (cur_ptr->i == it)
			{
				arr[t_i] = cur_ptr->key;
			}
		}
	}




	delete(arr);
	return 0;
}

Matrix::Matrix(int size)
{
	this->size = size;
	arr = new Element * [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = NULL;
	}
}

void Matrix::add(int key, int i, int j)
{
	Element* cur_ptr = arr[hash(size, key)];

	if (cur_ptr == NULL)
	{
		arr[hash(size, key)] = new Element;
		cur_ptr = arr[hash(size, key)];
	}
	else if (cur_ptr != NULL)
	{		
		while (cur_ptr->next != NULL)
		{
			cur_ptr = cur_ptr->next;
		}
		cur_ptr->next = new Element;
		cur_ptr = cur_ptr->next;		
	}

	cur_ptr->i = i;
	cur_ptr->j = j;
	cur_ptr->key = key;
	cur_ptr->next = NULL;
}

int Matrix::search(int it, int jt)
{
	Element* cur_ptr;

	for (int i = 0; i < this->size; i++)
	{
		cur_ptr = this->arr[i];

		if (cur_ptr != NULL)
		{
			while (cur_ptr->next != NULL)
			{
				if (cur_ptr->i == it && cur_ptr->j == jt)
				{
					return cur_ptr->key;
				}
				cur_ptr = cur_ptr->next;
			}
			if (cur_ptr->i == it && cur_ptr->j == jt)
			{
				return cur_ptr->key;
			}
		}
	}
	return 0;
}

void Matrix::mx_out(int n, int m)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp = search(i, j);
			if (temp != 0)
			{
				cout << temp << " ";
			} 
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}

