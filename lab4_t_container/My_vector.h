#pragma once

template<class T>
class My_vector
{
public:
	My_vector();
	My_vector(int size);
	~My_vector();

	void push_back(T& obj);
	void pop_back();
	void erase(int index);
	int size();

	T& operator[](int index);
private:
	T* arr;
	int arr_size;
};

template<class T>
inline My_vector<T>::My_vector()
{
	this->arr = nullptr;
	this->arr_size = 0;
}

template<class T>
inline My_vector<T>::My_vector(int size)
{
	if (size < 0) throw "Negative vector size";

	this->arr = new T[size];
	this->arr_size = size;
}

template<class T>
inline My_vector<T>::~My_vector()
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr_size = 0;
	}
}

template<class T>
inline int My_vector<T>::size()
{
	return this->arr_size;
}

template<class T>
inline void My_vector<T>::push_back(T& obj)
{
	T* t_arr = new T[this->arr_size + 1];
	for (int i = 0; i < this->arr_size; i++)
	{
		t_arr[i] = this->arr[i];
	}
	t_arr[this->arr_size] = obj;

	delete[] this->arr;
	this->arr = t_arr;
	this->arr_size = this->arr_size + 1;
}

template<class T>
inline void My_vector<T>::pop_back()
{
	T* t_arr = new T[this->arr_size - 1];
	for (int i = 0; i < this->arr_size - 1; i++)
	{
		t_arr[i] = this->arr[i];
	}

	this->arr_size--;
	delete[] this->arr;

	if (this->arr_size == 0)
	{
		this->arr = nullptr;
	}
	else this->arr = t_arr;
}

template<class T>
inline void My_vector<T>::erase(int index)
{
	if (index < 0 || index >= this->arr_size) throw "Out-of-bounds index";
	T* t_arr = new T[this->arr_size - 1];

	for (int i = 0; i < index; i++)
	{
		t_arr[i] = this->arr[i];
	}
	for (int i = index + 1; i < this->arr_size; i++)
	{
		t_arr[i - 1] = this->arr[i];
	}

	this->arr_size--;
	delete[] this->arr;

	if (this->arr_size == 0)
	{
		this->arr = nullptr;
	}
	else this->arr = t_arr;
}

template<class T>
inline T& My_vector<T>::operator[](int index)
{
	if (index < 0 || index >= this->arr_size) throw "Out-of-bounds index";
	return this->arr[index];
}
