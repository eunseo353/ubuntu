#include <stdio.h>
#include <stdlib.h>
#include "word_count.h"
#include "line_count.h"
#include "frequency.h"

int main() {
    char filename[100];
    printf("분석할 파일의 이름을 입력하세요: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 단어 수 계산
    int words = word_count(file);
    rewind(file);  // 파일 포인터를 처음으로 돌림

    // 줄 수 계산
    int lines = line_count(file);
    rewind(file);

    // 단어 빈도수 계산
    WordFreq word_array[MAX_WORDS];
    int word_freq_count = frequency(file, word_array);

    printf("\n파일 분석 결과:\n");
    printf("단어 수: %d\n", words);
    printf("줄 수: %d\n", lines);
    printf("단어 빈도수:\n");
    print_frequencies(word_array, word_freq_count);

    fclose(file);
    return 0;
}
