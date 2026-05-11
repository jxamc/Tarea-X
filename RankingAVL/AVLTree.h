#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
using namespace std;

struct Student {
    int student_id;
    string full_name;
    string career;
    int semester;
    float gpa;
    int skill_score;
};

struct Node {
    Student data;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
private:
    Node* root;
    int totalNodes;

    int getHeight(Node* node);
    int getBalance(Node* node);

    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);

    Node* insert(Node* node, Student student);

    void inOrder(Node* node);
    Node* search(Node* node, int skill_score);

public:
    AVLTree();

    void insertStudent(Student student);
    void showRanking();
    void searchByScore(int score);
    void showStatistics();
};

#endif