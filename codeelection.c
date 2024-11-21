#include <stdio.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
    int count[10] = {0}; 

    for (int i = 0; i < n; i++) {
        count[votes[i] - 1]++;
    }

    int max = count[0];
    *most_voted = 1;
    for (int i = 1; i < 10; i++) {
        if (count[i] > max) {
            max = count[i];
            *most_voted = i + 1;
        }
    }

    int second_max = 0;
    *second_most_voted = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] > second_max && i != *most_voted - 1) {
            second_max = count[i];
            *second_most_voted = i + 1;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int votes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &votes[i]);
    }

    int most_voted, second_most_voted;
    compute_votes(n, votes, &most_voted, &second_most_voted);

    printf("%d %d", most_voted, second_most_voted);

    return 0;
}
