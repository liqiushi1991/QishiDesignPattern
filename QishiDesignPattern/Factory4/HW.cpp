#include <string>
using namespace std;

struct Person
{
    int id;
    string name;
};

class PersonFactory
{
    int id = 0;
public:
    Person create_person(const string& name)
    {
        // todo
        Person p;
        p.id = id;
        p.name = name;
        id += 1;
        return p;
    }
};
