# Alvo padrão que será construído ao rodar 'make'
all: main

# Regra para construir o executável 'main' a partir dos arquivos objeto 'main.o' e 'pedido.o'
main: main.o pedido.o
	@gcc -o main main.o pedido.o  # Comando para linkar os objetos e gerar o executável

# Regra para construir o arquivo objeto 'main.o' a partir do código-fonte 'main.c'
main.o: src/main.c include/pedido.h
	@gcc -c src/main.c  # Comando para compilar 'main.c' gerando 'main.o'

# Regra para construir o arquivo objeto 'pedido.o' a partir do código-fonte 'pedido.c'
pedido.o: src/pedido.c include/pedido.h
	@gcc -c src/pedido.c  # Comando para compilar 'pedido.c' gerando 'pedido.o'

# Regra para limpar os arquivos objeto e o executável gerados durante a compilação
clean:
	@rm -f *.o main  # Comando para remover os arquivos 'main.o', 'pedido.o' e 'main'
