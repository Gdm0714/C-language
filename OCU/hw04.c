#pragma warning(disable:4996)//scanf�� '��ȯ���� ���õǾ����ϴ�' ��� ���� �ذ� ���
#include<stdio.h>
#include<stdlib.h>

int getIncom() {
	int income;
	scanf("%d", income);
	return income;
}

void calclncomeTax(int income) {
	if (income <= 1000) {
		income -= income * 0.8;
	}
	else if (income <= 4000) {
		income -= 1000 * 0.8 + ((income - 1000) * 0.17);
	}
	else if (income <= 8000) {
		income -= 1000 * 0.8 + 4000 * 0.17 + ((income - 4000) * 0.26);
	}
	else {
		income -= 1000 * 0.8 + 4000 * 0.17 + 8000 * 0.26 + ((income - 8000) * 0.35);
	}
	printf("%d\n", income);
}

int getRate(int income) {
	income += income * (((rand() % 5) + 1) / 100);
	return income;
}

int main(void) {                                                     
	int income, money;
	for (int i = 0; i < 5; i++) {
		printf("%d�� ������ �Է��ϼ���.\n", i + 1);
		income = getIncom();
		for (int year = 0; year < 30; year++) {
			money = income;
			calclncomeTax(money);
			income = getRate(income);
		}
	}
}