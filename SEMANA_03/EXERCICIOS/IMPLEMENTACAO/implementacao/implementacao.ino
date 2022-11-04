#include <Arduino.h>

#define botaoSalvar 4
#define botaoLer 5

int vetor[4];
int valoresGuardados[10];
int posicaoAtual = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(1, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(botaoSalvar, INPUT_PULLUP); 
  pinMode(botaoLer, INPUT_PULLUP);
  pinMode(14, INPUT);
}

void conversorBinario(int number){
  for (int i=0; i < 4; i++){
    Serial.print(number);
    if (number%2 == 0){
      vetor[i] = 0;
    } else{
      vetor[i]= 1;
    }
    number = (number/2);
  }
}

int salvar(int valor, int posicao) {
  valoresGuardados[posicao] = valor; 
  posicoes(valor);
  buzina(valor);
  return posicao + 1; 
}

void posicoes (int valor){
    conversorBinario(valor);

    if (vetor[0] == 1){
      digitalWrite(1, 1);
    }
    else if (vetor[0] == 0){
      digitalWrite(1, 0);
    }
    if (vetor[1] == 1){
      digitalWrite(42, 1);
    }
    else if (vetor[1] == 0){
      digitalWrite(42, 0);
    }
    if (vetor[2] == 1){
      digitalWrite(39, 1);
    }
    else if (vetor[2] == 0){
      digitalWrite(39, 0);
    }
     if (vetor[3] == 1){
      digitalWrite(36, 1);
    }
    else if (vetor[3] == 0){
      digitalWrite(36, 0);
    }
    Serial.print(vetor[0]);
    Serial.print(vetor[1]);
    Serial.print(vetor[2]);
    Serial.print(vetor[3]);
}

void buzina(int number){
  for (int h = 0; h < number; number--) {
    Serial.println("tocando");
    tone(8, (number * 100), 200);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int valorLDR = analogRead(14);
  int valor = valorLDR / 273; 


  if (digitalRead(botaoSalvar) == LOW) {
    posicaoAtual = salvar(valor, posicaoAtual); 
  }

  if (digitalRead(5) == LOW) {
    for(int i = 0; i <= posicaoAtual; i++) {
      posicoes(valoresGuardados[i]);
      buzina(valoresGuardados[i]);
      delay(3000);
    }
  }

  delay(2000);
}