#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 6

char buffer[SIZE];
int head = 0, tail = 0, count = 0;

bool isFull() { return count == SIZE; }
bool isEmpty() { return count == 0; }

void write(char c) {
    if (isFull()) {
        printf("Overflow! '%c' lost\n", c);
        return;
    }
    buffer[tail] = c;
    tail = (tail + 1) % SIZE;
    count++;
}

char read() {
    if (isEmpty()) {
        return '\0';
    }
    char c = buffer[head];
    head = (head + 1) % SIZE;
    count--;
    return c;
}

int main() {
    char text[100];
    
    printf("Input: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Buffer size: %d\n", SIZE);
    printf("Text length: %zu\n\n", strlen(text));
    
    for (int i = 0; i < strlen(text); i++) {
        write(text[i]);
    }
    
    printf("\nReading from buffer --\n");
    
    while (!isEmpty()) {
        printf("%c", read());
    }
    
    printf("\n\nBuffer is empty (isEmpty = %d)\n", isEmpty());
    
    return 0;
}
