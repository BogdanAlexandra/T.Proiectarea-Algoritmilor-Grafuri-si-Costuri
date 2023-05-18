# Tema 2 
## - Proiectrarea algoritmilor -

   > STUDENT: Bogdan Alexandra-Lăcrămioara

   > GRUPA: 325CD

**Rezolvarea problemelor**

   > **Problema 1**
   
 În rezolvarea acestei probleme am ales să folosesc un algoritm care verifică dacă există un ciclu într-un graf orientat folosind o parcurgere DFS (depth-first search) și un vector de stări pentru a marca nodurile vizitate în timpul parcurgerii. 
 Algoritmul începe prin a marca nodul u ca fiind vizitat și parcurge toți vecinii săi v. Pentru fiecare vecin, verifică dacă acesta a fost deja vizitat și dacă există o muchie orientată de la u la v în graf.
 Cazuri posibile:
        * Dacă v a fost deja vizitat în acest DFS (starea sa este 1), atunci am găsit un nod vizitat anterior în parcurgere, ceea ce înseamnă că există un ciclu în graf. Algoritmul întoarce true.
        * Dacă v nu a fost vizitat încă (starea sa este 0), atunci se continuă parcurgerea DFS pentru acest nod. Dacă se găsește un ciclu în subgraful care poate fi atins pornind de la v, atunci algoritmul întoarce true.
        * Dacă v a fost deja vizitat și a fost complet parcurs într-un DFS anterior (starea sa este 2), atunci nu mai avem nevoie să continuăm parcurgerea pentru acest nod, deoarece acesta nu poate duce la descoperirea unui ciclu nou. Algoritmul continuă cu următorul vecin al lui u.
După ce am terminat parcurgerea pentru toți vecinii lui u, nodul u este marcat ca fiind complet vizitat (starea sa este 2). Algoritmul întoarce false, ceea ce înseamnă că nu am găsit un ciclu în subgraful care poate fi atins pornind de la u.

   > **Problema 2**
   
   În ceea ce privește problema 2 am ales ca și algoritm pentru rezolvarea ei, algoritmul de sortare topologică, deoarece ne este precizat că graful este aciclic.
   uncția topologicalSort primește un nod de pornire, o listă de noduri vizitate și o listă de noduri sortate. Începând cu nodul de pornire, se parcurg toți vecinii săi nevizitați și se aplică recursiv aceeași logică. La final, nodul de pornire este adăugat la începutul listei sortate. Funcția shortestPath primește un nod de pornire și utilizează funcția topologicalSort pentru a obține lista sortată a nodurilor grafului. Se inițializează distanțele de la nodul de pornire către toate celelalte noduri cu o valoare infinită. Apoi, pentru fiecare nod din lista sortată, se parcurg toți vecinii și se actualizează distanța minimă de la nodul de pornire către vecin, dacă aceasta este mai mică decât distanța curentă stocată în vectorul distances. În final, vectorul distances conține distanțele minime de la nodul de pornire către toate celelalte noduri din graf.
   
   > **Problema 3**
   
   Pentru rezolvarea acestei probleme, am ales ca algorim de rezolvare, algoritmul A*, care ne-a fost prezentat conceptual în cadrul ultimului laborator.
   Algoritmul începe cu un nod de start și se extinde succesiv prin adăugarea nodurilor cele mai apropiate de nodul curent. Costul de a ajunge la un nod este măsurat prin suma distanței de la nodul de start până la nodul curent și o estimare a distanței până la nodul țintă (calculată cu ajutorul funcției heuristic).
    În implementarea mea am utilizat o coadă de priorități pentru a alege nodul cel mai apropiat de nodul de start. Nodurile sunt ordonate în coadă în funcție de costul estimat de a ajunge la nodul țintă, dat de suma costului real și a costului euristic. La fiecare iterație, este luat nodul cu cel mai mic cost estimat din coadă, apoi este extins nodul prin evaluarea tuturor succesorilor acestuia. Costurile reale pentru fiecare succesor sunt calculate prin adăugarea costului de a ajunge la succesor de la nodul curent și costul de a ajunge la nodul curent din nodul de start. Costul euristic se calculează apoi pentru a estima costul de a ajunge la nodul țintă din succesor.
   

**Reguli de rulare**
* make -f Makefile- compilează sursele
* make run-X - rulează problema cu numărul X (1,2,3) pentru toate testele din pbX_test si afiseaza "Ok" daca output-urile corespund sau "Bad" in caz contrar.
* make clean
* make run - ruleaza toate cele 3 probleme 

**Conținut arhivă**

* pbX_tests - directoarele care conțin fișierele de test primite în cadrul temei (X = 1,2,3)
* pbX_tests_out - directoarele care conțin fișierele de output pentru fiecare problemă (X = 1,2,3), care sunt comparate cu fișierele de ouptut care sunt așteptate (_.out) din directoarele pbX_tests
* 1.cpp - rezolvarea problemei 1
* 2.cpp - rezolvarea problemei 2
* 3.cpp - rezolvarea problemei 3
* Makefile
* README.md

În cazul în care doriți să testati pentru alte teste, trebuie să schimbați doar input_file , output_file și expected_output_file din fiecare fișier care conține codul pentru fiecare problemă (1.cpp, 2.cpp, 3.cpp).

**Bibliografie**
* https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-09
* https://ocw.cs.pub.ro/courses/pa/tutoriale/astar
* https://www.simplilearn.com/tutorials/artificial-intelligence-tutorial/* a-star-algorithm
* https://towardsdatascience.com/a-star-a-search-algorithm-eb495fb156bb
* https://www.geeksforgeeks.org/cpp-program-to-compare-paths-of-two-files/
* https://www.geeksforgeeks.org/compare-two-files-line-by-line-in-python/


