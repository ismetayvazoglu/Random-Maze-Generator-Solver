//
// Created by EXCALIBUR on 25.10.2023.
//
//ismetayvazoglu 29493

#include <vector>

using namespace std;

#ifndef CS300_HW1_CELL_H
#define CS300_HW1_CELL_H

class cell{

public:
    cell(int r, int c);
    void set_visited(bool b);
    int get_row();
    int get_col();
    bool get_visited();
    void knockdown_walls(cell & next);  // while generating the maze knocks the walls
    vector<int> get_walls();        // returns the info of a cell to use while writing
    bool check_wall(cell & potential);  // checks the wall between current and potential next

private:
    bool visited;
    bool up_wall;
    bool down_wall;
    bool left_wall;
    bool right_wall;
    int row;
    int col;
};

#endif //CS300_HW1_CELL_H
