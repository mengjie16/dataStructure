# 两个有序链表序列的合并
### 本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

#### 函数接口定义：

>List Merge( List L1, List L2 );

##### 其中List结构定义如下：

```
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
```

> L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。


####  裁判测试程序样例：

```
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
```

#### /* 你的代码将被嵌在这里 */
>输入样例：

```
3
1 3 5
5
2 4 6 8 10
```

>输出样例：

```
1 2 3 4 5 6 8 10
NULL
NULL
```

时间限制: 400ms
内存限制: 64MB

> 想到链表的插入，而不是拷贝哦 所以也不需要删除 free啦 因为原来的节点都在的！ 注意是带有头结点，所以第一个节点是头结点的Next哦


###  正确答案

```
List Merge(List L1, List L2) {
	List P1, P2, L, P;
	L = (List)malloc(sizeof(struct Node));
	P = L;
	P1 = L1->Next;
	P2 = L2->Next;
	L->Next = NULL;
	while (P1 && P2) {
		if (P1->Data <= P2->Data) {
			P->Next = P1;
			P = P->Next;
			P1= P1->Next;
		}
		else {
	    P->Next = P2;
			P = P->Next;
			P2= P2->Next;
		}

	}
  P->Next = NULL;

	if (P1) {
	  P ->Next =  P1;
	}

	if (P2) {
		P ->Next =  P2;
	}
	L1->Next = NULL;
  L2->Next = NULL;
	return L;

}
```


###### 一开始的错误答案

```
List Merge(List L1, List L2) {
	List P1, P2, L, P;
	L = (List)malloc(sizeof(struct Node));
	P = L;
	L->Next = NULL;
	while (L1 && L2) {
		if (L1->Data <= L2->Data) {
			P1 = L1;
			P->Data = L1->Data;
			L1 = L1->Next;
			free(P1);
		}
		else {
			P2 = L2;
			P->Data = L2->Data;
			L2 = L2->Next;
			free(P2);
		}
		P = P->Next;
	}

	while (L1) {
		P->Data = L1->Data;
		P = P->Next;
		P1 = L1;
		L1 = L1->Next;
		free(P1);
	}

	while (L2) {
		P->Data = L2->Data;
		P = P->Next;
		P2 = L2;
		L2 = L2->Next;
		free(P2);
	}
	return L;

}
```
