#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RIGHE_MAX 10
#define COLONNE_MAX 10

#define MIN_RAND_VAL 0
#define MAX_RAND_VAL 5


typedef struct matrice{
	int riga;
	int colonna;
	int m[RIGHE_MAX][COLONNE_MAX];
}matrice;

int leggere_riga(matrice mat);
int leggere_colonna(matrice mat);
int leggere_elemento(matrice mat,int riga, int colonna);
void scrivere_riga(matrice *mat,int valore);
void scrivere_colonna(matrice *mat,int valore);
void scrivere_elemento(matrice *mat,int riga, int colonna,int valore);
void stampare_matrice(matrice mat, char messaggio[50]);
void trasposta_matrice(matrice mat, matrice *trasposta);
void prodotto_matrici(matrice mat1, matrice mat2, matrice *prodotto);
void prodotto_scalare(matrice mat, int scalare, matrice *prodotto);
void somma_matrici(matrice mat1, matrice mat2, matrice *matrice_somma);
void matrice_random(matrice *mat,int righe,int colonne);


int main(void) {
//Creazione matrice randomica
	matrice matrice1;
	matrice_random(&matrice1,2,2);
	stampare_matrice(matrice1, "Matrice 1");

//Operazione Trasposta di matrice
	matrice trasposta;
	trasposta_matrice(matrice1,&trasposta);
	stampare_matrice(trasposta,"Matrice trasposta di Matrice 1");

//Operazione Prodotto di Matrici
	matrice matrice_prodotto;
	prodotto_matrici(matrice1, matrice1, &matrice_prodotto);
	stampare_matrice(matrice_prodotto,"Prodotto di Matrice 1 per Matrice 1");

//Operazione Prodotto di matrice per scalare
	matrice matrice_prodotto_scalare;
	prodotto_scalare(matrice1, 12, &matrice_prodotto_scalare);
	stampare_matrice(matrice_prodotto_scalare,"Prodotto scalare tra Matrice 1 e lo scalare 12");

//Operazione Somma di matrici
	matrice matrice_somma;
	somma_matrici(matrice1, matrice1, &matrice_somma);
	stampare_matrice(matrice_somma,"Somma della Matrice 1 per la Matrice 1");

	system("pause");
	return 0;
}

int leggere_riga(matrice mat){
	return mat.riga;
}

int leggere_colonna(matrice mat){
	return mat.colonna;
}

int leggere_elemento(matrice mat,int riga, int colonna){
	return mat.m[riga][colonna];
}

void scrivere_riga(matrice *mat,int valore){
	mat->riga=valore;
	return;
}

void scrivere_colonna(matrice *mat,int valore){
	mat->colonna=valore;
	return;
}

void scrivere_elemento(matrice *mat,int riga, int colonna,int valore){
	mat->m[riga][colonna]=valore;
	return;
}

void stampare_matrice(matrice mat, char messaggio[50]){
	int i, j;
	printf("\n%s (%d righe - %d colonne)\n", messaggio, leggere_riga(mat),leggere_colonna(mat));
	i = 0;
	while (i < leggere_riga(mat)) {
		j = 0;
		while (j < leggere_colonna(mat)) {
			printf("%d\t", leggere_elemento(mat,i,j));
			j++;
		}
		printf("\n");
		i++;
	}
	return;
}

void trasposta_matrice(matrice mat, matrice *trasposta){
	int i,j;
	scrivere_colonna(trasposta, leggere_riga(mat));
	scrivere_riga(trasposta, leggere_colonna(mat));
	i = 0;
	while (i < leggere_riga(mat)) {
		j = 0;
		while (j < leggere_colonna(mat)) {
			scrivere_elemento(trasposta,j,i,leggere_elemento(mat,i,j));
			j++;
		}
		i++;
	}
	return;
}

void prodotto_matrici(matrice mat1, matrice mat2, matrice *prodotto){
	int i, j, k, valore_prodotto_scalare;

	scrivere_riga(prodotto, leggere_riga(mat1));
	scrivere_colonna(prodotto, leggere_colonna(mat2));

	i = 0;
	while (i < leggere_riga(*prodotto)) {
		j = 0;
		while (j < leggere_colonna(*prodotto)) {
			valore_prodotto_scalare = 0;
			k = 0;
			while (k < leggere_colonna(mat1)) {
				valore_prodotto_scalare = valore_prodotto_scalare + (leggere_elemento(mat1,i,k) * leggere_elemento(mat2,k,j));
			k++;
			}
			scrivere_elemento(prodotto,i,j,valore_prodotto_scalare);
		j++;
		}
	i++;
	}
	return;
}

void prodotto_scalare(matrice mat, int scalare, matrice *prodotto){
	scrivere_riga(prodotto,leggere_riga(mat));
	scrivere_colonna(prodotto,leggere_colonna(mat));

	int i, j;

	i=0;
	while(i<leggere_riga(*prodotto)){
		j=0;
		while(j<leggere_colonna(*prodotto)){

			scrivere_elemento(prodotto,i,j,leggere_elemento(mat,i,j)*scalare);

		j++;
		}
	i++;
	}

	return;
}

void somma_matrici(matrice mat1, matrice mat2, matrice *matrice_somma){
	scrivere_riga(matrice_somma,leggere_riga(mat1));
	scrivere_colonna(matrice_somma,leggere_colonna(mat1));

	int i, j;

	i=0;
	while(i<leggere_riga(*matrice_somma)){
		j=0;
		while(j<leggere_colonna(*matrice_somma)){

			scrivere_elemento(matrice_somma,i,j,leggere_elemento(mat1,i,j)+leggere_elemento(mat2,i,j));

		j++;
		}
	i++;
	}

	return;
}

void matrice_random(matrice *mat,int righe,int colonne){
	scrivere_riga(mat,righe);
	scrivere_colonna(mat,colonne);
	int i,j;
	srand(time(NULL));
	i=0;
	while(i<leggere_riga(*mat)){
		j=0;
		while(j<leggere_colonna(*mat)){


			scrivere_elemento(mat,i,j,rand()%MAX_RAND_VAL+MIN_RAND_VAL);

		j++;
		}
	i++;
	}

	return;
}
