#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// reprezentarea cuvintelor
struct dictionary_entry
{
    char *word;
    int priority;
};
// functie pentru adaugarea unui cuvant
void addword(int n, char *c, struct dictionary_entry *v)
{
    // cuvantul nou este adaugat in  dictionar, iar prioritatea lui devine 1
    strcpy(v[n - 1].word, c);
    v[n - 1].priority = 1;
}
// functie pentru cautarea cuvintelor care se termina in *
void specialsearchword(int n, char *c, struct dictionary_entry *v, int *found)
{
    int i;
    // am folosit parametrul found pentru a verifica daca exista deja in
    // dictionar cuvantul
    // initial found ia valoarea -1, urmand ca, in cazul in care in
    // dictionar exista un cuvant identic cu cel primit prin intermediul
    // parametrului c, acesta sa ia valoarea indicelui aparitiei acelui
    // cuvant
    *(found) = -1;
    for (i = 0; i < n; i++)
    {
        if (strcmp(v[i].word, c) == 0)
        {
            *(found) = i;
            break;
        }
    }
}
// functie pentru cautarea cuvintelor
void searchword(int n, char *c, struct dictionary_entry *v, int *found)
{
    int i, maxpriority, ind[10000], k = 0;
    char aux[22];
    *(found) = -1;
    for (i = 0; i < n; i++)
    {
        // se cauta aparitiile cuvantului transmis prin parametrul c, in
        // fiecare cuvant deja aflat in dictionar si se verifica, prin
        // intermediul celei de-a doua conditii daca, cuvintele gasite in
        // dictionar incep cu cuvantul cautat
        if (strstr(v[i].word, c) && strlen(v[i].word) ==
                                        strlen(strstr(v[i].word, c)))
        {
            // in cazul in care se gaseste o prima asemanare, variabila
            // maxpriority ia valoarea prioritatii cuvantului cu care s-a
            // facut potrivirea
            // in vectorul ind se retin indicii din dictionar ai cuvintelor
            // care se potrivesc cu cuvantul cautat si care au o la acel moment
            // prioritatea maxima
            if (*(found) == -1)
            {
                *(found) = i;
                maxpriority = v[i].priority;
                ind[k] = i;
                k++;
            }
            // cazul in care au fost deja gasite posibile optiuni pentru
            // autocomplete
            else
            {
                // cazul in care noua optiune are prioritatea egala cu
                // actuala prioritate maxima
                // indicele cuvantului gasit este adaugat in vector
                if (v[i].priority == maxpriority)
                {
                    *(found) = i;
                    ind[k] = i;
                    k++;
                }
                // daca se gaseste o optiune cu prioritatea mai mare, se
                // actualizeaza prioritatea maxima si vectorul de indici
                // cum, in continuare am folosit doar elementele de la 0 la
                // k-1, am suprascris elementele vectorului
                if (v[i].priority > maxpriority)
                {
                    *(found) = i;
                    maxpriority = v[i].priority;
                    k = 0;
                    ind[k] = i;
                    k++;
                }
            }
        }
    }
    // am verificat daca s-au gasit mai multe optiuni cu prioritati egale, caz
    // in care potrivirea se face in functie de ordinea lexicografica
    if (k > 1)
    {
        // am initializat variabilele in care voi retine cuvantul ales si
        // indicele sau
        // astfel, la final aux va contine cuvantul cel mai mic
        strcpy(aux, v[ind[0]].word);
        *(found) = ind[0];
        for (i = 1; i < k; i++)
        {
            // daca se gaseste un cuvant mai mic decat cel deja retinut in aux
            // acesta este copiat in vector, iar found retine indicele acestuia
            if (strcmp(v[ind[i]].word, aux) < 0)
            {
                strcpy(aux, v[ind[i]].word);
                *(found) = ind[i];
            }
        }
    }
}

int main()
{
    int N, M, i, found;
    char s[22], cuv[22];
    scanf("%d", &N);
    // alocarea memoriei pentru vectorul de structuri
    struct dictionary_entry *v = (struct dictionary_entry *)
        malloc((N + 1) * sizeof(struct dictionary_entry));
    getchar();
    for (i = 0; i < N; i++)
    {
        // se citesc cuvintele si prioritatile si se aloca memorie pentru ele
        scanf("%s", s);
        v[i].word = malloc(sizeof(char) * (strlen(s) + 2));
        strcpy(v[i].word, s);
        v[i].priority = 0;
        getchar();
    }
    scanf("%d", &M);
    getchar();
    for (i = 0; i < M; i++)
    {
        scanf("%s", cuv);
        // conditie care asigura faptul ca se afiseaza corect caracterele
        if (strcmp(cuv, ",") == 0 || strcmp(cuv, ".") == 0 ||
            strcmp(cuv, ":") == 0 || strcmp(cuv, "!") == 0 ||
            strcmp(cuv, "?") == 0)
        {
            printf("%s ", cuv);
        }
        else
        {
            // cazul in care cuvantul se termina in *
            if (cuv[strlen(cuv) - 1] == '*')
            {
                // am eliminat caracterul * si am afisat cuvantul
                cuv[strlen(cuv) - 1] = '\0';
                printf("%s ", cuv);
                specialsearchword(N, cuv, v, &found);
                // daca s-a gasit deja cuvantul in dictionar, prioritatea lui
                // creste
                if (found >= 0)
                {
                    v[found].priority++;
                }
                // daca nu, atunci se realoca memorie si cuvantul este adauugat
                // in dictionar
                else
                {
                    N++;
                    v = realloc(v, (N + 1) * sizeof(struct dictionary_entry));
                    v[N - 1].word = malloc(sizeof(char) * (strlen(cuv) + 1));
                    addword(N, cuv, v);
                }
            }
            // cazul in care cuvantul nu se termina in *
            else
            {
                searchword(N, cuv, v, &found);
                // daca s-a gasit deja cuvantul in dictionar, prioritatea lui
                // creste si este afisat
                if (found >= 0)
                {
                    printf("%s ", v[found].word);
                    v[found].priority++;
                }
                // daca nu, atunci se realoca memorie si cuvantul este adaugat
                // in dictionar, iar mai apoi este afisat
                else
                {
                    N++;
                    v = realloc(v, (N + 1) * sizeof(struct dictionary_entry));
                    v[N - 1].word = malloc(sizeof(char) * (strlen(cuv) + 1));
                    addword(N, cuv, v);
                    printf("%s ", cuv);
                }
            }
        }
        getchar();
    }
    for (i = 0; i < N; i++)
    {
        free(v[i].word);
    }
    free(v);
    return 0;
}
