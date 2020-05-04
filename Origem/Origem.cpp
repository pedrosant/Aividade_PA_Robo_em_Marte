#include <iostream>

using namespace::std;

void gerarMarte(int marte[][10], int i, int j);
void imprimirMarte(int marte[][10], int i, int j);
void inserirobo(int marte[][10]);
void procurarRobo(int marte[][10], int i, int j, int quemProcura);
void rotacionarRobo(int marte[][10]);

void moverEmGrau90aEsquerda(int marte[][10], int i, int j);
void moverEmGrau180Esquerda(int marte[][10], int i, int j);
void moverEmGrau360Esquerda(int marte[][10], int i, int j);

void moverEmGrau90aDireita(int marte[][10], int i, int j);
void moverEmGrau180aDireita(int marte[][10], int i, int j);
void moverEmGrau360aDireita(int marte[][10], int i, int j);
void controlador(int marte[][10], int i, int j, int quemProcura);

int main() {

	int marte[10][10];

	gerarMarte(marte, 0, 0);
	inserirobo(marte);
	imprimirMarte(marte, 0,0);
	rotacionarRobo(marte);
	imprimirMarte(marte,0,0);

	return 0;
}

void inserirobo(int marte[][10]) {
	marte[5][5] = 2;
}

void procurarRobo(int marte[][10], int i , int j, int quemProcura) {
	if (i <= 9) {
		if (j <= 9) {			
			if (marte[i][j] == 2) {
				controlador(marte, i, j, quemProcura);
			}
			j++;			
			procurarRobo(marte, i, j, quemProcura);
		}
		else {
			i++;
			j = 0;
			procurarRobo(marte, i, j, quemProcura);
		}
	}
}

void gerarMarte(int marte [][10], int i, int j) {
	if (i <= 9){
		if (j <= 9){
			marte[i][j] = 0;
			j++;
			gerarMarte(marte,i,j);			
		}
		else {
			i++;
			j = 0;
			gerarMarte(marte, i, j);
		}
	}
}

void imprimirMarte(int marte[][10], int i, int j) {
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cout << marte[i][j];
			cout << " | ";
		}
		cout << "\n";
	}
}

void rotacionarRobo(int marte[][10]) {
	string result;
	cout << "Digite L para left ou R para Right para girar 90°: ";
		cin >> result;
	if (result == "l"){
		procurarRobo(marte,0,0,1);
	}else if(result == "ll"){
		procurarRobo(marte, 0, 0, 2);
	}else if (result == "lll") {
		procurarRobo(marte, 0, 0, 3);
	}else if (result == "r") {
		procurarRobo(marte, 0, 0, 4);
	}else if (result == "rr") {
		procurarRobo(marte, 0, 0, 5);
	}else if (result == "rrr") {
		procurarRobo(marte, 0, 0, 6);
	}
}



void moverEmGrau90aEsquerda(int marte[][10], int i, int j) {
	if (i > 0){
		marte[i][j] = 0;
		j--;
		marte[i][j] = 2;
	}
	else {
		cout << "Voce esta tentando ultrapassar os limites de marte";
		cout << "Digite outro local";
	}
	
};
void moverEmGrau180Esquerda(int marte[][10], int i, int j) {
	marte[i][j] = 0;
	i++;
	marte[i][j] = 2;
};
void moverEmGrau360Esquerda(int marte[][10], int i, int j) {
	marte[i][j] = 0;
	j++;
	marte[i][j] = 2;
};

void moverEmGrau90aDireita(int marte[][10], int i, int j) {
	marte[i][j] = 0;
	j++;
	marte[i][j] = 2;
};
void moverEmGrau180aDireita(int marte[][10], int i, int j) {
	marte[i][j] = 0;
	i++;
	marte[i][j] = 2;
};
void moverEmGrau360aDireita(int marte[][10], int i, int j) {
	marte[i][j] = 0;
	j--;
	marte[i][j] = 2;
};
void controlador(int marte[][10], int i,int j, int quemProcura) {
	
		if (quemProcura == 1) {
			moverEmGrau90aEsquerda(marte, i, j);
		}
		else if (quemProcura == 2) {
			moverEmGrau180Esquerda(marte, i, j);
		}
		else if (quemProcura == 3) {
			moverEmGrau360Esquerda(marte, i, j);
		}
		else if (quemProcura == 4) {
			moverEmGrau90aDireita(marte, i, j);
		}
		else if (quemProcura == 5) {
			moverEmGrau180aDireita(marte, i, j);
		}
		else if (quemProcura == 6) {
			moverEmGrau360aDireita(marte, i, j);
		}

}

