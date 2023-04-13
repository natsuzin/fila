#include <iostream>
#include <time.h>
#include "FilaEstaticaGenerica.h"

using namespace std;

int main()
{
    FilaEstaticaGenerica<int, 100> filaCinema;

    int i, j, numeroDePessoas, pessoasQueVieramAssistirOFilme;

    srand(time(NULL));

    cria(filaCinema);

    for (i = 1; i <= 12; i++)
        insere(filaCinema, 1);

    pessoasQueVieramAssistirOFilme = 12;

    for (i = 1; i <= 45 * 60; i++)
    {
        if (i % 60 == 0)
        {
            numeroDePessoas = rand()%3 + 2;
            pessoasQueVieramAssistirOFilme += numeroDePessoas;

            for (j = 1; j <= numeroDePessoas; j++)
                insere(filaCinema, 1);
        }
        if (i % 30 == 0)
            if (!ehVazia(filaCinema))
                retira(filaCinema);
    }

    cout << "pessoas que vieram assistir o filme = " << pessoasQueVieramAssistirOFilme <<
         "\nquantidade de pessoas na fila quando o filme comecou = " <<
         numeroDeElementos(filaCinema);

    return 0;
}
