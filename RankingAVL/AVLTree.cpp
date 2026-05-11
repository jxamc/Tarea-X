#include "AVLTree.h"

AVLTree::AVLTree() {
    root = NULL;
    totalNodes = 0;
}

int AVLTree::getHeight(Node* node) {
    if (node == NULL)
        return 0;

    return node->height;
}

int AVLTree::getBalance(Node* node) {
    if (node == NULL)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* AVLTree::insert(Node* node, Student student) {

    if (node == NULL) {
        Node* newNode = new Node();

        newNode->data = student;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;

        totalNodes++;

        return newNode;
    }

    if (student.skill_score < node->data.skill_score)
        node->left = insert(node->left, student);

    else if (student.skill_score > node->data.skill_score)
        node->right = insert(node->right, student);

    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && student.skill_score < node->left->data.skill_score)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && student.skill_score > node->right->data.skill_score)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && student.skill_score > node->left->data.skill_score) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && student.skill_score < node->right->data.skill_score) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::insertStudent(Student student) {
    root = insert(root, student);
}

void AVLTree::inOrder(Node* node) {

    if (node != NULL) {

        inOrder(node->right);

        cout << node->data.full_name
             << " - Score: "
             << node->data.skill_score
             << endl;

        inOrder(node->left);
    }
}

void AVLTree::showRanking() {

    if (root == NULL) {
        cout << "No hay estudiantes registrados\n";
        return;
    }

    cout << "\n===== RANKING ACADEMICO =====\n";
    inOrder(root);
}

Node* AVLTree::search(Node* node, int skill_score) {

    if (node == NULL || node->data.skill_score == skill_score)
        return node;

    if (skill_score < node->data.skill_score)
        return search(node->left, skill_score);

    return search(node->right, skill_score);
}

void AVLTree::searchByScore(int score) {

    Node* result = search(root, score);

    if (result == NULL) {
        cout << "Estudiante no encontrado\n";
    }
    else {

        cout << "\n===== ESTUDIANTE ENCONTRADO =====\n";

        cout << "ID: " << result->data.student_id << endl;
        cout << "Nombre: " << result->data.full_name << endl;
        cout << "Carrera: " << result->data.career << endl;
        cout << "Semestre: " << result->data.semester << endl;
        cout << "GPA: " << result->data.gpa << endl;
        cout << "Skill Score: " << result->data.skill_score << endl;
    }
}

void AVLTree::showStatistics() {

    cout << "\n===== ESTADISTICAS AVL =====\n";

    cout << "Altura del arbol: "
         << getHeight(root)
         << endl;

    cout << "Factor de balance raiz: "
         << getBalance(root)
         << endl;

    cout << "Cantidad de nodos: "
         << totalNodes
         << endl;
}