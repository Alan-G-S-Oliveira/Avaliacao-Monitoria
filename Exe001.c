#include <stdio.h>
#include <stdlib.h>

int numero_noVetor(int x, int n, const int *vetor);

int main() {

    int n, tamanhoRepeticoes;
    int *vetor, *numeros, *repeticoes;

    //Coleta o tamanho do vetor e guarda em n.
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    /*
        Alocação de memória para três vetores, caso um deles seja igual a NULL o programa
        libera a memória dos ponteiros caso algum deles tenha sido alocado
        e encerra a execução do programa.
    */
    vetor = (int *)malloc(sizeof(int) * n);
    numeros = (int *)malloc(sizeof(int) * n);
    repeticoes = (int *)calloc(sizeof(int), n);
    if(vetor == NULL || numeros == NULL || repeticoes == NULL) {

        if(vetor != NULL)
            free(vetor);
        if(numeros != NULL)
            free(numeros);
        if(repeticoes != NULL)
            free(repeticoes);

        printf("Erro ao alocar o vetor!");
        exit(1);

    }

    //Preenche o vetor com números digitados pelo usuário.
    for(int i = 0; i < n; i++) {

        printf("Digite um valor: ");
        scanf("%d", &vetor[i]);

    }

    /*
        Inicialmente coloca um elemento em numeros[0] e incrementa 1 em repeticoes[0].
        A cada iteração d laço for, ele verifica se o elemento vetor[i] está em numeros
        usando a função auxiliar numero_noVetor(). Se sim, ele incrementa 1 em repeticoes
        na posição em que vetor[i] se encontra em números. Senão, ele adciona vetor[i] em
        numeros[tamanhoRepeticoes] que é a primeira posição vazia de numeros e incrementa
        1 em repeticoes[tamanhoRepeticoes], além disso tamanhoRepeticoes é incrementado  em 1,
        pois ele reprenta a última posição livre de numeros e repeticoes.
    */
    numeros[0] = vetor[0];
    tamanhoRepeticoes = 1;
    repeticoes[0]++;
    for(int i = 1; i < n; i++) {

        int x = numero_noVetor(vetor[i], tamanhoRepeticoes, numeros);
        if(x == -1) {

            numeros[tamanhoRepeticoes] = vetor[i];
            repeticoes[tamanhoRepeticoes] ++;
            tamanhoRepeticoes++;

        } else{

            repeticoes[x]++;

        }

    }

    //Percorre numeros e repeticoes exibindo os resultados.
    for(int i = 0; i < tamanhoRepeticoes; i++)
        printf("Valor %d, quantidade: %d.\n", numeros[i], repeticoes[i]);

    //Libera os ponteiros alocados.
    free(vetor);
    free(numeros);
    free(repeticoes);

    return 0;
}

/*
    Percorre o vetor procurando pelo elemento x, se o encontrar
    retona sua devida posição.Caso contrário, retorna -1.
*/
int numero_noVetor(int x, int n, const int *vetor) {

    for(int i = 0; i < n; i++) {

        if(x == vetor[i])
            return i;

    }

    return -1;

}
