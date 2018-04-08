#include <stdio.h>
#include<stdlib.h>
int max3(int a, int b, int c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
int divideAndConquer(int a[], int left, int right) {
	int maxLeftSum, maxRightSum;
	int maxLeftBorderSum, maxRightBorderSum;
	int leftBorderSum, rightBorderSum;
	int i;
	if (left == right) {
		if (a[left] > 0) {
			return a[left];
		}
		else {
			return 0;
		}
	}
	int middle = (left + right) / 2;
	maxLeftSum = divideAndConquer(a, left, middle);
	maxRightSum = divideAndConquer(a, middle + 1, right);

	maxLeftBorderSum = 0; leftBorderSum = 0;
	for (i = middle; i >= left; i--) {
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum) {
			maxLeftBorderSum = leftBorderSum;
		}
	}
	maxRightBorderSum = 0; rightBorderSum = 0;
	for (i = middle + 1; i <= right; i++) {
		rightBorderSum += a[i];
		if (rightBorderSum > maxRightBorderSum) {
			maxRightBorderSum = rightBorderSum;
		}
	}
	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}
int maxSumSubsquence(int a [],int N) {
	return divideAndConquer(a, 0, N - 1);
}
int main(){
	int N;
	int max_sum = 0;
	scanf("%d\n", &N);
	int *a= (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	max_sum =maxSumSubsquence(a, N);
	free(a);
	printf("%d\n", max_sum);
	return 0;
}
