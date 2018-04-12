//
//  main.m
//  LinearList
//
//  Created by sanjingrihua on 2018/4/12.
//  Copyright © 2018年 sanjingrihua. All rights reserved.
//栈：通过声明局部变量申请的空间，生命周期由函数把控
//堆：通过malloc函数申请内存空间，通过free函数销毁之前申请的空间

#import <Foundation/Foundation.h>
#import "LinerList.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        NSMutableArray *arr = [NSMutableArray array];
        //arr本质是指针
        [arr addObject:@"3"];
        
        LinearList * list1 = listCreat(10);
        LinearList * list2 = listCreat(10);
        LinearList * list3 = listCreat(10);
        listAdd(list1, (LinearListNodeValue)10);
        listAdd(list1, (LinearListNodeValue)34);
        listAdd(list1, (LinearListNodeValue)18);
        listAdd(list1, (LinearListNodeValue)18);
        listAdd(list1, (LinearListNodeValue)25);
        listAdd(list1, (LinearListNodeValue)25);
        listAdd(list1, (LinearListNodeValue)25);
        listPrint(list1);
        listRemoveValue(list1, (LinearListNodeValue)10);
        listPrint(list1);
        listRemoveValue(list1, (LinearListNodeValue)25);
        listPrint(list1);
        listClear(list1);
        listPrint(list1);
//        list1->length 封装之后，不能访问。
        //内存指针
        NSLog(@"\n%p\n%p\n%p",list1,list2,list3);
        NSLog(@"%lu",sizeof(LinearList));
        
        //直接free，会造成内存泄露,创建方法内部values的malloc，没有释放
        free(list3);
    }
    return 0;
}
