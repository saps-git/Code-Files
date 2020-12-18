#include <iostream>
using namespace std;

template <class T> //to use any datatype we want
class Array
{
private: //basic attributes
    T *a;
    int sz;
    int length;

public:
    Array() // non parametrized constructor
    {
        sz = 10;
        length = 0;
        a = new T[sz];
    }
    Array(int s) // parametrized constructor
    {
        sz = s;
        length = 0;
        a = new T[sz];
    }
    ~Array() // destructor
    {
        delete[] a;
    }
    void Display(); //member functions declararion
    void Insert(T x, int index);
    void Delete(int index);
    void Append(T x);
    void Linear(T key);
    int Sum();
    //bool Sort();
};

template <class T>
void Array<T>::Display() //defination of the function
{
    for (int i = 0; i < sz; i++)
    {
        cout << a[i] << endl;
    }
}

template <class T>
void Array<T>::Insert(T x, int index)
{
    if (index >= 0 && index <= sz)
    {
        for (int i = length - 1; i > index; i--)
        {
            a[i + 1] = a[i];
        }
        a[index] = x;
        length++;
    }
}

template <class T>
void Array<T>::Delete(int index)
{
    T x = a[index];
    for (int i = index; i < sz; i++)
    {
        a[i] = a[i + 1];
    }
    length--;
    cout << x << endl;
}

template <class T>
void Array<T>::Append(T x)
{
    a[length++] = x;
}

template <class T>
void Array<T>::Linear(T key)
{
    for (int i = 0; i < sz; i++)
    {
        if (key == a[i])
            cout << i << endl;
    }
    //return 0;
}

template <class T>
int Array<T>::Sum()
{
    int sum = 0;
    for (int i = 0; i < sz; i++)
        sum = sum + a[i];
    return sum;
}

int main()
{
    int sz, ch, p;
    int O;
    int x;
    cout << "enter the size\n";
    cin >> sz;
    Array<int> arr(sz); //object creation
    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Insert at a specific\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";

        cout << "enter the choice\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "enter element to be added\n";
            cin >> x;
            arr.Append(x);
            break;
        case 2:
            cout << "enter positon of the element to be deleted\n";
            cin >> p;
            arr.Delete(p);
            break;
        case 3:
            cout << "Enter the element to be searched\n";
            cin >> x;
            arr.Linear(x);
            break;
        case 4:
            cout << "the total sum is:\n";
            O = arr.Sum();
            cout << O;
            break;
        case 5:
            cout << "the element and position \n";
            cin >> x >> p;
            arr.Insert(x, p);
            break;
        case 6:
            cout << "to display all the elements\n";
            arr.Display();
            break;
        }
    } while (ch < 7);
}
