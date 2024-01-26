//
// Created by EXCALIBUR on 25.10.2023.
//
//ismetayvazoglu 29493

#include <cstdlib>
#include "grid.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>


grid::grid(int m, int n, int id){
    this->row = m;
    this->col = n;
    this->maze_id = id;
    gen_cells();
    this->current = &cells[0];
}

void grid::gen_cells(){
    for (int i = 0; i< this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            this->cells.push_back(cell(i,j));
        }
    }
}

void::grid::gen_maze(){

    while (true){
        current->set_visited(true);
        cell *next = rand_next_gen();
        if (next != nullptr) {
            next->set_visited(true);
            stack.push(current);
            current->knockdown_walls(*next);
            current = next;
        } else if (!(stack).isEmpty()) {
                current = stack.at_top();
                stack.pop();
        } else if (stack.isEmpty()){
                break;
        }
    }
}

cell* grid::rand_next_gen(){

    RandGen rand;
    auto time = std::chrono::system_clock::now();
    auto since_epoch = time.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);
    long now = millis.count();
    rand.SetSeed(now);

    vector<cell*> unvisited_neighbors = get_available_next_step();
    if(unvisited_neighbors.size()>0){
        int ranran = rand.RandInt(unvisited_neighbors.size()+1);
        int ran = ranran % unvisited_neighbors.size();
        //cout << ranran << " mod("<< unvisited_neighbors.size() << ") \t" << ran << endl;
        return unvisited_neighbors.at(ran);
    }
    return nullptr;
}

vector<cell*> grid::get_available_next_step(){

    vector<cell*> availables;

    int curr_row = this->current->get_row();
    int curr_col = this->current->get_col();

    int neighbors[4] = {
            checkNfind_idx(curr_row-1,curr_col),
            checkNfind_idx(curr_row+1,curr_col),
            checkNfind_idx(curr_row,curr_col-1),
            checkNfind_idx(curr_row,curr_col+1)
    };
    for (int i : neighbors){
        if(i != -1 && !(this->cells[i].get_visited())){
            availables.push_back(&cells[i]);
        }
    }
    return availables;
}

int grid::checkNfind_idx(int r, int c){
    if (r < 0 || c < 0 || r > (this->row)-1 || c > (this->col)-1){
        return -1;
    }
    else{
        return (this->col)*r + c;
    }
}

void grid::write_maze_g(string fname) {
    ofstream output(fname);
    if(output.is_open()){
        output << this->col << " " << this->row << endl;
        for(unsigned i = 0; i< this->row*this->col; i++){
            vector<int> walls = this->cells[i].get_walls();
            output << "x=" << this->cells[i].get_col() << " y=" << this->cells[i].get_row() <<
                    " l=" << walls[0] << " r=" << walls[1] << " u=" << walls[2] << " d=" << walls[3] << endl;
        }
        output.close();
    }
    else {
        cout << "Unable to open " << fname << " for writing." << endl;
    }
}

void grid::solve_maze(int en_x, int en_y, int ex_x, int ex_y) {

    this->reset_visited();
    this->current = &cells[(this->col)*en_x+en_y];

    while (true){
        current->set_visited(true);
        cell* next = rand_next_solve();
        if (next != nullptr){
            next->set_visited(true);
            this->stack.push(current);
            current = next;
            if(current->get_row() == ex_x && current->get_col() == ex_y){
                this->stack.push(current);
                break;
            }
        }
        else if (!(this->stack.isEmpty())){
            current = stack.at_top();
            stack.pop();
        }
    }
}

void grid::reset_visited(){
    for(unsigned i = 0; i< this->cells.size(); i++){
        this->cells[i].set_visited(false);
    }
}
cell* grid::rand_next_solve() {
    RandGen rand;
    vector<cell*> unvisited_neighbors = get_available_next_step();

    for (int i = unvisited_neighbors.size() - 1; i >= 0; i--) {
        if (!(current->check_wall(*unvisited_neighbors[i]))){
            unvisited_neighbors.erase(unvisited_neighbors.begin() + i);
        }
    }
    if(unvisited_neighbors.size()>0){
        return unvisited_neighbors.at(rand.RandInt() % unvisited_neighbors.size());
    }
    return nullptr;
}

void grid::write_maze_s(string fname) {

    Stack<cell*> temp_stack;
    while(!(this->stack.isEmpty())){
        temp_stack.push(this->stack.at_top());
        this->stack.pop();
    }

    ofstream output(fname);
    if(output.is_open()){
        while(!(temp_stack.isEmpty())){
            output << temp_stack.at_top()->get_col() << " "
                    << temp_stack.at_top()->get_row() << endl;
            temp_stack.pop();
        }
        output.close();
    }
    else{
        cout << "Unable to open " << fname << " for writing." << endl;
    }
}

bool grid::operator==(const grid& rhs) const {
    return (this->maze_id == rhs.maze_id);
}
