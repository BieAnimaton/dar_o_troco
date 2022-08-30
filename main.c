/* Problema:
Encontrar a menor quantidade de moedas para o troco de uma transação comercial
Condições: Não há limite para a quantidade de moedas dispoíveis
*/

#include <stdio.h>
#define TAM 100

int valores_moedas [TAM];
int quant_moedas [TAM];

/* ================================================= Ordenacao */
int ordem (int tamanho)
{
    int x, y, troca;
    for (x = tamanho; x >= 1; x--)   /* define a posicao de teto */
    {
        for (y = 1; y < x; y++)
        {
            if (valores_moedas[y] > valores_moedas[y+1])
            {
                troca = valores_moedas[y];
                valores_moedas[y] = valores_moedas[y + 1];
                valores_moedas[y + 1] = troca;
            }
        }
    }
}
/* ================================================================ */

Inicializar (int m)
{
    int i;
    for (i = 1; i <= m; i++)
       quant_moedas[i] = 0;
}

void main()
{
    int v_desejado, m, resto, i, moeda_selecionada;

    printf("Valor de troco: ");
    scanf("%d", &v_desejado);

    printf("Quantidade de tipos de moedas: ");
    scanf("%d", &m);

    Inicializar (m);
    for (i = 1; i <= m; i++)
    {
        printf("Valor de moeda: ");
        scanf("%d", &valores_moedas[i]);
    }

    /* Ordenação crescente para os valores dos tipos de moedas */
    ordem (m);

    resto = v_desejado;
    moeda_selecionada = m;   /* começa pela moeda de maior valor */

    while ((resto != 0) && (moeda_selecionada != 0)) { // se resto e moeda_selec. tiverem conteúdo
        if (resto >= valores_moedas[moeda_selecionada]) { // se 467 for maior ou igual a 100
            quant_moedas[moeda_selecionada]++; // quantidade de uso da moeda 100 aumenta 1
            resto = resto - valores_moedas[moeda_selecionada]; // tira 100 de 467, resultando 367
                                                               // repete ciclo até ser < q 100
        }
        else
            moeda_selecionada--; // como 67 é menor q 100, o tipo da moeda abaixa,
                                 // ou seja, agr é 50 e ciclo repete
    }

    /* mostrar resultado */
    if (resto != 0)
        printf("\n\nTroco nao possivel\n");
    else{
        printf("\nTipos de moedas -----------\n");
        for (i = 1; i <= m; i++)
        {
            printf("%d ", valores_moedas[i]); // imprime moedas inseridas
        }

        printf("\nTroco realizado -----------\n");
        for (i = 1; i <= m; i++)
        {
            printf("%d ", quant_moedas[i]);// imprime a quantidades q foi usada de cada moeda
        }
    }
}
