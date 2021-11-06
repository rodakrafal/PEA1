#include "BranchAndBound.hpp"
#include <iostream>
#include <limits.h>

using namespace std;

void BranchAndBound::bnb(Graph &graph){
   int Vnum = graph.getVertices();
   Node* source = newNode(graph.tableMatrix, r, 0 ,-1, 0, Vnum); //create and calculate the cost of source node & TSP starts from first city which is node 0
   source->cost= costFind(source->mtrxReduced, Vnum); //find lower bound of path starting at node 0
   
   
   pq.push(source); //add source to list of live nodes
   
   int trackcost = INT_MAX; //initial upperbound
    
//    int trackcost = 917371; //initial upperbound
   
   //finds node with least cost, add its children to PQ and finally deletes it from PQ
   while( !pq.empty())
   {
       Node* leastCost = pq.top(); //find node with least cost
       pq.pop();  // this node is deleted from PQ
       if(leastCost->cost >= trackcost){
           continue;
       }
       int i = leastCost-> cityNum; // i is the current city number
       
       //when all cities are visited
       if( leastCost-> level == Vnum-1)
       {
           leastCost->trackpath.push_back(make_pair(i,0));//return to the startpoint(first city)
           
           trackcost = leastCost->cost; //in order to update upperbound
           cout << "Current upperbound: " << trackcost << endl;
                     
           
           printTrackPath(leastCost->trackpath); //print list of cities visited
     
       }
       
       
       //do this for each child of leastCost node which (i,j) forms an edge in space tree
       for(int j=0; j<Vnum; j++)
       {
           if(leastCost->mtrxReduced[i][j] != INT_MAX)
           {   //create a child node and calculate the cost for it

               Node* child = newNode(leastCost->mtrxReduced,leastCost->trackpath, leastCost->level + 1, i, j, Vnum);
             
               // child cost = ancestor node cost + edge (i,j) cost + lower bound of path starting at node j
               
               child->cost = leastCost->cost + leastCost->mtrxReduced[i][j];
               child->cost += costFind(child->mtrxReduced,Vnum);
               
               //add child to PQ
               
               if(child->cost < trackcost){
               pq.push(child);
               }
               
           }
       }
  
       //clear out all memory
       for(int f = 0; f< Vnum; ++f ){
           delete[] leastCost->mtrxReduced[f];
       }
       delete [] leastCost->mtrxReduced;
       
       
       delete leastCost; //remove ancestor node when printing solution

   }
}

// Function to allocate a new node `(i, j)` corresponds to visiting city `j`
// from city `i`
Node* BranchAndBound::newNode(int** ancestorMtrx, vector<pair<int,int>> const &trackpath, int level, int i , int j, int Vnum ){
   struct Node* node = new Node;
   
   node->trackpath = trackpath; //in order to keep track of ancestor edges of state space tree
   
   node->mtrxReduced = new int*[Vnum];
   for(int z=0; z< Vnum; ++z){
       node->mtrxReduced[z] =new int[Vnum];
   }
   
   if(level != 0)
       node->trackpath.push_back(make_pair(i,j)); // add current edge to trackpath
   
   
   for(int y=0; y < Vnum; ++y){  //to copy data from ancestor node to current node
       for(int r=0; r < Vnum; ++r){
           node->mtrxReduced[y][r]=ancestorMtrx[y][r];
       }
   }
   
   //change all entries of row i and column j to infinity (skip this for source node)
   for(int k=0; level!=0 && k<Vnum; k++)
   {
       node->mtrxReduced[i][k] = INT_MAX; //outgoing edges for city i are set to infinity
       node->mtrxReduced[k][j] = INT_MAX; //incoming edges to city j are set to infinity
   }
   
   node->mtrxReduced[j][0]= INT_MAX;  // here start node is 0
   node->level = level; //number of cities visited until now are set
   node-> cityNum = j; //update current city number
   
   return node;
   
}

//Reduce each row. There must be at least one zero in each row.
void BranchAndBound::reduceRow(int**mtrxReduced, int* row, int Vnum)
{
   //fill_n(row, Vnum, INF); //initialize row array to INF
   
   for(int i=0; i<Vnum; i++){
       row[i]= INT_MAX;
   }

   
   //finding the row[i] that contains the min in row i
   for(int i=0; i< Vnum; i++)
       for(int j=0; j<Vnum; j++)
           if(mtrxReduced[i][j] < row[i])
               row[i] = mtrxReduced[i][j];
   
   
   //subtract the min value from each element in each row
   for( int i=0; i <Vnum; i++)
       for(int j=0; j<Vnum; j++)
           if(mtrxReduced[i][j] != INT_MAX && row[i] != INT_MAX)
               mtrxReduced[i][j] -= row[i];
  
}

//Reduce each column. There must be at least one zero in each column.
void BranchAndBound::reduceCol(int**mtrxReduced, int* col, int Vnum)
{
   fill_n(col, Vnum, INT_MAX); //initialize column array to INF
   
   //find row[i] contains the min in row i
   for(int i=0; i< Vnum; i++)
       for(int j=0; j<Vnum; j++)
           if(mtrxReduced[i][j] < col[j])
               col[j] = mtrxReduced[i][j];
   
   
   //subtract the min value from each element in each column
   for( int i=0; i <Vnum; i++)
       for(int j=0; j<Vnum; j++)
           if(mtrxReduced[i][j] != INT_MAX && col[j] != INT_MAX)
               mtrxReduced[i][j] -= col[j];
  
}

int BranchAndBound::costFind(int** mtrxReduced, int Vnum)
{
   int cost=0; //intialize cost to 0
   
   int *row = new int[Vnum];
   
   reduceRow(mtrxReduced, row, Vnum); //row reduction
   
   int *col = new int[Vnum];
    
   reduceCol(mtrxReduced, col, Vnum);//column reduction

   
   for(int i=0; i <Vnum; i++){
       cost += (row[i] != INT_MAX) ? row[i] : 0;
       cost += (col[i] != INT_MAX) ? col[i] : 0;

   }
   
   //clear out all memory
   
    delete [] row;
    delete [] col;
   

   return cost;
   
}

// print path of cities visited
void BranchAndBound::printTrackPath(vector<pair<int, int>> const &list)
{
    for(int i = 0; i < list.size(); i++){               
        cout << list[i].first;

        if(i < list.size() - 1) 
            cout << " ";
    }
    cout << " " << 0 << endl;
}