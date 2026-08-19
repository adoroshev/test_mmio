SRCS = $(wildcard *.c) #переменная для исходников с маской, чтобы брать все файлы с расширением *.c
OBJS = $(SRCS:.c=.o)   #переменная для объектных файлов, где за имя берётся имя исходяника
DEPS = $(SRCS:.c=.d)   #переменная для файлов зависимостей, которые будут создаваться во время компиляции .o
RELEASE_DIR = release
RELEASE_OBJS = $(SRCS:%.c=$(RELEASE_DIR)/%.o)
RELEASE_DEPS = $(SRCS:%.c=$(RELEASE_DIR)/%.d)


#$(info RELEASE_OBJS=$(RELEASE_OBJS))
$(info test=$(RELEASE_DIR))

all: release

release: $(RELEASE_OBJS)           #линковка
	gcc $^ -o $(RELEASE_DIR)/test_mmio

release/%.o: %.c		#создание объектных файлов и файлов зависимостей
	gcc -MMD -MP -c $< -o $@

clean:                 #цель, которая очищает каталог от объектных файлов, зависимостей и слинкованного 
	rm -f $(OBJS) $(DEPS) test_mmio $(RELEASE_DIR)/*
			
-include $(DEPS) $(RELEASE_DEPS)	#включает .d файлы
