class Solution {
public:
int calc(string cur,vector<int> fq,vector<int> &score){
    int ans=0;
    for(auto it:cur){
        fq[it-'a']--;
        if(fq[it-'a']<0) return -1;
        ans+=score[it-'a'];
    }
    return ans;
}

int help(vector<string> &words,vector<int> &score,vector<int> &fq,int pos){
    int n=words.size();
    if(pos==n) return 0;
    // option of not choosing words[pos]
    int ans=help(words,score,fq,pos+1);
    // now since I have the answer saved for not choosing word[pos], I must analyze the condition of choosing words[pos] IF I HAVE SUFFICIENT NUMBER OF LETTERS LEFT
    int inc = calc(words[pos],fq,score);
    if(inc==-1) return ans;
    // I must change the fq also since I included the words[pos]
    for(auto it:words[pos]) fq[it-'a']--;
    ans=max(ans,inc+help(words,score,fq,pos+1));
    for(auto it:words[pos]) fq[it-'a']++;                   //    bringing fq to its previous state (backtracking)
    return ans;
}

int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
{
    vector<int> fq(26,0);
    for(auto it:letters) fq[it-'a']++;
    return help(words,score,fq,0);
}

};