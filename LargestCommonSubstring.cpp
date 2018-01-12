#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printLCString(string s1, string s2)
{
    if(s1 == "" || s2 == "")
        return;

    int m = s1.size();
    int n = s2.size();
    vector<vector<int> > table(m+1, vector<int>(n+1));

    int biggest = 0;  // 记录表中最大值
    vector<pair<int, int> > firstPos;  // 记录子串开始的坐标 
    for(int i=0; i<m+1; ++i)  
    {  
        for(int j=0; j<n+1; ++j)  
        {  
            // 第一行和第一列置0  
            if (i == 0 || j == 0)  
                table[i][j] = 0;  
            else if(s1[i-1] == s2[j-1])  
            {
                table[i][j] = table[i-1][j-1] + 1;  
                if(table[i][j] > biggest)
                    biggest = table[i][j];
                if(table[i][j] == 1) 
                    firstPos.push_back(make_pair(i, j));
            }
            else  // 不相等置0
                table[i][j] = 0;  
        }  
    }

    // 输出所有的最长公共子串
    vector<pair<int, int> >::iterator beg = firstPos.begin();
    for( ; beg!=firstPos.end(); ++beg)
    {
        int start1 = beg->first-1;
        int start2 = beg->second-1;
        if(s1.substr(start1, biggest) == s2.substr(start2, biggest))
            cout << s1.substr(start1, biggest) << endl;
    }
}


int main ()
{
    string s1 = "ABCBADABCHGIKLKIGZZZ";
    string s2 = "GIKLKIGHCBADABCBAZZZ";
    printLCString(s1, s2);
    return 0;
}
