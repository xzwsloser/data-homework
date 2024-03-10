#ifndef _BASEMETHOD_H
#define _BASEMETHOD_H
#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h>  // 引入可变参数
// 定义结构体
typedef struct node{
    int data;
    struct node* next;
}Node;
// 建立头节点
Node*  createHead();

// 插入元素的操作
// 头插法
void insertHead(Node* head,int elem);
void displayList(Node* head);
Node* getHeadByParameters(int arg_cnt,...); // 根据可变参数后去链表

#endif