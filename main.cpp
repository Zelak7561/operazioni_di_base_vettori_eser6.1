/*
Utilizzando i sottoprogrammi, implementare un programma che esegua le seguenti
operazioni su un vettore, costituito dai seguenti sottoprogrammi.
a) Leggere da tastiera un vettore di interi V e il suo riempimento r.
b) Stampare gli elementi del vettore V.
c) Stampare gli elementi del vettore V in ordine inverso.
d) Richiedere il valore di un numero intero x e verificare se esiste nel vettore V. Nel caso in cui
l'elemento esista restituire la sua posizione.
e) Calcolare la sommatoria degli elementi di posto pari e la sommatoria degli elementi di
posto dispari e memorizzare in un vettore VP gli elementi con valore pari e in un vettore VD
gli elementi con valore dispari.
f) Calcolare il valore minimo, massimo e la media degli elementi di V.
g) Verificare se esistono elementi nulli nel vettore V. In caso positivo contarli e stamparli.
h) Dopo aver fatto la copia del vettore V, richiedere la posizione di un elemento da eliminare
nel vettore copia e eliminarlo dal vettore copia (V_copia).
i) Richiedere il valore di un elemento da eliminare nel vettore V e eliminarlo da V.
l) Richiedere il valore di un numero intero x e la posizione in cui deve essere inserito, e
successivamente inserire tale valore nel vettore V.
 */

#include <iostream>

using namespace std;

void leggereV(int *, int dim);

void stampaV(int *, int dim);

void stampaInversoV(int *, int dim);

int controlloValoreV(int *, int dim);

void calcoloSommatoriaDP(int *, int *, int *, int dim);

void calcoloValMinMaxMedia(int *, int dim);

void controlloElementiNulli(int *, int dim);

void copiaVEliminaElem(int *, int *, int dim);

void EliminaElemV(int *, int *dim);

void aggiungiElemV(int *, int *dim);

int main() {
    int dim = 0;

    cout << "Inserire la dimensione del vettore: " << endl;
    cin >> dim;
    int v[dim] = {};
    int v_copia[dim] = {};
    int vp[dim] = {};
    int vd[dim] = {};

    leggereV(v, dim);
    stampaV(v, dim);
    // cout << endl;
    // stampaInversoV(v, dim);
    // cout << endl;
    //
    // int p = controlloValoreV(v, dim);
    // if (p != -1) {
    //     cout << "Il valore cercato esiste e si trova in posizione: " << p << endl;
    //     cout << "|----------------------------|" << endl;
    // } else {
    //     cout << "Il valore inserito non esiste nel vettore" << endl;
    //     cout << "|----------------------------|" << endl;
    // }
    // cout << endl;
    //
    // calcoloSommatoriaDP(vp, vd, v, dim);
    // cout << endl;
    //
    // calcoloValMinMaxMedia(v, dim);
    // cout << endl;
    //
    // controlloElementiNulli(v, dim);
    // cout << endl;
    //
    // copiaVEliminaElem(v, v_copia, dim);
    // cout << endl;

    EliminaElemV(v , &dim);
    cout << endl;

    aggiungiElemV(v , &dim);
    cout << endl;

    return 0;
}

void leggereV(int *v, int dim) {
    cout << "|----------------------------|" << endl;
    for (int i = 0; i < dim; i++) {
        cout << "Inserie il numero #" << i + 1 << " :" << endl;
        cin >> *(v + i);
    }
    cout << "|----------------------------|" << endl;
    cout << endl;
}

void stampaV(int *v, int dim) {
    cout << "|----------------------------|" << endl;
    cout << "Vettore v: " << endl;
    for (int i = 0; i < dim; i++) {
        cout << *(v + i) << " ";
    }
    cout << endl;
    cout << "|----------------------------|" << endl;
}

void stampaInversoV(int *v, int dim) {
    cout << "|----------------------------|" << endl;
    cout << "Vettore v inverso: " << endl;
    for (int i = dim - 1; i >= 0; i--) {
        cout << *(v + i) << " ";
    }
    cout << endl;
    cout << "|----------------------------|" << endl;
}

int controlloValoreV(int *v, int dim) {
    int pos = 0;
    int n = 0;
    cout << "|----------------------------|" << endl;
    cout << "Inserire il numero da cercare" << endl;
    cin >> n;

    for (int i = 0; i < dim; i++) {
        if (n == v[i]) {
            pos = i;
            break;
        }
    }


    return pos + 1;
}

void calcoloSommatoriaDP(int *vp, int *vd, int *v, int dim) {
    int dimP = 0;
    int dimD = 0;
    int somP = 0;
    int somD = 0;

    cout << "|----------------------------|" << endl;
    cout << "Calcolo sommatorie..." << endl;
    for (int i = 0; i < dim; i++) {
        if (v[i] % 2 == 0) {
            vp[dimP] = v[i];
            somP += v[i];
            dimP++;
        } else if (v[i] % 2 != 0) {
            vd[dimD] = v[i];
            somD += v[i];
            dimD++;
        }
    }

    cout << "Vettore vp: " << endl;
    for (int i = 0; i < dimP; i++) {
        cout << *(vp + i) << " ";
    }
    cout << "- Sommatoria pari: " << somP << endl;

    cout << "Vettore vd: " << endl;
    for (int i = 0; i < dimD; i++) {
        cout << *(vd + i) << " ";
    }
    cout << "- Sommatoria dispari: " << somD << endl;
    cout << "|----------------------------|" << endl;
}

void calcoloValMinMaxMedia(int *v, int dim) {
    int som = 0;
    int max = v[0];
    int min = v[0];

    //Media
    for (int i = 0; i < dim; i++) {
        som += *(v + i);
    }

    //Max
    for (int i = 0; i < dim; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }

    //Max
    for (int i = 0; i < dim; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }

    cout << "|----------------------------|" << endl;
    cout << "La media del vettore v e: " << som / dim << endl;
    cout << "Il massimo del vettore v e: " << max << endl;
    cout << "Il minimi del vettore v e: " << min << endl;
    cout << "|----------------------------|" << endl;
}

void controlloElementiNulli(int *v, int dim) {
    int cont = 0;

    for (int i = 0; i < dim; i++) {
        if (v[i] == 0) {
            cont++;
        }
    }

    cout << "|----------------------------|" << endl;
    cout << "Gli elementi nulli del vettore v sono: " << cont << endl;
    cout << "|----------------------------|" << endl;
}

void copiaVEliminaElem(int *v, int *v_copia, int dim) {
    int pos = 0;

    for (int i = 0; i < dim; i++) {
        v_copia[i] = v[i];
    }

    cout << "|----------------------------|" << endl;
    cout << "Inserisci la posizione di un elemento da eliminare dal v_copia: " << endl;
    cin >> pos;

    cout << endl;

    cout << "v_copia prima dell'eliminazione:" << endl;
    for (int i = 0; i < dim; i++) {
        cout << *(v_copia + i) << " ";
    }
    cout << endl;

    int mediano = (dim - 1) / 2;
    if (pos <= mediano) {
        for (int i = pos; i < dim - 1; i++) {
            v_copia[i] = v_copia[i + 1];
        }
    } else {
        for (int i = pos; i < dim - 1; i++) {
            v_copia[i] = v_copia[i + 1];
        }
    }
    dim--;


    cout << "v dopo l'eliminazione:" << endl;
    for (int i = 0; i < dim; i++) {
        cout << *(v_copia + i) << " ";
    }
    cout << endl;
    cout << "|----------------------------|" << endl;
}

void EliminaElemV(int *v, int *dim) {
    int pos = 0;

    cout << "|----------------------------|" << endl;
    cout << "Inserisci la posizione di un elemento da eliminare (0 - " << *dim << "): " << endl;
    cin >> pos;

    cout << endl;

    cout << "v prima dell'eliminazione:" << endl;
    for (int i = 0; i < *dim; i++) {
        cout << *(v + i) << " ";
    }
    cout << endl;

    int mediano = (*dim - 1) / 2;
    if (pos <= mediano) {
        for (int i = pos; i < *dim - 1; i++) {
            v[i] = v[i + 1];
        }
    } else {
        for (int i = pos; i < *dim - 1; i++) {
            v[i] = v[i + 1];
        }
    }
    (*dim)--;


    cout << "v dopo l'eliminazione:" << endl;
    for (int i = 0; i < *dim; i++) {
        cout << *(v + i) << " ";
    }
    cout << endl;
    cout << "|----------------------------|" << endl;
}

void aggiungiElemV(int *v, int *dim) {
    int pos = 0;
    int n = 0;

    cout << "|----------------------------|" << endl;
    cout << "Inserisci la posizione di un elemento da aggiungere (0 - " << *dim << "): " << endl;
    cin >> pos;
    cout << "Inserisci il valore dell'elemento da aggiungere: " << endl;
    cin >> n;

    cout << endl;

    cout << "v prima dell'aggiunta: " << endl;
    for (int i = 0; i < *dim; i++) {
        cout << *(v + i) << " ";
    }
    cout << endl;

    int mediano = (*dim - 1) / 2;

    if (pos <= mediano) {
        for (int i = *dim; i > pos; i--) {
            v[i] = v[i - 1];
        }
    } else {
        for (int i = *dim; i > pos; i--) {
            v[i] = v[i - 1];
        }
    }

    v[pos] = n;
    (*dim)++;

    cout << "v dopo l'aggiunta:" << endl;
    for (int i = 0; i < *dim; i++) {
        cout << *(v + i) << " ";
    }
    cout << endl;
    cout << "|----------------------------|" << endl;
}




