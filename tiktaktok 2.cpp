#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h> // bool 자료형 사용
#define SIZE 3 // 빙고판 크기 정의

// 빙고 체크 함수
bool check_bingo(int board[SIZE][SIZE], int player_mark) {
    for (int i = 0; i < SIZE; i++) {
        // 가로 빙고 체크
        if (board[i][0] == player_mark && board[i][1] == player_mark && board[i][2] == player_mark) {
            return true;
        }
        // 세로 빙고 체크
        if (board[0][i] == player_mark && board[1][i] == player_mark && board[2][i] == player_mark) {
            return true;
        }
    }
    // 대각선 빙고 체크
    if (board[0][0] == player_mark && board[1][1] == player_mark && board[2][2] == player_mark) {
        return true;
    }
    if (board[0][2] == player_mark && board[1][1] == player_mark && board[2][0] == player_mark) {
        return true;
    }
    return false; // 빙고가 없는 경우
}
// 빙고판 출력 함수
void print_board(int board[SIZE][SIZE]) {
    printf("\n빙고판 상태:\n");
    printf("-------------\n"); // 상단 테두리
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == -1) {
                printf("| O "); // Player 1
            }
            else if (board[i][j] == -2) {
                printf("| X "); // Player 2
            }
            else {
                printf("| %d ", board[i][j]); // 선택되지 않은 숫자
            }
        }
        printf("|\n"); // 행 끝 테두리
        printf("-------------\n"); // 행 구분선
    }
}
int main() {
    int board[SIZE][SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // 빙고판 초기화
    int p1, p2;  // 플레이어 입력값
    int ch;      // 선택값 확인 변수
    int re = SIZE * SIZE;  // 남은 숫자 카운트
    int choice;
    while (1) {
        // 현재 빙고판 출력
        print_board(board);

        // 플레이어 1 차례
        printf("플레이어 1, 어떤 숫자를 선택하시겠습니까? ");
        scanf("%d", &p1);
        ch = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == p1) {
                    board[i][j] = -1; // Player 1의 선택
                    ch = 1;
                }
            }
        }
        if (!ch) {
            printf("다시입력해주세요\n");
            continue;
        }
        re--;
        if (check_bingo(board, -1)) {
            print_board(board);
            printf("플레이어 1 승리!\n");
            break;
        }
        if (re == 0) {
            printf("무승부입니다!\n");
            printf("다시 하고싶으시면 1번을 아니라면 2번을 눌러주세요");
            scanf("%d", &choice);
            if (choice == 1) {
                main();
            }
            else {
                printf("종료하겠습니다");
                return 0;
            }
        }

        // 현재 빙고판 출력
        print_board(board);

        // 플레이어 2 차례
        printf("플레이어 2, 어떤 숫자를 선택하시겠습니까? ");
        scanf("%d", &p2);
        ch = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == p2) {
                    board[i][j] = -2; // Player 2의 선택
                    ch = 1;
                }
            }
        }
        if (!ch) { // 잘못된 입력 처리
            printf("다시 입력해주세요\n");
            continue;
        }
        re--;
        if (check_bingo(board, -2)) {
            print_board(board);
            printf("플레이어 2 승리!\n");
            break;
        }
        if (re == 0) {
            printf("무승부입니다!\n");
            main();
        }
    }
    return 0;
}