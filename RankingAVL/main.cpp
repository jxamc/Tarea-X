#include "AVLTree.h"

int main() {

    AVLTree ranking;

    int option;

    do {

        cout << "\n===== MENU AVL =====\n";
        cout << "1. Insertar estudiante\n";
        cout << "2. Mostrar ranking academico\n";
        cout << "3. Buscar por skill_score\n";
        cout << "4. Mostrar estadisticas AVL\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch(option) {

            case 1: {

                Student s;

                cin.ignore();

                cout << "ID: ";
                cin >> s.student_id;

                cin.ignore();

                cout << "Nombre completo: ";
                getline(cin, s.full_name);

                cout << "Carrera: ";
                getline(cin, s.career);

                cout << "Semestre: ";
                cin >> s.semester;

                cout << "GPA: ";
                cin >> s.gpa;

                cout << "Skill Score: ";
                cin >> s.skill_score;

                ranking.insertStudent(s);

                cout << "Estudiante insertado correctamente\n";

                break;
            }

            case 2:
                ranking.showRanking();
                break;

            case 3: {

                int score;

                cout << "Ingrese skill_score: ";
                cin >> score;

                ranking.searchByScore(score);

                break;
            }

            case 4:
                ranking.showStatistics();
                break;

            case 5:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while(option != 5);

    return 0;
}