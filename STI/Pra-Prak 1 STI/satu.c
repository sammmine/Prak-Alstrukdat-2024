#include <stdio.h>

int main() {
    char nama[20];
    
    scanf("%s", nama);
    // bisa pake &nama juga (tergantung compiler)
    
    printf("%s bertanya: \"Apa yang dicari orang sigma?\"\n", nama);

    return 0;
}