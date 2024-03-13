
#include <iostream>   

class Presenter
{
   private:
        QueueTurn turn;
        View view;
        
    public:
    Presenter(): {
        this->turn =  QueueTurn();
        this->view = View(this);
    }



void Presenter::Presenter() {
    turn = QueueTurn();
    view = View();
}

int Presenter::mostrarMenu() {
    int option = 0;
    try {
        option = std::stoi(view.readData(MENU));
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return option;
}

void Presenter::run() {
    int option = mostrarMenu();
    switch (option) {
        case 1:
            createTurn();
            break;
        case 2:
            showNextTurn();
            break;
        case 3:
            attendingTurn();
            break;
        case 0:
            view.showMessage("Fin del programa");
            exit(0);
            break;
        default:
            view.showMessage("Ingrese otra opcion");
            break;
    }
    do {
        run();
    } while (option != 4);
}

void Presenter::createTurn() {
    std::string name = view.readData("Ingrese el nombre del paciente");
    char category = selectCategory();
    Patient patient(name, category);
    turn.createTurnByCategory(patient);
}

char Presenter::selectCategory() {
    char category;
    do {
        category = view.readData("Ingrese la categoria del paciente: (A) Adulto Mayor, (E) Embarazada y  (G) Usuario General")[0];
        if (category != 'A' && category != 'E' && category != 'G') {
            view.showMessage("Categoria no valida");
        }
    } while (category != 'A' && category != 'E' && category != 'G');
    return category;
}

void Presenter::showNextTurn() {
    view.showMessage("Turno Siguiente. Modulo de Atención: " + turn.showNextTurn());
}

void Presenter::attendingTurn() {
    if (turn.isEmpty()) {
        view.showMessage("No hay turnos por atender");
        return;
    } else {
        view.showMessage("Turno atendido: " + turn.attendTurn());
    }
}

};