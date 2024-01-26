//
// Created by EXCALIBUR on 25.10.2023.
//
//ismetayvazoglu 29493

#include "cell.h"

cell::cell(int r, int c) {
    this->visited = false;
    this->row = r;
    this->col = c;
    this->up_wall = true;
    this->down_wall = true;
    this->left_wall = true;
    this->right_wall = true;
}
void cell::set_visited(bool b) {
    this->visited = b;
}
bool cell::get_visited(){
    return this->visited;
}

int cell::get_col() {
    return this->col;
}
int cell::get_row() {
    return this->row;
}

void cell::knockdown_walls(cell &next) {

    int x = this->col - next.col;
    int y = this->row - next.row;

    if(x == -1 && y == 0){ //goes right
        this->right_wall = false;
        next.left_wall = false;
        return;
    }
    else if (x == 1 && y == 0){ //goes left
        this->left_wall = false;
        next.right_wall = false;
        return;
    }
    else if (y == -1 && x == 0){ //goes up
        this->up_wall = false;
        next.down_wall = false;
        return;
    }
    else if (y == 1 && x == 0){ //goes down
        this->down_wall = false;
        next.up_wall = false;
    }
}

vector<int> cell::get_walls() { // to write
    vector<int> x;
    if(this->left_wall){
        x.push_back(1);
    }
    else{
        x.push_back(0);
    }
    if(this->right_wall){
        x.push_back(1);
    }
    else{
        x.push_back(0);
    }
    if(this->up_wall){
        x.push_back(1);
    }
    else{
        x.push_back(0);
    }
    if(this->down_wall){
        x.push_back(1);
    }
    else{
        x.push_back(0);
    }
    return x;
}

bool cell::check_wall(cell &potential) { //checking extra for solving the maze
                                            // cause now we have to check
                                                // the wall between current cell and next cell
    int x = this->row - potential.row;
    int y = this->col - potential.col;

    if (y == 1){
        if (this->left_wall && potential.right_wall){
            return false;
        }
        return true;
    }
    else if(y == -1){
        if (this->right_wall && potential.left_wall){
            return false;
        }
        return true;
    }
    else if (x == 1){
        if (this->down_wall && potential.up_wall){
            return false;
        }
        return true;
    }
    else if(x == -1){
        if (this->up_wall && potential.down_wall){
            return false;
        }
    }
    return true;
}