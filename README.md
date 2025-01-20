
<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=02A6F4&height=120&section=header"/>
<h1 align="center">Embarcatec | Terceira Atividade Em Grupo</h1>

<div align="center">  
  <img width=40% src="http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=02A6F4&style=for-the-badge"/>
</div>

<div align="center">
 <a href="#-objetivo-do-projeto"> Objetivo do Projeto</a> • 
  <a href="#-lista-de-requisitos"> Requisitos</a> • 
 <a href="#-tecnologias"> Tecnologias</a> • 
 <a href="#-desenvolvedores"> Desenvolvedores</a>
</div>

## Objetivo do Projeto

O objetivo deste projeto é utilizar a ferramenta educacional BitDogLab para controlar os pinos GPIO do microcontrolador RP2040, por meio da comunicação serial UART. Será feito o acionamento do LED RGB, controlado pelos GPIOs 11, 12 e 13.

## 🗒️ Lista de requisitos

- Deve-se utilizar o ambiente de desenvolvimento VS Code em todas as duas atividades; 
- Os códigos devem ser escritos na linguagem C, juntamente com os recursos do kit de Desenvolvimento de Software Pico SDK; 
- Deve-se criar um repositório do github para o versionamento, registro e submissão dessa atividade.
- Utilização do software de emulação de terminal PuTTy.

## 🛠 Tecnologias

1. **Git e Github**;
2. **VScode**;
3. **Linguagem C**;
4. **Software de emulação PuTTy.**

## 🔧 Funcionalidades Implementadas:

## Passos:

1. Compilar o Código
- Compile o código-fonte em C para o Raspberry Pi Pico W.
2. Colocar o RP2040 no Modo Bootsel
- Para colocar o Raspberry Pi Pico W no modo Bootsel, mantenha pressionado o botão BOOTSEL enquanto conecta o dispositivo ao computador via USB.
- O dispositivo irá aparecer como uma unidade de armazenamento no seu computador.
3. Enviar o Arquivo UF2
- Copie o arquivo UF2 compilado para a unidade do Raspberry Pi Pico W.
- Após a transferência, o RP2040 será reiniciado automaticamente e a unidade desaparecerá no seu PC.
4. Identificar a Porta COM
- Acesse o Gerenciador de Dispositivos no Windows e procure por "Portas COM e LPT".
- Encontre a porta COM associada ao seu RP2040, que será exibida ao conectar o dispositivo.
5. Configuração do Putty
- Abra o Putty e selecione a opção "Serial".
- Em "Serial line", escolha a porta COM identificada no passo anterior.
- Em "Speed", coloque 115200, que trata-se da taxa de transmissão padrão para o RP2040.
6. Configuração do Terminal no Putty
- No menu à esquerda do Putty, selecione "Terminal".
- Em "Local echo", escolha "Force On".
- Em "Local line editing", também selecione "Force On".
- Isso é necessário para poder ver o que está sendo digitado no terminal, além de conseguir pressionar "Enter" para enviar comandos.
7. Interagindo com o LED
- Agora, no terminal Putty, você pode escolher entre as funções "red", "green", "blue", "white", "leds_off" ou "bip", digitando algumas delas para controlar o LED ou o buzzer do seu Raspberry Pi Pico W.


## 💻 Desenvolvedores
 
<table>
  <tr>
    <td align="center"><img style="" src="https://avatars.githubusercontent.com/u/72825281?v=4" width="100px;" alt=""/><br /><sub><b> Marcio Fonseca </b></sub></a><br />👨‍💻</a></td>
    <td align="center"><img style="" src="https://avatars.githubusercontent.com/u/191687774?v=4" width="100px;" alt=""/><br /><sub><b> José Vinicius </b></sub></a><br />👨‍💻</a></td>
    <td align="center"><img style="" src="https://avatars.githubusercontent.com/u/164667970?v=4" width="100px;" alt=""/><br /><sub><b> Pedro Barros
    </b></sub></a><br />👨‍💻</a></td>
    <td align="center"><img style="" src="https://avatars.githubusercontent.com/u/124692269?v=4" width="100px;" alt=""/><br /><sub><b> Paola Fagundes </b></sub></a><br />👨‍💻</a></td>
    <td align="center"><img style="" src="https://avatars.githubusercontent.com/u/143294885?v=4" width="100px;" alt=""/><br /><sub><b> Sara Souza </b></sub></a><br />👨‍💻</a></td>
<td align="center"><img style="" src="https://avatars.githubusercontent.com/u/135754687?v=4" width="100px;" alt=""/><br /><sub><b> João Paulo </b></sub></a><br />👨‍💻</a></td>
<td align="center"><img style="" src="https://avatars.githubusercontent.com/u/96251377?v=4" width="100px;" alt=""/><br /><sub><b> Moises Amorim </b></sub></a><br />👨‍💻</a></td>
<td align="center"><img style="" src="https://avatars.githubusercontent.com/u/103523809?v=4" width="100px;" alt=""/><br /><sub><b> Alexsami Lopes </b></sub></a><br />👨‍💻</a></td>
<td align="center"><img style="" src="https://avatars.githubusercontent.com/u/60956248?v=4" width="100px;" alt=""/><br /><sub><b> Ramom Andrade </b></sub></a><br />👨‍💻</a></td>
  </tr>
</table>


## 🎥 Demonstração: 
- Para ver o funcionamento do projeto, acesse o vídeo:
[![Demostração de comunicação serial com a placa bitdoglab](/images/foto_bitdoglab.jpg)](https://youtu.be/me8tVMfQ_Yk)
- Abaixo, clic na imagem para ver o vídeo de funcionamento no Linux:
[![Demostração de comunicação serial com a placa bitdoglab no Linux](/images/Captura%20de%20tela%20de%202025-01-19%2020-29-08.png)](https://youtu.be/bw3YnIqMpPw)

