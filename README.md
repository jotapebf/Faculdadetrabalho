Você precisa ter um compilador C instalado:
 No Windows

Instale o MinGW (ou use o terminal do Code::Blocks / Dev-C++)
https://osdn.net/projects/mingw/

Durante a instalação, marque a opção:

mingw32-gcc-g++


Depois, adicione o MinGW ao PATH (ou use o terminal “MSYS2” que já vem configurado).

No Linux (Ubuntu/Debian)

Abra o terminal e execute:

sudo apt update
sudo apt install build-essential

No macOS

Abra o Terminal e execute:

xcode-select --install

2. Compilar o programa

No terminal (ou prompt de comando), vá até a pasta onde está o arquivo trabalho2.c.

Exemplo:

cd C:\Users\SeuNome\Downloads


ou no Linux/macOS:

cd ~/Downloads


Agora compile o código:

gcc trabalho2.c -o trabalho2


Isso cria um executável chamado trabalho2 (no Windows será trabalho2.exe).

Executar o programa
Windows:
trabalho2.exe

Linux/macOS:
./trabalho2

O que você verá

O programa exibirá algo assim:

=== SUPER TRUNFO: DESAFIO FINAL ===

Carta 1: Brasil
Carta 2: Japão

Escolha um atributo para comparar:
1 - População
2 - Área
3 - PIB
4 - Densidade Demográfica
Opção:


Você digita o número do atributo (por exemplo 3 para PIB),
em seguida escolhe o segundo atributo diferente (por exemplo 1 para População).

Depois, o programa mostrará o resultado completo da comparação.

Dicas

Se der o erro gcc não é reconhecido, o compilador não está no PATH.
→ Abra o Prompt do MinGW ou MSYS2 e tente de novo.

Se quiser recompilar após mudanças, basta repetir o comando:

gcc trabalho2.c -o trabalho2


Para limpar o terminal:

Windows: cls

Linux/macOS: clear


VS Code direto

Baixe e instale:
👉 https://code.visualstudio.com/

Extensão de C/C++
No VS Code:
Vá em Extensões (ícone de blocos no lado esquerdo ou Ctrl+Shift+X)

Pesquise por “C/C++”
Instale a extensão oficial da Microsoft

Compilador GCC
No Windows

Instale o MinGW:
https://osdn.net/projects/mingw/

Durante a instalação, marque:
mingw32-gcc-g++


Depois, adicione o caminho C:\MinGW\bin às variáveis de ambiente do Windows.
Para verificar se deu certo, abra o prompt e digite:
gcc --version


Se aparecer a versão do GCC, está tudo ok.

No Linux
Instale com:

sudo apt update
sudo apt install build-essential

No macOS
Instale o compilador via terminal:

xcode-select --install

Abrir o projeto no VS Code

Abra o VS Code
Vá em Arquivo → Abrir Pasta...
Escolha a pasta onde está o arquivo trabalho2.c
Confirme a abertura

Rodar o programa com um clique
Opção A — Usar o terminal integrado

No menu do VS Code, clique em Terminal → Novo Terminal

No terminal que aparece embaixo, digite:
gcc trabalho2.c -o trabalho2


Depois execute:

No Windows:
.\trabalho2.exe


No Linux/macOS:
./trabalho2

Seu programa vai rodar dentro do terminal do VS Code.

 Opção B — Rodar com um botão (Code Runner)

Quer rodar com Ctrl + Alt + N? Faça isso:

No VS Code, abra as Extensões (Ctrl+Shift+X)

Pesquise e instale Code Runner

Abra o arquivo trabalho2.c

Clique no ícone “Run Code” no canto superior direito
ou pressione Ctrl + Alt + N

O Code Runner:

Compila e executa automaticamente

Mostra a saída logo abaixo

Se o Code Runner reclamar que não encontra gcc, é porque o compilador ainda não está no PATH.
Basta corrigir isso seguindo o passo 1.3.
