class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i:stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int largest=pq.top();
            pq.pop();
            int secondlargest=pq.top();
            pq.pop();
            if(largest!=secondlargest){
                int node=largest-secondlargest;
                pq.push(node);
            }
        }
        if(pq.size()==1){
            return pq.top();
        }
        return 0;
    }
};
