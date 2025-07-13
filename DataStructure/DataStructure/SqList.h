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
void InitListj(SqList &L)
{
	for (int i = 0; i < MAXSIZE; ++i)
	{
		L.data[i] = 0;
	}

	L.length = 0;
}

