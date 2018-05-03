class Solution {
private:
    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }
public:
    void reverseWords(string &s) {     
        int i=0, j=0;
        int start=0;
        int len=s.length();
        int wordcount=0;       
        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            start=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;} 
            reverseword(s,start,j-1);                // reverse word in place
            wordcount++;     
        }     
        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }
};
