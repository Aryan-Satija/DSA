#include <bits/stdc++.h>
using namespace std;
stack<int> insertAtCorrectPosition(stack<int> &s, int num){
	if(s.empty() or s.top() <= num){
		s.push(num);
		return s;
	}
	int top = s.top(); s.pop();
	insertAtCorrectPosition(s, num);
	s.push(top);
	return s;
}
stack<int> sortStack(stack<int> &s)
{
	if(s.empty())
		return s;
	int top = s.top();
	s.pop();
	s = sortStack(s);
	return insertAtCorrectPosition(s, top);
}
int main(){
    // FAST INPUT-OUTPUT
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    cin >> n;
    stack<int> st;
    for(int i = 0; i < n; i++){
        cin >> num;
        st.push(num);
    }
	st = sortStack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}