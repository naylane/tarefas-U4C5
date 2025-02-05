<h2 align="center"> Atividade 1: Temporizador periódico. </h2>

Tarefa promovida pelo programa EmbarcaTech com objetivo de aplicar conhecimentos sobre temporizadores e controle de LEDs.

## Funcionamento
O fluxo do programa pode ser visto da seguinte forma:
1. Desliga LEDs amarelo e verde, liga LED vermelho e aguarda 3 segundos;
2. Desliga LED vermelho, liga LED amarelo e aguarda 3 segundos;
3. Desliga LED amarelo, liga LED verde e aguarda 3 segundos.

E assim a atuação do semáforo acontece.

<div align="center">  
  <img align="center" width=50% src="https://github.com/naylane/tarefas-U4C5/blob/0551d9930e86fdc17b3acbbb49140a8cbc5c8495/atividade-1/atv1.gif">
  <p><em>Execução na placa.</em></p>
</div>



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

Ou, se preferir, [clique aqui para ver a simulação no Wokwi Web](https://wokwi.com/projects/421991045218041857).

## Referências
* [1] [Documentação da Raspberry Pi Pico](https://www.raspberrypi.com/documentation/microcontrollers/)
