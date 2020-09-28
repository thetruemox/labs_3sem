#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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
	void del(int it, int jt);
	void add(int key, int i, int j);
	int search(int it, int jt);
	void mx_out(int n, int m);
};

template <typename T>
T read(T* var);

int hash(int size, int i, int j);
int find_max(Matrix* mx);
int* busort(Matrix* mx, int it, int m);
void modif_out(Matrix* mx, int it, int* arr, int n, int m);

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
			cin >> temp;
			if (temp != 0)
			{
				mx.add(temp, i, j);
			}

		}
	}

	cout << endl << "Original matrix";
	mx.mx_out(n, m);

	cout << endl <<  "Modified matrix" << endl;
	modif_out(&mx, find_max(&mx),busort(&mx, find_max(&mx), m), n, m);

	return 0;
}

template<typename T> //
T read(T *var) //элементы матрицы могут быть отрицательными
{
	T temp;
	cin >> temp;
	
	while (!cin.good() || temp < 0)
	{
		cout << endl << "Invalid input, try again" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> temp;
	}

	*var = temp;
	return temp;
}

int hash(int size, int i, int j)
{
	return (i+j) % size;
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

int* busort(Matrix* mx, int it, int m)
{
	int* arr = new int[m];
	
	Element* cur_ptr;

	for (int j = 0; j < m; j++)
	{
		arr[j] = mx->search(it, j);
	}

	
	int first = arr[0];
	int temp;
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (first > 0)
			{
				if (arr[j] > arr[j+1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
			else
			{
				if (arr[j] < arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	return arr;
}

void modif_out(Matrix* mx, int it, int* arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		if (i == it)
		{
			for (int j = 0; j < m; j++)
			{
				cout << arr[j] << " ";
			}
		}
		else
		{
			for (int j = 0; j < m; j++)
			{
				cout << mx->search(i, j) << " ";
			}
		}	

		cout << endl;
	}
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

void Matrix::del(int it, int jt)
{
	Element* cur_ptr = arr[hash(size, it, jt)];
	Element* prev_ptr = cur_ptr;
	
	if (cur_ptr == NULL)
	{
		cout << "No such element!" << endl;
		return;
	}

	if (cur_ptr->i == it && cur_ptr->j == jt)
	{
		arr[hash(size, it, jt)] = cur_ptr->next;
		delete(cur_ptr);
		return;
	}

	while (cur_ptr->next != NULL)
	{
		prev_ptr = cur_ptr;
		cur_ptr = cur_ptr->next;

		if (cur_ptr->i == it && cur_ptr->j == jt)
		{
			prev_ptr->next = cur_ptr->next;
			delete(cur_ptr);
			return;
		}
	}

	if (cur_ptr->i == it && cur_ptr->j == jt)
	{
		prev_ptr->next = cur_ptr->next;
		delete(cur_ptr);
		return;
	}

}

void Matrix::add(int key, int i, int j)
{
	Element* cur_ptr = arr[hash(size, i, j)];

	if (cur_ptr == NULL)
	{
		arr[hash(size, i, j)] = new Element;
		cur_ptr = arr[hash(size, i, j)];
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
	Element* cur_ptr = arr[hash(size, it, jt)];

	if (cur_ptr == NULL) return 0;
	
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

	return 0;
}

void Matrix::mx_out(int n, int m)
{
	int temp;

	cout << endl;

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

