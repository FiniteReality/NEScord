#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include <nes.h>

static const char message[] = "Hello, world!";

int main(void)
{
	unsigned char XSize, YSize;

	clrscr();
	screensize(&XSize, &YSize);

	gotoxy((XSize - strlen(message)) / 2, YSize / 2);
	cprintf("%s", message);

	while (1) ;

	clrscr();

	return 0;
}
