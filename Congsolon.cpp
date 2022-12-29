#include <bits/stdc++.h>
using namespace std;
string Add(string a, string b)
{
    string res = "";
    int nho = 0;
    while (a.size() < b.size())
        a = "0" + a;
    while (a.size() > b.size())
        b = "0" + b;
    int len = a.size() - 1;
    for (int i = len; i >= 0; i--)
    {
        int so = int(a[i] - '0') + int(b[i] - '0') + nho;
        res = char(so % 10 + '0') + res;
        nho = so / 10;
    }
    if (nho > 0)
        res = char(nho + '0') + res;
    return res;
}

string Add2(string a, string b){
    if(a.length() < b.length()) swap(a,b);
    string kq = "";
    int n1 = a.length(); 
    int n2 = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for(int i = 0; i < n2; i++){
        int sum = ((a[i]-'0')+(b[i]-'0')+carry);
        kq.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for(int i = n2; i < n1; i++){
        int sum = ((a[i]-'0')+carry);
        kq.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if(carry) kq.push_back(carry+'0');
    reverse(kq.begin(), kq.end());
    return kq;
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << Add2(a, b) << endl;
    return 0;
}