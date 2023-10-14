#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq;
    int minDelete = 0;
    int nowSize = 0;
    for(int i=0; i<operations.size(); ++i){
        if(operations[i]=="D 1"){
            if(nowSize>0) {
                pq.pop();
                nowSize--;
            }
        }
        if(operations[i]=="D -1"){
            if(nowSize>0) {
                minDelete++;
                nowSize--;
            }
        }
        if(operations[i][0]=='I'){
            operations[i].replace(0,2,""); // 숫자만 남김
            int num = stoi(operations[i]);
            pq.push(num);
            nowSize++;
        }
    }
    if(nowSize==0 || nowSize <= minDelete) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        int pqtop = pq.top();
        while(pq.size()>minDelete+1) {
            cout << pq.top()<<" ";
            pq.pop();
        }
        answer.push_back(pqtop);
        answer.push_back(pq.top());
    }
    return answer;
}