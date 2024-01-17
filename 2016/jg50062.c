#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef _BOOK_H
#define _BOOK_H
 
#define MAXN 100
#define MAXL 25
 
typedef struct {
    char book_title[MAXL], author[MAXL];
}BookAuthor;
 
typedef struct {
    char book_title[MAXL];
    int selling, date;
}BookSelling;
 
typedef struct {
    char book_title[MAXL], author[MAXL];
    int selling, date;
}BookInfo;
 
typedef struct {
    int num; // the number of BookInfo
    BookInfo books[MAXN];
}BookInfoList;

void swap(BookInfo a, BookInfo b){
    char temp[MAXL]; int temp1;
    strcpy(temp, a.book_title); strcpy(a.book_title, b.book_title); strcpy(b.book_title,temp);
    strcpy(temp, a.author); strcpy(a.author, b.author); strcpy(b.author,temp);
    temp1 = a.selling; a.selling=b.selling; b.selling=temp1;
    temp1 = a.date; a.date=b.date; b.date=temp1;
}

BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[]){
    BookInfoList list; int total=0; list.num=0;
    for (int i=0; i<M; i++){
        int find=0;
        for (int j=0; j<N; j++){
            if (strcmp(sellingArr[i].book_title,authorArr[j].book_title)==0){
                strcpy(list.books[total].book_title, sellingArr[i].book_title);
                list.books[total].selling = sellingArr[i].selling; list.books[total].date = sellingArr[i].date;
                strcpy (list.books[total].author,authorArr[j].author);  total++; list.num++;
                break;
            }
        }
    }

    for (int i=list.num-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            if (strcmp(list.books[j].book_title,list.books[j+1].book_title)>0 || 
            (strcmp(list.books[j].book_title,list.books[j+1].book_title)==0 && 
            (list.books[j].date > list.books[j+1].date))){
                char temp[MAXL]; int temp1; 
                strcpy(temp, list.books[j+1].book_title); strcpy(list.books[j+1].book_title, list.books[j].book_title); strcpy(list.books[j].book_title,temp);
                strcpy(temp, list.books[j+1].author); strcpy(list.books[j+1].author, list.books[j].author); strcpy(list.books[j].author,temp);
                temp1 = list.books[j+1].selling; list.books[j+1].selling=list.books[j].selling; list.books[j].selling=temp1;
                temp1 = list.books[j+1].date; list.books[j+1].date=list.books[j].date; list.books[j].date=temp1;
            } 
        }
    }
    return list;
}
 
#endif