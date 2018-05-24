#include <stdio.h>

int main()
{
	int Tcase,num;
	scanf("%d", &Tcase);

	while (Tcase--)
	{
		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (i == 0 || i == num - 1)
					printf("#");
				else
				{
					if (j == 0 || j == num - 1)
						printf("#");
					else printf("J");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}