#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
    int a,b,c,d;
    printf("\n Enter the first byte");
    scanf("%d",&a);
    printf("\n Enter the second byte");
    scanf("%d",&b);
    printf("\n Enter the third byte");
    scanf("%d",&c);
    printf("\n Enter the fourth byte");
    scanf("%d",&d);
printf("\n the Ip address is=%d.%d.%d.%d",a,b,c,d);
if(a<127){
    printf("\n Class A");

}
else if(a>127&&a<=191){
    printf("\n Class B");
}
else if(a>191&&a<=223){
         printf("\n Class C");

}
else if(a>223&&a<=239){
     printf("\n Class D");
}
else{
    printf("\n Class E");
}
}
