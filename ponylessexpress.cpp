#include <iostream>
#include <vector>
#include <cassert>
#include <climits>
#include <iomanip>

using namespace std;

struct location{
  int c;
  int d;
  int parent;
  vector<int> children;
};

void Print_Locations(const vector<location>& v){
  for(int i = 0; i < v.size(); i++){
    cout << "Location: " << i <<":" << endl;
    cout << "c: " << v[i].c << " d: " << v[i].d << " parent: " << v[i].parent << endl;
    cout << "children: ";
    for(int j = 0; j < v[i].children.size(); j++)
      cout << v[i].children[j] << " ";
    cout << endl << endl;
  }
}

void Print_2D_Vector(const vector<vector<int> >& v){
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i].size(); j++){
      cout << setw(4) << v[i][j] << " ";
    }
    cout << endl;
  }
}

// stolen from Wikipedia

bool ckmin(int &a, const int &b) { return b < a ? a = b, 1 : 0; }

int Hungarian(const vector<vector<int> >& C){
const int J = (int)size(C), W = (int)size(C[0]);
 assert(J <= W);
 // job[w] = job assigned to w-th worker, or -1 if no job assigned
 // note: a W-th worker was added for convenience
 vector<int> job(W + 1, -1);
 vector<int> ys(J), yt(W + 1);  // potentials
 // -yt[W] will equal the sum of all deltas
 vector<int> answers;
 const int inf = INT_MAX;
 for (int j_cur = 0; j_cur < J; ++j_cur) {  // assign j_cur-th job
   int w_cur = W;
   job[w_cur] = j_cur;
   // min reduced cost over edges from Z to worker w
   vector<int> min_to(W + 1, inf);
   vector<int> prv(W + 1, -1);  // previous worker on alternating path
   vector<bool> in_Z(W + 1);    // whether worker is in Z
   while (job[w_cur] != -1) {   // runs at most j_cur + 1 times
     in_Z[w_cur] = true;
     const int j = job[w_cur];
     int delta = inf;
     int w_next;
     for (int w = 0; w < W; ++w) {
       if (!in_Z[w]) {
	 if (ckmin(min_to[w], C[j][w] - ys[j] - yt[w]))
	   prv[w] = w_cur;
	 if (ckmin(delta, min_to[w])) w_next = w;
       }
     }
     // delta will always be nonnegative,
     // except possibly during the first time this loop runs
     // if any entries of C[j_cur] are negative
     for (int w = 0; w <= W; ++w) {
       if (in_Z[w]) ys[job[w]] += delta, yt[w] -= delta;
       else min_to[w] -= delta;
     }
     w_cur = w_next;
   }
   // update assignments along alternating path
   for (int w; w_cur != W; w_cur = w) job[w_cur] = job[w = prv[w_cur]];
   answers.push_back(-yt[W]);
 }
 return answers[answers.size()-1];
}

void Calc_Scores(const vector<location>& location_list, vector<vector<int> >& Scores, int cur_location){
  // first, see if the children have values
  for(int i = 0; i < location_list[cur_location].children.size(); i++){
    int child = location_list[cur_location].children[i];
    if(Scores[child][1] == -1){
      Calc_Scores(location_list, Scores, child);
    }
  }

  for(int day = 0; day < Scores[cur_location].size(); day++){
    int dist = abs(location_list[cur_location].d-day);
    int local_score = dist*dist*location_list[cur_location].c;
    int child_score = 0;
    if(location_list[cur_location].children.size() > 0){
      vector<vector<int> > Hungarian_Grid(location_list[cur_location].children.size());
      for(int i = 0; i < Hungarian_Grid.size(); i++){
	Hungarian_Grid[i].resize(Hungarian_Grid.size());
	for(int j = 0; j < Hungarian_Grid.size(); j++){
	  //Grid[i][j] is the cost of doing child i on day day+j+1;
	  int child_i = location_list[cur_location].children[i];
	  int day_j = day+j+1;
	  Hungarian_Grid[i][j] = Scores[child_i][day_j];
	}
      }
    
    child_score = Hungarian(Hungarian_Grid);
    }
    Scores[cur_location][day] = local_score + child_score;
  }
}

int main(){
  int n;
  cin >> n;
  vector<location> location_list(n+1);
  vector<bool> is_parent(n+1, false);
  location city;
  city.c = 0;
  city.d = 0;
  city.parent = -1;
  for(int i=1; i <= n; i++){
    cin >> location_list[i].c;
    cin >> location_list[i].d;
    int parent;
    cin >> parent;
    
    location_list[i].parent = parent;
    location_list[parent].children.push_back(i);
    is_parent[parent] = true;
    
  }

  // Print_Locations(location_list);

  vector<vector<int> > Scores(n+1); // rows are locations cols are days
  for(int i = 0; i < n+1; i++){
    Scores[i].resize(n+2, -1);
  }

  Calc_Scores(location_list, Scores, 0);	
  //  Print_2D_Vector(Scores);
  cout << Scores[0][0] << endl;

  return 0;
}