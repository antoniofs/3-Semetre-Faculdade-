//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

/**
@Professor/Disciplina: Marcos / Algebrar Linear
@Contact: antonio@unisantos.br
@auhor: Antonio Flávio Sousa Silva Nascimento Júnior / 201626192
@version: 1.0 Build Alpha
*/

//Prototipos das funcoes
void InserirDadosTabela(double [][4], int, int);
double encontrarMultiplicador(double, double);
void MostrarMatriz(double [][4], int, int);
void ZerarLinha(double [][4], int, int, double, int);
void SalvaNovaMatriz(double * );


//DECLARAÇÃO GLOBAL
double matrizModoSimplex[3][4];

//Função main
void main()
{

    printf("Bem vindo ao programa para calculo com Metodo Simplex\n");
    puts("Ao final da digitacao será gerada uma matriz, favor conferir se os numero estao certos");
    puts("");
    printf("Digite a matriz !!!");
    puts("");

    //Chamada a função para Inserir dados da tabela
    InserirDadosTabela(matrizModoSimplex, 3, 4);




}

//Essa função faz um loop na matriz até a mesma ser preenchida, ela recebe por referencia o endereco da matriz
void InserirDadosTabela(double matrizInserida[][4], int linha, int coluna)
{
    int i = 0, j = 0;
    char letrasMatriz[5] = { 'X', 'Y', 'Z', '=' };

    //Laço para a linha da matriz
    for(i = 0; i < linha; i++)
    {
        //laço para a coluna da matriz
        for(j = 0; j < coluna; j++)
        {

            printf("%c : ", letrasMatriz[j]);
            scanf("%lf", &matrizInserida[i][j]);

        }
        puts("");
    }
    //Chamada a função para imprimir dados da tabela
    MostrarMatriz(matrizInserida,linha,coluna);
}

//Essa funcao faz um loop para mostrar na tela a matriz
void MostrarMatriz(double matrizInserida[][4], int linha, int coluna)
{
    int i = 0, j = 0;
    double multiplicador = 0;
    double troca;

    printf("\n\n");
    printf("Seu primeiro termo e' : %2.0lf\n", matrizInserida[i][j]);

   //Confere se a primeira posiçã é 0, se for ele troca para a segunda posição
    if(matrizInserida[0][0] == 0)
    {
        j++;
        matrizInserida[0][0] = matrizInserida[i][j];
        printf("Seu primeiro termo e' : %2.0lf\n", matrizInserida[i][j]);
    }

    printf("\nMostrar matriz: \n");
    printf("--------------------------------------------------------------\n");
    //Laço para mostrar a matriz
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {

            printf("%3.0lf ", matrizInserida[i][j]);

        }
        puts("");
    }
    printf("-------------------------------------------------------------");
    printf("\n\nE ser estiver certo aperte enter'............\n");
    system("pause");
    system("cls");

    //chamada para encontrar o multiplicador, imprimir ele na tela e logo apos zera a 1° linha
    multiplicador = encontrarMultiplicador(matrizInserida[1][0], matrizInserida[0][0]);
    printf("\nMULTIPLICADOR: %.0lf\n", multiplicador);
    ZerarLinha(matrizInserida, linha, coluna, multiplicador, 1);

    //chamada para encontrar o multiplicador, imprimir ele na tela e logo apos zera a 2° linha
    multiplicador = encontrarMultiplicador(matrizInserida[2][0], matrizInserida[0][0]);
    printf("\nMULTIPLICADOR: %.0lf\n", multiplicador);
    ZerarLinha(matrizInserida, linha, coluna, multiplicador, 2);



}
//Função para encontrar o multiplicador de cada coluna na matriz, recebe como parametro o elemento e o pivot
double encontrarMultiplicador(double elemento, double pivot) {
    //EXEMPLO : multiplicador = ( (matrizInserida[1][0] * (- 1) ) / matrizInserida[0][0] );
    return ( (elemento ) / pivot );

}
//Função para zerar as linhas da matriz, recebe como parametro MATRIZ ORIGINAL, LINHA E COLUNAS, MULTIPLICADOR E A LINHA QUE IRA ZERAR
void ZerarLinha(double matrizInserida[][4], int linha, int coluna, double mult, int llinha)
{
    //Conta feita: L2 - (M * L1)

    int i = 0;
    double novosValores[4];

    //Criando um vetor com novos valores
    for(i = 0; i <= linha; i++) {

            novosValores[i] = matrizInserida[llinha][i]  - (mult  * matrizInserida[0][i]);
            printf("%.0lf ", novosValores[i]);

        }
        printf("\n");

        SalvaNovaMatriz(novosValores);

}
//Funcao para salvar os novos valores zerados da matriz ORIGINAL, recebe como parametro o endereço do vetor
void SalvaNovaMatriz(double * novoValores){

    static double Matriz[3][4];
    static int j = 0;
    int i;
    double multiplicador = 0;

    double y;
    double x;
    double z;

    for(i = 0; i < 4; i++)
    {
        Matriz[j][i] = novoValores[i];
    }
    j++;

    //Encontra o valor o valor da ultima linha e depois faz as contas para encontrar:  Z Y X
    if(j == 2)
    {

    multiplicador = encontrarMultiplicador(Matriz[1][1], Matriz[0][1]);
    printf("\nMULTIPLICADOR: %.0lf\n", multiplicador);
    ZerarLinha(Matriz, 2, 4, multiplicador, 1);

    printf("------------------------------------------------------------------------------------");
    z = matrizModoSimplex[2][2] / Matriz[2][2];
    printf("\nX:%.0f", z);

    //  = 12
    // = 8
    // = 32
    y = Matriz[0][2] * z;
    y = Matriz[0][3] + (y * (-1));
    y = y / Matriz[0][1];

    printf("\nY:%.0f", y);

    z = matrizModoSimplex[0][2] * z;
    y = matrizModoSimplex[0][1] * y;
    x = z + y;
    x = matrizModoSimplex[0][3] + (x * (-1));
    x = x / matrizModoSimplex[0][0];
    printf("\nZ:%.0f\n", x);

    printf("-------------------------------------------------------------------------------------");
    }

}

