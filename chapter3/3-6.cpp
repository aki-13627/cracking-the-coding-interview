#include <bits/stdc++.h>
using namespace std;

class AnimalCenter {
   private:
    queue<pair<string, int>> dog;
    queue<pair<string, int>> cat;

   public:
   enum Animal {
        DOG,
        CAT,
    };
    void enqueue(string name, Animal type, int id) {
        if (type == DOG) {
            dog.push(make_pair(name, id));
        } else {
            cat.push(make_pair(name, id));
        }
    }

    void dequeueAny() {
        if (dog.empty() && cat.empty()) {
            throw runtime_error("no animals exist");
        }

        if (dog.empty()) {
            dequeueCat();
        } else if (cat.empty()) {
            dequeueDog();
        } else {
            if (dog.front().second < cat.front().second) {
                dequeueDog();
            } else {
                dequeueCat();
            }
        }
    }
    void dequeueDog() {
        if (dog.empty()) throw runtime_error("no dog exist");
        cout << "dequeueing cat: " << dog.front().first << endl;
        dog.pop();
    }
    void dequeueCat() {
        if (cat.empty()) throw runtime_error("no cat exist");
        cout << "dequeueing cat: " << cat.front().first << endl;
        cat.pop();
    }
};

int main() {
    AnimalCenter center;

    center.enqueue("Pochi", AnimalCenter::DOG, 1);
    center.enqueue("Tama", AnimalCenter::CAT, 2);
    center.enqueue("Shiro", AnimalCenter::DOG, 3);

    center.dequeueAny();  // → Pochi（id 1）
    center.dequeueAny();  // → Tama（id 2）
    center.dequeueAny();  // → Shiro（id 3）
}
