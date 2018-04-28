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
