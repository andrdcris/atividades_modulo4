#include <iostream>
#include <string>

using namespace std;
char *direcoes[4] = {(char *) "Direita", (char *) "Esquerda",(char *) "Frente",(char *) "Trás"};

//#1 ajusta os valores percentualmente entre dois valores mínimo e máximo e retorna esse valor
int ajusteDeValor (int medida, int minimo, int maximo){
    int valor = (medida - minimo)*100;
    int variacao =  maximo - minimo;
    int resultado = valor/variacao;

    return resultado;
}

//#2 simule a leitura de um sensor lendo o valor do teclado ao final a função retorna este valor
int leitura (int indiceDirecao){
    int valor;
    cout << "Digite a distância até:" << direcoes[indiceDirecao] << endl;
    cin >> valor;
    return valor;
}

//#3 Armazena o valor das quatro direções do vetor
//
int armazenaValorVetor (int medida, int *vetor, int tamanhoMaximoVetor, int posicaoAtual){
    if (posicaoAtual > tamanhoMaximoVetor){
        cout << "Posição Inválida";
    } else{
        vetor[posicaoAtual] = medida; 
    }
    return posicaoAtual + 1;
}

//#5 pergunta se continua o processo
int perguntaSeContinua(){
    char resposta;
    cout << "Deseja continuar? (s/n)";
    cin >> resposta;
    int valor = 0;

    if (resposta == 's'){
        valor = 1;
    } else if (resposta == 'n'){
        valor = 0;
    } else {
        cout << "Valor inválido";
    }
    return valor;
}

// 6 completando a finção
int dirige(int *v,int maxv){
	int tamanhoMaximoVetor = maxv;
	int *vetorDeMovimento = v;
	int posicaoAtualVetor = 0;
	int dirigindo = 1;

 //enquanto dirigindo for igual a 1 a função ira rodar   
	while(dirigindo){		
        for (int i=0; i<4; i++){ //ajuste das posições
            int medida = leitura(i);/// .. Chame a função de de leitura da medida para a "Direita"
            medida = ajusteDeValor(medida,0,830);
            posicaoAtualVetor = armazenaValorVetor(medida, vetorDeMovimento, tamanhoMaximoVetor, posicaoAtualVetor);
            // Chame a função para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
        }
		dirigindo = perguntaSeContinua();		
	}
	return posicaoAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento

//6 lê os 4 valores das direções, ordena os valores para que o maior numero esteja no indice 0 da função
char* direcaoMaiorCaminho(int *vetor, int* maiorDirecao){
    int maiorDistancia = vetor[0];
    int indice;

    for (int i=0; i < 4; i++){
        if (vetor[i]>maiorDistancia){
            maiorDistancia = vetor[i];
            indice = i;
        }
    }
    *maiorDirecao = maiorDistancia;
    return direcoes[indice];
}

//6
void percorre(int *v,int tamanhoPercorrido){		
	int *vetorDeMovimento = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamanhoPercorrido; i+=4){
		char *direcao = direcaoMaiorCaminho(&(vetorDeMovimento[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int tamanhoMaximoDoVetor = 100;
	int vetorDeMovimento[tamanhoMaximoDoVetor*4];
	int posAtualDoVetor = 0;
	
	posAtualDoVetor = dirige(vetorDeMovimento,tamanhoMaximoDoVetor);
	percorre(vetorDeMovimento,posAtualDoVetor);
	
	return 0;
}