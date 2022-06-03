#include <iostream>
#include <fstream>
void selectionSort()
{

}

void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
}

void cocktailSort(int* arr, int n)
{
	int left = 0; int right = n - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++)
			if (arr[i] > arr[i + 1])
				std::swap(arr[i], arr[i + 1]);
		right--;
		for (int i = right; i > left; i--)
			if (arr[i] < arr[i - 1])
				std::swap(arr[i], arr[i - 1]);
		left++;
	}
}

void combSort(int* arr, int n)
{
	double factor = 1.247;
	double gapFactor = n / factor;
	while (gapFactor > 1)
	{
		int gap = floor(gapFactor);
		int i, j;
		for (i = 0, j = gap; j < n; i++, j++)
			if (arr[j] < arr[i])
				std::swap(arr[i], arr[j]);
		gapFactor = gapFactor / factor;
	}
}

void selectionSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		if (min_idx != i)
			std::swap(arr[i], arr[min_idx]);
	}
}

void gnomeSort(int* arr, int n)
{
	int i = 1; int j = 2;
	while (i < n)
	{
		if (arr[i - 1] <= arr[i])
		{
			i = j; 
			++j;
		}
		else
		{
			std::swap(arr[i - 1], arr[i]);
			--i;
			if (i == 0)
			{
				i = j;
				++j;
			}
		}
	}
}

int binary_search(int x, int* arr, int i)
{
	return x;
}

void insertionSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int x = arr[i];
		int j = binary_search(x, arr, i);
		for (int k = j; k < i; k++)
			arr[k + 1] = arr[k];
		arr[j] = x;
	}
}

void quickSort(int* arr, int right, int left)
{
	int pivot_indx = left + (right - left) / 2;
	int pivot = arr[pivot_indx];
	int i = left, j = right;
	while (i < j)
	{
		while (arr[i] < pivot) i++;
		while (pivot < arr[j]) j--;
		if (i < j)
		{
			std::swap(arr[i], arr[j]);
			++i; --j;
		}
		else if (i == j)
		{
			++i; --j;
		}
	}
	quickSort()
}


void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	std::ifstream inFile("C:\\Users\\Александр\\github-classroom\\amcp-pit\\task1-minimum-queue-AlexanderMenkeev\\tests\\in\\input1.txt");
	if (!inFile) { return 2; }

	int x = 0;
	char operation;
	int n = 0;
	inFile >> n;
	int* arr = new int[n];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		inFile.ignore(255, '\n');
		inFile.get(operation);
		switch (operation)
		{
		case '+':
			inFile.ignore(255, ' ');
			inFile >> x;
			arr[j] = x;
			j++;
			break;
		}
	}
	n = j;
	insertionSort(arr, n);
	print(arr, n);
	gnomeSort(arr, n);
	print(arr, n);
	selectionSort(arr, n);
	print(arr, n);
	print(arr, n);
	cocktailSort(arr, n);
	print(arr, n);
	combSort(arr, n);
	print(arr, n);
	bubbleSort(arr, n);
	print(arr, n);
	

	std::cout << "Time: " << clock() << std::endl;
	inFile.close();
	return 0;
}