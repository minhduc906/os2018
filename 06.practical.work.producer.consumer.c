#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct {
	char type; // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i){
	while ((first + 1) % BUFFER_SIZE == last) {
		// do nothing -- no free buffer item
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
		// do nothing -- nothing to consume
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

void display(){
	printf("Value of first: %c %d %c\n",buffer[first].type,buffer[first].amount,buffer[first].unit);
	printf("Value of last: %c %d %c\n",buffer[last].type,buffer[last].amount,buffer[last].unit);
}

int main(){
	item i1,i2;
	i1.type = '0';
	i1.amount = 2;
	i1.unit = '0';
	i2.type = '1';
	i2.amount = 200;
	i2.unit = '1';
	produce(&i1);
	display();
	produce(&i2);
	display();
	consume();
	display();
}
