#include "line_count.h" // 줄 수 계산을 위한 함수 선언이 있는 헤더 파일 포함

// line_count 함수: 파일에서 줄 수를 계산하는 함수
int line_count(FILE *file) {
    int count = 0;  // 줄 수를 저장할 변수
    char c;         // 파일에서 읽은 한 문자를 저장할 변수

    // 파일의 모든 문자를 읽을 때까지 반복
    while ((c = fgetc(file)) != EOF) {
        // 문자가 줄바꿈 문자('\n')이면 한 줄이 끝났다는 의미이므로 count를 증가시킴
        if (c == '\n') {
           ㅁ // 줄 수 증가
        }
    }

    return count;  // 최종 줄 수를 반환
}
