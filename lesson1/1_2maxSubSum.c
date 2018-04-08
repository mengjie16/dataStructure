#include<stdio.h>
#include<stdlib.h>
void maxSumSubsequence(int a[], int N, int * max_sum,int *start,int *end) {
	int thisSum = 0; int sub_start = 0;
	int i;
	for (i = 0; i < N; i++) {
		thisSum += a[i];
		if (thisSum > *max_sum) {
			*max_sum = thisSum;
			*end = i;
			*start = sub_start;
		}
		else if (thisSum < 0) {
			thisSum = 0;
			sub_start = i + 1;
		}
	}
	if (*max_sum < 0) {
		*max_sum = 0;
		*start = 0;
		*end = N - 1;
	}
}
int main() {
	int N,max_sum,leftTag,rightTag;
	scanf("%d\n", &N);
	int *a = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	leftTag = rightTag = 0;max_sum = -1;
	maxSumSubsequence(a, N,&max_sum,&leftTag,&rightTag);
	printf("%d %d %d", max_sum, a[leftTag], a[rightTag]);
	free(a);
	return 0;
}
