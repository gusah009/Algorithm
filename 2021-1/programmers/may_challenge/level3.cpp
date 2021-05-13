#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> s)
{
    vector<string> answer;
    for (int i = 0; i < s.size(); i++)
    {
        int count = 0;
        string res = "";
        for (int j = 0; j < s[i].size(); j++)
        {
            if (s[i].substr(j, 3) == "110")
            {
                count++;
                int l = j - 1;
                int r = j + 3;
                while (true)
                {
                    if ((l >= 0 && r < s[i].size() - 1) &&
                        s[i][l] == '1' && s[i][r] == '1' && s[i][r + 1] == '0')
                    {
                        j += 2;
                        count++;
                        l = l - 1;
                        r = r + 2;
                        res.pop_back();
                    }
                    else if ((l >= 1 && r < s[i].size()) &&
                             s[i][l - 1] == '1' && s[i][l] == '1' && s[i][r] == '0')
                    {
                        j += 1;
                        count++;
                        l = l - 2;
                        r = r + 1;
                        res.pop_back();
                        res.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                j += 2;
            }
            else
            {
                res.push_back(s[i][j]);
            }
        }
        string ans = "";
        int j = 0;
        for (; j < res.size(); j++)
        {
            if (res.substr(j, 3) == "111")
            {
                ans += res.substr(0, j);
                for (int k = 0; k < count; k++)
                {
                    ans += "110";
                }
                ans += res.substr(j);
                break;
            }
        }
        if (j == res.size())
        {
            if (res.size() == 1)
            {
                if (res[0] == '1')
                {
                    for (int k = 0; k < count; k++)
                    {
                        ans += "110";
                    }
                    ans += '1';
                }
                else
                {
                    ans += '0';
                    for (int k = 0; k < count; k++)
                    {
                        ans += "110";
                    }
                }
            }
            else if (res.size() == 2)
            {
                if (res[0] == '1')
                {
                    if (res[1] == '1')
                    {
                        for (int k = 0; k < count; k++)
                        {
                            ans += "110";
                        }
                        ans += "11";
                    }
                    else
                    {
                        for (int k = 0; k < count; k++)
                        {
                            ans += "110";
                        }
                        ans += "10";
                    }
                }
                else
                {
                    if (res[1] == '1')
                    {
                        ans += '0';
                        for (int k = 0; k < count; k++)
                        {
                            ans += "110";
                        }
                        ans += '1';
                    }
                    else
                    {
                        ans += "00";
                        for (int k = 0; k < count; k++)
                        {
                            ans += "110";
                        }
                    }
                }
            }
            else
            {
                ans = res;
                for (int k = 0; k < count; k++)
                {
                    ans += "110";
                }
            }
        }
        answer.push_back(ans);
    }
    return answer;
}