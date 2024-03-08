// 第一题: 有序元素去重复
#include<stdio.h>
#include<stdlib.h>

int main(){
    // 数组输入部分,假设输入10个数据
    int array[10];
    for(int i=0;i<10;i++){
        printf("请输入第%d个数据:\n",i+1);
        scanf("%d",&array[i]);
    } // 1. 数据输入部分
    // 展示数据
    printf("去重之前的数据为:\n");
    for(int k=0;k<10;k++){
        printf("%-3d",array[k]);
    }
    int len=10; // 数组长度
    // 2. 核心逻辑,数据去重 可以利用双指针法,fast指针一直走记录元素,slow记录索引
    int slow=0;
    for(int fast=0;fast<len;fast++){
        if(array[fast]!=array[slow]){
            array[slow+1]=array[fast];
            slow++; // 索引后移
        }
    }
    // 输出去重之后的数组
    printf("去重之后的数组为:\n");
    for(int j=0;j<=slow;j++){
        printf("%-3d",array[j]);
    }
}