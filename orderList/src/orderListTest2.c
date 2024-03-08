// 题目2: 除去所有0元素
#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("请输入要创建数组的长度:\n");
    int len=0;
    scanf("%d",&len);
    int arr[len];
    for(int i=0;i<len;i++){
        printf("请输入第%d个数据:\n",i+1);
        scanf("%d",&arr[i]);
    }

    printf("你创建的数组为:\n");
    displayArray(arr,len);
    // 2. 进行核心业务的处理
    // 还是利用快慢指针法进行处理
    int slow=0;
    // 利用slow找值为0的元素
    for(int fast=0;fast<len;fast++){
       if(arr[fast]!=0){
        int temp=arr[fast];
        arr[fast]=arr[slow];
        arr[slow]=temp;
        slow++;  // 记录的就是非0位置的索引
       }
    }
    // 遍历数组
    printf("取出0之后的数组为:\n");
    displayArray(arr,slow);
}

// 数据展示函数
void displayArray(int *p,int len){
    for(int i=0;i<len;i++){
        printf("%-3d",p[i]);
    }
    printf("\n");
}