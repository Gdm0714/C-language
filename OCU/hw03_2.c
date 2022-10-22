#pragma warning(disable:4996)//scanf의 '반환값이 무시되었습니다' 경고에 대한 해결 방안
#include<stdio.h>//#include는 전처리기로 stdio.h를 포함한다는 의미로 내가 작성하는 코드에stdio.h를 포함한다는 뜻이다. stdio.h의 는 입출력 함수에 대한 정보를 가지고 있는 헤더파일로 h가 header를 의미한다.

int main(void) {//main()함수를 정의하는 문장으로 c프로그램을 시작하는 문장이다. int main()과 달리 int main(void)는 매개변수 없이만 호출이 가능하다.
	int number;//입력받은 정수를 받을 변수 선언
	printf("정수를 입력하세요\n");
	scanf("%d", &number);//number에 입력받은 정수 저장
	if (number % 2 == 0) {//입력받은 정수  number가 2로 나눈 나머지가 0일때를 if문으로 표현
		printf("정수 %d는 짝수임.\n", number);
	}
	else {//입력받은 정수  number가 2로 나눈 나머지가 0이 아닐때 이므로 간편하게 else로 구현
		printf("정수 %d는 홀수임.\n", number);
	}
}