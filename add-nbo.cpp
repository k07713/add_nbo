#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){
    FILE *fp1 = fopen(argv[1], "rb");
    FILE *fp2 = fopen(argv[2], "rb");

    uint32_t n1, n2, sum;

    fread(&n1, sizeof(uint32_t), 1, fp1);
    fread(&n2, sizeof(uint32_t), 1, fp2);

    n1 = ntohl(n1);
    n2 = ntohl(n2);
    sum = n1 + n2;

    printf("%d(0x%x)  + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum);

    fclose(fp1);
    fclose(fp2);

    return 0;
}