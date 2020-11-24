#include<stdio.h>
#include<malloc.h>
int main() {
	char* ff;
	int n, g, r = 0, i, v = 0,m=0;
	scanf_s("%d", &n);
	n++;

	ff = (char*)malloc(n * sizeof(char));
	//sizeof(ff) != NULL;
	if (!(ff = (char*)malloc(n * sizeof(char)))) {
		printf("Sorry");
		return 0;
	}
	getchar();
	fgets(ff, n, stdin);
	fflush(stdin);

	for (i = 0; ff[i] != '\0'; i++) {
		if (ff[i] == '#')
			v++;

	}
	i = 0;
	while (v >= 0) {
		if (ff[0] == '#') {
			g = i;
			while (ff[i] == '#') {
				for (i = 0; ff[i] != '\0';i++) {
					ff[i] = ff[i + 1];

				}
				g++;
				i = g;
				v--;
				if (v == 0) {

					puts(ff);
					free(ff);
					return 0;
				}
			}

		}
		while (ff[i] == '#') {
			m = i;
			for (i; ff[i] != '\0'; i++) {
				ff[i - 1] = ff[i + 1];
			}
			v--;
			m--;
			i = m;
			if (m == 0) {
				while (ff[i] == '#'){
					r++;
					i++;
				}
				
				i = 0;
				for (i; ff[i] != '\0'; i++) {
					ff[i] = ff[i + r];
				}
			
				i = 1;
				v -= r;
				r = 0;
			}
			
			
			
		}


		if (v == 0) {

			puts(ff);
			free(ff);
			return 0;
		}
		if (ff[i] != '#')
			i++;
	}
	puts(ff);
	free(ff);
		return 0;
}
/*Даны натуральное число n и символы s1,…,sn. Среди символов этой строки особую роль играет знак #, появление которого означает отмену предыдущего символа строки; k знаков # отменяет k предыдущих символов.
Преобразовать строку с учетом роли знака #.
Например, строка «VR#Y##HELO#LO» должна быть «HELLO». Результирующую строку вывести на экран.*/