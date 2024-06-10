#include <bits/stdc++.h>

using namespace std;

class Pair
{
public:
    int first, second;
    // void make_pair(int a, int b)
    // {
    //     first = a;
    //     second = b;
    // }
};
int main()
{

    // Pair p;
    // // p.first = 10;
    // // p.second = 20;
    pair<int, int> p;
    p = make_pair(20, 30);
    cout << p.first << " " << p.second << endl;

    return 0;
}