Position BinarySearch(List L, ElementType X) {
	Position last = L->Last;
	Position start = 1;

	while (start <= last) {
  	if (X == L->Data[start]) {
  		return start;
  	}else if (X == L->Data[last]) {
  		return last;
  	}
	  Position center = (start + last) / 2;
		if (X == L->Data[center]) {
			return center;
		}
		if (X > L->Data[center]) {
			start = center + 1;
		}
		else {
			last = center - 1;
		}
	}

	return NotFound;
}
