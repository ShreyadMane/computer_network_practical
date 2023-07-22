#include<stdio.h>
#include<string.h>
main(){
    char a[20],b[20];
    int i,n,j;
    char f,s;
    printf("Enter the size of the frame");
    scanf("%d",&n);
    n=n*2;
    printf("Enter the characters in frame");
    for(i=0;i<n;i++)
        scanf("%c",&a[i]);
    printf("\nFrame\n");
    for(i=0;i<n;i++)
        printf("%c",a[i]);
    j=0;
    for(i=0;i<n;i++){
        if(a[i]=="f")
        {
            b[j]='s';
            j++;
            b[j]=a[i];
        }
        else if(a[i]='s'){
            b[j]='s';
            j++;
            b[j]=a[i];
        }
        else
            b[j]=a[i];
        j++;
    }
    printf("\nRESULT\n");
    printf("f");
    for(i=0;i<j;i++){
        printf("\n");
        printf("%c",b[i]);
    }
printf("\nf");
    }
    /*Data of each frame at the sender side, is first stuffed with 8-bit flag sequence (‘F’) at the beginning
and end of each frame.

 Next, the data is scanned to see if any similar flag sequence (‘F’) forms a part of it or not. If yes, then
before each such flag sequence, an extra escape sequence (‘E’) is stuffed.  Now, if any similar escape sequence (‘E’) is found to form a part of the data to be sent, then an extra
escape sequence (‘E’) is stuffed before the occurrence of each such escape sequence.*/
