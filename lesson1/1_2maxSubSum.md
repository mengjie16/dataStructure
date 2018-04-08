# 01-复杂度2 Maximum Subsequence Sum
> Given a sequence of K integers { N1, N2 , ..., NK}. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj} where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

## Input Specification:
>Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

## Output Specification:

>For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

### Sample Input:

>10

>-10 1 2 3 4 -5 -23 3 7 -21

### Sample Output:

>10 1 4

#### 关键：在线处理
#####  T(n)=n
###### 注意输出的不是index 而是值（可以用地址来获取）

```
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
```
