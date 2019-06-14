
#include "util.h"

typedef struct _student {
	char* name;
	char* no;
	int age;
} student;

int main() {
	PRINT_SIZE_OF(sizeof(student));
	student* s = (student*)calloc(1,sizeof(student));
	s->name = "jack";
	s->no = "1";
	s->age = 23;

	return 0;
}
