#include <stdio.h>
#include <stdlib.h>

float media_vetor(int *vetor, int n);

int main() {

    int n;
    int **matriz;
    float *vetor;

    //Ler o tamanho da matriz e o guarda em n.
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    //Aloca a linha da matriz. Se der erro encerra o progarma.
    matriz = (int **)malloc(sizeof(int *) * n);
    if(matriz == NULL)
        exit(1);

    /*
        Percorre a linha que foi alocada, em cada uma alocando uma coluna para a matriz.
        Se em algum momento a alocação falhar, o programa desaloca tudo que foi alocado
        até agora e encerra o programa.
    */
    for(int i = 0; i < n; i++) {

        matriz[i] = (int *)malloc(sizeof(int) * n);
        if(matriz[i] == NULL){

            for(int j = 0; j < i; j++)
                free(matriz[j]);
            free(matriz);

            exit(1);

        }

    }

    //Aloca o vetor. Se falhar encerra o programa.
    vetor = (float *)malloc(sizeof(float) * n);
    if(vetor == NULL)
        exit(1);

    //Preenche a matriz números digitados pelo usuário.
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            printf("Digite um valor: ");
            scanf("%d", &matriz[i][j]);

        }

    }

    /*
        Chama a função media_vetor para calcular a média da linha i da matriz
        e a guarda na posição i do vetor.
    */
    for(int i = 0; i < n; i++)
        vetor[i] = media_vetor(matriz[i], n);

    //Percorre o vetor exibindo os resultados.
    for(int i = 0; i < n; i++)
        printf("Media da linha %d: %f.\n", i, vetor[i]);

    //Libera a memória alocada
    for(int i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);
    free(vetor);

    return 0;
}

//Faz um somatório dos elementos do vetor e no final o divide pelo tamanho.
float media_vetor(int *vetor, int n) {

    int soma = 0;

    for(int i = 0; i < n; i++) 
        soma += vetor[i];

    return soma / (float) n;

}