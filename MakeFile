# Nombre del ejecutable
TARGET = programa

# Compilador
CXX = g++

# Flags del compilador
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Directorios
SRC_DIR = .
BUILD_DIR = build

# Encuentra todos los archivos .cpp en el proyecto
SRCS := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Regla para compilar el programa
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Regla para compilar los archivos .cpp en .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Regla por defecto
.PHONY: all clean
all: $(TARGET)