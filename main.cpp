// ismet ayvazoglu 29493

#include <iostream>
#include "stack.h"
#include "cell.h"
#include "grid.h"
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


    int K, m,n, maze_id, entry_x, entry_y, exit_x, exit_y;
    cout << "Enter the number of mazes: ";
    cin >> K;
    cout << "Enter the number of rows and columns (M and N): ";
    cin >> m >> n;


    vector<grid> mazes;
    for(unsigned i = 1; i < (K+1); i++) {
        grid griddy(m, n, i);
        griddy.gen_maze();
        stringstream fname_gen;
        fname_gen << "maze_" << i << ".txt";
        griddy.write_maze_g(fname_gen.str());

        mazes.push_back(griddy);
    }
    cout << "All mazes are generated.\n\n";


    cout << "Enter a maze ID between 1 to "<< K <<" inclusive to find a path: ";
    cin >> maze_id;
    cout << "Enter x and y coordinates of the entry points (x,y) or (column,row): ";
    cin >> entry_x >> entry_y;
    cout << "Enter x and y coordinates of the exit points (x,y) or (column,row): ";
    cin >> exit_x >> exit_y;

    vector<grid>::iterator it = find(mazes.begin(),mazes.end(),grid(m,n,maze_id));
    grid to_solve = *it;

    to_solve.solve_maze(entry_x, entry_y, exit_x, exit_y);

    stringstream fname_solve;
    fname_solve << "maze_" << maze_id << "_path_"
                    << entry_x << "_"<< entry_y << "_"
                    << exit_x << "_" << exit_y << ".txt";

    to_solve.write_maze_s(fname_solve.str());


    return 0;
}

