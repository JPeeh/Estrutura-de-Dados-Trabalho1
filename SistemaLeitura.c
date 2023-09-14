#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calcularMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2;
}

const char* determinarSituacao(float media) {
    if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main() {
    FILE *entrada = fopen("EntradaDados.txt", "r");
    FILE *saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    fprintf(saida, "Nome,Nota Média,Situação\n");

    char linha[256];

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        char nome[100];
        char telefone[20];
        char curso[100];
        float nota1, nota2;

        if (sscanf(linha, "%[^,],(%[^)])%*[^,],%[^,],%f,%f,", nome, telefone, curso, &nota1, &nota2) == 5) {
            float media = calcularMedia(nota1, nota2);
            const char* situacao = determinarSituacao(media);
            fprintf(saida, "%s,%.2f,%s\n", nome, media, situacao);
        }
    }

    fclose(entrada);
    fclose(saida);

    printf("Arquivo SituacaoFinal.csv gerado com sucesso!\n");

    return 0;
}
