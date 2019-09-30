#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#define SIZE 10

void initArray(int* arr);
void shortingFunc(int* arr, void (*Func)(int* ), const char* name);


void SelectSort(int* arr);
void BubbleSort(int* arr);
void InsertSort(int* arr);
void RadixSort(int* arr);
void MergeSort(int* arr);
void QuickSort(int* arr);

void MergeSort_(int* arr, int* tarr, int size);
void QuickSort_(int* arr, int size);

int main() {
	int cm[SIZE] = { 170, 155, 168, 162, 158, 172, 178, 160, 153, 164 };

	shortingFunc(cm, SelectSort, "선택 정렬");
	shortingFunc(cm, BubbleSort, "버블 정렬");
	shortingFunc(cm, InsertSort, "삽입 정렬");
	shortingFunc(cm, RadixSort, "기수 정렬");
	shortingFunc(cm, MergeSort, "병합 정렬");
	shortingFunc(cm, QuickSort, "퀵 정렬");



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
	printf("정렬 전 : ");
	for (i = 0; i < SIZE; i++) {
		printf("%5d", arr[i]);
	}printf("\n");

	Func(arr);

	printf("정렬 후 : ");
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

void RadixSort(int* arr){
	Queue queue[10];
	int i,j, k, data;
	int dec = 10;

	for (i = 0; i < 10; i++)
		Queueinit(queue + i);


	for (i = 0; i < 3; i++) {
		for (j = 0; j < SIZE; j++) {
			enque(queue + (arr[j] % dec *10 / dec), arr[j]);
		}
		
		k = 0;
		for (j = 0; j < 10; j++) {
			for (; deque(queue + j, &data); k++) {
				arr[k] = data;
			}

		}

		dec *= 10;
	}
	

}

void MergeSort(int* arr) {
	int tarr[SIZE];//두 그룹을 합칠때 사용할 임시 배열
	MergeSort_(arr, tarr, SIZE);
}
void MergeSort_(int* arr, int* tarr, int size) {//재귀적으로 병합 정렬을 실행할 함수
	int secondS;//두번째 그룹의 시작점
	int i, j;
	int cur;

	if (size <= 1)
		return;

	secondS = (size / 2);

	MergeSort_(arr, tarr, size / 2);
	MergeSort_(arr + size / 2, tarr, size - secondS);

	i = 0; j = secondS;
	cur = 0;


	while (i < secondS && j < size) {
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


void QuickSort(int* arr) {
	QuickSort_(arr, SIZE);
}
void QuickSort_(int* arr, int size) {
	int i;
	int temp;
	int pivot = 0;
	int comp = size-1;
	int compVec = -1; //-1 : 뒤에서 앞으로   1 : 앞에서 뒤로

	if (size < 2)
		return;

	while (pivot != comp) {
		if (arr[pivot] > arr[comp] && pivot < comp || arr[pivot] < arr[comp] && pivot > comp) {
			temp = arr[pivot];
			arr[pivot] = arr[comp];
			arr[comp] = temp;

			temp = pivot;
			pivot = comp;
			comp = temp;

			compVec *= -1;
		}
		comp += compVec;

	}


	QuickSort_(arr, pivot);
	QuickSort_(arr + pivot + 1, size - comp - 1);
}