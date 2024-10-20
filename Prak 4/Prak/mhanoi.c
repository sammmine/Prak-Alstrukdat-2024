#include <stdio.h>
#include "matrix.h"

boolean canPlace(Matrix board, Matrix piece, int startRow, int startCol) {
    // Cek apakah matriks piece bisa ditempatkan di posisi startRow, startCol pada board
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (ELMT(board, startRow + i, startCol + j) <= ELMT(piece, i, j)) {
                return false;
            }
        }
    }
    return true;
}

void rotatePiece(Matrix *piece) {
    // Rotasi 90 derajat searah jarum jam untuk matriks 2x2
    int temp = ELMT(*piece, 0, 0);
    ELMT(*piece, 0, 0) = ELMT(*piece, 1, 0);
    ELMT(*piece, 1, 0) = ELMT(*piece, 1, 1);
    ELMT(*piece, 1, 1) = ELMT(*piece, 0, 1);
    ELMT(*piece, 0, 1) = temp;
}

int main() {
    int N;
    scanf("%d", &N);
    
    Matrix board, piece;
    readMatrix(&board, N, N); // Membaca matriks papan N x N
    readMatrix(&piece, 2, 2); // Membaca matriks gabungan piringan 2 x 2

    int validPositions = 0;

    // Iterasi posisi di papan yang bisa menampung matriks 2x2
    for (int i = 0; i <= N - 2; i++) {
        for (int j = 0; j <= N - 2; j++) {
            // Cek untuk 4 rotasi
            for (int k = 0; k < 4; k++) {
                if (canPlace(board, piece, i, j)) {
                    validPositions++;
                    break; // Jika valid, lanjut ke posisi berikutnya
                }
                rotatePiece(&piece); // Rotasi matriks piece
            }
        }
    }

    printf("%d\n", validPositions);
    return 0;
}