PROBLEMA 1- TEXT HIGHLIGHT

    Rezolvarea primei probleme mi-a luat o zi.
    Am utilizat pentru implementarea acesteia doua functii:
        1. cautare() - functia principala a programului, ce are ca parametri
        linia in care se cauta un anumit cuvant, cuvantul, vectorul de indici,
        in care se retine pozitia cuvantului ce trebuie subliniat si
        numarul total de indici
        Avem 2 cazuri principale, cel in care cuvantul-cheie este alcatuit
    dintr-un singur cuvant si cel in care acesta contine 2 cuvinte separate
    prin spatii.
        Pentru primul caz, am cautat in sir aparitiile cuvantului, i-am retinut
    indicele de inceput si i-am gasit indicele de final. Am verificat apoi daca
    acesta nu face parte dintr-un alt cuvant, daca incepe sau se termina cu
    alte caractere. Daca acesta indeplineste conditiile, indicii lui sunt
    salvati in vector si se repeta cautarea in sir, de la finalul cuvantului
    gasit. Daca nu, atunci se gaseste finalul cuvantului si se cauta iarasi in
    sir, incepand de acolo.
        Pentru cuvintele-cheie alcatuie dintr-un singur cuvant, exista si
    posibilitatea ca acestea sa fi fost deja marcate ca parte a unui
    cuvant-cheie alcatuit din 2 cuvinte, ce il continea deja. De aceea, la
    inceput am verificat daca indicele de inceput al cuvantului se regasea deja
    in vectorul de indici.
        Pentru cel de-al doilea caz, am impartit secventa in 2 cuvinte. Am
    cautat mai intai primul cuvant, verificand ca nu face parte dintr-un alt
    cuvant si apoi, am verificat daca, dupa un numar indiferent de mare de
    spatii, cuvantul urmator era cel cautat. Daca da, indicele de inceput al
    primului cuvant si indicele de final al celui de-al doilea cuvant se
    salveaza in vectorul de indici. Daca cel de-al doilea cuvant face parte
    dintr-un alt cuvant, se trece peste acesta. Daca cel de-al doilea cuvant
    difera de cel cautat se incepe cautarea in sir, incepand cu indicele sau
    de inceput, deoarece acesta ar putea reprezenta primul cuvant al secventei
    cautate.
        2. sortare() - functie folosita pentru a sorta vectorul de indici

        In main, am alocat dinamic memorie pentru vectorul in care sunt
    retinute liniile introduse si pentru fiecare linie in parte.
        Am retinut cuvintele-cheie in matricea key si am folosit un vector
    indici[], pentru a retine in acesta indicii de inceput si indicii de final
    ai cuvintelor de subliniat.
        Am afisat fiecare linie si apoi, sublinierile corespunzatoare.
        Folosindu-ma de structuri repetitive, am cautat in fiecare linie,
    fiecare cuvant-cheie, retinut in matricea key, prin intermediul functiei
    cautare(). In variabila k am retinut numarul de indici gasiti. Dupa ce
    indicii au fost gasiti, am sortat vectorul de indici, cu ajutorul functiei
    sortare(), in ordine crescatoare.
        Daca nu au fost gasite cuvinte de subliniat, am afisat doar spatii.
        In caz contrar, folosindu-ma de 2 indici, j si k am afisat caracterul
    _, pentru pozitiile aflate intre perechile de indici din vector si spatii
    in rest.

PROBLEMA 2- AUTOCOMPLETE

    Rezolvarea celei de-a doua probleme mi-a luat cateva ore. 
    Am utilizat pentru implementarea acesteia trei functii:
        1. addword() - functie folosita pentru adaugarea unui cuvant nou in
        dictionar, dupa ce, anterior, s-a realocat memorie in main si numarul
        total de cuvinte, N, a fost incrementat
            Cuvantul este adaugat in v[n-1].word, iar prioritatea lui este
        initializata cu 1.

        2. specialsearchword() - functie folosita pentru a cauta in dictionar
        cuvintele care au fost introduse de catre utilizator, cu un caracter
        special, *, la final. 
            Difera de cealalta functie de cautare, intrucat,
        de aceasta data se cauta o potrivire exacta pentru a ne putem da semna
        daca acel cuvant a mai fost utilizat si adaugat in dictionar inainte
        sau apare pentru prima data, caz in care trebuie adaugat. Acest lucru
        se realizeaza prin intermediul parametrului found, care fie ia valoarea
        -1, daca nu a fost gasit cuvantul, fie cea a indicelui cuvantului
        identic din dictionar.

        3. searchword() - functie folosita pentru a cauta in dictionar
        cuvinte asemanatoare cu cele introduse de utilizator
            Se cauta toate cuvintele asemanatoare, care incep cu cuvantul
        respectiv, prin intermediul functiilor strstr si strlen. Apoi, se
        cauta printre optiuni, cuvintele cu prioritatea cea mai mare,
        indicele acestora fiind retinut in vectorul ind. In cazul in care avem
        mai multe optiuni, cu prioritate identica, acestea sunt alese in
        functie de ordinea lexicografica. Elementele gasite anterior, cu
        prioritate maxima, sunt comparate cu ajutorul functiei strcmp si a unei
        structuri repetitive, urmand ca la final, indicele optiunii cautate sa
        fie retinut in variabila found.
        
        In main, se aloca memorie pentru dictionar si componentele sale, iar
        apoi se citesc cuvintele si se initializeaza prioritatile cu 0. Pentru
        fiecare cuvant citit de la tastatura se verifica daca este un caracter
        special, caz in care acesta este doar afisat. Daca se citeste un cuvant
        urmat de caracterul *, acesta se afiseaza fara * si apoi se apeleaza
        functia specialsearchword(). Daca acesta este gasit, prioritatea lui
        creste, iar in caz contrar, se realoca memorie si se apeleaza functia
        addword(), pentru a adauga noul cuvant in dictionar. Daca se citeste un
        cuvant obisnuit, se apeleaza mai intai functia searchword(), pentru a
        gasi o potrivire cat mai exacta. In cazul in care se gaseste o optiune,
        prioritatea acesteia creste si este afisata. Daca nu, se realoca memorie
        si cuvantul este adaugat in dictionar si afisat.

PROBLEMA 3- CALCULATOR PE BITI

    Rezolvarea celei de-a treia probleme mi-a luat cateva ore.
    Am utilizat pentru implementarea acesteia patru functii, retinute intr-un
    vector de pointeri, p, care primesc ca parametri doi vectori in care
    am retinut cele doua numere:
        1. adunare() 
            Se aduna bit cu bit, fiecare numar, iar in cazul in care, in urma
        adunarii rezultatul obtinut este mai mare, am utilizat variabila j
        pentru a fi adaugata la adunarea urmatorilor 2 biti.
        2. interschimbare() 
            Am calculat mai intai cele 2 pozitii, trecand in baza 10 numerele
        formate din primii, respectiv ultimii 2 biti ai celui de-al doilea numar.
        Apoi, am efectuat interschimbarea.
        3. rotatielastanga() 
            Am adus cel de-al doilea numar inapoi in baza 2, pentru a gasi
        numarul necesar de rotatii la stanga. Apoi in functie de numarul gasit,
        am folosit o structura repetitiva pentru a roti primul numar, fiecare
        bit din numar, mutandu-se cu o pozitie la stanga.
        4. fxor()
            Pentru fiecare bit al celor 2 numere am aplicat operatia xor, fara
        a folosi operatorul xor. Astfel, se compara valorile bitilor cu 0 si 1
        si cu ajutorul tabelului de adevar, specific operatiei xor, se
        calculeaza rezultatul.
        
        In main, am retinut intr-un vector bitii rezultati in urma
    transformarii numarului citit in baza 2, in ordine inversa. 
        In cazul in care numarul de operatii este 0, se aduce in baza 10 si
    apoi se afiseaza numarul format din cei mai semnificativi N*6+4 biti,
    adica 4. Acestia sunt, de fapt primele 4 elemente din vector, intrucat,
    am salvat cifrele in vector in ordine inversa. 
        In cazul in care trebuie sa se efectueze mai multe operatii, se extrag,
    daca este necesar, cei N*6+4 biti si apoi se imparte vectorul in numere si
    operatii. Initial avem nevoie de 2 numere din vector, reprezentate pe 4
    biti, urmand ca mai apoi sa aplicam operatiile asupra rezultatului obtinut
    din operatiile anterioare si a unui singur numar alcatuit din elementele
    vectorului. Se citesc si bitii prin care se codifica operatiile, iar in
    functie de acestia, se decide ce functie trebuie apelata, conform tabelului
    din cerinta. La final rezultatul obtinut este transformat in baza 10 si
    afisat.


PROBLEMA 4 - WORDLE

    Rezolvarea celei de-a treia probleme mi-a luat o zi.
    Am utilizat pentru implementarea acesteia cinci functii:
        1. get_menu() - functia care afiseaza meniul
            Utilizatorul poate alege intre 2 variante, care pot fi selectate
        prin intermediul tastelor KEY_UP si KEY_DOWN si care, o data selectate
        sunt evidentiate. Decizia este luata o data cu apasarea tastei enter.
            In functie de optiunea selectata, parametrul play indica daca 
        utilizatorul doreste sa joace in continuare sau sa iasa din joc.

        2. pick_a_word() - functie care alege un cuvant aleatoriu, din lista
        declarata in main, cuvant care va trebui sa fie ghicit

        3. table()- functie care creeaza tabla de joc, formata din 6 randuri de
        cate 5 casute, toate inconjurate de o margine, pentru a fi vizibile

        4. add_word()- functie pentru adaugarea cuvintelor pe tabla de joc
            Sirul introdus de utilizator este salvat in sirul cuv si alcatuit
        litera cu litera. Toate literele introduse de utilizator sunt
        transformate in litere mari, astfel incat acesta poate folosi orice tip
        de litere. Cat timp nu este apasata tasta enter, sunt adaugate litere
        in sir, iar daca este apasata tasta backspace, acestea sunt inlocuie
        cu spatii, iar lungimea sirului scade, astfel incat sa i se pastreze
        lungimea corespunzatoare.
            Pe masura ce este format, cuvantul este afisat deasupra casetelor,
        astfel incat utilizatorul sa-l poata vedea si modifica mai usor. Daca
        dupa introducerea cuvantului se constata ca acesta nu are numarul
        corect de litere, se afiseaza un mesaj care semnaleaza acest lucru.
        Dupa apasarea tastei enter, utilizatorul are posibilitatea de a
        introduce un nou cuvant.
            Daca cuvantul este corect, atunci el este introdus in ferestre,
        fiecare litera fiind colorata corespunzator. 
            Se retine, de asemenea, numarul de incercari necesare pentru
        ghicirea cuvantului.

        4. wordle()
            Se alege cuvantul ce trebuie ghicit si se afiseaza tabla de joc.
        Utilizatorul introduce, apoi, cuvinte, pana la ghicirea celui ales
        initial sau pana isi epuizeaza numrul de incercari.
            La final, doua variabile indica daca a fost gasit cuvantul si
        numarul de incercari.

        In main, jocul incepe o data cu apasarea tastei enter. Variabila play
    ia valoarea 1, cat timp jocul se desfasoara si devine 0, atunci cand
    utilizatorul doreste sa paraseasca jocul. Fie ca utilizatorul pierde sau
    castiga, acesta poate deschide meniul pentru a alege daca mai joaca un joc
    sau iese din acesta.
    