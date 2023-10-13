class Animal {
    public:
        virtual void sound() {
            cout << "Animal makes a sound" << endl;
        }
}

class Dog: public Animal {
    public:
        void sound() {
            cout << "Dog barks" endl;
        }
}
