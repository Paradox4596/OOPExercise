#include <iostream>

template <typename T>

void Sort(T* x, int y)
{
	T temp{};

	for (int i = 0; i < y; i++)
	{
		for (int j = i+1; j < y; j++)
		{
			if (x[i] < x[j])
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
}

template <typename T>

void Print(T* x, int y)
{
	for (int i = 0; i < y; i++)
	{
		std::cout << x[i] << ", ";
	}
	std::cout << std::endl;
}


int main()
{
	int array1[]{ 1, 2, 3, 5, 4 };
	Sort(array1, 5);
	Print(array1, 5);

	float array2[]{ 1.1f, 2.5f, 3.0f, 5.1f, 4.4f };
	Sort(array2, 5);
	Print(array2, 5);
}