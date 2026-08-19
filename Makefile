CC = gcc

# Все исходники с расширением *.c
SRCS = $(wildcard *.c)

# Объектные файлы, где за имя берётся имя исходника
OBJS = $(SRCS:.c=.o)

# Списки зависимостей в формате Makefile, которые будут создаваться во время компиляции .o
DEPS = $(SRCS:.c=.d)

# Директория для release
RELEASE_DIR = release

# Релизные .o
RELEASE_OBJS = $(SRCS:%.c=$(RELEASE_DIR)/%.o)

# Релизные .d
RELEASE_DEPS = $(SRCS:%.c=$(RELEASE_DIR)/%.d)

# Директория для debug
DEBUG_DIR = debug

# Дебажные .o
DEBUG_OBJS = $(SRCS:%.c=$(DEBUG_DIR)/%.o)

# Дебажные .d
DEBUG_DEPS = $(SRCS:%.c=$(DEBUG_DIR)/%.d)

all: release

# Линковка release
release: $(RELEASE_OBJS)
	$(CC) $^ -o $(RELEASE_DIR)/test_mmio

# Линковка debug
debug: $(DEBUG_OBJS)
	$(CC) $^ -o $(DEBUG_DIR)/test_mmio

# Создание release .o и .d с включённой оптимизацией
$(RELEASE_DIR)/%.o: %.c
	mkdir -p $@
	$(CC) -MMD -MP -O3 -c $< -o $@

# Создание debug .o и .d с включённой отладкой
$(DEBUG_DIR)/%.o: %.c
	mkdir -p $@
	$(CC) -MMD -MP -Og -c $< -o $@

# Очистка корня, release и debug от .o, .d
clean:                 			#очистка корня, release и debug от .o, .d 
	rm -f $(OBJS) $(DEPS) test_mmio $(RELEASE_DIR)/* $(DEBUG_DIR)/*
			
# Включает .d файлы для отслеживания изменения зависимостей
-include $(DEPS) $(RELEASE_DEPS) $(DEBUG_DEPS)
