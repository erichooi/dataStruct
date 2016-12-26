#include <iostream>
using namespace std;


struct Pelajar 
{
    string name;
    string kursus;
    int tahun;
    Pelajar *next;
};

class ListPelajar 
{
    private:
        Pelajar *head = nullptr;
    public:
        ListPelajar() {};
        ~ListPelajar() {};
        void addPelajar(string, string, int);
        void printPelajar();
};
/*
ListPelajar::~ListPelajar()
{
    Pelajar *travel = head;
    Pelajar *follow = nullptr;
    while (travel != nullptr) {
        follow = travel;
        travel = travel->next;
        delete follow;
    }
}
*/
void ListPelajar::addPelajar(string n, string k, int t) 
{
    // create record based on info
    Pelajar *newRec = new Pelajar;
    newRec->name = n;
    newRec->kursus = k;
    newRec->tahun = t;
    newRec->next = nullptr;

    // traverse the existing list
    Pelajar *travel = head;
    Pelajar *follow = nullptr;
    while(travel != nullptr) {
        follow = travel;
        travel = travel->next;
    }

    // insert the new record into the list
    if (head == nullptr) {
        head = newRec;
    } else {
        travel = newRec;
    }
}

void ListPelajar::printPelajar() 
{
    Pelajar *temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << endl;
        cout << "Kursus: " << temp->kursus << endl;
        cout << "Tahun: " << temp->tahun << endl;
        temp = temp->next;
    }
}

int main(int argc, char *argv[])
{
    ListPelajar lp;
    lp.addPelajar("jame", "Computer science", 3); 
    lp.addPelajar("bon", "Architecture", 4);
    lp.addPelajar("khoo", "Network", 1);
    lp.printPelajar();
    return 0;
}
