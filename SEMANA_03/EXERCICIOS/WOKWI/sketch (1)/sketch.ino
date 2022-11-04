#define led_vermelho 22
#define led_azul 21
#define led_amarelo 19
#define led_verde 18
#define botao_verde 33
#define botao_vermelho 32
#define buzzer 23
#define ldr 13

int vetor[4];
int vetorBotaoVerde[1];

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(led_vermelho, OUTPUT);
  pinMode (led_azul, OUTPUT);
  pinMode (led_amarelo, OUTPUT);
  pinMode(botao_verde, INPUT_PULLUP);
  pinMode(botao_vermelho, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(ldr, INPUT);
}
void conversorBinario(int number){
  for (int i=0; i < 4; i++){
    if (number%2 == 0){
      vetor[i] = 0;
    } else{
      vetor[i]= 1;
    }
    number = (number/2);
  }
}

void posicoes (){
    if (vetor[0] == 1){
      digitalWrite(led_vermelho, 1);
    }
    else if (vetor[0] == 0){
      digitalWrite(led_vermelho, 0);
    }
    if (vetor[1] == 1){
      digitalWrite(led_azul, 1);
    }
    else if (vetor[1] == 0){
      digitalWrite(led_azul, 0);
    }
    if (vetor[2] == 1){
      digitalWrite(led_amarelo, 1);
    }
    else if (vetor[2] == 0){
      digitalWrite(led_amarelo, 0);
    }
     if (vetor[3] == 1){
      digitalWrite(led_verde, 1);
    }
    else if (vetor[3] == 0){
      digitalWrite(led_verde, 0);
    }

    Serial.print(vetor[0]);
    Serial.print(vetor[1]);
    Serial.print(vetor[2]);
    Serial.print(vetor[3]);
}

void buzina(int number){
  for (int h = 0; h < number; number--) {
    tone(buzzer, (number * 100), 200);
  }
}

void primeiroBotao(int number){
  if (digitalRead(botao_verde) == 0){
    vetorBotaoVerde[0] = number;
  }
}

void segundoBotao(int number){
  if (digitalRead(botao_vermelho) == 0){
    posicoes();
    buzina(vetorBotaoVerde[0]);
  }
}


void loop() {
  int valorNumerico = analogRead(13); //variavel que armazena os valores lidos por LDR
  int valorLDR = (valorNumerico/273);
  conversorBinario(valorLDR);
  delay(2000);
  posicoes();
  delay(1000);
  buzina(valorLDR); 
  delay(3000);
  primeiroBotao(valorLDR);
  delay(1000);
  segundoBotao(valorLDR); 
}
