#include<stdio.h>
#pragma warning(disable:4996)//scanf의 '반환값이 무시되었습니다' 경고에 대한 해결 방안

int main(void) {
	int g;//g을 받을 정수형 변수 선언
	printf("정수를 입력하세요\n");//정수를 입력하라는 문장을 출력
	scanf("%d", &g);//입력받은 정수를 변수g에 저장
	double kg = (double)g / 1000;//g을 kg으로 바꾸기 위해 1000을 나눠주고 double형으로 강제 형 변환
	printf("%d g = %lf kg\n", g, kg);//정수형 변수g와 실수형 변수kg을 각각 %d와 %lf를 이용하여 출력
	short int kg2 = kg;//실수형 변수 kg의 값을 받을 short int형 변수 kg2를 선언하여 변수kg의 값 저장
	printf("%d(short int), %lf(double)", kg2, kg);//short int형 변수kg2와 실수형 변수kg을 각각 %d와 %lf를 이용하여 출력
	return 0;
}