class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // int n=tickets.size();
        // queue<int> q;
        // int time = 0;
        // for(int i=0;i<n;i++){
        //     q.push(i);
        // }
        // while(!q.empty()){
        //     int curr = q.front();
        //     q.pop();
        //     tickets[curr]--;
        //     time++;
        //     if(curr==k && tickets[curr]==0) return time;

        //     if(tickets[curr]!=0) q.push(curr);
        // }

        // return time;
        int value = tickets[k];
        int seconds = 0;
        for(int i = 0; i<tickets.size(); i++) {
            int max = (i<=k)? value: value-1;
            seconds+= min(tickets[i],max);
        }
        return seconds;
    }
};