#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, maior;
    int *vetor;

    //Coleta o tamanho do vetor e guarda em n.
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    //Aloca o ponteiro, caso dê errado encerra o programa.
    vetor = (int *)malloc(sizeof(int) * n);
    if(vetor == NULL)
        exit(1);

    //Preenche o vetor com números digitados pelo usuário.
    for(int i = 0; i < n; i++) {

        printf("Digite um valor: ");
        scanf("%d", &vetor[i]);

    }

    /*
        É utilizado a função abs para calcular o degrau.
        Inicialmente maior recebe o primeiro degrau.
        Dentro do for comparamos se o degrau calculado é maior que o de "maior",
        se sim, "maior" recebe esse degrau.
    */
    maior = abs(vetor[0] - vetor[1]);
    for(int i = 1; i < n - 1; i++) {

        if(abs(vetor[i] - vetor[i + 1]) > maior)
            maior = abs(vetor[i] - vetor[i + 1]);

    }

    //Exibe o resultado.
    printf("Maior degrau: %d.\n\n", maior);

    //Libera o ponteiro.
    free(vetor);

    return 0;
}