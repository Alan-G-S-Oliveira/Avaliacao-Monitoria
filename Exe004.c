#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 6

typedef struct {

    int matricula;
    char nome[20];
    float notas[3];

} aluno;

float media_aluno(aluno x);
int alunos_aprovados(aluno *vetor, int n);
void  ordena_alunos(aluno *vetor, int n);
int *matricula_aprovados(aluno *vetor, int n);

int main() {

    int *aprovados;
    aluno turma[TAMANHO];

    //Alguns alunos são adcionados.
    turma[0] = (aluno){1903, "Satoro Gojo", {10, 10, 9.8}};
    turma[1] = (aluno){1904, "Ryomen Sukuna", {7, 9.8, 9.8}};
    turma[2] = (aluno){1905, "Yuta Okkotsu", {9.9, 9.5, 9.8}};
    turma[3] = (aluno){1906, "Yuji Itadori", {7.5, 6, 6.1}};
    turma[4] = (aluno){1907, "Suguru Geto", {5, 5, 7.8}};
    turma[5] = (aluno){1908, "Roronoa zoro", {7, 8.4, 10}};

    //Lista todos os alunos.
    printf("Lista de alunos:\n\n");
    for(int i = 0; i < TAMANHO; i++)
        printf("Aluno: %s.\nMatricula: %d.\nMedia: %.2f.\n\n", turma[i].nome, turma[i].matricula, media_aluno(turma[i]));

    //Exibe a quantidade de alunos aprovados.
    printf("%d alunos foram aprovados com media maior ou igual a 7.\n\n", alunos_aprovados(turma, TAMANHO));

    //Ordena os alunos por média e exibe seus respectivos nomes.
    ordena_alunos(turma, TAMANHO);
    printf("Alunos ordenados por media:\n\n");
    for(int i = 0; i < TAMANHO; i++)
        printf("%s\n", turma[i].nome);
    puts("");

    //Calcula a matrícula dos aprovados e a exibe.
    aprovados = matricula_aprovados(turma, TAMANHO);
    printf("Matricula dos aprovados:\n");
    for(int i = 0; i < alunos_aprovados(turma, TAMANHO); i++)
        printf("%d\n", aprovados[i]);
    puts("");

    return 0;
}

//Retorna a soma das notas dividido por 3. 
float media_aluno(aluno x){

    return (x.notas[0] + x.notas[1] + x.notas[2]) / 3;

}

/*
    Percorre o vetor de alunos e usa a função media_aluno
    para ver quais tem média maior ou igual a 7 e incrementando 1
    na variavél aprovado. No final retorna aprovado.
*/
int alunos_aprovados(aluno *vetor, int n) {

    int aprovados = 0;

    for(int i = 0; i < n; i++) {

        if(media_aluno(vetor[i]) >= 7)
            aprovados++;

    }

    return aprovados;

}

/*
    Usa a algortimo do bubble_sort para ordenar os alunos.
    Para que ele funcione nesse caso, a média de todos os alunos
    é guardado no vetor médias, que é usada na comparação. No momento
    em que for feita a troca de posição dos alunos, também é preciso
    fazê-la em médias.
*/
void ordena_alunos(aluno *vetor, int n) {

    float aux_media;
    aluno aux_aluno;

    float *medias = (float *)malloc(sizeof(float) * n);
    if(medias == NULL)
        exit(1);

    for(int i = 0; i < n; i++)
        medias[i] = media_aluno(vetor[i]);

    for(int i = 0; i < n - 1; i++) {

        for(int j = i + 1; j < n; j++) {

            if(medias[i] > medias[j]) {

                aux_media = medias[i];
                medias[i] = medias[j];
                medias[j] = aux_media;

                aux_aluno = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux_aluno;

            }

        }

    }

    free(medias);

}

/*
    Aloca um vetor matriculas com a quantidade de aprovados + 1.
    Percorre vetor de alunos, se a média do aluno na posição i
    é maior ou igual a 7, sua respectiva matricula é adcionada em matriculas.
    Retorna o endereço de matriculas.  
*/
int *matricula_aprovados(aluno *vetor, int n) {

    int cont = 0;
    int aprovados = alunos_aprovados(vetor, n);
    int *matriculas = (int *)calloc(sizeof(int), aprovados);
    for(int i = 0; i < n; i++) {

        if(media_aluno(vetor[i]) >= 7) {

            matriculas[cont] = vetor[i].matricula;
            cont++;

        }

    }

    matriculas[aprovados] = -1;
    return matriculas;

}
