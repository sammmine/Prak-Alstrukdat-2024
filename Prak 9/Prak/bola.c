#include <stdio.h>
#include "list_circular.h"

int main() {
    // Input jumlah agent
    int n;
    scanf("%d\n", &n);

    // Inisialisasi list agent (1-N)
    List agent;
    CreateList(&agent);
    int i;
    for (i=1; i<=n; i++){
        insertLast(&agent, i);
    }

    // Proses
    Address p = FIRST(agent);
    int length = n;
    boolean firstMove = true;
    for (i=0; i<n-1; i++){
        int move;
        scanf(" %d", &move); // Proses per-move
        
        if (move<0) { // Untuk move ke kiri
            move = (move % length) + length;
        } else {
            if (!firstMove){ 
                // Untuk move ke kanan, namun bukan move pertama, harus dikurang 1 karena agent lama sudah di-delete
                move-=1;
            }
            move = move % length;
        }

        // Geser pointer sebanyak move
        int j;
        for (j=0; j<move; j++){
            p = NEXT(p);
        }

        // Hapus agent yang sedang memegang bola
        int bin;
        FIRST(agent) = p;
        deleteFirst(&agent, &bin);

        // Update untuk iterasi berikutnya
        p = FIRST(agent);
        length-=1;

        // Setelah iterasi/move pertama, buat flag menjadi false
        firstMove = false;
    }

    // Output the last standing agent
    printf("%d\n", INFO(FIRST(agent)));
    return 0;
}