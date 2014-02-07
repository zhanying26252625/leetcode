/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:

    //O(N)
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int gasSum = 0;
        int costSum = 0;
        int index = 0;
        int profit = 0;
        
        for(int i = 0 ; i < gas.size(); ++i){
            gasSum += gas[i];
            costSum += cost[i];
            profit += gas[i]-cost[i];
            if(gasSum<costSum){
                index = i + 1;
                gasSum = 0;
                costSum = 0;
            }    
        }
        
        if(profit<0)
            return -1;
        else
            return index;
        
    }
    
    
    //O(N^2)
    int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        
        for(int i = 0; i < N; ++i){
            int gasSum=0;
            int costSum = 0;
            int len = 0;
            for(int j = i ;  len != N; ++len, ++j){
                if(j==N)
                    j=0;
                gasSum += gas[j];
                costSum += cost[j];
                if(gasSum<costSum) // can NOT do it
                    break;
            }
            
            if(len==N)
                return i;
        }
        
        return -1;
    }
    
};