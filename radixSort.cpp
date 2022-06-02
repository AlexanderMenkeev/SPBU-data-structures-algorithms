#include <fstream>
#include <iostream>
#include <ctime>

void print(int* ID, int M)
{
	for (int i = 0; i < M; i++)
		std::cout << ID[i] + 1 << " ";
	std::cout << std::endl;
}

struct tuple
{
    int value;
    int indx;
    tuple(int value, int indx)
    {
        this->value = value;
        this->indx = indx;
    }
    tuple() { value = 0; indx = 0; }
};

 void bubbleSort(tuple* arr, int n)
 {
     for (int i = 0; i < n; i++)
         for (int j = n - 1; j > i; j--)
             if (arr[j].value < arr[j - 1].value)
                 std::swap(arr[j], arr[j - 1]);
 }

// Function to merge the two haves
// arr[l..m] and arr[m+1..r] of array arr[]
 void merge(tuple* arr, int l, int m, int r);

 // l is for left index and r is
 // right index of the sub-array
 // of arr to be sorted
 void mergeSort(tuple* arr, int l, int r)
 {
     if (l < r)
     {
         // Same as (l+r)/2 but avoids
         // overflow for large l & h
         int m = l + (r - l) / 2;
         mergeSort(arr, l, m);
         mergeSort(arr, m + 1, r);
         merge(arr, l, m, r);
     }
 }

 // Function to merge the two haves arr[l..m]
 // and arr[m+1..r] of array arr[]
 void merge(tuple* arr, int l, int m, int r)
 {
     int k;
     int n1 = m - l + 1;
     int n2 = r - m;

     // Create temp arrays
     tuple* L = new tuple[n1];
     tuple* R = new tuple[n2];

     // Copy data to temp arrays L[] and R[]
     for (int i = 0; i < n1; i++)
         L[i] = arr[l + i];
     for (int j = 0; j < n2; j++)
         R[j] = arr[m + 1 + j];

     // Merge the temp arrays
     // back into arr[l..r]
     int i = 0;
     int j = 0;
     k = l;

     while (i < n1 && j < n2)
     {
         if (L[i].value <= R[j].value)
         {
             arr[k] = L[i];
             i++;
         }
         else
         {
             arr[k] = R[j];
             j++;
         }
         k++;
     }

     // Copy the remaining elements
     // of L[], if there are any
     while (i < n1)
     {
         arr[k] = L[i];
         i++;
         k++;
     }

     // Copy the remaining elements
     // of R[], if there are any
     while (j < n2)
     {
         arr[k] = R[j];
         j++;
         k++;
     }
     delete[] L;
     delete[] R;
 }



int main(int argc, char* argv[])
{
    std::ifstream inFile(argv[1], std::ios::binary);
	if (!inFile){ return -2; }
	std::ofstream outFile(argv[2]);
	if (!outFile){ return -3; }

	int N, M, K;
	inFile >> N >> M >> K;

	int b = inFile.tellg();
	b++;

	char* a = new char[N + 1];
	a[N] = '\0';

    tuple* arr = new tuple[N];
    for (int i = 0; i < N; i++)
        arr[i] = tuple(0, i);

	for (int j = 0; j < K; j++)
	{
		int pos = b + (M - j - 1) * (N + 1);
		inFile.seekg(pos);
		for (int i = 0; i < N; i++)
		{
			inFile.seekg(pos + arr[i].indx);
			inFile.get(a[i]);
		}
        for (int i = 0; i < N; i++)
            arr[i].value = int(a[i]);
        mergeSort(arr, 0, N - 1);
	}


    /*for (int i = 0; i < N; i++)
        std::cout << arr[i].indx << ":" << arr[i].value << " ";
    std::cout << std::endl;*/

     for (int i = 0; i < N; i++)
     {
     	outFile << arr[i].indx + 1;
     	if (i != N - 1)
     		outFile << " ";
     }
	 delete[] arr;
	std::cout << "Time: " << clock() << std::endl;
	inFile.close();
	outFile.close();
	return 0;
}
