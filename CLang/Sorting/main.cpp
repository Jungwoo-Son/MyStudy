#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void initArray(int *arr);
void shortingFunc(int* arr, void (*Func)(int* arr), const char *name);


void SelectSort(int* arr);
void BubbleSort(int* arr);
void InsertSort(int* arr);


void MergeSort(int* arr);
void MergeSort_(int* arr, int* tarr, int size);



int main() {
	int cm[SIZE] = { 170, 155, 168, 162, 158, 172, 178, 160, 153, 164 };

	shortingFunc(cm, SelectSort, "���� ����");
	shortingFunc(cm, BubbleSort, "���� ����");
	shortingFunc(cm, InsertSort, "���� ����");

	shortingFunc(cm, MergeSort, "���� ����");



	return 0;
}

void initArray(int* arr) {
	arr[0] = 170;
	arr[1] = 155;
	arr[2] = 168;
	arr[3] = 162;
	arr[4] = 158;
	arr[5] = 172;
	arr[6] = 178;
	arr[7] = 160;
	arr[8] = 153;
	arr[9] = 164;
}

void shortingFunc(int* arr, void (*Func)(int*), const char* name) {
	int i;

	initArray(arr);

	printf("-------%s-------\n", name);
	printf("���� �� : ");
	for (i = 0; i < SIZE; i++) {
		printf("%5d", arr[i]);
	}printf("\n");

	Func(arr);

	printf("���� �� : ");
	for (i = 0; i < SIZE; i++) {
		printf("%5d", arr[i]);
	}printf("\n");
}



void SelectSort(int* arr) {
	int i, j;
	int temp;

	for (i = 0; i < SIZE; i++) {
		for (j = i; j < SIZE; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}
void BubbleSort(int* arr) {
	int i, j;
	int checker = 0;
	int temp;

	for (i = 0; i < SIZE - 1; i++) {
		checker = 0;
		for (j = 0; j < SIZE - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				checker = 1;
			}

		}
		if (checker == 0)
			break;
	}

}

void InsertSort(int* arr) {
	int i, j;
	int temp;

	for (i = 0; i < SIZE; i++) {
		for (j = i; j > 0; j--) {
			if (arr[j - 1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
			else 
				break;
		}

	}

}

void MergeSort(int* arr) {
	int tarr[SIZE];//�� �׷��� ��ĥ�� ����� �ӽ� �迭
	MergeSort_(arr, tarr ,SIZE);
}
void MergeSort_(int* arr, int *tarr, int size) {//��������� ���� ������ ������ �Լ�
	int secondS;//�ι�° �׷��� ������
	int i, j;
	int cur;
	
	if (size <= 1) 
		return;

	secondS = (size / 2);

	MergeSort_(arr, tarr, size / 2);
	MergeSort_(arr + size / 2, tarr, size-secondS);

	i = 0; j = secondS;
	cur = 0;


	while(i < secondS && j < size) {
		if (arr[i] > arr[j]) {
			tarr[cur] = arr[j];
			j++;
		}
		else {
			tarr[cur] = arr[i];
			i++;
		}
		cur++;
	}

	if (cur < size) {
		i = i < secondS ? i : j;
		for (; cur < size; cur++) {
			tarr[cur] = arr[i];
			i++;
		}

	}


	for (cur = 0; cur < size; cur++)
		arr[cur] = tarr[cur];



}
