#include<stdio.h>
#pragma warning(disable:4996)//scanf�� '��ȯ���� ���õǾ����ϴ�' ��� ���� �ذ� ���

int main(void) {
	int g;//g�� ���� ������ ���� ����
	printf("������ �Է��ϼ���\n");//������ �Է��϶�� ������ ���
	scanf("%d", &g);//�Է¹��� ������ ����g�� ����
	double kg = (double)g / 1000;//g�� kg���� �ٲٱ� ���� 1000�� �����ְ� double������ ���� �� ��ȯ
	printf("%d g = %lf kg\n", g, kg);//������ ����g�� �Ǽ��� ����kg�� ���� %d�� %lf�� �̿��Ͽ� ���
	short int kg2 = kg;//�Ǽ��� ���� kg�� ���� ���� short int�� ���� kg2�� �����Ͽ� ����kg�� �� ����
	printf("%d(short int), %lf(double)", kg2, kg);//short int�� ����kg2�� �Ǽ��� ����kg�� ���� %d�� %lf�� �̿��Ͽ� ���
	return 0;
}