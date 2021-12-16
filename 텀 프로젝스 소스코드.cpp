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
        tmp = rand() % 9 + 1; // tmp�� ���� ���� ���� �����Ѵ�.
        ComputerBall[i] = tmp; // ������ִ� tmp�� ComputerBall�� �����Ѵ�. 
        for (j = 0; j < i; j++) { // ���� �߰��� ��ŭ �ݺ�.
            if (tmp == ComputerBall[j] && i != j) { // ���� ���� tmp���� ������ ���� �� �� ������ �� �ִٸ� 
                i--; // i�� ���� �ٿ� �ٽ� �������� ���ư����� �Ѵ�.
            }
        }
    }

    printf("############################################################\n");
    printf("# [���� �߱� ����]�� �����մϴ�.                           #\n");
    printf("# 1~9������ �� ��, �ߺ����� �ʴ� ���� 3���� �Է��� �ּ���. #\n");
    printf("# 1~9������ �� ���� ���� �Է��ϸ� ������ �ߴ��մϴ�.       #\n");
    printf("############################################################\n\n");

    while (1) // �� ���� ����
    {
        while (1) { // ���ǿ� �´� ���ڸ� �Է¹ޱ� ���� �ݺ�.
            printf("[%d��° ����] ���� �Է� : ", count);
            scanf("%d %d %d", &UserBall[0], &UserBall[1], &UserBall[2]);
            if (UserBall[0] == UserBall[1] || UserBall[1] == UserBall[2] || UserBall[2] == UserBall[0]) {  // �ߺ��� ���ڰ� ����� �ٽ� �Է¹޴´�.
                printf("�ߺ��� �����Դϴ� �ٽ� �Է��� �ּ���.\n\n");
            }
            else { 
                break; //�Է¿� ���� ���ٸ� �ݺ��� ����.
            }
        }
        
        if ((UserBall[0] < 0 || UserBall[0] > 9) || (UserBall[1] < 0 || UserBall[1] > 9) || (UserBall[0] < 0 || UserBall[0] > 9)) { // 1~9�̿��� ���ڰ� �ϳ��� ������ ������ ����.
            printf("\n");
            printf("������ �����մϴ�...");
            break;
        }

        Ball = 0;
        Strike = 0;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) { // ComputerBall[1]~[3]�� ���� �� UserBall[1]~[3] ��.
                if (ComputerBall[i] == UserBall[j]) { // ���� ���� ������
                    if (i == j) { // ���� ��ġ�϶�
                        Strike++;
                    }
                    else { // �ٸ� ��ġ�϶�
                        Ball++;
                    }
                }
            }
        }

        if (Ball == 0 && Strike == 0) { // ���� ��ġ�� ���� �ٸ���.
            wrong++;
        }
        
        printf("%d [Strike], %d [Ball]\n\n", Strike, Ball);

        if (Strike == 3) // ��Ʈ����ũ�� 3���� �¸�.
        {
            printf("Out~!!\n\n");

            printf("############################################################\n");
            printf("# ��� �Ͻðڽ��ϱ�? 1(���) or 2(����)                    #\n");
            printf("############################################################\n");
            scanf("%d", &k);
            if (k == 2) { // �Էµ� ���� 2�̸� ����
                printf("������ �����մϴ�...");
                break;
            }
            for (i = 0; i < 3; i++) { // �ٽ� ���� �����ϰ� ����.
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

        else if (wrong == 3) // ������ wrong�� 3�̸� �й�
        {
            printf("�� �� �̻� �뽺Ʈ����ũ �뺼�� �й�\n\n");

            printf("############################################################\n");
            printf("# ��� �Ͻðڽ��ϱ�? 1(���) or 2(����)                    #\n");
            printf("############################################################\n");
            scanf("%d", &k);
            if (k == 2) {
                printf("������ �����մϴ�...");
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
            wrong = 0; // ������ �ٽ� �ϱ� ���� wrong ���� ����.
        }

        count++; // ������ �ѻ���Ŭ
    }
    return 0;
}