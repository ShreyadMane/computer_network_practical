#include<stdio.h>
#include<string.h>
int main(){
    char test[100];
    scanf("%s",test);
    printf("test message is%s\n",test);
    char csum=0*00;
    char polynomial=0*07;
    int len=strlen(test);
    for(int j=0;j<len;j++){
        char ch =test[j];
        csum=csum^ch;
        int i=0;
        while(i<=7){
            csum=(csum<<1)^((csum&0*80)?polynomial:0*00);
            i++;
        }
    }
    printf("checksum is %d\n",(int)csum);
    return 0;
}
