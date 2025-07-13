/**
 * @file sq_list.h
 * @brief 顺序表静态实现
 * @author CodeXiXi
 * @date 2025/7/13
 *
 * 本文件实现了顺序表的基本操作，包括插入、删除、查找等。
 */

#ifndef SQ_LIST_H
#define SQ_LIST_H

// 定义最大长度(静态)
#define MAXSIZE 50

// 静态顺序表的类型定义
typedef struct {
	int data[MAXSIZE];  // 用静态的“数组”存储顺序表的元素
	int length;         // 顺序表的当前长度
} SqList;

#endif // SQ_LIST_H

// 初始化顺序表(静态)
void InitListj(SqList &L)
{
	for (int i = 0; i < MAXSIZE; ++i)
	{
		L.data[i] = 0;
	}

	L.length = 0;
}

