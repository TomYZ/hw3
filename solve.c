//
//  solve.c
//  hw3
//
//  Created by Zhen Yang on 2/21/16.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
void compute_AC(char *input,int len,int max_t){//compute AC by adding all the count
    int i=0,j=0,count=0;
    for(i=1; i<=max_t; i++) {
        count=0;
        for(j=0; j<len-i; j++) {
            if((input[j]>='a'&&input[j]<='z')&&(input[i+j]>='a'&&input[i+j]<='z')) {//j and j+1 are both letters
            if(input[j] == input[j+i]) {
                count++;
            }
            }
        }
        printf("t=%d, count=%d\n", i, count);

    }
    printf("\n");
}
void compute_IC(char* input,int len,int max_t){
    int table[26];
    int L=0,i=0;
    double kp=0.0658,IC=0,EIC=0;
    for(i=0; i<26; i++) {//initialize the table to 0
        table[i] = 0;
    }
    for(i=0; i<len; i++) {
        if(input[i]>='a'&&input[i]<='z') {//count all the letters to L
            L++;
            table[input[i]-'a']++;
        }
    }
    printf("L=%d\n",L);//output the total number
    for(i=0; i<26; i++) {
        printf("f('%c')=%d\n", 'a'+i, table[i]);
    }
    for(i=0;i<26;i++){
        IC+=(table[i]*(table[i]-1));
    }
    IC=IC/(L*(L-1));
    printf("IC=%.8g\n",IC);
    for(i=1;i<=max_t;i++){
        if(i==1){
            printf("t=%d, E(IC)=%.8g\n", i, kp);//output kp
        }
        else{
            EIC=0;
            EIC=(kp*(L-i)/(i*(L-1)));
            EIC=EIC+(double)((double)1/26)*((double)(i-1)/i)*((double)L/(L-1));
            printf("t=%d, E(IC)=%.8g\n",i,EIC);//compute E(IC)=kp*(L-t)/(t*(L-1))+1/26*t-1/t*L/L-1(random english)
        }
    }
    printf("\n");
}
bool letters(char* buf,int len){//if the buf is all letters
    int i;
    for (i=0; i<len; i++) {
        if(buf[i]>='a'&&buf[i]<='z'){
            
        }
        else{
            return false;
        }
    }
    return true;
}

void compute_kasiki(char* input,int len){//compute kasiki
    int t=4;
    int flag=true;
    char in[len+1];
    char buffer[len+1];
    int i=0,j=0;
    while (flag) {//set the length from 4 to len
        flag=false;
        for(i=0; i<len-t-1; i++) {
            memcpy(in, &input[i], t);in[t]='\0';//copy the input to input buffer
            if(letters(in, t)==true) {//match only letters
            for(j=i+1; j<len-t; j++) {//find a match
                memcpy(buffer, &input[j], t);buffer[t]='\0';
                if(!letters(buffer, t)) {
                    continue;
                }
                if(strcmp(in, buffer)==0) {
                    printf("len=%d, i=%d, j=%d, j-i=%d, %s\n",t,i,j,j-i,in);//output a match
                    flag=true;
                }
            }
            }
        }
        if(flag==false) {
            printf("len=%d, no more matches\n", t);//if no matches, break
            break;
        }
        t++;
    }
    printf("\n");
}
void solve(int max_t,FILE *in){
    // the following code is modified from http://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
    fseek(in, 0, SEEK_END);
    int len = ftell(in);
    fseek(in, 0, SEEK_SET);
    //citation end
    
    char* input=(char*)malloc(len);
    fread(input,len,1,in);
    printf("Kasiski Method\n");
    printf("==============\n");
    compute_kasiki(input,len);
    printf("Average Index of Coincidence\n");
    printf("============================\n");
    compute_IC(input,len,max_t);
    printf("Auto-correlation Method\n");
    printf("=======================\n");
    compute_AC(input,len,max_t);
    free(input);
}

