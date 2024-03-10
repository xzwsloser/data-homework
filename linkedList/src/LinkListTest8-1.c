#include "BaseMethod.h"
/**
 *  用于演示约瑟夫问题(有损情况下)
 *  问题描述:
 *      约瑟夫环（约瑟夫问题）是一个数学的应用问题：
 *       已知 n 个人（以编号1，2，3…n分别表示）围坐在一张圆桌周围。
 *      从编号为 k 的人开始报数，数到 m 的那个人出圈；他的下一个人又从 1 开始报数，
        数到 m 的那个人又出圈；依此规律重复下去，直到剩余最后一个胜利者。
*/
int main(){
    printf("请输入总人数:\n");
    int n;
    scanf("%d",&n);
    printf("请问从第几个人开始报数:\n");
    int k;
    scanf("%d",&k);
    printf("请问数到几才会退出:\n");
    int m;
    scanf("%d",&m);
    // 首先还是建立链表
    Node* head=createHead();
    for(int i=n;i>=1;i--){
        insertHead(head,i); 
    }
    Node* pjun=head;
    head=head->next;
    free(pjun);
    // 构建环形链表
    // 找到尾部
    Node* pstr=head;
    while(pstr->next!=NULL){
        pstr=pstr->next;
    }
    // 相接即可
    pstr->next=head;
    Node* start=head;
    // 找到编号为k的人
    if(k==1){
        start=pstr;
    }else{
        for(int j=0;j<k-2;j++){
        start=start->next;
    }
    }
    
    // 找到起点之前的一个人
    // 开始数
    while(start->next!=start){
        // 不断循环,start是出局的人前面的一个人
        for(int h=0;h<m-1;h++){
            start=start->next;
        }
        // 删除元素
        Node* temp=start->next;
        start->next=temp->next;
        free(temp);  // 此时start后面的一个就是下一个开始的人了
    }
    printf("最后留下的人的编号为:%d ",start->data);
}
