/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 05 - Foundation of Algorithm
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Kenny Pramanik Najla Wibowo (133224088)
 *   Nama File           : modul5.c
 *   Deskripsi           : Membuat program untuk generate bracket berdasarkan input dari user, dimana urutan dari hasil mengikuti lekursif
*/
#include <stdio.h> 

#define MAX 100

long factorial(int n) { //[1]
    int c;
    long result = 1;
    for (c = 1; c <= n; c++)
        result = result * c;
    return result;
} 

long find_ncr(int n, int r) { //[1]
    long result;
    result = factorial(n) / (factorial(r) * factorial(n - r));
    return result;
} 

void combination(int pos, int n, int open, int close);

void combination_main(int n){
    if (n>0){
        combination(0,n,0,0);
    }
    return;
}
void combination(int pos, int n, int open, int close){ //[2]
    int i = 0;
    static char str[MAX];

    if(n==0){
        return;
    }

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
    
    //parameter untuk fungsi kombinasi 
    //untuk n : 
    int m = n*2;

    combination_main(n);
    int total = (find_ncr(m, n)) / (n+1);
    printf("TOTAL %d", total);
    getchar();
    return 0;

}
