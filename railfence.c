#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Y 4
#define MAX 1000

int main() {
	int *m;
	int *q;
	
	m = (int*)malloc(sizeof(int*));
	q = (int*)malloc(sizeof(int*));
	
	*m = 0;
	*q = (2 * Y) - 2;
	
	int k[Y];
	int i = 0;
	while (i < Y) {
			k[i] = *q - *m;
			*m = *m + 2;
			i++;
	}
	k[Y - 1] = k[0];
	
	free(m);
	free(q);

	printf("CHAVE:%d\n", Y);
	
	char str[MAX];
	printf("MENSAGEM:");
	scanf("%s", str);
	
	int len;
	len = strlen(str);
	printf("TAMANHO:%d\n", len);
	
	printf("CIFRA:");
	
	int temp; 
	int l = 0, n = Y - 1;
	int j = 0; 
	for(i = 0; i < Y && i < len; i++) {
		temp = i;
		do {
			if ((j % 2) == 0) {
				printf("%c", str[i]);
				i = i + k[l];	
			}
			else {
				printf("%c", str[i]);
				i = i + k[n];
			}
			j++;
		} while (i < len);
		l = l + 1;
		n = n - 1;
		i = temp;
		j = 0;
	}
	printf("\n");
	return 0;
}
