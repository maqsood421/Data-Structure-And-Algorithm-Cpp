#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int> stockSpan(vector<int>);

int main(void)
{
    vector<int> a = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stockSpan(a);

    for(auto i: res)
        cout << i << " ";

    return 0;
}

vector<int> stockSpan(vector<int> prices){
    vector<int> ans;
    stack<pair<int, int>> st;

    for(auto price: prices){
        int days = 1;
        while(!st.empty() && st.top().first <= price){
            days += st.top().second;
            st.pop();
        }
        st.push({price, days});
        ans.push_back(days);
    }


    return ans;
}