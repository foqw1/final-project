#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int main(){
    int i, j, k;
    int tmp;
    int Strike, Ball;
    int ComputerBall[3];
    int UserBall[3];
    int wrong = 0;
    int count = 1;

    srand((unsigned)time(NULL));
    for (i = 0; i < 3; i++){
        tmp = rand() % 9 + 1; // tmp에 현재 랜덤 값을 저장한다.
        ComputerBall[i] = tmp; // 저장되있던 tmp을 ComputerBall에 저장한다. 
        for (j = 0; j < i; j++) { // 현재 추가된 만큼 반복.
            if (tmp == ComputerBall[j] && i != j) { // 만약 현재 tmp값과 이전에 넣은 값 중 동일한 게 있다면 
                i--; // i의 값을 줄여 다시 이전으로 돌아가도록 한다.
            }
        }
    }

    printf("############################################################\n");
    printf("# [숫자 야구 게임]을 시작합니다.                           #\n");
    printf("# 1~9까지의 수 중, 중복되지 않는 숫자 3개를 입력해 주세요. #\n");
    printf("# 1~9까지의 수 밖의 수를 입력하면 게임을 중단합니다.       #\n");
    printf("############################################################\n\n");

    while (1) // 본 게임 시작
    {
        while (1) { // 조건에 맞는 숫자만 입력받기 위한 반복.
            printf("[%d번째 게임] 숫자 입력 : ", count);
            scanf("%d %d %d", &UserBall[0], &UserBall[1], &UserBall[2]);
            if (UserBall[0] == UserBall[1] || UserBall[1] == UserBall[2] || UserBall[2] == UserBall[0]) {  // 중복된 숫자가 존재시 다시 입력받는다.
                printf("중복된 숫자입니다 다시 입력해 주세요.\n\n");
            }
            else { 
                break; //입력에 문제 없다면 반복을 종료.
            }
        }
        
        if ((UserBall[0] < 0 || UserBall[0] > 9) || (UserBall[1] < 0 || UserBall[1] > 9) || (UserBall[0] < 0 || UserBall[0] > 9)) { // 1~9이외의 숫자가 하나라도 있으면 게임을 종료.
            printf("\n");
            printf("게임을 종료합니다...");
            break;
        }

        Ball = 0;
        Strike = 0;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) { // ComputerBall[1]~[3]에 따라 각 UserBall[1]~[3] 비교.
                if (ComputerBall[i] == UserBall[j]) { // 비교한 값이 같으면
                    if (i == j) { // 같은 위치일때
                        Strike++;
                    }
                    else { // 다른 위치일때
                        Ball++;
                    }
                }
            }
        }

        if (Ball == 0 && Strike == 0) { // 만약 위치도 값도 다를때.
            wrong++;
        }
        
        printf("%d [Strike], %d [Ball]\n\n", Strike, Ball);

        if (Strike == 3) // 스트라이크가 3개면 승리.
        {
            printf("Out~!!\n\n");

            printf("############################################################\n");
            printf("# 계속 하시겠습니까? 1(계속) or 2(종료)                    #\n");
            printf("############################################################\n");
            scanf("%d", &k);
            if (k == 2) { // 입력된 값이 2이면 종료
                printf("게임을 종료합니다...");
                break;
            }
            for (i = 0; i < 3; i++) { // 다시 값을 랜덤하게 지정.
                tmp = rand() % 9 + 1;
                ComputerBall[i] = tmp;
                for (j = 0; j < i; j++) {
                    if (tmp == ComputerBall[j] && i != j) {
                        i--;
                    }
                }
            }
            printf("\n");
        }

        else if (wrong == 3) // 누적된 wrong이 3이면 패배
        {
            printf("세 번 이상 노스트라이크 노볼로 패배\n\n");

            printf("############################################################\n");
            printf("# 계속 하시겠습니까? 1(계속) or 2(종료)                    #\n");
            printf("############################################################\n");
            scanf("%d", &k);
            if (k == 2) {
                printf("게임을 종료합니다...");
                break;
            }
            for (i = 0; i < 3; i++) {
                tmp = rand() % 9 + 1;
                ComputerBall[i] = tmp;
                for (j = 0; j < i; j++) {
                    if (tmp == ComputerBall[j] && i != j) {
                        i--;
                    }
                }
            }
            printf("\n");
            wrong = 0; // 게임을 다시 하기 위해 wrong 값을 리셋.
        }

        count++; // 게임의 한사이클
    }
    return 0;
}