/*
https://www.codewars.com/kata/57bfea4cb19505912900012c/train/cpp     CodeWars
https://www.hackerrank.com/challenges/find-point/problem   Hackerrank

"Point reflection" or "point symmetry" is a basic concept in geometry where a given point, P, at a given position relative
to a mid-point, Q has a corresponding point, P1, which is the same distance from Q but in the opposite direction.

Task
Given two points P and Q, output the symmetric point of point P about Q. 
Each argument is a two-element array of integers representing the point's X and Y coordinates. 
Output should be in the same format, giving the X and Y coordinates of point P1. 
You do not have to validate the input.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'findPoint' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER px
 *  2. INTEGER py
 *  3. INTEGER qx
 *  4. INTEGER qy
 */


// CodeWars:

// std::pair<int, int> symmetricPoint(const std::pair<int, int>& p, const std::pair<int, int>& q) 
// {
//     int v1 = 2* q.first - p.first ;
//     int v2 = 2* q.second - p.second;

//     return std::make_pair(v1 , v2); 
// }



//Hackerranke:

vector<int> findPoint(int px, int py, int qx, int qy) 
{
    vector<int> r;
    int V1 , V2;
    V1 = 2* qx - px ;
    V2 = 2* qy - py ;

    r.push_back(V1);
    r.push_back(V2);

    return r ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int px = stoi(first_multiple_input[0]);

        int py = stoi(first_multiple_input[1]);

        int qx = stoi(first_multiple_input[2]);

        int qy = stoi(first_multiple_input[3]);

        vector<int> result = findPoint(px, py, qx, qy);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
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
