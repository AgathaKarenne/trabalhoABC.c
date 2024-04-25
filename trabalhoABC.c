#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura para representar um ponto
typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a área de um triângulo formado por três pontos A, B e C
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return fabs((A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2.0);
}

// Função para calcular a área do polígono
float AreaPoligono(FILE *file) {
    int numVertices;
    fscanf(file, "%d", &numVertices);

    Ponto A, B, C;
    fscanf(file, "%f %f", &A.X, &A.Y);
    fscanf(file, "%f %f", &B.X, &B.Y);

    float areaTotal = 0;
    for (int i = 2; i < numVertices; i++) {
        fscanf(file, "%f %f", &C.X, &C.Y);
        areaTotal += AreaTriangulo(A, B, C);
        B = C; // Avançar para o próximo ponto
    }

    return areaTotal;
}

int main() {
    FILE *file;
    file = fopen("C:\\Users\\Public\\Desktop\\trianguloABC.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        perror("fopen");
        return 1;
    }

    float area = AreaPoligono(file);

    printf("A área do poligono é %.2f\n", area);

    fclose(file);
    return 0;
}
