/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 05 - Foundation of Algorithm
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Kenny Pramanik Najla Wibowo (133224088)
 *   Nama File           : modul5.c
 *   Deskripsi           :
*/
#include <stdio.h> 

#define MAX 100
void combination(int pos, int n, int open, int close);

void combination_main(int n){
    if (n>0){
        combination(0,n,0,0);
    }
    return;
}
void combination(int pos, int n, int open, int close){
    int i = 0;
    static char str[MAX];

    if(close == n){
        printf("%s\n", str);
        return;
    }

    else{

        if(open < n){
            str[pos] = '(';
            combination(pos+1, n, open+1, close);
        }
        if (open > close){
            str[pos] = ')';
            combination(pos+1, n, open, close+1);
        }
    }
    i++;
}

int main(){
    int n; 
    scanf("%d", &n);
    
    combination_main(n);
    int total; 
    total = n*2 - 1;
    printf("TOTAL %d", total);
    getchar();
    return 0;

}
