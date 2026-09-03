#include <stdio.h>  

#define MAX 100

int total(int m[], int s) {
    int t = 0;
    for (int i = 0; i < s; i++) t += m[i];
    return t;
}

float percent(int t, int s) {
    return (float)t / (s * 100) * 100;
}

char grade(float p) {
    if (p >= 90) return 'A';
    else if (p >= 75) return 'B';
    else if (p >= 60) return 'C';
    else if (p >= 50) return 'D';
    else return 'F';
}

int main() {
    int n, s;
    char name[MAX][30];
    int marks[MAX][5];
    int tot[MAX], top = 0;
    float per[MAX];
    char g[MAX];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter number of subjects (3-5): ");
    scanf("%d", &s);

    for (int i = 0; i < n; i++) {
        printf("\nEnter student name: ");
        scanf("%s", name[i]);

        for (int j = 0; j < s; j++) {
            printf("Enter marks of subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }

        tot[i] = total(marks[i], s);
        per[i] = percent(tot[i], s);
        g[i] = grade(per[i]);

        if (per[i] > per[top]) top = i;
    }

    printf("\n--- RESULTS ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s\nTotal: %d\nPercentage: %.2f\nGrade: %c\n",
               name[i], tot[i], per[i], g[i]);
    }

    printf("\nTopper: %s (%.2f%%)\n", name[top], per[top]);

    return 0;
}
