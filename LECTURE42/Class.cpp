//Padding and Greedy Alignment
//https://chatgpt.com/share/675c04bc-41d4-8006-a27f-2ee30e4ba001

#include<iostream>
#include<cstring>
using namespace std;

class Hero
{
    private:
    //Properties
    int health;

    public:
    char * name;
    char level;
    static int timeToComplete;

    Hero()
    {
        cout << "Default Constructor Called " << endl;
        name = new char[100];
    }

    //Parametrised constructor
    Hero(int health)
    {
        //this is a pointer which is pointing to the object
        this -> health = health;
    }

    Hero(int health, char level)
    {
        this -> level = level;
        this -> health = health;
    }

    //copy constructor
    Hero(Hero& temp)
    {
        char * ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this -> name = ch;

        cout << "Copy Constructor called " << endl;
        this -> health = temp.health;
        this -> level = temp.level; 
    }

    void print()
    {
        cout << endl;
        cout << "[ Name: " << this -> name << " ,"; 
        cout << "Health: " << this -> health << " ,";
        cout << "Level: " << this -> level << " ]";
        cout << endl;
    }

    //getter
    int getHealth()
    {
        return health;
    }

    //getter
    char getLevel()
    {
        return level;
    }

    //setter
    void setHealth(int h)
    {
        health = h;
    }

    //setter
    void setLevel(char ch)
    {
        level = ch;
    }

    void setName(char name[])
    {
        strcpy(this-> name, name);
    }
    //strcpy is a function in C/C++ that is used to copy the contents 
    //of one string (source) into another string (destination)

    static int random()
    {
        return timeToComplete;
    }

    ~Hero()
    {
        cout << "Destructor called " << endl;
    }

};

int Hero :: timeToComplete = 5; 

int main()
{

    
    // cout << Hero :: timeToComplete << endl;


    cout << Hero :: random() << endl;












    // //Static
    // Hero a;
    
    // //Dynamic
    // Hero * b = new Hero();
    // //Manually destructor called 
    // delete b;
    
    
    // return 0;
        
}
    
    
    
    
    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[7] = "Babbar";
    // hero1.setName(name);

    // //hero1.print();

    // //use default copy constructor

    // Hero hero2(hero1);
    // //hero2.print();
    // //hero hero2 = hero1;


    // hero1.name[0] = 'G';
    // hero1.print();

    // hero2.print();

    // hero1 = hero2; 

    // hero1.print();
    // hero2.print();


    // //object created statically
    // Hero ramesh(10);
    // cout << "Address of ramesh " << &ramesh << endl;
    // ramesh.getHealth();
    
    // //dynamically
    // Hero * h = new Hero(11);







    // //static allocation
    // Hero a;
    // a.setLevel('B');
    // a.setHealth(80);

    // cout << "Level is " << a.level << endl;
    // cout << "health is " << a.getHealth() << endl;
 
    // //Dynamic Allocation
    // Hero * b = new Hero;
    
    // b -> setLevel('A');
    // b -> setHealth(70);

    // cout << "Level is " << (*b).level << endl;
    // cout << "health is " << (*b).getHealth() << endl;
    // //SAME AS 
    // cout << "Level is " << b->level << endl;
    // cout << "health is " << b->getHealth() << endl;







    // //creation of Object
    // Hero ramesh;

    // //using getter
    // cout << "Ramesh health is " << ramesh.getHealth() << endl;
    
    // //using setter
    // ramesh.setHealth(70);
    // ramesh.level = 'A';

    // // cout << "size: " << sizeof(h1) << endl;
    // cout << "Health is: " << ramesh.getHealth() << endl;
    // cout << "level is: " << ramesh.level << endl;

//     return 0;
// }