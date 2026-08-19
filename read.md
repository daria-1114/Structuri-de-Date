# Structuri de date
# 1. Liste inlantuite simple
- structura de date de baza
- `nod={data, next}`; <br>
data = tipul de date a listei;<br>
next= pointer catre urmatorul nod(adresa de memorie) 
- memorie alocata dinamic **(Heap)**
- se acceseaza printr-un pointer catre primul nod (**HEAD**)
- ultimul nod (next=0) se numeste **TAIL**
### Travesare
 - se face printr-un pointer catre primul nod **HEAD**, pana cand next = null
 - **O(n)**
 ### Inserare si stergere
 - la inceput: O(1)
 - la o pozitie data/sfarsit: O(n) pentru parcurgerea listei;O(1) pentru inserare; 
 ### Cautare
 -O(n) pentru traversarea listei si cautarea pozitiei; O(1) pentru inserare

# 2. Liste inlantuite duble
- **nod = {prev,data,next}**

### Traversare
- fie de la primul nod catre ultimul, fie invers: O(N)

### Inserare/Stergere
- la inceput, final: O(1);
- la o anumita pozitie: O(n);

## 3. Alte tipuri de liste
1. Liste circulare
- ultimul nod are pointerul care indica spre primul nod din lista
- Traversare: O(n)
<br>
<br>
2. Liste circulare duble
- la fel ca lista simpla circulara, insa pointerul prev al primului nod indica spre ultimul element
- Traversare: O(n)
<br>
<br>
3. Liste cu sentinel (Header list)
- primul nod (**Header sau dummy node**) poate contine meta data despre lista(inclusiv lungimea) si contine pointerul catre primul element al listei

4. Liste circulare duble cu santinela
- preiau proprietatile celor doua liste

## Pasi inserare element
1. Alocarea memoriei pentru noul element
2. Conectarea nodului la nodurile vecine (prev, next)
3. Actualizarea referintelor ale celor doua noduri vecine 
## Pasi stergere element
1. Actualizarea referintelor nodurilor vecine
2. Eliberarea memoriei ocupat de nod

# Dictionare
- tip de date abstract utilizat pentru cautare eficienta bazata pe o cheie de cautare
<br>
### Implementare
**1. Vector de liste**
- folosit cand numarul de categorii este cunoscut (exp: 12 luni ale anului)
- alocat static sau dinamic
- structura: fiecare element contine `Master(categoria)` si un `pointer de legatura` catre o lista simplu inlantuita 
<br>

**2. Liste de liste**
- categoriile nu sunt cunoscute la inceput si pot aparea dinamic
- structura: `Master List(lista principala)` - contine un camp cheie `Master key`, pointer catre urmatoarea categorie `next` si pointer catre propria lista `link` (sub-liste)

- adaugarea unui nod incepe cu verificarea daca exista deja categora in lista principala

# Stiva si coada
**1. Stiva**
- principiul LIFO
- implementare fie prin vector, fie prin lista inlantuita
- singurul punct de access este varful
<br>

Operatii:
- push(adaugare element)
- pop(extragere element)
- top/peek(obtinere element din varful stivei (**top**), fara a modifica continutul)
<br>

**2. Coada**
- principiul FIFO
- inserarea se face la sfarsit (**tail**), iar extragerea la inceput(**front**)
<br>

Operatii:
- Enqueue (adaugarea la sfarsitul cozii)
- Dequeue (extragerea de la inceput)
- FrontQ (citirea primului element fara stergere)