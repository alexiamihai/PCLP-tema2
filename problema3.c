#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void (*p)(int[], int[]);
// functia de adunare
void adunare(int v1[], int v2[])
{
    int i, j = 0;
    // se incepe de la ultimul bit si se aduna bit cu bit
    // in j se retine cat mai trebuie adaugat in urmatorul pas al adunarii,
    // pentru ca aceasta sa fie corecta
    for (i = 3; i >= 0; i--)
    {
        v1[i] = v1[i] + v2[i] + j;
        if (v1[i] == 1)
        {
            j = 0;
        }
        // cazul in care prin adunare se obtine o valoare impara, diferita de 1
        else if (v1[i] % 2 == 1)
        {
            v1[i] = 1;
            j = 1;
        }
        // cazul in care prin adunare se obtine o valoare para, diferita de 0
        else if (v1[i] % 2 == 0 && v1[i] != 0)
        {
            v1[i] = 0;
            j = 1;
        }
    }
}
// functia de interschimbare
void interschimbare(int v1[], int v2[])
{
    int p1, p2, aux;
    // se calculeaza cele 2 pozitii, trecandu-se in baza 10 numerele formate
    // din primii 2 biti, respectiv ultimii 2 biti ai celui de-al doilea numar
    p1 = v2[0] * 2 + v2[1];
    p2 = v2[2] * 2 + v2[3];
    // se interschimba bitii din primul numar care se afla pe pozitiile
    // calculate anterior
    aux = v1[p1];
    v1[p1] = v1[p2];
    v1[p2] = aux;
}
void rotatielastanga(int v1[], int v2[])
{
    int aux, i, j, p = 8, nr = 0;
    // cel de-al doilea numar se transforma din baza 10 in baza 2
    for (i = 0; i < 4; i++)
    {
        if (v2[i] == 1)
        {
            nr = nr + p;
        }
        p = p / 2;
    }
    // numarul se roteste de un numar de ori egal cu valoarea retinuta in
    // variabila nr
    for (i = 0; i < nr; i++)
    {
        // fiecare bit se muta in stanga
        aux = v1[0];
        for (j = 0; j < 3; j++)
        {
            v1[j] = v1[j + 1];
        }
        v1[3] = aux;
    }
}
// functia xor
void fxor(int v1[], int v2[])
{
    int i;
    // pentru fiecare bit se efectueaza operatia xor, conform tabelului
    // de adevar corespunzator
    for (i = 0; i < 4; i++)
    {
        if (v1[i] == 0)
        {
            if (v2[i] == 0)
            {
                v1[i] = 0;
            }
            else
            {
                v1[i] = 1;
            }
        }
        else
        {
            if (v2[i] == 0)
            {
                v1[i] = 1;
            }
            else
            {
                v1[i] = 0;
            }
        }
    }
}
int main()
{
    int N, i = 0, j, b[100], n1[4], n2[4], k, op1, op2, nr;
    unsigned int M;
    // vectorul de pointeri la functii
    p v[] = {adunare, interschimbare, rotatielastanga, fxor};
    scanf("%d", &N);
    getchar();
    scanf("%u", &M);
    // in vectorul b se retin, in ordine inversa cifrele rezultate in urma
    // transformarii numarului citit de la tastatura in baza 2
    while (M > 0)
    {
        b[i] = M % 2;
        M = M / 2;
        i++;
    }
    // cazul in care avem de efectuat operatii
    if (N > 0)
    {
        // daca numarul se reprezinta pe mai mult de N*6+4 biti in baza 2,
        // extragem doar cei N*6+4 biti
        if (i > N * 6 + 4)
        {
            i = N * 6 + 4;
        }
        // incepand cu ultimul element din vector, care este de fapt primul
        // bit din reprezentarea numarului, construim numerele si operatiile
        j = i - 1;
        while (j > 0)
        {
            // la inceput, avem nevoie de 2 numere n1 si n2 pentru a efectua
            // operatiile, urmand ca mai apoi sa ne folosim de rezultatul
            // obtinut in urma operatiilor si de un singur numar pe care il vom
            // construi cu elementele din vector
            if (j == i - 1)
            {
                k = 0;
                while (k < 4)
                {
                    n1[k] = b[j];
                    k++;
                    j--;
                }
            }
            // in op1 si op2 sunt retinuti cei 2 biti folositi pentru
            // codificarea operatiei
            op1 = b[j--];
            op2 = b[j--];
            k = 0;
            // se construieste cel de-al doilea numar
            while (k != 4)
            {
                n2[k] = b[j];
                k++;
                j--;
            }
            // in functie de op1 si op2 se decide ce operatie trebuie aplicata
            if (op1 == 0 && op2 == 0)
            {
                v[0](n1, n2);
                // se aplica adunarea
            }
            if (op1 == 0 && op2 == 1)
            {
                v[1](n1, n2);
                // se aplica interschimbarea
            }
            if (op1 == 1 && op2 == 0)
            {
                v[2](n1, n2);
                // se aplica rotatia la stanga
            }
            if (op1 == 1 && op2 == 1)
            {
                v[3](n1, n2);
                // se aplica xor
            }
        }
        // la final rezultatul obtinut este adus in baza 10 si afisat
        k = 8;
        nr = 0;
        for (i = 0; i < 4; i++)
        {
            if (n1[i] == 1)
            {
                nr = nr + k * 1;
            }
            k = k / 2;
        }
        printf("%d", nr);
    }
    // daca nu avem de efectuat operatii, se calculeaza numarul in baza 10
    // format din cei mai importanti N*6+4 biti, adica primii 4, avand in
    // vedere ca am salvat cifrele in vector in ordine inversa
    if (N == 0)
    {
        nr = 0;
        k = 1;
        for (i = 0; i < 4; i++)
        {
            nr = nr + b[i] * k;
            k = k * 2;
        }
        printf("%d", nr);
    }
    return 0;
}
