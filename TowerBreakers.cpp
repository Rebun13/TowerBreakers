#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int towerBreakers(int n, int m) {
    vector<int> towers(n, m);
    bool moreMovesAvailable = true;
    int currentPlayer = 0;
    while(moreMovesAvailable) {
        moreMovesAvailable = !moreMovesAvailable;
        for(int i = 0; i < n; i++) { // Iteration over towers
            for(int j = 2; j <= m; j++) { // Iteration over multipliers
                if(towers[i] % j == 0) {
                    moreMovesAvailable = !moreMovesAvailable;
                    towers[i] = towers[i] / j;
                    cout << "[" << currentPlayer + 1 << "] T" << i << " - " << towers[i] << endl;
                    break;
                }
            }
            if(moreMovesAvailable) {
                currentPlayer = !currentPlayer;
                break;
            }
        }
    }
    return !currentPlayer + 1;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = towerBreakers(n, m);

        cout << "Ganador: " << result << endl;
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);})
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c);}).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
