CC := c++

SRC_DIR := src
OBJ_DIR := src

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
INCLUDE_FILES := $(wildcard $(SRC_DIR)/*.h)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LDFLAGS := -I $(SRC_DIR) -pthread -std=c++11 -g -O2 

main: main.cpp $(OBJ_FILES) $(INLUDE_FILES)  
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(LDFLAGS) -c -o $@ $< 

clean:
	rm $(OBJ_DIR)/*.o main