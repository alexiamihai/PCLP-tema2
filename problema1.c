#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// functia de cautare
void cautare(char *v, char *s, int in[], int *k)
{
    int i, ok = 0, ok2, ind, ind2, nr, l;
    char t[102], q[102], p[102], *aux;
    nr = (*k);
    // nr va contine la final numarul de indici gasiti, adica dublul
    // numarului de cuvinte identificate
    // se verifica daca secventa cautata contine spatii, caz in care variabila
    // ok ia valoarea 0
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            ok = 1;
            break;
        }
    }
    // linia in care se cauta este copiata in t
    strcpy(t, v);
    // cazul in care secventa nu contine spatii
    if (ok == 0)
    {
        // se cauta aparitiile cuvantului in sir
        while (strstr(t, s))
        {
            // in variabila ind se retine pozitia aparitiei cuvantului in sir
            ind = strlen(v) - strlen(strstr(t, s));
            // se verifica daca acelasi cuvant a fost gasit anterior,
            // cautandu-i indicele de inceput in vectorul de indici
            // deoarece printre cuvintele cheie se gasesc secvente care contin
            // aceleasi cuvinte si care ar putea fi recunoscute de 2 ori
            ok2 = 0;
            for (i = 0; i <= nr; i++)
            {
                if (in[i] == ind)
                {
                    ok2 = 1;
                }
            }
            // cazul in care cuvantul nu a mai fost recunoscut
            if (ok2 == 0)
            {
                // se verifica daca indicele marcheaza inceputul unui cuvant
                if (ind == 0 || v[ind - 1] == ' ')
                {
                    // se verifica apoi daca secventa descoperita se termina
                    // cu spatiu sau cu terminatorul de sir, pentru a se
                    // asigura faptul ca am gasit cuvantul cautat
                    if (((strstr(t, s) + strlen(s))[0] == ' ' ||
                         (strstr(t, s) + strlen(s))[0] == '\0'))
                    {
                        // daca toate conditiile sunt indeplinite, se retin
                        // in vectorul in, indicii de inceput si de sfarsit ai
                        // cuvantului
                        in[nr++] = ind;
                        in[nr++] = ind + strlen(s) - 1;
                        strcpy(t, strstr(t, s) + strlen(s));
                    }
                    // daca cuvantul descoperit nu este un cuvant de
                    //sine-statator, ci se afla in interiorul altui
                    //cuvant, se trece peste acesta
                    else
                    {
                        ind = strlen(t) - strlen(strstr(t, s));
                        while (t[ind] >= 'a' && t[ind] <= 'z')
                        {
                            ind++;
                        }
                        strcpy(t, t + ind);
                    }
                }
                // daca cuvantul descoperit nu este un cuvant de sine-statator,
                // ci se afla in interiorul altui cuvant, se trece peste acesta
                else
                {
                    while (v[ind] >= 'a' && v[ind] <= 'z')
                    {
                        ind++;
                    }
                    strcpy(t, v + ind);
                }
            }
            // cazul in care cuvantul a fost recunoscut anterior
            // se trece peste acesta si se copiaza in t sirul care incepe
            // imediat dupa finalul cuvantului
            else
            {
                while (v[ind] >= 'a' && v[ind] <= 'z')
                {
                    ind++;
                }
                strcpy(t, v + ind);
            }
        }
    }
    // cazul in care secventa contine spatii
    else
    {
        // am despartit secventele ce contineau cate un spatiu in 2 cuvinte
        // separate, retinute in aux si q
        strcpy(p, s);
        strcpy(q, strchr(p, ' ') + 1);
        strcat(p, "NULL");
        aux = strtok(p, " ");
        // se cauta aparitiile primului cuvant in sir
        while (strstr(t, aux))
        {
            // in variabila ind se retine pozitia aparitiei cuvantului in sir
            ind = strlen(v) - strlen(strstr(t, p));
            // se verifica daca este un cuvant de sine-statator sau parte
            // din alt cuvant
            if (ind == 0 || v[ind - 1] == ' ')
            {
                // se retine indicele de final al cuvantului si se cauta cea
                // de-a doua parte a secventei
                ind2 = ind + strlen(p);
                while (v[ind2] == ' ')
                {
                    ind2++;
                }
                int ok1 = 0;
                // se verifica daca urmatoarele caractere gasite de dupa spatii
                // apartin celui de-al doilea cuvant
                for (i = 0; i < strlen(q); i++)
                {
                    if (q[i] != v[ind2 + i])
                    {
                        ok1 = 1;
                    }
                }
                // se verifica daca s-a ajuns la finalul secventei si ca nu
                // exista si alte caractere dupa finalul cuvantului
                if (ok1 == 0 && (v[ind2 + i] == ' ' || v[ind2 + i] == '\0'))
                {
                    // daca se respecta toate conditiile, indicii cuvantului
                    // sunt retinuti in vector si se trece peste secventa
                    // gasita
                    ind2 = ind2 + i;
                    in[nr++] = ind;
                    in[nr++] = ind2 - 1;
                    strcpy(t, t + ind2);
                }
                else
                {
                    // daca caracterele gasite nu au corespuns cuvantului
                    // cautat, sirul se actualizeaza, devenind cel de dupa
                    // sfarsitul primului cuvant, in cazul in care cel de-al
                    // doilea cuvant ar putea reprezenta inceputul unei noi
                    // secvente
                    if (ok1 == 1)
                    {
                        strcpy(t, t + ind2 - 1);
                    }
                    // daca cel de-al doilea cuvant gasit nu este de
                    // sine-statator, noul sir in care se cauta, incepe cu
                    // finalul celui de-al doilea cuvant
                    else if (v[ind2 + i] != ' ' && v[ind2 + i] != '\0')
                    {
                        l = ind2;
                        while (v[l] >= 'a' && v[l] <= 'z')
                        {
                            l++;
                        }
                        strcpy(t, v + l);
                    }
                }
            }
            // daca nu este cuvant de sine-statator, se trece peste el
            else
            {
                while (v[ind] >= 'a' && v[ind] <= 'z')
                {
                    ind++;
                }
                strcpy(t, v + ind);
            }
        }
    }
    // la final, k ia valoarea numarului de indici gasiti
    (*k) = nr;
}
// functia de sortare, care asigura faptul ca perechile de indici
// corespunzatoare cuvintelor care trebuie subliniate sunt
// ordonate crescator
void sortare(int v[], int k)
{
    int i, j, aux;
    for (i = 0; i < k - 1; i++)
    {
        for (j = i + 1; j < k; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main()
{
    int N, i, j, indici[102], k, x, t;
    char **v, key[15][100], s[102];
    j = 0;
    // in matricea key se retin cuvintele cheie, care trebuie cautate in text
    strcpy(key[j++], "first of");
    strcpy(key[j++], "for each");
    strcpy(key[j++], "for");
    strcpy(key[j++], "from");
    strcpy(key[j++], "in");
    strcpy(key[j++], "is a");
    strcpy(key[j++], "is");
    strcpy(key[j++], "list of");
    strcpy(key[j++], "unit");
    strcpy(key[j++], "or");
    strcpy(key[j++], "while");
    strcpy(key[j++], "int");
    strcpy(key[j++], "float");
    strcpy(key[j++], "double");
    strcpy(key[j++], "string");
    scanf("%d", &N);
    getchar();
    // alocare dinamica pentru vectorul in care se retin liniile de text
    v = (char **)malloc(N * sizeof(char *));
    // textul se citeste linie cu linie, alocandu-se memorie pentru fiecare
    // linie
    // am citit mai intai linia in sirul s pentru a aloca exact cata memorie
    // este necesara pentru linie, in functie de lungimea sirului citit
    for (i = 0; i < N; i++)
    {
        fgets(s, 102, stdin);
        v[i] = (char *)malloc((strlen(s)) * sizeof(char));
        s[strlen(s) - 1] = '\0';
        strcpy(v[i], s);
    }
    for (i = 0; i < N; i++)
    {
        // am initializat fiecare element al vectorului indici, in care am
        // retinut indicii de inceput si indicii de final ai cuvintelor de
        // subliniat, cu -1
        for (j = 0; j < 102; j++)
        {
            indici[j] = -1;
        }
        k = 0;
        // mai intai se afiseaza linia si apoi o noua linie cu sublinierile
        // corespunzatoare
        printf("%s\n", v[i]);
        for (j = 0; j < 15; j++)
        {
            // se cauta, in fiecare linie, aparitiile tuturor cuvintelor
            // retinute in key
            // in parametrul k se va retine numarul de indici gasiti, adica
            // dublul numarului total de cuvinte identificate in text
            cautare(v[i], key[j], indici, &k);
        }
        // indicii cuvintelor descoperite sunt sortati in ordine crescatoare
        // pentru a usura sublinierea lor si pentru a se pastra perechile
        sortare(indici, k);
        // cazul in care s-au gasit cuvinte si k este diferit de 0
        if (k != 0)
        {
            // se porneste cu indicele j, pentru a parcurge intreaga linie
            // anterior citita si cu indicele x, pentru a parcurge vectorul
            // de indici
            j = 0;
            x = 0;
            while (j < strlen(v[i]))
            {
                // cat timp acesta nu este indicele de inceput al unui cuvant,
                // se afiseaza doar spatii
                if (j != indici[x])
                {
                    printf(" ");
                }
                // daca j este indicele de inceput al unui cuvant, de la
                // acesta si pana la indicele de sfarsit al cuvantului se
                // afiseaza _
                // apoi j devine indicele de dupa indicele de final al
                // cuvantului anterior subliniat, iar x creste, trecandu-se
                // la urmatoarea pereche de indici
                else
                {
                    for (t = indici[x]; t <= indici[x + 1]; t++)
                    {
                        printf("_");
                    }
                    j = indici[x + 1];
                    x = x + 2;
                }
                j++;
            }
            printf("\n");
        }
        // daca nu s-au gasit cuvinte, se afiseaza doar spatii
        else
        {
            for (j = 0; j < strlen(v[i]); j++)
            {
                printf(" ");
            }
            printf("\n");
        }
    }
    free(v);
    return 0;
}
