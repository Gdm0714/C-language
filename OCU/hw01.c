#include<stdio.h>//#include는 전처리기로 stdio.h를 포함한다는 의미로 내가 작성하는 코드에stdio.h를 포함한다는 뜻이다. stdio.h의 는 입출력 함수에 대한 정보를 가지고 있는 헤더파일로 h가 header를 의미한다.
int main(void) {
	printf("HELLO! This is my first C program.\n\r");//printf는 원하는 것을 출력할때 사용하는 것이고 \n은 줄바꿈 문자, \r은 현재 줄의 처음으로 이동하는 것이다. 
	printf("고동민: 인제대학교 컴퓨터공학부 학번 20192601 goes for a great C programmer.\n\r");//\n은 줄을 바꾸기 위한 것이고, \r은 그 줄의 첫번째로 이동하기 위한 것이다.
	return (0);//해당 함수를 끝내고 운영체제에게 값을 반환하고 실행 중인 해당 함수를 벗어나겠다는 뜻이다.
}