CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = HW2main
OBJS = HW2main.o approximations.o pi_approx.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

HW2main.o: HW2main.cpp approximations.h pi_approx.h
	$(CC) $(CFLAGS) -c HW2main.cpp

approximations.o: approximations.cpp approximations.h pi_approx.h
	$(CC) $(CFLAGS) -c approximations.cpp

pi_approx.o: pi_approx.cpp pi_approx.h
	$(CC) $(CFLAGS) -c pi_approx.cpp

clean:
	rm -f $(TARGET) $(OBJS)
