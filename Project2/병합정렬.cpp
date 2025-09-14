#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[], int start, int middle, int end)
// 배열에는 상수 값이 들어가야 하기 때문에 vector를 사용
{
	// 합친 결과를 임시로 저장할 배열
	// 배열의 크기는 합칠 범위의 크기(end - start + 1)와 같아야 함

	vector<int>Arr(end - start + 1);

	int i = start;
	int j = middle+1;
	int k = 0;

	// i가 왼쪽 부분의 끝을 넘지 않고, j도 오른쪽 부분의 끝을 넘지 않는 동안 반복
	while (i <= middle && j <= end)
	{
		if (arr[i] <= arr[j]) // 왼쪽을 가리키는 곳의 값과 오른쪽 값을 비교
		{
			Arr[k] = arr[i]; // 왼쪽 값이 더 작으면, Arr에 복사
			i++; // 왼쪽을 가리키는 곳을 다음 칸으로 이동
		}
		else
		{
			Arr[k] = arr[j]; // 오른쪽 값이 더 작으면, Arr에 복사
			j++; // 오른쪽으로 이동

		}
		k++; // 어떤 값이 들어왔든, Arr의 다음 칸을 채워야 하므로 k는 항상 이동
	}

	// 왼쪽 부분에 원소가 남아 있다면
	while (i <= middle)
	{
		Arr[k] = arr[i];
		// 남은 원소를 순서대로 Arr에 복사
		i++;
		k++;
	}

	// 오른쪽 부분에 원소가 남아 있다면
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

	cout << size << "개의 숫자를 입력하세요 : ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << "정렬 전 배열 : ";
	printarr(arr, size);

	mergsort(arr, 0, size - 1);
	cout << "정렬 후 배열 : ";
	printarr(arr, size);

}