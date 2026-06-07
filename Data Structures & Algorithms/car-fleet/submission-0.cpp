#include<stack>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> indexes(n);
        vector<float> time(n);
        for(int i = 0; i < n; ++i) {
            indexes[i] = i;
            time[i] = (float)(target - position[i]) / speed[i];
        }

        sort(indexes.begin(), indexes.end(), [&](int a, int b){
            return position[a] > position[b];
        });

        int ans = 0;
        float max_time = 0;
        for(auto& i: indexes){
            //cout << time[i] << endl;
            if(time[i] > max_time){
                ans++;
                max_time = time[i];
            }
        }
        return ans;
    }
};
