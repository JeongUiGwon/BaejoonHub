#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> player2rank;
unordered_map<int, string> rank2player;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    for (int i = 0; i < players.size(); i++)
    {
        player2rank[players[i]] = i + 1;
        rank2player[i + 1] = players[i];
    }
    
    for (int i = 0; i < callings.size(); i++)
    {
        int cur_rank = player2rank[callings[i]];
        string front_player = rank2player[cur_rank - 1];
        
        player2rank[callings[i]] = cur_rank - 1;
        rank2player[cur_rank - 1] = callings[i];
        
        player2rank[front_player] = cur_rank;
        rank2player[cur_rank] = front_player;
    }
    
    for (int i = 0; i < players.size(); i++)
        answer.push_back(rank2player[i + 1]);
    
    return answer;
}