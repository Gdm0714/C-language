#pragma warning(disable:4996)//scanf�� '��ȯ���� ���õǾ����ϴ�' ��� ���� �ذ� ���
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//rand()�Լ��� ������ ���̺귯���� rand()�� ���� ���� ���־���.
#include<time.h>//time()�Լ��� ������ ���̺귯���� srand(time(NULL))�� ���� ���� ���־���. 

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
	if (income <= 1000) {//�Է¹��� ������ 1000���� ������ ���� ���ǹ�
		tax = income * 0.8;
	}
	else if (income <= 4000) {//�Է¹��� ������ 1õ���� �ʰ� 4000���� ������ ���� ���ǹ�
		tax = 1000 * 0.08 + ((income - 1000) * 0.17);
	}
	else if (income <= 8000) {//�Է¹��� ������  4õ���� �ʰ� 8000���� ������ ���� ���ǹ�
		tax = 1000 * 0.08 + 3000 * 0.17 + ((income - 4000) * 0.26);

	}
	else {//�Է¹��� ������ 8000���� �ʰ��� ���� ���ǹ�
		tax = 1000 * 0.08 + 3000 * 0.17 + 4000 * 0.26 + ((income - 8000) * 0.35);
	}
	return tax;
}

double calMoney(double tax, double sal) {
	sal -= tax;
	return sal;
}

double getRate() {
	//�Ź� �ٸ� �õ尪�� �����ϱ� ���� ���̴�.
	double ran = 0;
	ran = rand() % 6 + 2;//+1�� ������ ������ 0�̻� 5�̸��� ���� +1�� ���־ 1�̻� 6�̸��� ���߿��� ���� ���� ���´�.
	ran += 1;
	return ran;
}


int main(void) {
	struct empoly em[5];
	char na;
	float rate[10];
	for (int i = 0; i < 5; i++) {
		srand(time(NULL));
		printf("%d���� �̸� �Է� : ", i + 1);
		scanf("%s", em[i].name);
		printf("%d���� ���� �Է� : ", i + 1);
		scanf("%lf", &em[i].pays->sal[0]);
		for (int j = 0; j < 10; j++) {//i�� 0, 1, 2, 3, 4�� 5�� �ݺ��ϴ� for�ݺ����� ����Ͽ���.

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
		printf("(%d) �̸�: %s\n", i + 1, em[i].name);
		for (int j = 0; j < 10; j++) {
			if (j < 9)
				printf("%d���� ����: %3.0lf��, ����: %3.0lf��, �����ӱ�: %3.0lf��, �����λ��: %3.0lf%\n", j + 1, em[i].pays->sal[j], em[i].pays->tax[j], em[i].pays->money[j], em[i].pays->inc[j]);
			else {
				printf("%d���� ����: %3.0lf��, ����: %3.0lf��, �����ӱ�: %3.0lf��\n\n", j + 1, em[i].pays->sal[j], em[i].pays->tax[j], em[i].pays->money[j]);
			}
		}
	}
}