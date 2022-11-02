#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)//scanf의 '반환값이 무시되었습니다' 경고에 대한 해결 방안

int main(void) {
	char text[100];//문자열을 입력받아 저장할 char형 배열을 선언해준다.
	int len = 0;
	printf("문자열을 입력하세요 : ");
	scanf("%[^\n]s", text);//문자열을 공백을 포함하여 입력받기 위해[^\n]를 추가하였다.
	printf("문자열  출력 : ");
	char* result = strtok(text, " ");//문자열을 자르기 위한 함수로 뒤에 " "로 인해 공백을 기준으로 잘라진다.
	while (result != NULL) {//strtok함수에 strtok(NULL, " ")을 한다면 공백을 기준으로 잘라진 다음 문자로 넘어가는데 더 이상 없을 경우 NULL이 되므로 NULL이 아닐때에만 실행한다.
		len = strlen(result);//strlen은 문자열의 길이를 알아내는 함수이다.
		for (int i = len - 1; i >= 0; i--) {//문자열을 뒤집기 위해 알아낸 문자열 길이의 가장 뒤부터 반복문을 돌린다.
			printf("%c", result[i]);
		}
		printf(" ");
		result = strtok(NULL, " ");
	}
	return 0;
}