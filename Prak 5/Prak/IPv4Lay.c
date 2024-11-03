#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
// #include "mesinkarakter.c"
// #include "mesinkata.c"

boolean cekStream(Word kata) {
    // Panjang maksimal 50 karakter
    if (kata.Length > 50) return false;

    int oktet_count = 0;
    int at_count = 0;
    char store[51]; // Store currentWord ke array of char untuk mempermudah parsing
    strncpy(store, kata.TabWord, kata.Length); // strncpy(dest, src, n) adalah fungsi untuk meng-copy sejumlah karakter
    store[kata.Length] = '\0';

    // Hitung dulu @-nya ada berapa (harus ada 3) (loop all)
    for (int i = 0; i < kata.Length; i++) {
        // Untuk karakter selain angka 0-9 dan @, return false
        if (!((store[i] >= '0' && store[i] <= '9') || store[i] == '@')) {
            return false;
        }
        if (store[i] == '@') {
            at_count++;
        }
    }

    if (at_count != 3) return false;

    char *token = strtok(store, "@"); // strtok(string, delimiter) adalah fungsi untuk memecah string berdasarkan delimiter tertentu (di sini delimiternya @)
    // strtok() mengubah string asli dengan menempatkan \0 (null character) pada tiap posisi delimiter yang ditemukan

    while (token != NULL) {
        if (oktet_count >= 4) return false;

        int panjang = strlen(token);

        if (panjang == 0 || (panjang > 1 && token[0] == '0')) return false; // Jika ada leading zero

        int oktet = atoi(token);
        if (oktet < 0 || oktet > 255) return false; // Jika oktet tidak 0-255

        oktet_count++; // Jika semua kondisi di atas terlewati, tambahkan oktet_count
        token = strtok(NULL, "@"); // Lanjut ke oktet berikutnya
    }

    return oktet_count == 4;
}

int main() {
    STARTWORD();
    
    boolean first = true;
    while (!EndWord) {
        if (!first) {
            printf(" ");
        }

        if (cekStream(currentWord)) {
            printf("4Lay");
        } else {
            printf("ewh");
        }

        first = false;
        ADVWORD();
    }
    
    printf("\n");
    return 0;
}