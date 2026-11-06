
const byte segmentos[7] = {2, 3, 4, 5, 6, 7, 8};
const byte botao = 12;

// Configuração dos números conforme o circuito original
const byte numeros[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {1, 0, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {1, 0, 1, 0, 0, 1, 1}, // 4
  {0, 1, 1, 1, 0, 1, 1}, // 5
  {0, 1, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

int numeroAtual = 0;
bool girando = true;
bool podeClicar = true;

unsigned long ultimaTroca = 0;
unsigned long inicioSoltura = 0;

const unsigned long velocidade = 70;

// Mostra o número no display
void mostrarNumero(int numero) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], numeros[numero][i]);
  }
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }

  // Botão com resistor pull-up externo
  pinMode(botao, INPUT_PULLUP);
  mostrarNumero(numeroAtual);
}

void loop() {
  unsigned long agora = millis();
  bool pressionado = (digitalRead(botao) == LOW);

  // Alterna entre girar e parar ao apertar
  if (pressionado) {
    inicioSoltura = 0;

    if (podeClicar) {
      girando = !girando;
      podeClicar = false;
      ultimaTroca = agora;
    }
  } else {
    // Evita múltiplos cliques por contato do botão
    if (inicioSoltura == 0) {
      inicioSoltura = agora;
    }

    if (agora - inicioSoltura >= 40) {
      podeClicar = true;
    }
  }

  // Alterna os números somente enquanto estiver girando
  if (girando && agora - ultimaTroca >= velocidade) {
    ultimaTroca = agora;
    numeroAtual = (numeroAtual + 1) % 10;
    mostrarNumero(numeroAtual);
  }
}
