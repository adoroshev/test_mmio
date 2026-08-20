CC = gcc

CFLAGS = -MMD -MP

# Название программы
APP = test_mmio

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

# Префикс для конструирования других переменных
PREFIX = /usr/local

# Путь для установки программы
BINDIR = $(PREFIX)/bin

#Команда для установки программ
INSTALL = install

#Явное объявление абстрактных целей
.PHONY: all release debug install clean distclean dist

all: release

# Линковка release
release: $(RELEASE_OBJS)
	$(CC) $^ -o $(RELEASE_DIR)/$(APP)

# Линковка debug
debug: $(DEBUG_OBJS)
	$(CC) $^ -o $(DEBUG_DIR)/$(APP)

# Установка release в систему
install: release
	$(INSTALL) -m 755 $(RELEASE_DIR)/$(APP) $(BINDIR)

# Архивируем исходники и Makefile
dist: $(SRCS) Makefile
	tar -czf $(APP).tar.gz $^

# Создание release .o и .d с включённой оптимизацией
$(RELEASE_DIR)/%.o: %.c
	mkdir -p $(RELEASE_DIR)
	$(CC) $(CFLAGS) -O3 -c $< -o $@

# Создание debug .o и .d с включённой отладкой
$(DEBUG_DIR)/%.o: %.c
	mkdir -p $(DEBUG_DIR)
	$(CC) $(CFLAGS) -g -c $< -o $@

# Очистка корня, release и debug от .o, .d
clean:
	rm -f $(OBJS) $(DEPS) $(APP) $(RELEASE_DIR)/* $(DEBUG_DIR)/*

# Цель аналогична clean
distclean: clean

# Включает .d файлы для отслеживания изменения зависимостей
-include $(DEPS) $(RELEASE_DEPS) $(DEBUG_DEPS)
