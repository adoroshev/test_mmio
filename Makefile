SRCS = $(wildcard *.c) #переменная для исходников с маской, чтобы брать все файлы с расширением *.c
OBJS = $(SRCS:.c=.o)   #переменная для объектных файлов, где за имя берётся имя исходяника
DEPS = $(SRCS:.c=.d)   #переменная для файлов зависимостей, которые будут создаваться во время компиляции .o
RELEASE_OBJS = $(SRC:.c=release/.c)
RELEASE_DEPS = $(SRC:.c=release/.o)

all: release

release: $(RELEASE_OBJS)           #линковка
	gcc $^ -o release/test_mmio

%.o: %.c               #создание объектных файлов и файлов зависимостей
	gcc -MMD -MP -c $< -o $@

clean:                 #цель, которая очищает каталог от объектных файлов, зависимостей и слинкованного 
	rm -f $(OBJS) $(DEPS) test_mmio
			
-include $(DEPS) $RELEASE_DEPS	#включает .d файлы
