// 题目三: 演示各种排序算法
#include<stdio.h>
#include<stdlib.h>
int main(){
    // 信息输入
     printf("请输入要创建数组的长度:\n");
    int len=0;
    scanf("%d",&len);
    int arr[len];
    for(int i=0;i<len;i++){
        printf("请输入第%d个数据:\n",i+1);
        scanf("%d",&arr[i]);
    }

    printf("你创建的数组为:\n");
    // 首先拷贝三份数据
    
    displayArray(arr,len);
    // 进行各种排序算法演示
    printf("冒泡排序的结果:\n");
    bubbleSort(arr,len);
    displayArray(arr,len);
    printf("=================\n");
    printf("选择排序的结果:\n");
    selectSort(arr,len);
    displayArray(arr,len);
    printf("=================\n");
     printf("插入排序的结果:\n");
    insertSort(arr,len);
    displayArray(arr,len);
    
}
// 数据展示函数
void displayArray(int *p,int len){
    for(int i=0;i<len;i++){
        printf("%-3d",p[i]);
    }
    printf("\n");
}
// 冒泡排序
void bubbleSort(int* p,int len){
    // 执行冒泡排序的逻辑
    for(int i=0;i<len-1;i++){
        // 外层
        for(int j=0;j<len-i-1;j++){
            // 默认升序排列
            if(p[j]>p[j+1]){
                swap(&p[j],&p[j+1]);
            }
        }
    }
}
// 选择排序
void selectSort(int *p,int len){
    // 利用降序排列演示选择排序
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(p[i]<p[j]){
                swap(&p[i],&p[j]);
            }
        }
    }
}
// 插入排序算法
// 利用升序排列演示插入排序
// 找到不同的索引
int findDifferentIndex(int *p,int len){
    for(int i=0;i<len-1;i++){
        if(p[i]>p[i+1]){
            return i; // 就是交出分界点
        }
    }
    return -1;
}
void insertSort(int *p,int len){
    int index=findDifferentIndex(p,len);
   
    if(index==-1){
        return ;
    }
    else{
        int count=0;
        for(int i=index+1;i<len;i++){
             int count=i;
            for(int j=i-1;j>=0;j--){
               
                if(p[j]>p[count]){
                    // 开始交换
                    swap(&p[j],&p[count]);
                    count--;
                } else{
                    break;
                }
            }
            
            }
        }
    }

// 交换操作
void swap(int * pa,int * pb){
    int temp=*pa;
    *pa=*pb;
    *pb=temp;
}