//
//  LinerList.c
//  LinearList
//
//  Created by sanjingrihua on 2018/4/12.
//  Copyright © 2018年 sanjingrihua. All rights reserved.
//
typedef void * LinearListNodeValue;

//定义结构体
typedef struct {
    int capacity;//容量
    int length;//长度
    LinearListNodeValue *values;//节点数据的指针
}LinearList;
#define LINEARLIST_STRUCT
#include "LinerList.h"
#include <stdlib.h>
LinearList * listCreat(int capacity){
    //函数内的东西，就会在内存中，函数内部的局部变量，函数的参数值都在栈内存  栈平衡：出栈，释放
//    LinearList list;
//    list.capacity = capacity;
//    list.length = 0;
//    list.values = NULL;
//    LinearList * pList = &list;
//    return pList;
    
    if (capacity<0) {
        return NULL;
    }
    //字节数 结构体占字节4+4+8=16
    LinearList *list = malloc(sizeof(LinearList));
    if (list) {
        list->capacity = capacity;
        list->length = 0;
        list->values = malloc(capacity * sizeof(LinearListNodeValue));
    }
    //存放假数据
    for (int i=0; i<capacity; i++) {
        list->values[i] = 0x11111111;
    }
    return list;
}
void listRelease(LinearList *list){
    if (list == NULL) {
        return;
    }
    free(list->values);
    free(list);
}
void listClear(LinearList *list){
    if (list == NULL) {
        return;
    }
    list->length = 0;
}
int listLength(LinearList *list){
    if (list == NULL) {
        return 0;
    }
    return list->length;
}
/*获取index对象的数据*/
LinearListNodeValue listGet(LinearList *list,int index){
    if (list == NULL|| index<0 ||index>=list->length) {
        return 0;
    }
    return list->values[index];
}
void listInsert(LinearList *list,int index,LinearListNodeValue value){
    if (list == NULL|| index<0 ||index>list->length || list->length == list->capacity) {
        return;
    }
    //从index开始，移动数据，放数据;从最后一个开始挪动
    for (int i = list->length-1; i>=index; i--) {
        list->values[i+1] = list->values[i];
    }
    //设置值
    list->values[index] = value;
    //length+1
    list->length++;
}
/*添加元素*/
void listAdd(LinearList *list,LinearListNodeValue value){
    if (list == NULL) {
        return;
    }
    listInsert(list, list->length, value);
}
void listSet(LinearList *list,int index,LinearListNodeValue value){
    if (list == NULL|| index<0 ||index>=list->length) {
        return;
    }
    list->values[index] = value;
}
/*删除元素*/
void listRemove(LinearList *list,int index){
    if (list == NULL|| index<0 ||index>=list->length) {
        return;
    }
    //从index+1开始，后面的数据往前挪 疑问：删最后一个value时候，虽然for循环没进去，但是数据长度减1了，所以没问题。
    for (int i=index+1; i<list->length; i++) {
        list->values[i-1]=list->values[i];
    }
    list->length--;
}
void listRemoveValue(LinearList *list,LinearListNodeValue value){
    if (list == NULL) {
        return;
    }
    
    //定义一个初始值 高效
    int removeCount = 0;
    
    //先遍历所有的元素 while循环；倒序遍历删除
    for (int i=0; i<list->length; i++) {
        //效率低 while 嵌套for循环
//        while (list->values[i] == value) {
//            listRemove(list, i);
//        }
        
        if (list->values[i] == value) {
            //需要删除的当前元素 这样写不行，如果连续几个都一样的值，i++后，会跳过删除的数据
//            listRemove(list, i);
            removeCount++;
        }else{
            //不需要删除的 挪动count的个数
            list->values[i-removeCount]=list->values[i];
        }
    }
    list->length -=  removeCount;
    
    
}
void listPrint(LinearList *list){
    if (list == NULL) {
        return;
    }
    printf("list{\n");
    printf("\tlength = %d\n",list->length);
    printf("\tcapacity = %d\n",list->capacity);
    printf("\tvalues = ");
    listPrintValues(list);
    printf("}\n\n");
}
/*打印线性表里面的值*/
void listPrintValues(LinearList *list){
    printf("[");
    for (int i=0; i<list->length; i++) {
        printf("%p",list->values[i]);
        if (i<list->length -1) {
            printf(",");
        }
    }
    printf("];\n\n");
}
