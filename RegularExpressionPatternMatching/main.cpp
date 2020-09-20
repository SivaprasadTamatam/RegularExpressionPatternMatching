//
//  main.cpp
//  Regular Expression Pattern Matching
//
//  Created by Sivaprasad Tamatam on 20/09/20.
//

#include <iostream>

using namespace std;

bool isMatch(string s, string p){
    
    int n = s.length();
    int m = p.length();
    
    bool T[n+1][m+1];
    
    T[0][0] = true;
    
    // Deal with patternslike a*, a*b* or a*b*c*
    
    for( int i =1; i<m; ++i){
        if(p[i-1] == '*')
            T[0][i] = T[0][i-2];
        
    }
    
    for( int i = 1; i<n; ++i){
        for( int j =1; j<m; ++j){
            if( p[j-1] == s[i-1] || p[j-1] == '.')
                T[i][j] = T[i-1][j-1];
            else if(p[j-1] == '*'){
                T[i][j] = T[i][j-1];
                
                if(s[i-1] == p[j-2] || p[j-2] == '.')
                    T[i][j] = T[i][j] || T[i-1][j];
            } else
                T[i][j] = false;
        }
    }
    return T[n][m];
}

int main(int argc, const char * argv[]) {
   
    cout<<isMatch("xaabyc", "xa*b.c")<<endl;
    return 0;
}
