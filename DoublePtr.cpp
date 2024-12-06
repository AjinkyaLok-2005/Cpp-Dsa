#include<iostream>

using namespace std;

void update(int **p2)
{
    // p2 = p2 + 1;
    //kuch change hoga?? - NO

    // *p2 = *p2 + 1; 
    //kuch change hoga?? - YES

    **p2 = **p2 + 1; 
    //kuch change hoga?? - Yes 
}

int main()
{
    /*
    int i = 5;
    int* p = &i;
    int** p2 = &p;

    /*
    cout << endl << "Everything ok" << endl << endl;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;

    cout << endl;

    cout << &i << endl;
    cout << p << endl;
    cout << *p2 << endl;

    cout << endl;

    cout << &p << endl;
    cout << p2 << endl;



    cout << endl;
    cout << "before " << i << endl;
    cout << "before " << p << endl;
    cout << "before " << p2 << endl;
    update(p2);
    cout << "after " << i << endl;
    cout << "after " << p << endl;
    cout << "after " << p2 << endl;
    cout << endl;
    */

    int f = 8;
    int *p = &f;
    cout << (*p)++ << " ";
    cout << f << endl;

    int f = 8;
    int *p = &f;
    cout << *p++ << " "; //BOTH THE EXAMPLES ARE DIFFERENT
    cout << f << endl;

    int arr[6] = {11, 12 ,31};
    int *p = arr;
    cout << p[2] << endl;   //p[2] = *(p+2)  


    return 0;
}