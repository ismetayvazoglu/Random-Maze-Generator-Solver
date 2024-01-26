//
// Created by EXCALIBUR on 25.10.2023.
//
//ismetayvazoglu 29493

#include "cell.h"
#include <vector>
#include <iostream>
#include <sstream>
#include "stack.h"
#include "randgen.h"

using namespace std;

#ifndef CS300_HW1_GRID_H
#define CS300_HW1_GRID_H
class grid{

public:

    grid(int m, int n, int id);
    void gen_cells();   //creates an array for holding every cell info in the maze
    void gen_maze();    //iterative backtracing to gen maze
    cell* rand_next_gen();  //finds random next step to go
    vector<cell*> get_available_next_step();    //returns the unvisitied and valid next step
    int checkNfind_idx(int row, int col);       //checks if the coordinates are valid
    void write_maze_g(string fname);            //write every cell info on the maze into a file
    void solve_maze(int en_x, int en_y, int ex_x, int ex_y);    //solve maze using iterative backtrace
    void reset_visited();       // resets visited as false before solving
    cell* rand_next_solve();    // checks if there is a wall between different than rand_next_gen
    void write_maze_s(string fname);    //write the solution path into a file

    bool operator==(const grid& rhs) const;     // to identify which path to solve

private:

    int row;
    int col;
    int maze_id;
    vector<cell> cells;
    cell* current;
    Stack<cell*> stack;

};
#endif //CS300_HW1_GRID_H
