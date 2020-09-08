#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n, i, j;
    printf("Enter the number of data: ");
    scanf("%d", &n);
    float x[n], y[n], x1 = 0.0, y1 = 0.0, xy = 0.0, x2 = 0.0, y2 = 0.0;
    printf("Enter the x and its respective y:\n");
    for(i = 0; i < n; i++){
        printf("x%d: ", i + 1);
        scanf("%f", &x[i]);
        printf("y%d: ", i + 1);
        scanf("%f", &y[i]);
        x1 += x[i];
        x2 += x[i] * x[i];
        y1 += y[i];
        y2 += y[i] * y[i];
        xy += x[i] * y[i];
    }
    float rc,rc1;
    rc = (n * xy - x1 * y1) / (n * x2 - pow(x1, 2));
    rc1 = (n * xy - x1 * y1) / (n * y1 - pow(y1, 2));
    float ans  =rc*rc1;
    ans = sqrt(ans);
        printf("Regression : %f", ans);
}
