//https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26]={0};
        for(char ch:s)arr[ch-'a']--;
        for(char ch:t)arr[ch-'a']++;
        for(int i=0;i<26;i++)
            if(arr[i]>0)return i+'a';
        
        return 'a';
    }
};





////By ascii summation


class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        for(char ch:t)ans+=ch-'a';
        for(char ch:s)ans-=ch-'a';
        return ans+'a';
    }
};




/////By xor

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans=0;
        for(char ch:t)ans^=ch;
        for(char ch:s)ans^=ch;
        return ans;
    }
};