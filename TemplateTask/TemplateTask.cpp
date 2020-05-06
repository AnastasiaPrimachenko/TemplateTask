#include "Queue.h"

int main()
{
    Queue <int> first(1, 10);
    for (int i = 2; i <= 10; ++i) {
        first.push(i);
    }
    cout << "When trying to add more than allowed: ";
    first.push(11);
    cout << "Queue before deleting an element:";
    first.print();
    cout << "Number of elements: ";
    cout << first.count(0) << endl;
    cout << endl;
    cout << "Queue after deleting an element:";
    first.pop();
    first.print();
    cout << "Number of elements: ";
    cout << first.count(0) << endl;
    cout << endl;
    cout << "Creating second queue: ";
    Queue <int> second(11, 5);
    for (int i = 12; i <= 15; ++i) {
        second.push(i);
    }
    second.print();
    cout << endl;
    cout << "After uniting the queues: ";
    first.unite(second);
    first.print();
    cout << "Number of elements: ";
    cout << first.count(0) << endl;
    cout << endl;
    cout << "Adding to the united queue: ";
    first.push(16);
    first.print();
    cout << "Number of elements: ";
    cout << first.count(0) << endl;
    cout << endl;
    cout << "When trying to add more than allowed: ";
    first.push(17);
}

