/**
 * @file sq_list.h
 * @brief ˳���̬ʵ��
 * @author CodeXiXi
 * @date 2025/7/13
 *
 * ���ļ�ʵ����˳���Ļ����������������롢ɾ�������ҵȡ�
 */

#ifndef SQ_LIST_H
#define SQ_LIST_H

// ������󳤶�(��̬)
#define MAXSIZE 50

// ��̬˳�������Ͷ���
typedef struct {
	int data[MAXSIZE];  // �þ�̬�ġ����顱�洢˳����Ԫ��
	int length;         // ˳���ĵ�ǰ����
} SqList;

#endif // SQ_LIST_H

// ��ʼ��˳���(��̬)
void InitList(SqList &L)
{
	for (int i = 0; i < MAXSIZE; ++i)
	{
		L.data[i] = 0;
	}

	L.length = 0;
}

// ��L��λ��i������Ԫ��e
bool ListInsert(SqList &L, int i, int e)
{
	if (L.length >= MAXSIZE)
	{
		return false;
	}

	if (i < 1 || i > L.length + 1)
	{
		return false;
	}

	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;

	return true;
}

// ɾ��L��λ��Ϊi��Ԫ��
bool ListDelete(SqList &L, int i, int &e)
{
	if (i < 1 || i > L.length)
	{
		return false;
	}

	e = L.data[i - 1];
	for (int j = i; j < L.length; ++j)
	{
		L.data[j - 1] = L.data[j];
	}

	L.length--;
	return true;
}

// ��λ���ң���ȡL�е�i��λ�õ�Ԫ��
int GetElem(SqList L, int i)
{
	return L.data[i - 1];
}

// ��ֵ����, �ڱ�L�в���ֵΪe��Ԫ�أ�����λ��
int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; ++i)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}

	return 0;
}

// ���L��ȫ����Ԫ��
void PrintList(SqList L)
{
	for (int i = 0; i < L.length; ++i)
	{
		printf("%d\t", L.data[i]);
	}

	printf("\n");
}