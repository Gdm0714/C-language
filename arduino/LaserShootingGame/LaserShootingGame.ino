#include <TM1637TinyDisplay.h>
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

// Pin 3 - > CLK
// Pin 2 - > DIO
TM1637TinyDisplay tm(3, 2);

int timeDelay = 20;  //0.02초 단위로 체크하여 모션을 만들어 준다.

int sensor_value;   //1번 조도센서값
int sensor_value2;  //2번 조도센서값
int sensor_value3;  //3번 조도센서값


int Servopin1 = 6;  //1번 서보모터
int Servopin2 = 9;  //2번 서보모터
int Servopin3 = 8;  //3번 서보모터
int buzzer = 10;    //부저 pin
int btn = 5;        //버튼 pin
int lightPin1 = 0;
int lightPin2 = 1;
int lightPin3 = 2;


boolean redStatus = LOW;
boolean yellowStatus = LOW;
boolean greenStatus = LOW;
int redPin = 13;
int yellowPin = 12;
int greenPin = 11;


int stopTimeCnt = 0;
int stopTimeCnt2 = 0;
int stopTimeCnt3 = 0;
int chkTimeCnt = 0;
int getScore = 0;
int displayValue = 0;
int toneCnt = 0;



int sleepTime = 40;  //타겟이 누워서 머무는 시간 - timeDelay가 loop가 한번 도는데 걸리는 시간이 0.02초 이므로 1초는 50이다.
int LimitTime = 20;  //게임 시간

int getTimeInt = LimitTime;
void setup() {
  //tm.init();
  myservo1.attach(Servopin1);
  myservo2.attach(Servopin2);
  myservo3.attach(Servopin3);
  pinMode(buzzer, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);
}


//조도센서값, 조도센서 조건범위, 타겟제어정수값, 타겟이 누웠을때의 서보모터값, 타겟이 서있을때의 서보모터값, 서보모터
int DoWorking(int sv, int sval, int stc, int servoS, int servoE, Servo mySv) {

  if (stc < 1) {    //1번 타겟이 명중되기 전이라면
    if (sv < sval)  //조도센서값을 체크하여 서보모터를 움직여준다. 기준값은 취향대로 설정해준다.
    {
      mySv.write(servoS);  //명중하면 서보모터 각도를 움직여 타겟을 눕혀준다.
      stc = 1;             //타겟이 누워있는동안은 서보모터를 움직이지 못하게 하기 위해 stop 값을 1로 설정해 멈춤을 알려준다.
    } else {
      mySv.write(servoE);  //타겟이 서있는 각도값을 지정해준다.
    }
  }

  if (stc > 0 && stc <= sleepTime) {  // 타겟이 명중하면
    if (stc == 1) {
      getScore += 10;  //점수를 올려준다.
    }
    stc++;
  } else if (stc > sleepTime) {  //stop 50보다 큰경우 즉 약 2.5초 후에(timeDelay * 4 가 loop가 한번 도는데 걸리는 시간이므로 1초는 20번 돌아야 한다)
    stc = 0;
  }
  return stc;
}

int DoWorking3(int sv, int sval, int stc, int servoS, int servoE, Servo mySv, boolean redStatus, boolean yellowStatus, boolean greenStatus) {
  if (stc < 1) {
    if (sv < sval) {
      mySv.write(servoS);
      stc = 1;
    } else {
      mySv.write(servoE);
    }
  }

  if (stc > 0 && stc <= sleepTime) {
    if (stc == 1) {
      if (greenStatus == HIGH) {
        getScore += 20;
      }
      if (redStatus == HIGH) {
        getScore -= 5;  // 빨간색일 때는 점수 감소
      }
    }
    stc++;
  } else if (stc > sleepTime) {
    stc = 0;
  }
  return stc;
}





void loop() {
  int btnVal = digitalRead(btn);  //누르면 0  게임을 세로 시작하기위한 버튼값
  chkTimeCnt++;

  if (chkTimeCnt <= 15) {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  } else if (chkTimeCnt <= 30) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
  } else if (chkTimeCnt <= 50) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  }

  redStatus = digitalRead(redPin);
  yellowStatus = digitalRead(yellowPin);
  greenStatus = digitalRead(greenPin);

  if (getTimeInt <= 0) {       //0초가 되면 모두 멈추고 부저로 소리를 만든다.
    if (toneCnt < 3) {         //알림이 총 3번 울리도록 설정
      if (chkTimeCnt <= 30) {  //0.6초에 한번 소리나도록 한다. 50번이 1초
        tone(buzzer, 330, 20);
      } else if (chkTimeCnt > 30 && chkTimeCnt <= 60) {
        noTone(buzzer);
      } else {
        chkTimeCnt = 0;
        toneCnt++;
      }
    } else {
      if (btnVal == 0) {         //누른값이 있다면 초기값으로 셋팅
        stopTimeCnt = 0;         //1번째 타겟을 조율하기 위한 정수 값
        stopTimeCnt2 = 0;        //2번째 타겟을 조율하기 위한 정수 값
        stopTimeCnt3 = 0;        //3번째 타겟을 조율하기 위한 정수 값
        chkTimeCnt = 0;          //시간을 측정하기 위한 정수값 50 = 1초
        getTimeInt = LimitTime;  //최초 게임 제한 시간 설정, 현재 남은 시간(초)
        getScore = 0;            //점수
        toneCnt = 0;             //게임 종료시 부저 소리 노출 횟수
        displayValue = 0;
      }
    }




  } else {  //30초 안에 있으면 게임을 작동시켜준다.
    noTone(buzzer);

    sensor_value = analogRead(lightPin1);  //1번 타겟의 조도센서값을 실시간으로 체크해준다.
    stopTimeCnt = DoWorking(sensor_value, 700, stopTimeCnt, 110, 20, myservo1);

    sensor_value2 = analogRead(lightPin2);  //2번 타겟의 조도센서값을 실시간으로 체크해준다.
    stopTimeCnt2 = DoWorking(sensor_value2, 700, stopTimeCnt2, 110, 20, myservo2);

    sensor_value3 = analogRead(lightPin3);  //3번 타겟의 조도센서값을 실시간으로 체크해준다.
    stopTimeCnt3 = DoWorking3(sensor_value3, 700, stopTimeCnt3, 110, 20, myservo3, redStatus, yellowStatus, greenStatus);


    if (chkTimeCnt >= 50) {  //chkTimeCnt 1회가 0.02초, 50번이면 1초이다.
      chkTimeCnt = 0;
      getTimeInt--;
    }

    displayValue = getScore;
  }


  tm.setBrightness(7, true);          //밝기값
  tm.showNumber(displayValue, true);  //시간표시

  Serial.println(sensor_value2);
  delay(timeDelay);
}
