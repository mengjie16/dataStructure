#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode *Polynomial;
struct PolyNode
{
	int coef;
	int expon;
	Polynomial link;
};
Polynomial ReadPoly();
void PrintPoly(Polynomial P);
Polynomial Mult(Polynomial P1, Polynomial P2);
Polynomial Add(Polynomial P1, Polynomial P2);
void Attach(int c, int e, Polynomial *pRear);

int main() {
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1, P2);
	PrintPoly(PP);
	PS = Add(P1, P2);
	if(PS==NULL && P1==NULL){
	  PrintPoly(P2);
	}else if(PS==NULL && P2==NULL){
	  PrintPoly(P1);
	}else{
	  PrintPoly(PS);
	}
	return 0;
}

Polynomial ReadPoly() {
	int c, e, N;
	Polynomial P, Rear, t;
	scanf("%d", &N);
	if(N==0){return NULL;}// 0 项

	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
  // 创建一个空结点，避免Attach 判断

	Rear = P;
  while (N--) {
  		scanf("%d %d", &c, &e);
  		Attach(c, e, &Rear);
  }


	t = P; P = P->link, free(t);
	return P;
}

void Attach(int c, int e, Polynomial *pRear) {
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}

Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial P, Rear, t1, t2, t;
	if (!P1 || !P2) return NULL;// important
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	t = P;
	while (t1 && t2) {
		if (t1->expon == t2->expon) {
			if (t1->coef + t2->coef != 0) {
				Attach(t1->coef + t2->coef, t1->expon, &Rear);
			}
			t1 = t1->link;
			t2 = t2->link;
		}
		else if (t1->expon > t2->expon) {
			Attach(t1->coef, t1->expon, &Rear);
			t1 = t1->link;
		}
		else {
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->link;
		}
	}
	while (t1) {
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->link;
	}
	while (t2) {
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->link;
	}

	P = P->link;
	free(t);
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, t1, t2, t;
	int c, e;

	if (!P1 || !P2)return NULL;

	t1 = P1; t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode)); P->link = NULL;
	Rear = P;

	while (t2) {
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1) {
		t2 = P2; Rear = P;
		while (t2) {
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;
			while (Rear->link && Rear->link->expon > e) {
				Rear = Rear->link;

			}
			if (Rear->link && Rear->link->expon == e) {
				if (Rear->link->coef + c) {
					Rear->link->coef += c;
				}
				else {
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
			}
			else {
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
				Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = P; P = P->link; free(t2);
	return P;
}
void PrintPoly(Polynomial P) {
	int flag = 0;
	if (!P) { printf("0 0"); }//没有\n
	while (P)
	{
		if (!flag){
      flag = 1;
    }else{
      printf(" ");
    }


		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
	printf("\n");
}
