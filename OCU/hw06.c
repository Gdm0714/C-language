#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)//scanf�� '��ȯ���� ���õǾ����ϴ�' ��� ���� �ذ� ���

int main(void) {
	char text[100];//���ڿ��� �Է¹޾� ������ char�� �迭�� �������ش�.
	int len = 0;
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%[^\n]s", text);//���ڿ��� ������ �����Ͽ� �Է¹ޱ� ����[^\n]�� �߰��Ͽ���.
	printf("���ڿ�  ��� : ");
	char* result = strtok(text, " ");//���ڿ��� �ڸ��� ���� �Լ��� �ڿ� " "�� ���� ������ �������� �߶�����.
	while (result != NULL) {//strtok�Լ��� strtok(NULL, " ")�� �Ѵٸ� ������ �������� �߶��� ���� ���ڷ� �Ѿ�µ� �� �̻� ���� ��� NULL�� �ǹǷ� NULL�� �ƴҶ����� �����Ѵ�.
		len = strlen(result);//strlen�� ���ڿ��� ���̸� �˾Ƴ��� �Լ��̴�.
		for (int i = len - 1; i >= 0; i--) {//���ڿ��� ������ ���� �˾Ƴ� ���ڿ� ������ ���� �ں��� �ݺ����� ������.
			printf("%c", result[i]);
		}
		printf(" ");
		result = strtok(NULL, " ");
	}
	return 0;
}