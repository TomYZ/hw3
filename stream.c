//
//  stream.c
//  hw3
//
//  Created by Zhen Yang on 2/22/16.
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <sys/types.h>

void stream(const char *p, int length, unsigned char *buffer) {
    
    
     // the following code is modified from http://merlot.usc.edu/cs531-s16/homeworks/hw2/   key generation for a simple stream cipher
    unsigned char md5_buf[MD5_DIGEST_LENGTH];
    unsigned char* keybuffer=buffer;
    int len=strlen(p)+2+MD5_DIGEST_LENGTH;
    char *s=malloc(len+1);
    int i=0,count=0;
    MD5((const unsigned char*)p, strlen(p), md5_buf);
    //citation end
    
    while(length>0) {
        
        
        // the following code is modified from http://merlot.usc.edu/cs531-s16/homeworks/hw2/   key generation for a simple stream cipher
        sprintf(&s[MD5_DIGEST_LENGTH], "%02d%s", i, p);
        memcpy(s, md5_buf, MD5_DIGEST_LENGTH);
        MD5((const unsigned char*)s, len, md5_buf);
        //citation end
        
        
        if(length<=8) {
            count=length;
            length=0;
        } else {
            count=8;
            length-=8;
        }
        if(buffer!=NULL) {//output to buffer
            memcpy(keybuffer, md5_buf, count);
            keybuffer+=count;
        } else {//out put to stdout
            fwrite(md5_buf, 1, count, stdout);
        }
        if(++i == 100) i = 0;
    }
    free(s);
    
}

