#pragma warning(disable:4996)//scanf의 '반환값이 무시되었습니다' 경고에 대한 해결 방안
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//rand()함수를 포함한 라이브러리로 rand()를 쓰기 위해 써주었다.
#include<time.h>//time()함수를 포함한 라이브러리로 srand(time(NULL))을 쓰기 위해 써주었다. 

struct info {
	double sal[10];
	double inc[10];
	double tax[10];
	double money[10];
};

struct empoly {
	char name[100];
	struct info pays[10];
};

double getIncom() {
	double income = 0;
	scanf("%lf", &income);
	return income;
}

double calclncomeTax(double income) {
	double tax;
	if (income <= 1000) {//입력받은 연봉이 1000만원 이하일 때의 조건문
		tax = income * 0.8;
	}
	else if (income <= 4000) {//입력받은 연봉이 1천만원 초과 4000만원 이하일 때의 조건문
		tax = 1000 * 0.08 + ((income - 1000) * 0.17);
	}
	else if (income <= 8000) {//입력받은 연봉이  4천만원 초과 8000만원 이하일 때의 조건문
		tax = 1000 * 0.08 + 3000 * 0.17 + ((income - 4000) * 0.26);

	}
	else {//입력받은 연봉이 8000만원 초과일 때의 조건문
		tax = 1000 * 0.08 + 3000 * 0.17 + 4000 * 0.26 + ((income - 8000) * 0.35);
	}
	return tax;
}

double calMoney(double tax, double sal) {
	sal -= tax;
	return sal;
}

double getRate() {
	//매번 다른 시드값을 생성하기 위한 것이다.
	double ran = 0;
	ran = rand() % 6 + 2;//+1을 해주지 않으면 0이상 5미만의 수로 +1을 해주어서 1이상 6미만의 수중에서 랜덤 값이 나온다.
	ran += 1;
	return ran;
}


int main(void) {
	struct empoly em[5];
	char na;
	float rate[10];
	for (int i = 0; i < 5; i++) {
		srand(time(NULL));
		printf("%d직원 이름 입력 : ", i + 1);
		scanf("%s", em[i].name);
		printf("%d직원 연봉 입력 : ", i + 1);
		scanf("%lf", &em[i].pays->sal[0]);
		for (int j = 0; j < 10; j++) {//i가 0, 1, 2, 3, 4로 5번 반복하는 for반복문을 사용하였다.

			rate[j] = getRate();
			em[i].pays->tax[j] = calclncomeTax(em[i].pays->sal[j]);
			em[i].pays->money[j] = calMoney(em[i].pays->tax[j], em[i].pays->sal[j]);
			if (i == 0) {
				em[i].pays->inc[j] = rate[j];
				em[i + 1].pays->inc[j] = rate[j];
				em[i + 2].pays->inc[j] = rate[j];
				em[i + 3].pays->inc[j] = rate[j];
				em[i + 4].pays->inc[j] = rate[j];
			}
			if (j < 9)
				em[i].pays->sal[j + 1] = em[i].pays->sal[j] + em[i].pays->sal[j] * (em[i].pays->inc[j] / 100);
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("(%d) 이름: %s\n", i + 1, em[i].name);
		for (int j = 0; j < 10; j++) {
			if (j < 9)
				printf("%d년차 연봉: %3.0lf원, 세금: %3.0lf원, 실질임금: %3.0lf원, 연봉인상률: %3.0lf%\n", j + 1, em[i].pays->sal[j], em[i].pays->tax[j], em[i].pays->money[j], em[i].pays->inc[j]);
			else {
				printf("%d년차 연봉: %3.0lf원, 세금: %3.0lf원, 실질임금: %3.0lf원\n\n", j + 1, em[i].pays->sal[j], em[i].pays->tax[j], em[i].pays->money[j]);
			}
		}
	}
}