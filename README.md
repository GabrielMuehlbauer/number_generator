# 🎰 Roleta Eletrônica com Arduino

Projeto desenvolvido com **Arduino Uno**, um **display de 7 segmentos** e um **botão de pressão**, simulando uma roleta numérica.

## Funcionamento

O display alterna rapidamente entre os números de **0 a 9**. Ao pressionar o botão, a sequência é interrompida e o número exibido permanece fixo. Um novo clique reinicia a roleta.

## Componentes

- Arduino Uno
- Display de 7 segmentos
- Botão (push button)
- Protoboard, resistores e fios jumper

## Implementação

O display utiliza os pinos digitais **D2 a D8**, enquanto o botão utiliza o **D12**. O código utiliza `millis()` para controlar a alternância dos números sem bloquear a leitura do botão.

## Resultado

✅ **Projeto concluído com sucesso!**

O circuito foi montado e testado, permitindo iniciar e interromper a roleta por meio do botão, congelando o número exibido.
