//
//  LinerList.h
//  LinearList
//
//  Created by sanjingrihua on 2018/4/12.
//  Copyright © 2018年 sanjingrihua. All rights reserved.
//线性表

#ifndef LinerList_h
#define LinerList_h

#include <stdio.h>
#ifndef LINEARLIST_STRUCT
typedef void * LinearListNodeValue;

//定义结构体
typedef void LinearList;
#endif

//定义一个创建线性表的函数
LinearList * listCreat(int capacity);

/*销毁线性表结构体*/
void listRelease(LinearList *list);

/*清空线性表*/
void listClear(LinearList *list);

/*获取线性表的长度*/
int listLength(LinearList *list);
/*获取index对象的数据*/
LinearListNodeValue listGet(LinearList *list,int index);
/*插入元素*/
void listInsert(LinearList *list,int index,LinearListNodeValue value);
/*添加元素*/
void listAdd(LinearList *list,LinearListNodeValue value);

/*设置元素*/
void listSet(LinearList *list,int index,LinearListNodeValue value);
/*删除元素*/
void listRemove(LinearList *list,int index);
/*删除某个值的所有数据*/
void listRemoveValue(LinearList *list,LinearListNodeValue value);
/*打印当前线性表*/
void listPrint(LinearList *list);
/*打印线性表里面的值*/
void listPrintValues(LinearList *list);
#endif /* LinerList_h */
