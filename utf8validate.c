#include <stdio.h>

int main(){

int ch, codepoint, a=0, u=0;

while( (ch=getchar()) != EOF ){

    if( (ch&0x80) == 0 )            // 1-byte (ascii) char 
        codepoint=ch, a++;
    else
        if( (ch&0xE0) == 0xC0){     // 2-byte char
            codepoint=ch & 0x1F;
            ch=getchar(); if(ch==EOF){printf("Unexpected EOF\n"); return 0;}
            if( (ch&0xC0) != 0x80 ){
                printf("Invalid UTF-8 tail byte: 0x%02X\n", ch);
                return 0;
            }
            codepoint<<=6;
            ch&=0x3F;
            codepoint|=ch; 
            if( (codepoint&0x780) == 0 ){
                printf("Oversized UTF-8 code point: U+%04X\n", codepoint);
                return 0;
            }
            u++;
        }
        else
        if( (ch&0xF0) == 0xE0 ){    //3-byte char
            codepoint=ch & 0x0F;
           for(int i=0; i<2; i++){
                ch=getchar(); if(ch==EOF){printf("Unexpected EOF\n"); return 0;}
                if( (ch&0xC0) != 0x80 ){
                        printf("Invalid UTF-8 tail byte: 0x%02X\n", ch);
                        return 0;
                    }        
                codepoint<<=6;
                ch&=0x3F;
                codepoint|=ch;
            }
            if(codepoint >=0xD800 && codepoint<=0xDFFF){
                printf("Invalid UTF-8 code point: U+%04X\n", codepoint);
                return 0;
            }
            if( (codepoint&0xF800) == 0 ){
                printf("Oversized UTF-8 code point: U+%04X\n", codepoint);
                return 0;
            }
            u++;
        }
        else
        if( (ch&0xF8) == 0xF0 ){    // 4-byte char
        codepoint=ch&0x07;
            for(int i=0; i<3; i++){
                ch=getchar(); if(ch==EOF){printf("Unexpected EOF\n"); return 0;}
                if( (ch&0xC0) != 0x80 ){
                        printf("Invalid UTF-8 tail byte: 0x%02X\n", ch);
                        return 0;
                }        
                codepoint<<=6;
                ch&=0x3F;
                codepoint|=ch;
            }
            if(codepoint>0x10FFFF){
                printf("Invalid UTF-8 code point: U+%06X\n", codepoint);
                return 0;
            }
            if( (codepoint&0x1F0000) == 0 ){
                printf("Oversized UTF-8 code point: U+%04X\n", codepoint);
                return 0;
            }
            u++;
        }
        else{
            printf("Invalid UTF-8 header byte: 0x%02X\n", ch);
            return 0;
        }
    
}

printf("Found %d ASCII and %d multi-byte UTF-8 characters.\n", a, u);

    return 0;
}