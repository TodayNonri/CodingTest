#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    for(auto i: num_list)
    {
        while(i!=1)
        {
            if(i%2==0)
                i/=2;
            else
                i = (i-1)/2;
            
            answer++;
        }
    }
    
    return answer;
}