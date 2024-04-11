// CODING NINJAS -> TRAFFIC (imp)
#include <bits/stdc++.h> 
using namespace std;
int traffic(int n, int m, vector<int> vehicle) {
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(vehicle[i] == 1)
			cnt++;
	}
	if(m + cnt >= n)
		return n;
	if(cnt == 1)
		return (m + cnt);

	int s = 0, e = 0;
	int traffic = m, flip = m;
	while(e < n)
	{
		if(vehicle[e] == 0)
		{
			if(flip > 0){
				flip--;
				e++;
			}
			else{
				if(vehicle[s] == 0)
					flip++;
				s++;
			}
		}
		else
			e++;
		traffic = max(traffic, (e - s));
	}
	return traffic;
}