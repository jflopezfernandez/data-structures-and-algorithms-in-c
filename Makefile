
vpath %.c src

RM := rm -f

CC := gcc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic #-O0 -ggdb -g3 -fanalyzer -fsanitize=address -fstack-protector-strong
CPPFLAGS := -Iinclude -D_GNU_SOURCE
LDFLAGS := -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now,--error-unresolved-symbols #,-L/home/jflopezfernandez/projects/c/jlibc,-rpath,/home/jflopezfernandez/projects/c/jlibc
LIBS := -ljc

CPPFLAGS := $(CPPFLAGS) #-I/home/jflopezfernandez/projects/c/jlibc/include
LDFLAGS := $(LDFLAGS) #-L/home/jflopezfernandez/projects/c/jlibc

SRCS := $(notdir $(wildcard src/*.c))
OBJS := $(patsubst %.c,%.o,$(SRCS))

TARGET := dsa

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
