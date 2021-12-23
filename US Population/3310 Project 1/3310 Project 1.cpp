#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Data
{
    string name;
    int population = 0;
    int year = 0;

};

void selectionSort(Data* a, int sizeofArray)
{
    int count = 0;
    int temp = 0;
    for (int i = 0; i < sizeofArray; i++)
    {
        for (int j = i + 1; j < sizeofArray; j++)
        {
            count++;
            if (a[j].population < a[i].population)
            {
                temp = a[i].population;
                a[i].population = a[j].population;
                a[j].population = temp;
            }
        }
    }
}

int median(Data* arr, int sizeofArray)
{
    if (sizeofArray % 2 != 0)
        return arr[sizeofArray / 2].population;
    else
        return (arr[sizeofArray / 2].population + arr[((sizeofArray / 2) - 1)].population) / 2;
}


int mean_recursion(Data* ar, double sum, int n, int sizeofArray)
{
    double num = ar[n].population;
    sum += num;
    //cout << num << endl; //debug
    if (n == sizeofArray - 1)
    {
        cout << "\nThe mean of the population is:";
        return (sum / sizeofArray);
    }
    else
        return mean_recursion(ar, sum, n + 1, sizeofArray);
}


int main()
{
    ifstream population;
    population.open("StateData.txt");
    ifstream statename;
    statename.open("StateName.txt");


    int size_of_array;
    do {
        cout << "\nEnter '51', the number of States in the U.S. + District of Columbia:  ";
        cin >> size_of_array;
        if (size_of_array != 51)
        {
            cout << "Value is not valid, please try again\n";
        }
    } while (size_of_array != 51);


    Data* arr = new Data[size_of_array];

    for (int i = 0; i < size_of_array; i++)
    {
        statename >> arr[i].name;
        population >> arr[i].population;
        arr[i].year = 2020;
    }

    int mean = mean_recursion(arr, 0, 0, size_of_array);
    cout << endl << mean << endl << endl;

    double sum = 0;
    for (int i = 0; i < size_of_array; i++)
    {
        double num = arr[i].population;
        double diff = num - mean;
        double diffsq = diff * diff;
        sum += diffsq;
    }
    selectionSort(arr, size_of_array);
    median(arr, size_of_array);

    ifstream population1;
    population1.open("StateData.txt");
    ifstream statename1;
    statename1.open("StateName.txt");
    Data* dArray3 = new Data[size_of_array];

    for (int i = 0; i < size_of_array; i++)
    {
        statename1 >> dArray3[i].name;
        population1 >> dArray3[i].population;
        if (dArray3[i].population == median(arr, size_of_array))
        {
            cout << "\nThe state with the median population is " << arr[i].name << " with a population of " << median(arr, size_of_array) << " people. \n\n\n";
        }
    }

    cout << "The variance is: \n" << setprecision(14) << sum / (size_of_array - 1.0) << endl;
    cout << "\nThe standard deviation is: \n" << setprecision(13) << pow(sum / (size_of_array - 1.0), 0.5) << endl;

    /*int sum = 0;
    for (int i = 0; i < size_of_array; i++)
    {
        population1 >> dArray3[i];
        sum += dArray3[i];

    }
    cout << endl << endl << sum <<  "\n\n";
    */ //debugging

    population.close();
    statename.close();
    population1.close();

    return 0;
}