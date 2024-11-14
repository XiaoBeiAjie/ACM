#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;

stack<pair<char, int > > st;
stack<pair<char, int > >st2;
map<char, char> mp ;
void solve() {
    string s;
    cin >> s;
    int len = s.length();
    string s2 = "";
    while(!st.empty()) st.pop();
    while(!st2.empty()) st2.pop();
    for(int i = 0; i < len ; i++)
    {
        if(s[i] == '(' || s[i] == '[') st.push({s[i], i});
        else{
            if(s[i] == ']'){
                if(!st.empty() && st.top().x == '[') st.pop();
                else st.push({'[', i}), s[i] = '['; 
            }  
            else{
                if(!st.empty() && st.top().x == '(') st.pop();
                else st.push({'(', i}), s[i] = '(';
            }
        }
    }
    while(!st.empty()){
        if(!st2.empty() && mp[st.top().x] == st2.top().x)  st2.pop(), st.pop();
        else st2.push({mp[st.top().x], st.top().y}), s[st.top().y] = mp[st.top().x],st.pop();
    }
    if(!st2.empty()) return cout << "No" << endl, void();
    s2 = s;
    stack<char> ss;
    bool pre1 = 0;
    bool pre2 = 0;
    for(int i = 0; i < len ; i++){
        if(s[i] == '(' || s[i] == '[') {
            if(!ss.empty() && ss.top() == s[i]) return cout << "No" << endl, void();
            if(ss.empty() && s[i] == '(' && pre1) return cout << "No" << endl, void();
            if(ss.empty() && s[i] == '[' && pre2) return cout << "No" << endl, void();
            ss.push(s[i]);
        }
        else pre1 = (pre1 ||(ss.top() == '(')),pre2 = (pre2 ||(ss.top() == '[')), ss.pop();
    }
    cout << "Yes" << endl;
} 

int main(void) {
    mp.insert({'(', ')'});
    mp.insert({'[', ']'});
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}