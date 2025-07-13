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
#define INITSIZE 50

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
	}
}
