// imslavko
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define foreach(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

class FoxAndKgram {
	public:
	int maxK(vector <int> len) {
		int res = 0;
		vector<int> c(200);
		foreach(i,len)
			c[*i]++;
		for (int i = 1; i < 200; i++) {
			int C = c[i], CC = 0;
			if (i != 1)
				for (int j = 1, k = i-j-1; j < i; j++, k--)
					CC += min(c[j], c[k]);
			C += CC / 2;
			if (C >= i)
				res = i;
		}
		return res;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing FoxAndKgram (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1333815018;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FoxAndKgram _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int len[] = {1,1,1,1,3};
				_expected = 3;
				_received = _obj.maxK(vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 1:
			{
				int len[] = {2,2,1,3,5,5,5};
				_expected = 5;
				_received = _obj.maxK(vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 2:
			{
				int len[] = {1};
				_expected = 1;
				_received = _obj.maxK(vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 3:
			{
				int len[] = {2,2,2,2,2,2,2,2,2,2};
				_expected = 5;
				_received = _obj.maxK(vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 4:
			{
				int len[] = {1,2,3,1,2,4,2,3,1};
				_expected = 4;
				_received = _obj.maxK(vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 5:
			{
				int len[] = {2,3,5,7,11,13,17,19,23,29};
				_expected = 0;
				_received = _obj.maxK(vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 6:
			{
				int len[] = {3,2,2};
				_expected = 2;
				_received = _obj.maxK(vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			/*case 7:
			{
				int len[] = ;
				_expected = ;
				_received = _obj.maxK(vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int len[] = ;
				_expected = ;
				_received = _obj.maxK(vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
