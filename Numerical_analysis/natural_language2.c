#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//確率的自然言語生成プログラムです
//実験用プログラムファイルです
int main(void){

    FILE *fp1,*fp2;
    char ch;
    int n=0;
    //テキストファイルを読み込んでスペースと半角アルファベットのみを別のファイルに書くプログラム
    if((fp1 = fopen("English_text.txt","r"))== NULL){
        printf("ファイルが開けませんでした");
        exit(1);
    }
    if((fp2 = fopen("out_text.txt","w"))==NULL){
        printf("ファイルを開けませんでした");
        exit(1);
    }

    while(feof(fp1)==0){
        ch = fgetc(fp1);
        if(isalpha(ch)!= 0 || ch == ' '){
            if(fputc(ch,fp2) == EOF){
            printf("ファイルに書き込めませんでした");
            exit(1);
            }
        }else{
            ch=' ';
            fputc(ch,fp2);
        }
        if(n<=10){
            putchar(ch);
        }
        n++;
    }
    fclose(fp1);
    fclose(fp2);

    //

    return 0;

}
int alpha_count(char ch){
    int count[26];

    switch (ch)
    {
    case 'a':
        break;
    case 'b':
        break;
    case 'c':
        break;
    case 'd':
        break;
    case 'e':
        break;
    case 'f':
        break;
    case 'g':
        break;
    case 'h':
        break;
    case 'i':
        break;
    case 'j':
        break;
    case 'k':
        break;
    case 'l':
        break;
    case 'm':
        break;
    case 'n':
        break;
    case 'o':
        break;
    case 'p':
        break;
    case 'q':
        break;
    case 'r':
        break;
    case 's':
        break;
    case 't':
        break;
    case 'u':
        break;
    case 'v':
        break;
    case 'w':
        break;
    case 'x':
        break;
    case 'y':
        break;
    case 'z':
        break;

    default:
        count[26];
        break;
    }
    
}