#include <iostream>
#include<bits/stdc++.h>
using namespace std;
char getChar(int i)
{
    return (char)(i+97);
}

void printpalindrome(string s)
{
    map<char,vector<int>> freq;
    for(int i=0;i<s.length();i++)
    {
        freq[s[i]].push_back(i);
    }
    int odd_count=0;
    for(int i=0;i<26;i++)
    {
        if((freq[getChar(i)].size())%2!=0)
        {
            odd_count++;
        }
    }
    if(odd_count>=2)
    {
        cout<<"-1";
        return;
    }
    int ans[s.length()];
    int start=0;
    int end=(s.length())-1;
    for(int i=0;i<26;i++)
    {
        char currentchar=getChar(i);
        
        
        for(int j=0;j<freq[currentchar].size();j=j+2)
        {
            if(freq[currentchar].size()-j==1)
        {
            ans[s.length()/2]=freq[currentchar][j];
            continue;
        }
            ans[start]=freq[currentchar][j];
            ans[end]=freq[currentchar][j+1];
            start++;
            end--;
        }
        
    }
    for(int i=0;i<s.length();i++)
    {
        cout<<ans[i]+1<<" ";
    }
    
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	while(n--)
	{
	    string s;
	    cin>>s;
	    printpalindrome(s);
	    cout<<endl;
	}
	
	return 0;
}
