#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getPrioirty(char op) {
	if (op == '*' || op == '/') return 5;
	else if (op == '+' || op == '-') return 3;
	else return 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	string s;
	cin >> s;

	stack<char> st;
	int len = s.size();
	string ans = "";

	for (int i = 0; i < len; i++) {

		if (s[i] >= 'A' && s[i] <= 'Z') {
			ans += s[i];
		}
		else if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			char tmp;
			while (true) {
				tmp = st.top();
				st.pop();

				if (tmp == '(') break;

				ans += tmp;
			}
		}
		else {
			char tmp;
			while (!st.empty()) {
				tmp = st.top();
				if (getPrioirty(tmp) < getPrioirty(s[i])) break;

				st.pop();
				ans += tmp;
			}

			st.push(s[i]);
		}

	}

	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	cout << ans << '\n';


	return 0;
}