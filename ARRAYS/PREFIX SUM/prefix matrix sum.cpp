// https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/KAVGMAT?tab=statement
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>

vector<int> nse(vector<int>& arr) {
    vector<int> result(arr.size(), -1); 
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0 ; i--) {
        while (!st.empty() && arr[i] < arr[st.top()]) 
            st.pop();
        if(st.size() > 0) result[i] = st.top();
        st.push(i);
    }
    return result;
}

vector<int> nge(vector<int>& arr) {
    vector<int> result(arr.size(), -1); 
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0 ; i--) {
        while (!st.empty() && arr[i] > arr[st.top()]) 
            st.pop();
        if(st.size() > 0) result[i] = st.top();
        st.push(i);
    }
    return result;
}

vector<int> pge(vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) 
            st.pop();
        if(st.size() > 0)
            result[i] = st.top(); 

        st.push(i);
    }
    return result;
}

vector<int> pse(vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) 
            st.pop();
        if(st.size() > 0)
            result[i] = st.top(); 

        st.push(i);
    }
    return result;
}

vector<int> dijkstra(vector<vector<int>> &edge, int v, int e, int src)
{
	vector<vector<pair<int, int>>> adj(v);
	for(int i = 0; i < e; i++){
          adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
          adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
    }
	vector<int> distance(v, INT_MAX);
	distance[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	pq.push({0, src});
	while(!pq.empty()){
		int dst = pq.top().first;
		int nd = pq.top().second;
		pq.pop();
		for(auto p : adj[nd]){
		    int nbr = p.first;
			int wt = p.second;
			if((dst + wt) < distance[nbr]){
				distance[nbr] = dst + wt;
				pq.push({dst + wt, nbr});
			}
		} 
	}
	return distance;
}

bool issorted(vector<int> &arr){
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}

void solve(){
    //* Write code here
    int n, m, k;
    cin >> n >> m >> k;
    // calculating prefix sum matrix
    vector<vector<ll>> pre_mat(n + 1, vector<ll>(m + 1, 0));
    ll num;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> num;
            pre_mat[i][j] = num + pre_mat[i-1][j] + pre_mat[i][j-1] - pre_mat[i-1][j-1];
        }
    }
    
    // TC : (O(N*M*LOG(min(N, M))))

    ll res = 0, low, high, mid, sum, side;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            low = 0, high = min(n - i, m - j);
            side = high+1;
            while(low <= high){
                mid = (low + high)/2;
                // top left ==> (i, j)
                // top right ==> (i, j + mid)
                // bottom right ==> (i + mid, j + mid)
                // bottom left ==> (i + mid, j)
                sum = pre_mat[i+mid][j+mid] - pre_mat[i+mid][j - 1] - pre_mat[i-1][j+mid] + pre_mat[i-1][j-1];
                if((mid+1)*(mid+1)*k > sum) low = mid + 1;
                else
                    side = mid, high = mid-1;
            }
            if(n - i < m - j)
                res = res + n - (i + side) + 1;
            else    
                res = res + m - (j + side) + 1;
        }
    }
    cout << res << endl;

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}