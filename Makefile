SRCS = $(wildcard *.c)				#исходники с маской, чтобы брать все файлы с расширением *.c
OBJS = $(SRCS:.c=.o)				#объектные файлов, где за имя берётся имя исходяника
DEPS = $(SRCS:.c=.d)				#зависимости, которые будут создаваться во время компиляции .o
RELEASE_DIR = release				#релизная директория
RELEASE_OBJS = $(SRCS:%.c=$(RELEASE_DIR)/%.o)	#релизные .o
RELEASE_DEPS = $(SRCS:%.c=$(RELEASE_DIR)/%.d)	#релизные .d
DEBUG_DIR = debug				#дебажная директория
DEBUG_OBJS = $(SRCS:%.c=$(DEBUG_DIR)/%.o)	#дебажные .o
DEBUG_DEPS = $(SRCS:%.c=$(DEBUG_DIR)/%.d)	#дебажные .d

all: release

release: $(RELEASE_OBJS)			#линковка релиза
	gcc $^ -o $(RELEASE_DIR)/test_mmio

debug: $(DEBUG_OBJS)				#линковка дебага
	gcc $^ -o $(DEBUG_DIR)/test_mmio

$(RELEASE_DIR)/%.o: %.c				#создание .o и .d для релиза с включённой оптимизацией
	gcc -MMD -MP -O3 -c $< -o $@

$(DEBUG_DIR)/%.o: %.c				#создание .o и .d для дебага с включённой отладкой
	gcc -MMD -MP -Og -c $< -o $@

clean:                 				#очистка корня, release и debug от .o, .d 
	rm -f $(OBJS) $(DEPS) test_mmio $(RELEASE_DIR)/* $(DEBUG_DIR)/*
			
-include $(DEPS) $(RELEASE_DEPS) $(DEBUG_DEPS)	#включает .d файлы для отслеживания изменения зависимостей
