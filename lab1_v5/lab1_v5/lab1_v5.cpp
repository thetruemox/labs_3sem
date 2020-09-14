#include <iostream>
using namespace std;

void busort(float *arr, int size);


int main()
{
	int col;
	cout << "Enter array of array size: ";
	cin >> col;
	cout << endl;

	float** mx = new float*[col];
	int* arr_size = new int[col];

	for (int i = 0; i < col; i++)
	{
		cout << "Enter size of " << i <<" array: ";
		cin >> arr_size[i];

		mx[i] = new float[arr_size[i]];

		cout << endl << "Enter " << arr_size[i] << " numbers" << endl;
		for (int j = 0; j < arr_size[i]; j++)
		{
			cin >> mx[i][j];
		}

	}


	int m_sum = 0, t_sum = 0, m_i;

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < arr_size[i]; j++)
		{
			t_sum += mx[i][j];
		}

		if (t_sum > m_sum)
		{
			m_sum = t_sum;
			m_i = i;
		}

		t_sum = 0;

	}

	cout << "Original Array:" << endl;

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < arr_size[i]; j++)
		{
			cout << mx[i][j] << " ";
		}
		cout << endl;
	}
	 
	busort(mx[m_i], arr_size[m_i]);


	cout << "Edited Array:" << endl;

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < arr_size[i]; j++)
		{
			cout << mx[i][j] << " ";
		}
		cout << endl;
	}

	//cout << endl << "m_sum: " << m_sum << " m_i: "<< m_i << endl;

}

void busort(float* arr, int size)
{
	if (arr[0] > 0)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j] > arr[j+1])
				{
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	else 
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j] <= arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	
}