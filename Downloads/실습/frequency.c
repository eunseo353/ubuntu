#include "frequency.h" // 단어 빈도 계산을 위한 함수 선언이 있는 헤더 파일 포함
#include <ctype.h>     // isalpha(), tolower() 함수를 사용하기 위한 라이브러리
#include <string.h>    // strcmp(), strcpy() 함수를 사용하기 위한 라이브러리

// find_word 함수: 단어 배열에서 특정 단어의 인덱스를 찾는 함수
// word_array: 단어와 빈도를 저장하는 배열
// word: 찾고자 하는 단어
// size: 현재 배열에 저장된 단어의 개수
// 해당 단어가 있으면 인덱스를 반환하고, 없으면 -1을 반환
int find_word(WordFreq *word_array, char *word, int size) {
    for (int i = 0; i < size; i++) {
        // 단어를 비교하여 이미 배열에 있으면 인덱스 반환
        if (strcmp(word_array[i].word, word) == 0) {
            return i;
        }
    }
    return -1; // 단어를 찾지 못했을 때
}

// frequency 함수: 파일에서 단어 빈도를 계산하여 배열에 저장하는 함수
// file: 분석할 파일
// word_array: 단어와 빈도를 저장할 배열
// 함수는 파일에서 단어를 읽고 빈도를 계산한 후 배열에 저장
int frequency(FILE *file, WordFreq *word_array) {
    int word_count = 0;               // 현재까지 찾은 단어 수
    char word[MAX_WORD_LEN];          // 현재 읽고 있는 단어를 저장할 변수
    int idx = 0;                      // 단어의 각 문자를 저장할 인덱스
    char c;                           // 파일에서 읽은 한 문자를 저장할 변수

    // 파일의 모든 문자를 읽을 때까지 반복
    while ((c = fgetc(file)) != EOF) {
        // 문자가 알파벳이면, 소문자로 변환하여 단어에 추가
        if (isalpha(c)) {
            ㅁ  // 알파벳을 소문자로 저장
        } else if (idx > 0) {  // 공백이나 특수문자를 만나면 단어가 끝난 것
           ㅁ  // 단어 끝에 null 문자를 추가하여 문자열 종료
            idx = 0;           // 다음 단어를 위해 인덱스 초기화

            // 단어 배열에서 해당 단어가 이미 있는지 확인
            int found = find_word(word_array, word, word_count);
            if (found == -1) {
                // 배열에 없으면 새로운 단어를 배열에 추가하고 빈도를 1로 설정
                strcpy(word_array[word_count].word, word);
                word_array[word_count].count = 1;
                word_count++;  // 단어 수 증가
            } else {
                // 배열에 있으면 해당 단어의 빈도를 1 증가
                word_array[found].count++;
            }
        }
    }
    return word_count;  // 최종 단어 수 반환
}

// print_frequencies 함수: 단어와 빈도를 출력하는 함수
// word_array: 단어와 빈도를 저장한 배열
// size: 배열에 저장된 단어의 개수
void print_frequencies(WordFreq *word_array, int size) {
    for (int i = 0; i < size; i++) {
        // 배열에 저장된 단어와 해당 단어의 빈도를 출력
        printf("%s: %d\n", word_array[i].word, word_array[i].count);
    }
}
