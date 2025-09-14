#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[], int start, int middle, int end)
// �迭���� ��� ���� ���� �ϱ� ������ vector�� ���
{
	// ��ģ ����� �ӽ÷� ������ �迭
	// �迭�� ũ��� ��ĥ ������ ũ��(end - start + 1)�� ���ƾ� ��

	vector<int>Arr(end - start + 1);

	int i = start;
	int j = middle+1;
	int k = 0;

	// i�� ���� �κ��� ���� ���� �ʰ�, j�� ������ �κ��� ���� ���� �ʴ� ���� �ݺ�
	while (i <= middle && j <= end)
	{
		if (arr[i] <= arr[j]) // ������ ����Ű�� ���� ���� ������ ���� ��
		{
			Arr[k] = arr[i]; // ���� ���� �� ������, Arr�� ����
			i++; // ������ ����Ű�� ���� ���� ĭ���� �̵�
		}
		else
		{
			Arr[k] = arr[j]; // ������ ���� �� ������, Arr�� ����
			j++; // ���������� �̵�

		}
		k++; // � ���� ���Ե�, Arr�� ���� ĭ�� ä���� �ϹǷ� k�� �׻� �̵�
	}

	// ���� �κп� ���Ұ� ���� �ִٸ�
	while (i <= middle)
	{
		Arr[k] = arr[i];
		// ���� ���Ҹ� ������� Arr�� ����
		i++;
		k++;
	}

	// ������ �κп� ���Ұ� ���� �ִٸ�
	while (j <= end)
	{
		Arr[k] = arr[j];
		j++;
		k++;
	}

	for (int idx = 0; idx < k; idx++) {
		arr[start + idx] = Arr[idx];
	}

}

void mergsort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int middle = start + ((end - start) / 2);
	mergsort(arr, start, middle);
	mergsort(arr, middle + 1, end);
	merge(arr, start, middle, end);
}


void printarr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	const int size = 8;
	int arr[size];

	cout << size << "���� ���ڸ� �Է��ϼ��� : ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << "���� �� �迭 : ";
	printarr(arr, size);

	mergsort(arr, 0, size - 1);
	cout << "���� �� �迭 : ";
	printarr(arr, size);

}