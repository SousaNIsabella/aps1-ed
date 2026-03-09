CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Nomes dos executaveis
TARGET_LISTA = teste_lista
TARGET_SIM = teste_similaridade

# Arquivos fonte de cada atividade
SRC_LISTA = listacompras.cpp main_test_lista.cpp
SRC_SIM = listacompras.cpp similaridade.cpp main_test_similaridade.cpp

# A regra 'all' agora compila os dois programas
all: $(TARGET_LISTA) $(TARGET_SIM)

# Compila a Atividade 1
$(TARGET_LISTA): $(SRC_LISTA)
	$(CXX) $(CXXFLAGS) $(SRC_LISTA) -o $(TARGET_LISTA)

# Compila a Atividade 2
$(TARGET_SIM): $(SRC_SIM)
	$(CXX) $(CXXFLAGS) $(SRC_SIM) -o $(TARGET_SIM)

# Executa a Atividade 1 com o CSV de 7 mil linhas
run_lista: $(TARGET_LISTA)
	./$(TARGET_LISTA) dados_venda_cluster_20.csv

# Executa a Atividade 2 com o CSV de 7 mil linhas
run_sim: $(TARGET_SIM)
	./$(TARGET_SIM) dados_venda_cluster_20.csv

# Limpa os executaveis gerados
clean:
	rm -f $(TARGET_LISTA).exe $(TARGET_SIM).exe