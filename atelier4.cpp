//exercice 1:
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Function to add two complex numbers
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Function to subtract two complex numbers
    Complex operator-(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Function to multiply two complex numbers
    Complex operator*(const Complex &c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Function to divide two complex numbers
    Complex operator/(const Complex &c) {
        double denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator,
                       (imag * c.real - real * c.imag) / denominator);
    }

    // Function to display a complex number
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    double r1, i1, r2, i2;
    cout << "Enter real and imaginary parts of the first complex number: ";
    cin >> r1 >> i1;
    cout << "Enter real and imaginary parts of the second complex number: ";
    cin >> r2 >> i2;

    Complex c1(r1, i1), c2(r2, i2);

    cout << "Choose an operation: 1. Addition 2. Subtraction 3. Multiplication 4. Division: ";
    int choice;
    cin >> choice;

    Complex result;
    switch (choice) {
        case 1:
            result = c1 + c2;
            break;
        case 2:
            result = c1 - c2;
            break;
        case 3:
            result = c1 * c2;
            break;
        case 4:
            result = c1 / c2;
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    cout << "Result: ";
    result.display();
    return 0;
}

//exercice 2:
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;

public:
    void set_value(string n, int a) {
        name = n;
        age = a;
    }
    virtual void display() = 0; // Pure virtual function
};

class Zebra : public Animal {
public:
    void display() override {
        cout << "Zebra Name: " << name << ", Age: " << age << " years. Origin: Africa." << endl;
    }
};

class Dolphin : public Animal {
public:
    void display() override {
        cout << "Dolphin Name: " << name << ", Age: " << age << " years. Origin: Ocean." << endl;
    }
};

int main() {
    Zebra z;
    Dolphin d;

    z.set_value("Zara", 5);
    d.set_value("Dolly", 3);

    z.display();
    d.display();

    return 0;
}
//exercice 3
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string nom, prenom;
    string date_naissance;

public:
    // Constructor for initializing the person details
    Person(string n, string p, string dob) : nom(n), prenom(p), date_naissance(dob) {}

    // Virtual function for displaying person details
    virtual void afficher() {
        cout << "Nom: " << nom << ", Prenom: " << prenom << ", Date de naissance: " << date_naissance << endl;
    }
};

class Employe : public Person {
protected:
    double salaire;

public:
    Employe(string n, string p, string dob, double sal) : Person(n, p, dob), salaire(sal) {}

    void afficher() override {
        Person::afficher();
        cout << "Salaire: " << salaire << endl;
    }
};

class Chef : public Employe {
protected:
    string service;

public:
    Chef(string n, string p, string dob, double sal, string serv)
        : Employe(n, p, dob, sal), service(serv) {}

    void afficher() override {
        Employe::afficher();
        cout << "Service: " << service << endl;
    }
};

class Directeur : public Chef {
private:
    string societe;

public:
    Directeur(string n, string p, string dob, double sal, string serv, string soc)
        : Chef(n, p, dob, sal, serv), societe(soc) {}

    void afficher() override {
        Chef::afficher();
        cout << "Societe: " << societe << endl;
    }
};

int main() {
    Directeur dir("Dupont", "Jean", "01/01/1980", 75000, "Informatique", "TechCorp");
    dir.afficher();

    return 0;
}
//exercice 4:
#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
private:
    float x, y, z;

public:
    // Constructor with default values
    Vector3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    // Display components
    void display() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    // Sum of two vectors
    Vector3D add(const Vector3D &v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    // Dot product of two vectors
    float dotProduct(const Vector3D &v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    // Check if two vectors coincide
    bool coincide(const Vector3D &v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    // Calculate norm (magnitude)
    float norm() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Return the vector with the larger norm (using reference)
    static const Vector3D& normMax(const Vector3D &v1, const Vector3D &v2) {
        return (v1.norm() > v2.norm()) ? v1 : v2;
    }
};

int main() {
    Vector3D v1(3, 4, 5), v2(1, 2, 3);
    cout << "Vector 1: ";
    v1.display();
    cout << "Vector 2: ";
    v2.display();

    cout << "Sum: ";
    v1.add(v2).display();

    cout << "Dot Product: " << v1.dotProduct(v2) << endl;
    cout << "Do they coincide? " << (v1.coincide(v2) ? "Yes" : "No") << endl;
    cout << "Vector with max norm: ";
    Vector3D::normMax(v1, v2).display();

    return 0;
}
//exercice 5:
#include <iostream>
using namespace std;

class Test {
private:
    static int counter;

public:
    void call() {
        counter++;
        cout << "Function call() invoked " << counter << " times." << endl;
    }
};

// Initialize the static variable
int Test::counter = 0;

int main() {
    Test t1, t2;
    t1.call();
    t1.call();
    t2.call();

    return 0;
}
//exercice 5:
#include <iostream>
using namespace std;

class Test {
private:
    static int counter;

public:
    void call() {
        counter++;
        cout << "Function call() invoked " << counter << " times." << endl;
    }
};

// Initialize the static variable
int Test::counter = 0;

int main() {
    Test t1, t2;
    t1.call();
    t1.call();
    t2.call();

    return 0;
}
//exercice 6:
#include <iostream>
using namespace std;

class Point {
private:
    float x, y;

public:
    // Constructor
    Point(float x = 0, float y = 0) : x(x), y(y) {}

    // Move point by given dx and dy
    void move(float dx, float dy) {
        x += dx;
        y += dy;
    }

    // Display point coordinates
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p(2.0, 3.0);
    cout << "Initial point: ";
    p.display();

    p.move(1.0, -1.5);
    cout << "After moving: ";
    p.display();

    return 0;
}
//exercice 7:
#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    stack<int> s;

public:
    void push(int value) {
        s.push(value);
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Popped " << s.top() << " from the stack." << endl;
            s.pop();
        }
    }
};

int main() {
    Stack p1, p2;
    p1.push(5);
    p1.push(10);
    p1.pop();
    p1.pop();
    p1.pop();  // Test popping from an empty stack

    return 0;
}
//exercice 8:
#include <iostream>
using namespace std;

class File {
private:
    char *data;
    int length;

public:
    File(int len) : length(len) {
        data = new char[length];
    }

    ~File() {
        delete[] data;
    }

    void create() {
        for (int i = 0; i < length; i++) {
            data[i] = 'A' + i % 26;  // Arbitrary fill
        }
    }

    void display() const {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    File f(10);
    f.create();
    f.display();

    return 0;
}
//exercice 9:
#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

class List {
private:
    Element *head;

public:
    List() : head(nullptr) {}

    ~List() {
        while (head != nullptr) {
            Element *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value) {
        Element *newElem = new Element{value, head};
        head = newElem;
        cout << "Added " << value << " to the list." << endl;
    }

    void remove() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Element *temp = head;
        head = head->next;
        cout << "Removed " << temp->data << " from the list." << endl;
        delete temp;
    }

    void display() const {
        Element *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    List list;
    list.add(1);
    list.add(2);
    list.display();
    list.remove();
    list.display();

    return 0;
}
//exercice 10:
#include <iostream>
#include <string>
using namespace std;

void parseDateTime(const string &datetime) {
    string day = datetime.substr(0, 2);
    string month = datetime.substr(2, 2);
    string year = datetime.substr(4, 4);
    string hour = datetime.substr(8, 2);
    string minute = datetime.substr(10, 2);

    cout << "Date: " << day << "/" << month << "/" << year << endl;
    cout << "Time: " << hour << ":" << minute << endl;
}

int main() {
    string datetime = "010920091123";
    parseDateTime(datetime);

    return 0;
}
//exercice 11:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Traitement {
private:
    vector<int> vec;

public:
    void initialise() {
        int count = 0;
        while (count < 15) {
            int num;
            cout << "Enter an even integer: ";
            cin >> num;
            if (num != 0 && num % 2 == 0) {
                vec.push_back(num);
                count++;
            } else {
                cout << "Invalid input. Only even numbers (non-zero) are accepted." << endl;
            }
        }
    }

    void show(int index = 0) const {
        if (index < vec.size()) {
            cout << vec[index] << " ";
            show(index + 1);
        } else {
            cout << endl;
        }
    }

    friend double average(const Traitement &t) {
        double sum = 0;
        for (int num : t.vec) {
            sum += num;
        }
        return sum / t.vec.size();
    }

    friend double median(Traitement &t) {
        sort(t.vec.begin
//exercice 11:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Traitement {
private:
    vector<int> vec;

public:
    // Initialize vector with 15 even, non-zero integers
    void initialise() {
        int count = 0;
        while (count < 15) {
            int num;
            cout << "Enter an even integer: ";
            cin >> num;
            if (num != 0 && num % 2 == 0) {
                vec.push_back(num);
                count++;
            } else {
                cout << "Invalid input. Only even numbers (non-zero) are accepted." << endl;
            }
        }
    }

    // Recursive function to show elements in the vector
    void show(int index = 0) const {
        if (index < vec.size()) {
            cout << vec[index] << " ";
            show(index + 1);
        } else {
            cout << endl;
        }
    }

    // Friend function to calculate the average of elements
    friend double average(const Traitement &t) {
        double sum = 0;
        for (int num : t.vec) {
            sum += num;
        }
        return sum / t.vec.size();
    }

    // Friend function to calculate the median of elements
    friend double median(Traitement &t) {
        sort(t.vec.begin(), t.vec.end());
        int size = t.vec.size();
        if (size % 2 == 0) {
            return (t.vec[size / 2 - 1] + t.vec[size / 2]) / 2.0;
        } else {
            return t.vec[size / 2];
        }
    }
};

int main() {
    Traitement t;
    t.initialise();
    cout << "Vector elements: ";
    t.show();

    cout << "Average: " << average(t) << endl;
    cout << "Median: " << median(t) << endl;

    return 0;
}
