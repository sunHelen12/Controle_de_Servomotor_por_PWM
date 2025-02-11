<h1 align="center">Tarefa Controle de Servomotor por PWM - Embarcatech</h1>

<h2>Descrição</h2>
<p>Este projeto utiliza o Raspberry Pi Pico W para controlar um servomotor por meio do módulo PWM do microcontrolador RP2040. O projeto simula o controle do ângulo do servomotor utilizando o simulador Wokwi e implementa a movimentação suave da flange do servo entre 0° e 180°.</p>

<h2>Funcionalidades do Projeto</h2>
<ul>
    <li><strong>Configuração do PWM</strong><br>
        A GPIO 22 foi configurada para gerar um sinal PWM com frequência de aproximadamente 50Hz (período de 20ms).</li>
    <li><strong>Definição de Posições Fixas</strong><br>
        <ul>
            <li>Pulso de 2.400µs para a posição de 180° (aguarda 5 segundos).</li>
            <li>Pulso de 1.470µs para a posição de 90° (aguarda 5 segundos).</li>
            <li>Pulso de 500µs para a posição de 0° (aguarda 5 segundos).</li>
        </ul>
    </li>
    <li><strong>Movimentação Suave do Servomotor</strong><br>
        O braço do servomotor se move suavemente entre 0° e 180° com incrementos de ±5µs e um atraso de ajuste de 10ms.</li>
</ul>

<h2>Requisitos do Projeto</h2>
<ul>
    <li><strong>Uso do Simulador Wokwi</strong><br>
        O projeto foi testado no Wokwi para validar o funcionamento do controle de PWM.</li>
    <li><strong>Implementação no Pico SDK</strong><br>
        O código foi desenvolvido utilizando a linguagem C e a biblioteca Pico SDK.</li>
    <li><strong>Utilização do GitHub</strong><br>
        O código-fonte está versionado e armazenado em um repositório do GitHub.</li>
</ul>

<h2>Componentes Necessários</h2>
<ul>
    <li>1 x Raspberry Pi Pico W</li>
    <li>1 x Servomotor micro servo padrão</li>
    <li>1 x Simulador Wokwi</li>
</ul>
<h2>Tecnologias Utilizadas</h2>
<ul>
    <li>Linguagem C</li>
    <li>IDE Visual Studio Code</li>
    <li>Pico SDK</li>
    <li>Simulador Wokwi</li>
</ul>

<h2>Clone o Repositório</h2>
<ol>
    <li>Abra o <strong>Prompt de Comando</strong> ou o terminal de sua preferência.</li>
    <li>Clone o repositório usando o Git:
        <pre><code>git clone https://github.com/seu-usuario/seu-repositorio.git</code></pre>
    </li>
    <li>Entre no diretório do projeto:
        <pre><code>cd seu-repositorio</code></pre>
    </li>
</ol>

<h2>Como Compilar e Executar</h2>
<pre>
mkdir build
cd build
cmake ..
make
</pre>
