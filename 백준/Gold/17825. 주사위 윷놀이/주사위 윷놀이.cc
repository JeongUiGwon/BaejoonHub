#include <iostream>
#include <algorithm>

#define NUM_MOVEMENTS 10
#define PIECE_NUM 4
#define MAX_POS 45
#define START 0
#define END 20

using namespace std;

int move_nums[NUM_MOVEMENTS];
int curr_pos[PIECE_NUM];
int point[MAX_POS] = {
    0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 0,
    13, 16, 19, 0, 0,
    22, 24, 0, 0, 0,
    28, 27, 26, 0, 0,
    0, 0, 0, 0, 0,
    25, 30, 35, 40
};

int max_score;

bool IsBlue(int curr_pos) {
    return curr_pos != START && curr_pos % 5 == 0;
}

int GetNextPos(int curr_pos, int move_num) {
    if(curr_pos == END)
        return END;

    if(move_num == 0)
        return curr_pos;
    
    int next_pos = curr_pos + 1;

    if(curr_pos == 23 || curr_pos == 27 || curr_pos == 33) {
        next_pos = 41;
    }

    else if(curr_pos == 19) {
        next_pos = 44;
    } 

    else if(curr_pos == 44) {
        next_pos = END;
    }

    return GetNextPos(next_pos, move_num - 1);
}

bool IsOverlapped() {

    for(int i = 0; i < PIECE_NUM; i++) {
        for(int j = i + 1; j < PIECE_NUM; j++) {
            if(curr_pos[i] == curr_pos[j] && curr_pos[i] != START && curr_pos[i] != END) {
                return true;
            }
        }
    }

    return false;
}

// 지금까지 cnt번 움직였고
// 지금까지 얻은 점수가 score
void SearchMaxScore(int cnt, int score) {
    if(cnt == NUM_MOVEMENTS) {
        max_score = max(score, max_score);
        return;
    }

    for(int i = 0; i < PIECE_NUM; i++) {
        if(curr_pos[i] == END) {
            continue;
        }
        
        int temp = curr_pos[i];

        // 시작점이 파란색이면
        if(IsBlue(curr_pos[i])) {
            curr_pos[i] = GetNextPos(curr_pos[i] + 16, move_nums[cnt] - 1);
        }

        // 아니라면
        else {
            curr_pos[i] = GetNextPos(curr_pos[i], move_nums[cnt]);
        }

        // 겹치지 않는다면
        if(!IsOverlapped()) {
            SearchMaxScore(cnt + 1, score + point[curr_pos[i]]);
        }

        curr_pos[i] = temp;
    }
}

int main() {
    for(int i = 0; i < NUM_MOVEMENTS; i++) {
        cin >> move_nums[i];
    }

    SearchMaxScore(0, 0);

    cout << max_score << "\n";
    return 0;
}