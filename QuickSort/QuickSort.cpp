// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <thread>

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int HigherOrLower(int* array, int low, int high) {
    int middle = array[high];

    int i = (low - 1);

    //om i arrayn på plats j, om detta värdet är mindre än middle värdet ex {9,3,1,2}, 
    //denna loppen kmr byta plats med 9 och 1
    for (int j = low; j < high; j++) {
        if (array[j] <= middle) {
            i++;
            Swap(&array[i], &array[j]);
        }
            
    }
    
    Swap(&array[i + 1], &array[high]);
    //returnar värde 1 då efter första interaktionen. 
    return(i + 1);
}

void PrintTimeForFunction(clock_t start, clock_t end, std::string message) {
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    std::cout << message << std::setprecision(10) << time_taken << " sec \n";
}
bool ListIsSorted(int* array, int size) {
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1 && array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
void PrintList(int* array, int size,clock_t start =0, clock_t end =0, std::string message="") {

    PrintTimeForFunction(start, end, message);
    if (size > 1000) {
        for (int i = 0; i < 0; i++) {
            std::cout << array[i] << " ";
        }
    }
    else
    {
        for (int i = 0; i < size;i++) {
            std::cout << array[i] << " ";
        }
    }
    

    for (int i = 0; i < 1;i++) {
        std::cout << "\n";
        std::cout << "\n";
    }
    
} 


void QuickSort(int* array, int low, int high, int depth) {
    
    if (low < high) 
    {
        int mid = HigherOrLower(array, low, high);
        //vänster sida av mitten av arrayen blir sorterad då de som är vänster om mitten är mindre.
        QuickSort(array, low, mid - 1, depth + 1);
        //högersida av mitten av arryen blir sorterad då de som är höger om mitten är större.
        QuickSort(array, mid + 1, high, depth + 1);
     
    }
    
}



void BubbleSort(int* array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1;j++) {
            if (array[j] > array[j + 1]) {
                Swap(&array[j], &array[j + 1]);

            }
        }
    }
}



int main()
{
    srand((unsigned int)time(NULL));
     const int count = 10000;
     int* list = new int[count];
     int num;
     int* list2 = new int[count];

   for (int i = 0; i < count; i++) {
       num = rand() %1000 + 1 ;
       list[i] = num;
       list2[i] = num;
   }

    //PrintList(list, count);
    clock_t start_BubbleSort = clock();
    BubbleSort(list, count);
    clock_t end_BubbleSort = clock();
    std::string message_BubbleSort = "Bubble Sort takes ";

    clock_t start_QuickSort = clock();
    QuickSort(list2, 0, count-1, 0 );
    clock_t end_QuickSort = clock();
    std::string message_QuickSort = "Quick Sort takes ";
    clock_t end = clock();
    
    PrintList(list, count, start_BubbleSort, end_BubbleSort, message_BubbleSort);

    PrintList(list2, count, start_QuickSort, end_QuickSort, message_QuickSort);


       
        

    //PrintList(list, count,start,end,message);

    //vad behövs för en sorterings algoritm?
    // en lista/array med siffror
    // en metod som gör sorteringen 
    // main enbart kallar på objektet
    //klassen är en void som bara skriver ut metoden.
    
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
