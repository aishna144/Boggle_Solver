#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>

using namespace std;
#define M 3
#define N 3

bool isWord(char str[10]) {
  fstream F;
  F.open("FINAL.txt",ios::in);
  char dict[10];
  while(!F.eof()) {
    F>>dict; 
    if(strcmp(dict,str)==0){
      return true;
    }
  }
  F.close(); 
  return false;
}

void findWordsUtil(char boggle[M][N],
                   bool visited[M][N], 
                   int i,int j, 
                   char t[10],
                   int c) {
  char str[10]="";
  int n=strlen(t);
  for(int k=0;k<n;k++) {
    str[k]=t[k];
  }
  str[n]=boggle[i][j];
  str[n+1]='\0';
  visited[i][j] = true;
  c++;
  if (isWord(str))
    printf("%s\n",str);
  if(c<5)
    for (int row=i-1; row<=i+1 && row<M; row++)
      for (int col=j-1; col<=j+1 && col<N; col++)
        if (row>=0 && col>=0 && !visited[row][col])
          findWordsUtil(boggle,visited, row, col, str,c);
  str[strlen(str)-1]='\0';
  visited[i][j] = false;
  c--;
}
void findWords(char boggle[M][N]) {
  bool visited[M][N] = {{false}};
  char str[10]="";
  for (int i=0; i<M; i++)
    for (int j=0; j<N; j++)
      findWordsUtil(boggle, visited, i, j, str,0);
}

int main() {
  char boggle[M][N];
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++) {
      cout<<"Enter Boggle["<<i<<"]["<<j<<"]:";
      cin>>boggle[i][j];
    }
  cout<<"\n\n* * * * *"<<endl;
  for(int i=0;i<M;i++) {
    cout<<"* ";
    for(int j=0;j<N;j++) {
      cout<<boggle[i][j]<<" ";
    }
    cout<<"*"<<endl;
  }
  cout<<"* * * * *"<<endl;
  cout << "\nFollowing words of dictionary are present:\n";
  findWords(boggle);
  return 0;
}
