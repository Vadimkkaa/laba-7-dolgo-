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
				i=0;
				
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
/*Äàíû íàòóðàëüíîå ÷èñëî n è ñèìâîëû s1,…,sn. Ñðåäè ñèìâîëîâ ýòîé ñòðîêè îñîáóþ ðîëü èãðàåò çíàê #, ïîÿâëåíèå êîòîðîãî îçíà÷àåò îòìåíó ïðåäûäóùåãî ñèìâîëà ñòðîêè; k çíàêîâ # îòìåíÿåò k ïðåäûäóùèõ ñèìâîëîâ.
Ïðåîáðàçîâàòü ñòðîêó ñ ó÷åòîì ðîëè çíàêà #.
Íàïðèìåð, ñòðîêà «VR#Y##HELO#LO» äîëæíà áûòü «HELLO». Ðåçóëüòèðóþùóþ ñòðîêó âûâåñòè íà ýêðàí.*/
