//
// Created by nishit on 02-09-2020.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> findSpace(vector<vector<char>> board) {
    vector<int> index;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                index.push_back(i);
                index.push_back(j);
                return index;
            }
        }
    }
    return index;
}

int findNextCount(vector<vector<char>> board) {
    vector<int> spaceIndex = findSpace(board);
    int i = spaceIndex[0];
    int j = spaceIndex[1];

    if (((i == 0 and j == 0) or (i == 2 and j == 0) or (i == 0 and j == 2) or (i == 2 and j == 2)) and
        board[i][j] == ' ') {
        return 2;
    } else if (((i == 1 and j == 0) or (i == 0 and j == 1) or (i == 1 and j == 2) or (i == 2 and j == 1)) and
               board[i][j] == ' ') {
        return 3;
    } else {
        cout << i << j;
        return 4;
    }
    return -1;
}

class Node {

public:
    Node(vector<vector<char>> board, string location, int nextSize) {
        this->board = board;
        this->location = location;
        next = new vector<Node>();
    }

    vector<vector<char>> board;
    vector<Node> *next;
    string location;
};

Node *root;

void printBoard(vector<vector<char>> board,int dash) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < dash*2; ++j) {
            cout<<" ";
        }
        cout << "[";
        for (int j = 0; j < board[0].size(); ++j) {
            cout << " " << board[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void printBoard(Node node,int dash) {
    cout<<node.location<<endl;
    for (int i = 0; i < node.board.size(); ++i) {
        for (int j = 0; j < dash*2; ++j) {
            cout<<" ";
        }
        cout << "[";
        for (int j = 0; j < node.board[0].size(); ++j) {
            cout << " " << node.board[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void createTree(int level, Node *node) {
//    cout<<level<<"------------------------"<<endl;
//    printBoard(node->board,0);

    if (level > 0) {
        vector<int> spaceIndex = findSpace(node->board);
        int i = spaceIndex[0];
        int j = spaceIndex[1];
        if (((i == 0 and j == 0) or (i == 2 and j == 0) or (i == 0 and j == 2) or (i == 2 and j == 2)) and
            node->board[i][j] == ' ') {
            //space in corner
            string location = "";

            if (i == 0 and j == 0)
                location = "TL";
            else if (i == 2 and j == 0)
                location = "BL";
            else if (i == 2 and j == 2)
                location = "BR";
            else
                location = "TR";

            if (location == "TL") {
                //up
                vector<vector<char>> upBoard(node->board.begin(),node->board.end());
                upBoard[0][0] = upBoard[1][0];
                upBoard[1][0] = ' ';
                Node up(upBoard, "up",2);
                node->next->push_back(up);
                createTree(level - 1, &up);

                //left
                vector<vector<char>> leftBoard(node->board.begin(),node->board.end());
                leftBoard[0][0] = leftBoard[0][1];
                leftBoard[0][1] = ' ';
                Node left(leftBoard, "left",2);
                node->next->push_back(left);
                createTree(level - 1, &left);
            } else if (location == "BL") {
                //down
                vector<vector<char>> downBoard(node->board.begin(),node->board.end());
                downBoard[2][0] = downBoard[1][0];
                downBoard[1][0] = ' ';
                Node down(downBoard, "down",2);
                node->next->push_back(down);
                createTree(level - 1, &down);
                //left
                vector<vector<char>> leftBoard(node->board.begin(),node->board.end());
                leftBoard[2][0] = leftBoard[2][1];
                leftBoard[2][1] = ' ';
                Node left(leftBoard, "left",2);
                node->next->push_back(left);
                createTree(level - 1, &left);
            } else if (location == "BR") {
                //down
                vector<vector<char>> downBoard(node->board.begin(),node->board.end());
                downBoard[2][2] = downBoard[1][2];
                downBoard[1][2] = ' ';
                Node down(downBoard, "down",2);
                node->next->push_back(down);
                createTree(level - 1, &down);

                //right
                vector<vector<char>> rightBoard(node->board.begin(),node->board.end());
                rightBoard[2][2] = rightBoard[2][1];
                rightBoard[2][1] = ' ';
                Node right(rightBoard, "right",2);
                node->next->push_back(right);
                createTree(level - 1, &right);


            } else if (location == "TR") {
                //up
                vector<vector<char>> upBoard(node->board.begin(),node->board.end());
                upBoard[0][2] = upBoard[1][2];
                upBoard[1][2] = ' ';
                Node up(upBoard, "up",2);
                node->next->push_back(up);
                createTree(level - 1, &up);

                //right
                vector<vector<char>> rightBoard(node->board.begin(),node->board.end());
                rightBoard[0][2] = rightBoard[0][1];
                rightBoard[0][1] = ' ';
                Node right(rightBoard, "right",2);
                node->next->push_back(right);
                createTree(level - 1, &right);
            }


        } else if (((i == 1 and j == 0) or (i == 0 and j == 1) or (i == 1 and j == 2) or (i == 2 and j == 1)) and
                   node->board[i][j] == ' ') {
            //space in edges
            string location = "";

            if (i == 0 and j == 1)
                location = "UP";
            else if (i == 1 and j == 2)
                location = "RIGHT";
            else if (i == 1 and j == 0)
                location = "LEFT";
            else
                location = "DOWN";

            if (location == "UP") {
                //up
                vector<vector<char>> upBoard(node->board.begin(),node->board.end());
                upBoard[0][1] = upBoard[1][1];
                upBoard[1][1] = ' ';
                Node up(upBoard, "up",3);
                node->next->push_back(up);
                createTree(level - 1, &up);

                //right
                vector<vector<char>> rightBoard(node->board.begin(),node->board.end());
                rightBoard[0][1] = rightBoard[0][0];
                rightBoard[0][0] = ' ';
                Node right(rightBoard, "right",3);
                node->next->push_back(right);
                createTree(level - 1, &right);

                //left
                vector<vector<char>> leftBoard(node->board.begin(),node->board.end());
                leftBoard[0][1] = leftBoard[0][2];
                leftBoard[0][2] = ' ';
                Node left(leftBoard, "left",3);
                node->next->push_back(left);
                createTree(level - 1, &left);
            } else if (location == "DOWN") {
                //down
                vector<vector<char>> downBoard(node->board.size());
                copy(node->board.begin(),node->board.end(),downBoard.begin());
                downBoard[2][1] = downBoard[1][1];
                downBoard[1][1] = ' ';
                Node down(downBoard, "down",3);
                node->next->push_back(down);
                createTree(level - 1, &down);

                //right
                vector<vector<char>> rightBoard(node->board.begin(),node->board.end());
                rightBoard[2][1] = rightBoard[2][0];
                rightBoard[2][0] = ' ';
                Node right(rightBoard, "right",3);
                node->next->push_back(right);
                createTree(level - 1, &right);

                //left
                vector<vector<char>> leftBoard(node->board.begin(),node->board.end());
                leftBoard[2][1] = leftBoard[2][2];
                leftBoard[2][2] = ' ';
                Node left(leftBoard, "left",3);
                node->next->push_back(left);
                createTree(level - 1, &left);
            } else if (location == "RIGHT") {
                //up
                vector<vector<char>> upBoard(node->board.begin(),node->board.end());
                upBoard[1][2] = upBoard[2][2];
                upBoard[2][2] = ' ';
                Node up(upBoard, "up",3);
                node->next->push_back(up);
                createTree(level - 1, &up);

                //down
                vector<vector<char>> downBoard(node->board.begin(),node->board.end());
                downBoard[1][2] = downBoard[0][2];
                downBoard[0][2] = ' ';
                Node down(downBoard, "down",3);
                node->next->push_back(down);
                createTree(level - 1, &down);

                //right
                vector<vector<char>> rightBoard(node->board.begin(),node->board.end());
                rightBoard[1][2] = rightBoard[1][1];
                rightBoard[1][1] = ' ';
                Node right(rightBoard, "right",3);
                node->next->push_back(right);
                createTree(level - 1, &right);


            } else if (location == "LEFT") {
                //up
                vector<vector<char>> upBoard(node->board.begin(),node->board.end());
                upBoard[1][0] = upBoard[2][0];
                upBoard[2][0] = ' ';
                Node up(upBoard, "up",3);
                node->next->push_back(up);
                createTree(level - 1, &up);

                //down
                vector<vector<char>> downBoard(node->board.begin(),node->board.end());
                downBoard[1][0] = downBoard[0][0];
                downBoard[0][0] = ' ';
                Node down(downBoard, "down",3);
                node->next->push_back(down);
                createTree(level - 1, &down);

                //left
                vector<vector<char>> leftBoard(node->board.begin(),node->board.end());
                leftBoard[1][0] = leftBoard[1][1];
                leftBoard[1][1] = ' ';
                Node left(leftBoard, "left",3);
                node->next->push_back(left);
                createTree(level - 1, &left);
            }

        } else {
            //space in center
            //up
            vector<vector<char>> upBoard(node->board.begin(),node->board.end());
            upBoard[1][1] = upBoard[2][1];
            upBoard[2][1] = ' ';
            Node up(upBoard, "up",4);
            node->next->push_back(up);
            createTree(level - 1, &up);

            //down
            vector<vector<char>> downBoard(node->board.begin(),node->board.end());
            downBoard[1][1] = downBoard[0][1];
            downBoard[0][1] = ' ';
            Node down(downBoard, "down",4);
            node->next->push_back(down);
            createTree(level - 1, &down);

            //right
            vector<vector<char>> rightBoard(node->board.begin(),node->board.end());
            rightBoard[1][1] = rightBoard[1][0];
            rightBoard[1][0] = ' ';
            Node right(rightBoard, "right",4);
            node->next->push_back(right);
            createTree(level - 1, &right);

            //left
            vector<vector<char>> leftBoard(node->board.begin(),node->board.end());
            leftBoard[1][1] = leftBoard[1][2];
            leftBoard[1][2] = ' ';
            Node left(leftBoard, "left",4);
            node->next->push_back(left);
            createTree(level - 1, &left);
        }
    }
}

void display(Node *self, int dash) {//using pre order-recursion
    if(self!= nullptr) {
        cout<<"-------"<<self->location<<"-------"<<endl;
        printBoard(self->board,dash);
        dash++;
        for (int i = 0; i < self->next->size(); ++i) {
            vector<Node> &node = *self->next;
            display(&node[i],dash);
        }
    }else{
        cout<<"Tree is empty"<<endl;
    }
}

int findMismatch(vector<vector<char>> board,vector<vector<char>> goalState){
    int mismatch = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if(board[i][j]!=goalState[i][j])
                mismatch++;
        }
    }
    return mismatch;
}

bool compareBoard(vector<vector<char>> board,vector<vector<char>> goalState){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(board[i][j]!=goalState[i][j]){
                return false;
            }
        }
    }
    return true;
}

void best_first_search(vector<vector<char>> goalState) {
    vector<Node> priority_queue;
    priority_queue.push_back(*root);
    while (priority_queue.size()>0){
        Node current = priority_queue[0];
        printBoard(current,0);
        priority_queue.erase(priority_queue.begin());
        if(compareBoard(current.board,goalState)){
            //found goal
            cout<<"Found!"<<endl;
            return;
        } else if(current.next->size()==0){
            //empty do nothing
            //reached leaf
        }
        else{
            vector<Node> &node = *current.next;
            for (int i = 0; i < node.size(); ++i) {
                priority_queue.push_back(node[i]);
            }

            bool changeFound = true;
            //bubble sort
            while (changeFound) {
                changeFound = false;
                for (int i = 0; i < priority_queue.size() - 1; ++i) {
                    for (int j = i + 1; j < priority_queue.size(); ++j) {
                        if (findMismatch(priority_queue[i].board, goalState) > findMismatch(priority_queue[j].board, goalState)) {
                            vector<vector<char>> temp = priority_queue[i].board;
                            priority_queue[i].board = priority_queue[j].board;
                            priority_queue[j].board = temp;
                            changeFound = true;
                        }
                    }
                }
            }
        }
    }
}


int main() {
    //initialize board
    vector<vector<char>> board;
    for (int i = 0; i < 3; ++i) {
        vector<char> temp;
        for (int j = 0; j < 3; ++j) {
            temp.push_back('0');
        }
        board.push_back(temp);
    }

//    //set initial state
//    board[0][0] = '1';
//    board[0][1] = '8';
//    board[0][2] = '2';
//    board[1][0] = ' ';
//    board[1][1] = '4';
//    board[1][2] = '3';
//    board[2][0] = '7';
//    board[2][1] = '6';
//    board[2][2] = '5';

    //set initial state
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = ' ';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '4';
    board[2][1] = '7';
    board[2][2] = '8';

    //initialize board
    vector<vector<char>> goalState;
    for (int i = 0; i < 3; ++i) {
        vector<char> temp;
        for (int j = 0; j < 3; ++j) {
            temp.push_back('0');
        }
        goalState.push_back(temp);
    }

    //set initial state
    goalState[0][0] = '1';
    goalState[0][1] = '2';
    goalState[0][2] = '3';
    goalState[1][0] = '4';
    goalState[1][1] = '5';
    goalState[1][2] = '6';
    goalState[2][0] = '7';
    goalState[2][1] = '8';
    goalState[2][2] = ' ';

    //root set as initial state
    root = new Node(board, "root",3);
    createTree(3,root);
//    display(root,0);
    best_first_search(goalState);
    return 0;
}