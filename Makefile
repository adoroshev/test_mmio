SRCS = $(wildcard *.c) #переменная для исходников с маской, чтобы брать все файлы с расширением *.c
OBJS = $(SRCS:.c=.o)   #переменная для объектных файлов, где за имя берётся имя исходяника
DEPS = $(SRCS:.c=.d)   #переменная для файлов зависимостей, которые будут создаваться во время компиляции .o
RELEASE_OBJS = $(SRCS:%.c=release/%.o)
RELEASE_DEPS = $(SRCS:%.c=release/%.d)

$(info RELEASE_OBJS=$(RELEASE_OBJS))

all: release

release: $(RELEASE_OBJS)           #линковка
	gcc $^ -o release/test_mmio

release/%.o: %.c               #создание объектных файлов и файлов зависимостей
	gcc -MMD -MP -c $< -o $@

clean:                 #цель, которая очищает каталог от объектных файлов, зависимостей и слинкованного 
	rm -f $(OBJS) $(DEPS) test_mmio
			
-include $(DEPS) $(RELEASE_DEPS)	#включает .d файлы
