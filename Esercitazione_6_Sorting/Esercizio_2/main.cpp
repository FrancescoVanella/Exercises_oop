#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

vector<int> randomVector(unsigned int n, unsigned int r)
{
    // Creo un vettore ordinato partendo da 1.
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    //  numeri random compresi tra 0 e 100.
    srand(r);
    for(unsigned int i = 0; i < n; i++)
        v[i] = rand() % 100;

    return v;
}



int main()
{
    unsigned int r = 0;

    cout << "Enter the dimension of the vector: " << endl;
    unsigned int n;
    cin >> n;

    unsigned int t = 50;



    cout << "Test 1: change the seed" << endl;

    // Inizializzo il numero di iterazioni del ciclo while per creare vettori diversi
    unsigned int d = 50;

    while(r < d)
    {
        unsigned int a = 0;
        unsigned int b = 0;
        double duration_m = 0;
        double duration_b = 0;

        // MERGESORT:


        while(a <= t)
        {
            // Genero un vettore random con la funzione randomVector per MergeSort
            vector<int> v = randomVector(n, r);

            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            MergeSort(v);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

            double duration = chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
            duration_m += duration;
            a++;
        }

        double avg_m = duration_m / t;
        cout << "Average duration for MergeSort: " << avg_m << " microseconds" << endl;


        // BUBBLESORT:


        while(b <= t)
        {
            // Genero un vettore random con la funzione randomVector per BubbleSort
            vector<int> w = randomVector(n, r);

            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            BubbleSort(w);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

            double duration = chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
            duration_b += duration;
            b++;
        }

        // Calcolo la media dei tempi
        double avg_b = duration_b / t;
        cout << "Average duration for BubbleSort: " << avg_b << " microseconds" << endl;
        cout << endl;

        // Aumento di 10 il seme e ripeto il ciclo.
        r += 10;
    }

    cout << endl;


    cout << "Test 2: change the dimension" << endl;

    // Inizializzo il numero di iterazioni del ciclo while per creare vettori diversi
    unsigned int p = n * n;

    while(n < p)
    {
        unsigned int a = 0;
        unsigned int b = 0;
        double duration_m = 0;
        double duration_b = 0;

        // MERGESORT:

        while(a <= t)
        {
            // Genero un vettore random con la funzione randomVector per MergeSort
            vector<int> v = randomVector(n, r);

            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            MergeSort(v);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

            double duration = chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
            duration_m += duration;
            a++;

        }

        double avg_m = duration_m / t;
        cout << "Average duration for MergeSort: " << avg_m << " microseconds" << endl;


        // BUBBLESORT:

        while(b <= t)
        {
            // Genero un vettore random con la funzione randomVector per BubbleSort
            vector<int> w = randomVector(n, r);

            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            BubbleSort(w);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

            double duration = chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
            duration_b += duration;
            b++;

        }

        double avg_b = duration_b / t;
        cout << "Average duration for BubbleSort: " << avg_b << " microseconds" << endl;
        cout << endl;
        n += n;
    }


    return 0;
}
