# Structuri de date
## 1. Liste inlantuite simple
- structura de date de baza
- **nod={data, next}**;
data = tipul de date a listei;
next= pointer catre urmatorul nod(adresa de memorie) 
- memorie alocata dinamic (Heap)
- se acceseaza printr-un pointer catre primul nod (**HEAD**)
- ultimul nod (next=0) se numeste **TAIL**
### Travesare
 - se face printr-un pointer catre primul nod **HEAD**, pana cand next = null
 - **O(n)**
 ### Inserare si stergere
 - la sfarsit/inceput: O(1)
 - la o pozitie data: O(1) pentru inserare; O(n) pentru parcurgerea listei
## 2. Liste inlantuite duble
- **nod = {prev,data,next}**
