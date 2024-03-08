#include<stdio.h>
#include<stdlib.h>
int main(){
    // 用于演示模式匹配
    char master[100];
    char sub[100];
    printf("请输入主串的值:\n");
    scanf("%s",master);
    printf("请输入字串的值:\n");
    scanf("%s",sub);
    int res=forceMatch(master,sub);
    if(res==1){
        printf("匹配成功\n");

    } 
    else{
        printf("匹配失败\n");
    }
}
// 模式匹配的函数
int forceMatch(char*  master,char* sub){
    // 开始匹配
    int i=0,j=0;
    // 就是定义两个指针
    while(master[i]!='\0'&&sub[j]!='\0'){
        if(master[i]==sub[j]){
            // 就可以开始匹配
            i++;
            j++;
        } 
        else{
            i=i-j+1; // 退回到原来位置的下一个
            j=0; 
        }
    }
    if(sub[j]=='\0'){
        return 1;
    }
    return 0;
}