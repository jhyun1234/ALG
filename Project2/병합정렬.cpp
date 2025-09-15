#include<iostream>
#include<vector>
using namespace std;
// 트리의 노드를 표현하는 구조체
struct TreeNode {
	int data;            // 노드가 저장할 값
	TreeNode* left;      // 왼쪽 자식 노드를 가리키는 포인터
	TreeNode* right;     // 오른쪽 자식 노드를 가리키는 포인터

	// 생성자: 새 노드를 쉽게 만들기 위함
	TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 정렬된 배열의 특정 범위(start ~ end)를 받아
// 완전 이진 탐색 트리를 만들고 루트 노드를 반환하는 함수
TreeNode* sortedArrayToBST(int arr[], int start, int end) {
	// 재귀 호출의 종료 조건: 더 이상 만들 노드가 없음
	if (start > end) {
		return nullptr;
	}

	// 1. 배열의 가운데 인덱스를 찾는다.
	int middle = start + (end - start) / 2;

	// 2. 가운데 원소로 새로운 노드(루트)를 만든다.
	TreeNode* root = new TreeNode(arr[middle]);

	// 3. 왼쪽 배열 부분으로 왼쪽 서브트리를 재귀적으로 만든다.
	root->left = sortedArrayToBST(arr, start, middle - 1);

	// 4. 오른쪽 배열 부분으로 오른쪽 서브트리를 재귀적으로 만든다.
	root->right = sortedArrayToBST(arr, middle + 1, end);

	// 완성된 트리의 루트를 반환
	return root;
}

// 트리를 중위 순회하며 노드 값을 출력하는 함수
void inOrderTraversal(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	inOrderTraversal(root->left);    // 왼쪽 서브트리 방문
	cout << root->data << " ";  // 현재 노드 방문 (출력)
	inOrderTraversal(root->right);   // 오른쪽 서브트리 방문
}

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


	// 2. 정렬된 배열을 이용해 완전 이진 탐색 트리를 생성
	cout << "생성된 이진 탐색 트리 (중위 순회): ";
	TreeNode* root = sortedArrayToBST(arr, 0, size - 1);

	// 3. 생성된 트리를 출력하여 확인 (정렬된 순서로 출력되어야 함)
	inOrderTraversal(root);
	cout <<endl;

}