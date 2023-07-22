#include <stdio.h>
        #include <conio.h>
        #include <string.h>
        void main() {
        int i,j,keylen,msglen;
        char input[100], key[30],temp[30],quot[100],rem[30],key1[30];

        printf("Enter Data: ");
        gets(input);
        printf("Enter Key: ");
        gets(key);
        keylen=strlen(key);
        msglen=strlen(input);
        strcpy(key1,key);
        for (i=0;i<keylen-1;i++) {
        input[msglen+i]='0';
        }
        for (i=0;i<keylen;i++)
        temp[i]=input[i];
        for (i=0;i<msglen;i++) {
        quot[i]=temp[0];
        if(quot[i]=='0')
        for (j=0;j<keylen;j++)
        key[j]='0'; else
        for (j=0;j<keylen;j++)
        key[j]=key1[j];
        for (j=keylen-1;j>0;j--) {
        if(temp[j]==key[j])
        rem[j-1]='0'; else
        rem[j-1]='1';
        }
        rem[keylen-1]=input[i+keylen];
        strcpy(temp,rem);
        }
        strcpy(rem,temp);
        printf("\nQuotient is ");
        for (i=0;i<msglen;i++)
        printf("%c",quot[i]);
        printf("\nRemainder is ");
        for (i=0;i<keylen-1;i++)
        printf("%c",rem[i]);
        printf("\nFinal data is: ");
        for (i=0;i<msglen;i++)
        printf("%c",input[i]);
        for (i=0;i<keylen-1;i++)
        printf("%c",rem[i]);
        getch();
        }
/*Algorithm for Encoding using CRC
o The communicating parties agrees upon the size of message,M(x) and the generator
polynomial, G(x). o If r is the order of G(x),r, bits are appended to the low order end of M(x). This makes the block
size bits, the value of which is xrM(x). o The block xrM(x) is divided by G(x) using modulo 2 division. o The remainder after division is added to xrM(x) using modulo 2 addition. The result is the frame
to be transmitted, T(x). The encoding procedure makes exactly divisible by G(x). Algorithm for Decoding using CRC*/
