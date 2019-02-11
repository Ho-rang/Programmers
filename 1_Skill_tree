#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// skill_trees_len은 skill_trees의 길이입니다.
int solution(char* skill, char* skill_trees[], size_t skill_trees_len) {
    int answer = 0;
    
    bool check;
    size_t s;
    for (size_t i = 0; i < skill_trees_len; i++){ //스킬트리 개수
        check = true;
        s = 0;
        for(size_t j = 0; j < strlen(skill_trees[i]); j++){ //스킬트리 길이
            if(strchr(skill,skill_trees[i][j]) != NULL){ //skill에 [i][j]가 있나 체크
                if(skill[s] == skill_trees[i][j]){
                    s += 1;  
                }
                else{   //순서 틀리면 false후 다음 스킬트리
                    check = false;
                    break;
                }
            }
        }
        if(check){
            answer+=1;
        }
    }
        
    return answer;
}
