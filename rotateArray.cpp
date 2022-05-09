// Time Complexity: O(n)  | Auxiliary Space : O(1)

#include <iostream>

int Gcd(int a, int b);
void LeftRotate(int arr[], int d, int arrsize);
void Display(int arr[], int arrsize);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sizeArr = sizeof(arr) / sizeof(int);

    LeftRotate(arr, 2, sizeArr);
    Display(arr, sizeArr);
}

// Get Gcd of value a, b;
int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return Gcd(b, a % b);
}

// Left Rotate Array by element d.
void LeftRotate(int arr[], int d, int arrsize)
{
    // If d >= ArrSize, find it's mod and make it equal to rotate value.
    d = d % arrsize;
    int gcd = Gcd(d, arrsize);

    for (int i = 0; i < gcd; i++)
    {
        int temp = arr[i];
        int j = i;

        while (true)
        {
            int k = j + d;

            if (k >= arrsize)
                k = k - arrsize;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

// Display the array
void Display(int arr[], int arrsize)
{
    for (int i = 0; i < arrsize; i++)
        std::cout << arr[i] << " ";
}