#include <stdio.h>
#include "SqList.h"
#include "SeqList.h"

int main()
{
	SeqList L;
	InitList(L);
	IncreaseSize(L, 5);
	printf("%d", L.MaxSize);

	return 0;
}