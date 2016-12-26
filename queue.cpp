/*
    Author: Eric Khoo Jiun Hooi
    File Name: 
    Created At:
*/

#include <iostream>
using namespace std;


struct Pelajar {
    string name;
    string course;
    int year;
};

class QueuePelajar {
    private:
        int front;
        int back;
        int counter;
        const static int maxSize = 3;
        Pelajar item[maxSize];
    public:
        QueuePelajar();
        ~QueuePelajar();
        bool isFull();
        void enQueue(string n, string c, int y);
        void printAll();
        bool isEmpty();
        void deQueue();
};

QueuePelajar::QueuePelajar() 
    : front(0), back(1), counter(0)
{
}

QueuePelajar::~QueuePelajar() 
{
}

bool QueuePelajar::isFull()
{
    if (counter == maxSize) {
        return true;
    } else {
        return false;
    }
    // return back > maxSize - 1
}

void QueuePelajar::enQueue(string n, string c, int y) 
{
    if (this->isFull()) {
        cout << "Queue is full, unable to enqueue" << endl;
    } else {
        item[back].name = n;
        item[back].course = c;
        item[back].year = y;
        back = (back + 1) % maxSize;
        counter += 1;
    }
}

void QueuePelajar::printAll()
{
    int count = 0;
    int temp = front;
    while (counter == front) {
        cout << "Name: " << item[front].name << endl;
        cout << "Course: " << item[front].name << endl;
        cout << "Year: " << item[front].year << endl;
        temp = (temp+1) % maxSize;
    }
}

bool QueuePelajar::isEmpty() 
{
    if (counter == 0) {
        return true;
    } else {
        return false;
    }
}

void QueuePelajar::deQueue()
{
    if (this->isEmpty()) {
        cout << "queue is empty" << endl;
    } else {
        front = (front + 1) % maxSize;
        counter -= 1;
    }
}

int main() {
    QueuePelajar qp;
    qp.enQueue("jame", "SCSR", 3);
    qp.enQueue("bond", "SCSJ", 4);
    qp.enQueue("bond", "SCSJ", 4);
    qp.printAll();
}
