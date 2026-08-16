# Structuri de date
## 1. Liste inlantuite
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

