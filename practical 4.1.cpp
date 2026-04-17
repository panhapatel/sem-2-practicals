#include <iostream>
using namespace std;

int main()
{
    int *arr = NULL;
    int size = 0;

    // 🔹 Insert
    int value;
    cout << "Enter value to insert: ";
    cin >> value;

    int *temp = new int[size + 1];

    for (int i = 0; i < size; i++)
        temp[i] = arr[i];

    temp[size] = value;

    delete[] arr;
    arr = temp;
    size++;

    // 🔹 Insert again
    cout << "Enter another value: ";
    cin >> value;

    temp = new int[size + 1];

    for (int i = 0; i < size; i++)
        temp[i] = arr[i];

    temp[size] = value;

    delete[] arr;
    arr = temp;
    size++;

    // 🔹 Display
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    // 🔹 Delete (position)
    int pos;
    cout << "\nEnter position to delete: ";
    cin >> pos;

    if (pos >= 0 && pos < size)
    {
        temp = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != pos)
            {
                temp[j] = arr[i];
                j++;
            }
        }

        delete[] arr;
        arr = temp;
        size--;
    }
    else
    {
        cout << "Invalid position\n";
    }

    // 🔹 Final display
    cout << "Updated Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    delete[] arr;

    return 0;
}
