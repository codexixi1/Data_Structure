/**
 * @file seq_list.h
 * @brief ˳���̬ʵ��
 * @author CodeXiXi
 * @date 2025/7/13
 *
 * ���ļ�ʵ����˳���Ļ����������������롢ɾ�������ҵȡ�
 */

#ifndef SEQ_LIST_H
#define SEQ_LIST_H

// �����ʼ����(��̬)
#define INITSIZE 50		// ����ʱ���ʵ���С��ʼ����

#include <stdlib.h>

// ��̬˳�������Ͷ���
typedef struct {
	int* data;
	int MaxSize;
	int length;
} SeqList;

#endif // SEQ_LIST_H

// ��ʼ��˳���(��̬)
void InitList(SeqList &L)
{
	L.data = (int*)malloc(sizeof(SeqList) * INITSIZE);
	L.length = 0;
	L.MaxSize = INITSIZE;
}

// ���Ӷ�̬˳�����
void IncreaseSize(SeqList& L, int len)
{
	int *p = L.data;
	L.data = (int*)malloc(sizeof(SeqList) * (L.MaxSize + len));
	if (L.data)
	{
		for (int i = 0; i < L.length; ++i)
		{
			L.data[i] = p[i];
		}

		free(p);

		L.MaxSize = L.MaxSize + len;
		//printf("�ɹ����ӳ���%d!\n", len);
	}
}

// ��L��λ��i������Ԫ��e
bool ListInsert(SeqList &L, int i, int e)
{
	if (L.length >= L.MaxSize)
	{
		IncreaseSize(L, 1);
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
bool ListDelete(SeqList &L, int i, int &e)
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
int GetElem(SeqList L, int i)
{
	return L.data[i - 1];
}

// ��ֵ����, �ڱ�L�в���ֵΪe��Ԫ�أ�����λ��
int LocateElem(SeqList L, int e)
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
void PrintList(SeqList L)
{
	for (int i = 0; i < L.length; ++i)
	{
		printf("%d\t", *(L.data + i));
	}
}