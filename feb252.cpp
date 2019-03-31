
#include<bits/stdc++.h>
using namespace std;
 
int Board[64][64], size, tile = 1;
 
void TileBoard(int tr, int tc, int dr, int dc, int size)
{
   if (size == 1) return;
   int t = tile++,  
       s = size/2;  
 
   
   if (dr < tr + s && dc < tc + s)
     
      TileBoard(tr, tc, dr, dc, s);
   else {
         Board[tr + s - 1][tc + s - 1] = t;
         
         TileBoard(tr, tc, tr+s-1, tc+s-1, s);}
 
   
   if (dr < tr + s && dc >= tc + s)
      
      TileBoard(tr, tc+s, dr, dc, s);
   else {
         
         Board[tr + s - 1][tc + s] = t;
        
         TileBoard(tr, tc+s, tr+s-1, tc+s, s);}
 
   
   if (dr >= tr + s && dc < tc + s)
      
      TileBoard(tr+s, tc, dr, dc, s);
   else {
         Board[tr + s][tc + s - 1] = t;
         
         TileBoard(tr+s, tc, tr+s, tc+s-1, s);}
 
   
   if (dr >= tr + s && dc >= tc + s)
      
      TileBoard(tr+s, tc+s, dr, dc, s);
   else {
         Board[tr + s][tc + s] = t;
         
         TileBoard(tr+s, tc+s, tr+s, tc+s, s);}
}
 
void OutputBoard(int size)
{
   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++)
         cout << setw (5) << Board[i][j];
      cout << endl;
      }
}
 
int main(void)
{
   int k, dr, dc;
   int size;
   cout << "Enter k, board size is 2^k" << endl;
   cout << "k should be in the range 0 through 6" << endl;
   cin >> k;
   if (k < 0 || k > 6) {cerr << "k out of range" << endl;
                        exit(1);}
   size = 1;
   for (int i = 1; i <= k; i++) size += size;
   cout << "Enter location of defect" << endl;
   cin >> dr >> dc;
   if (dr < 1 || dr > size || dc < 1 || dc >size) {
      cerr << "Improper defect location" << endl;
      exit(1);}
   dr--; dc--;
   Board[dr][dc] = 0;
   TileBoard(0, 0, dr, dc, size);
   OutputBoard(size);
   return 0;
}
