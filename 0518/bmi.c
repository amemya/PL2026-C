#include <stdio.h>

int main(void) {
  int cm, kg;    // 身長[cm]，体重[kg] を入れるよ
  double m, bmi; // 身長[m]，BMI値 を入れるよ
  int n;         // 肥満度の階級値を入れるよ

  printf("BMIによるメタボ診断\n");
  while (1) {
    printf("----\n");
    printf("身長[cm] 体重[kg] > ");
    scanf("%d %d", &cm, &kg); // 身長・体重の入力

    m = (double)cm / 100.0; // 身長の単位変換
    bmi = kg / (m * m);     // BMIの計算

    printf("BMI = %.1f\n", bmi); // BMIの表示

    if (bmi < 18.5) {
      printf("低体重\n");
    } else if (bmi < 25.0) {
      printf("普通体重\n");
    } else {
      // 肥満度診断
      n = (int)((bmi - 25.0) / 5.0) + 1; // 肥満度の階級化
      switch (n) {
      case 1:
        printf("肥満（１度）\n");
        break;
      case 2:
        printf("肥満（２度）\n");
        break;
      case 3:
        printf("肥満（３度）\n");
        break;
      default:
        printf("肥満（４度）\n");
      }
    }
  }
  return (0);
}