#ifndef QUEUETURN_H
#define QUEUETURN_H

#include "MyQueue.cpp"
 

#include "Patient.h" 
#include <string>

class QueueTurn {
private:
    MyQueue<Patient>* turnsPatients;
    int countTurn;

public:
    QueueTurn() : turnsPatients(), countTurn(0) {}

    void createTurnByCategory(Patient patient) {
        switch (patient.getCategory()) {
            case 'A':
            case 'E':
            case 'G':
                createTurn(patient);
                break;
            default:
                break;
        }
    }

    void createTurn(const Patient& patient) {
        countTurn++;
        turnsPatients.push(patient.getName() + " - " + patient.getCategory() + std::to_string(countTurn));
    }

    Object showNextTurn() const {
        if (!turnsPatients.isEmpty()) {
            return turnsPatients.peek();
        }
        return Object(); // Devuelve un objeto vacío si la cola está vacía
    }

    Object attendTurn() {
        if (!turnsPatients.isEmpty()) {
            Object turnAttend = turnsPatients.peek();
            turnsPatients.poll();
            return turnAttend;
        }
        return Object(); // Devuelve un objeto vacío si la cola está vacía
    }

    bool isEmpty() const {
        return turnsPatients.isEmpty();
    }
};

#endif
