<h2 align="center"> Atividade 2: Temporizador de um disparo (One Shot). </h2>

Tarefa promovida pelo programa EmbarcaTech com objetivo de aplicar conhecimentos sobre temporizadores, debouncing e controle de LEDs.

## Funcionamento
O controle do botão foi implementado como uma rotina de interrupção. Quando pressionado, os três LEDs (azul, vermelho e verde) são acessos e então a sequência dos LEDs inicia. Durante esse tempo, o valor da váriavel `sys_free` é **falso** e o botão é impedido de reiniciar a sequência.

A função `turn_off_callback()` é responsável por mudar o estado dos LEDs, seguindo a ordem:
1. LED azul é desligado;
2. LED vermelho é desligado;
3. LED verde é desligado.

Após a finalização do terceiro passo, o sistema está livre, ou seja, o botão pode iniciar uma nova sequência.

## Instruções de uso
- É necessário instalar o SDK da Raspberry Pi Pico e realizar as configurações iniciais. [1]

Para ter acesso ao projeto, clone o repositório disponível na [plataforma GitHub](https://github.com/naylane/tarefas-U4C5).

Após clonar o repositório, no terminal, navegue até a pasta do projeto e execute os comandos:
```bash
mkdir build && cd build
cmake ..
make
```
Para executar a atividade na Raspberry Pi Pico, conecte a BitDogLab no computador enquanto pressiona o botão `BOOTSEL` e rode o código pelo VS Code.

⚠️ **Observação:** também é possível simular a atividade pelo Wokwi no Visual Studio Code. Basta instalar a extensão e executar o arquivo 'diagram.json'.

## Referências
* [1] [Documentação da Raspberry Pi Pico](https://www.raspberrypi.com/documentation/microcontrollers/)
