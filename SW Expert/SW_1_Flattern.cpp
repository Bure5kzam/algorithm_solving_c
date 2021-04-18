#include <stdio.h>
#define WIDTH 100
int main() {
	FILE fp = fopen("input.txt", "w";
	int dump, i, j, T, max, min, maxi, mini;
	int arr[] = {0, };
	scanf("%d ", &dump);
	printf("%d\n", dump);

	maxi = -1;
	mini = -1;
	max = -1;
	min = 1001;
	for (i = 0; i < 100; i++) {
		scanf("%d ", &arr[i]);
	}
	for (i = 0; i <= dump; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (max < arr[j]) { max = arr[j], maxi = j; }
			if (min > arr[j]) { min = arr[j], mini = j; }
			arr[maxi] = max - 1;
			arr[mini] = min + 1;
		}
	}
	printf("%d\n");
}