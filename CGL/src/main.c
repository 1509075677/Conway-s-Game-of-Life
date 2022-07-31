#include <stdio.h>
#include <stdbool.h>
#include "life.h"

/* Be sure to read life.h and the other given source files to understand
 * what they provide and how they fit together.  You don't have to
 * understand all of the code, but you should understand how to call
 * parse_life() and clearterm().
 */

/* This is where your program will start.  You should make sure that it
 * is capable of accepting either one or two arguments; the first
 * argument (which is required) is a starting state in one of the Life
 * formats supported by parse_life(), and the second (which is optional)
 * is a number of generations to run before printing output and stopping.
 *
 * The autograder will always call your program with two arguments.  The
 * one-argument format (as described in the handout) is for your own
 * benefit!
 */

bool isnumber(char c){
    int dvalue = c-'a'+97;
    if((dvalue)>47 && (dvalue)<58){
        return true;
    }
    else{
        return false;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 3){
        printf("error\n");
        return -1;
    }
    else{
    char **all = parse_life(argv[1]);
    char all2[2][GRIDY+2][GRIDX+2];
    int finaldimension=0;
    for(int column2=0;column2<GRIDY+2;column2++){
        for(int row2=0;row2<GRIDX+2;row2++){
            if(column2!=0&&row2!=0 &&column2!=25 &&row2!=81){
                all2[0][column2][row2]=all[column2-1][row2-1];
            }
            else{
                all2[0][column2][row2]=DEAD;
            }
        }
    }
    int a=0;
    char *gen = argv[2];
    int cc=0;
    //cc=atoi(argv[2]);
    int arraylen=0;
    while(gen[arraylen]!='\0'){
        arraylen=arraylen+1;
    }
    int dd=0;
    while(dd!=arraylen){
        cc=(gen[dd]-'0')+(cc*10);
        dd=dd+1;
    }
    if(cc>0){
        for(int current=0;a<(cc);current=(current+1)%2){
            for(int column=1;column<GRIDY+1;column++){
                for(int row=1;row<GRIDX+1;row++){
                    int count1=0;
                    // int count2=0;
                    if(all2[current][column][row]==DEAD){
                        if(all2[current][column-1][row-1]==LIVE){//top left
                            count1=count1+1;
                        }
                        if(all2[current][column-1][row]==LIVE){//top
                            count1=count1+1;
                        }
                        if(all2[current][column-1][row+1]==LIVE){//top right
                            count1=count1+1;
                        }
                        if(all2[current][column][row-1]==LIVE){ //left
                            count1=count1+1;
                        }
                        if(all2[current][column][row+1]==LIVE){ //right
                            count1=count1+1;
                        }
                        if(all2[current][column+1][row-1]==LIVE){ //bot right
                            count1=count1+1;
                        }
                        if(all2[current][column+1][row]==LIVE){ //bot
                            count1=count1+1;
                        }
                        if(all2[current][column+1][row+1]==LIVE){ //bot left
                            count1=count1+1;
                        }
                        if(count1==3){
                            all2[(current+1)%2][column][row]=LIVE;
                        }
                        if(count1!=3){
                            all2[(current+1)%2][column][row]=DEAD;
                        }
                    }
                    if(all2[current][column][row]==LIVE){
                        if(all2[current][column-1][row-1]==LIVE){
                            count1=count1+1;
                        }
                        if(all2[current][column-1][row]==LIVE){
                            count1=count1+1;
                        }
                        if(all2[current][column-1][row+1]==LIVE){
                            count1=count1+1;
                        }
                        if(all2[current][column][row-1]==LIVE){
                            count1=count1+1;
                        }
                        if(all2[current][column][row+1]==LIVE){
                            count1=count1+1;
                        }
                        if(all2[current][column+1][row-1]==LIVE){
                            count1=count1+1;
                        }
                        if(all2[current][column+1][row]==LIVE){
                            count1=count1+1;
                        }
                        if(all2[current][column+1][row+1]==LIVE){
                            count1=count1+1;
                        }
                        if(count1==3||count1==2){
                            all2[(current+1)%2][column][row]=LIVE;
                        }
                        if(count1>3 ||count1<2){
                            all2[(current+1)%2][column][row]=DEAD;
                        }
                    }
                }
            }
            a=a+1;
            finaldimension=(current+1)%2;
        }
    }
    for(int column3=1;column3<GRIDY+1;column3++){
        for(int row3=1;row3<GRIDX+1;row3++){
            printf("%c", all2[finaldimension][column3][row3]);
        }
        printf("%c",'\n');
    }
    return 0;
        }
}
