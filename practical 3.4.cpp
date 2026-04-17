 #include<iostream>
using namespace std;


template <class T>
void display(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <class T>
T findMax(T arr[], int n)
{
    T max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}


template <class T>
void reverseArr(T arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main()
{
    int n = 5;


    int a[] = {1, 5, 3, 9, 2};

    cout << "Integer Array:\n";
    display(a, n);
    cout << "Max: " << findMax(a, n) << endl;

    reverseArr(a, n);
    cout << "Reversed: ";
    display(a, n);


    float b[] = {1.1, 2.5, 0.5, 4.2, 3.3};

    cout << "\nFloat Array:\n";
    display(b, n);
    cout << "Max: " << findMax(b, n) << endl;

    reverseArr(b, n);
    cout << "Reversed: ";
    display(b, n);


    char c[] = {'A', 'D', 'B', 'Z', 'C'};

    cout << "\nCharacter Array:\n";
    display(c, n);
    cout << "Max: " << findMax(c, n) << endl;

    reverseArr(c, n);
    cout << "Reversed: ";
    display(c, n);

    return 0;
}
