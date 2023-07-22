#include<stdio.h>
#include<conio.h>
void main(){
int data[7],rec[7],i,c1,c2,c3,c;
printf("this works for message of 4bits in size\n enter message bit one by one: ");
scanf("%d%d%d%d",&data[0],&data[1],&data[2],&data[4]);
data[6]=data[0]^data[2]^data[4];
data[5]=data[0]^data[1]^data[4];
data[3]=data[0]^data[1]^data[2];
printf("\n the encoded bits are given below:\n");
for(i=0;i<7;i++){
    printf("%d",data[i]);

}
printf("\n enter the received data bits one by one:");
for(i=0;i<7;i++){
    scanf("%d",&rec[i]);
}
c1=rec[6]^rec[4]^rec[2]^rec[0];
c2=rec[5]^rec[4]^rec[1]^rec[0];
c3=rec[3]^rec[2]^rec[1]^rec[0];
c=c3*4+c2*2+c1;
if(c==0){
    printf("\n congratulations there is no error");

}else{
    printf("\n error on the position:%d\n the correct message is\n",c);
    if(rec[7-c]==0)
        rec[7-c]=1;
    else
        rec[7-c]=0;
    for(i=0;i<7;i++){
        printf("%d",rec[i]);
    }
}
}
/*Algorithm of Hamming code: Hamming Code is simply the use of extra parity bits to allow the
identification of an error. 1. Write the bit positions starting from 1 in binary form (1, 10, 11, 100, etc). 2. All the bit positions that are a power of 2 are marked as parity bits (1, 2, 4, 8, etc). 3. All the other bit positions are marked as data bits. 4. Each data bit is included in a unique set of parity bits, as determined its bit position in binary
form. a. Parity bit 1 covers all the bits positions whose binary representation includes a 1 in the least
significant position (1, 3, 5, 7, 9, 11, etc). b. Parity bit 2 covers all the bits positions whose binary
representation includes a 1 in the second position from the least significant bit (2, 3, 6, 7, 10, 11, etc). c. Parity bit 4 covers all the bits positions whose binary representation includes a 1 in the third
position from the least significant bit (4–7, 12–15, 20–23, etc). d. Parity bit 8 covers all the bits
positions whose binary representation includes a 1 in the fourth position from the least significant bit
bits (8–15, 24–31, 40–47, etc). e. In general, each parity bit covers all bits where the bitwise AND of
the parity position and the bit position is non-zero. 5. Since we check for even parity set a parity bit to 1 if the total number of ones in the positions it
checks is odd. 6. Set a parity bit to 0 if the total number of ones in the positions it checks is even.*/



















