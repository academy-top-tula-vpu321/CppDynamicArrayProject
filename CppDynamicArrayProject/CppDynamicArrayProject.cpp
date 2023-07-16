#include <iostream>

void ArrayPushBack(int*& array, int& size, int value);
void ArrayInsert(int*& array, int& size, int index, int value);

int ArrayPopBack(int*& array, int& size);
int ArrayRemove(int*& array, int& size, int index);

void ArrayPrint(int* array, int size);

int main()
{
    srand(time(nullptr));

    int a = 10;
    int* ptr = &a;
    
    int row = 3;
    int column = 4;

    int** matrix = new int*[row];
    for (int i = 0; i < row; i++)
        matrix[i] = new int[column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = rand() % 100;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }

    for (int i = 0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;

    
    

    int** zmatrix = new int*[row];

    for (int i = 0; i < row; i++)
    {
        int size = 3 + rand() % 4;
        zmatrix[i] = new int[size + 1];
        zmatrix[i][0] = size;

        for (int j = 1; j < size + 1; j++)
            zmatrix[i][j] = rand() % 100;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < zmatrix[i][0] + 1; j++)
            std::cout << zmatrix[i][j] << "\t";
        std::cout << "\n";
    }

    for (int i = 0; i < row; i++)
        delete[] zmatrix[i];
    delete[] zmatrix;

    /*
    int* sizes = new int[row];
    for (int i = 0; i < row; i++)
    {
        sizes[i] = 3 + rand() % 4;
        zmatrix[i] = new int[sizes[i]];
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < sizes[i]; j++)
            zmatrix[i][j] = rand() % 100;

    std::cout << "\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
            std::cout << zmatrix[i][j] << "\t";
        std::cout << "\n";
    }
     */   
        


    /*

    int size = 10;
    int* array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;
    ArrayPrint(array, size);

    ArrayPushBack(array, size, rand() % 100);
    ArrayPrint(array, size);

    ArrayInsert(array, size, 5, rand() % 100);
    ArrayPrint(array, size);

    std::cout << ArrayPopBack(array, size) << "\n";
    ArrayPrint(array, size);

    std::cout << ArrayRemove(array, size, 4) << "\n";
    ArrayPrint(array, size);*/
}



void ArrayPrint(int* array, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void ArrayPushBack(int*& array, int& size, int value)
{
    int* arrayNew = new int[size + 1];
    for (int i = 0; i < size; i++)
        arrayNew[i] = array[i];
    arrayNew[size] = value;

    delete array;
    array = arrayNew;

    size++;
}

void ArrayInsert(int*& array, int& size, int index, int value)
{
    if (index < 0)
        index = 0;
    if (index >= size)
    {
        ArrayPushBack(array, size, value);
        return;
    }

    int* arrayNew = new int[size + 1];
    for (int i = 0; i < index; i++)
        arrayNew[i] = array[i];
    arrayNew[index] = value;
    for (int i = index; i < size; i++)
        arrayNew[i + 1] = array[i];

    size++;
    delete[] array;
    array = arrayNew;
}

int ArrayRemove(int*& array, int& size, int index)
{
    if (index < 0)
        index = 0;
    if (index >= size)
        return ArrayPopBack(array, size);

    int value = array[index];
    int* arrayNew = new int[size - 1];

    for (int i = 0; i < index; i++)
        arrayNew[i] = array[i];
    for (int i = index + 1; i < size; i++)
        arrayNew[i - 1] = array[i];

    delete[] array;
    size--;
    array = arrayNew;

    return value;
}

int ArrayPopBack(int*& array, int& size)
{
    int* arrayNew = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
        arrayNew[i] = array[i];
    int value = array[size - 1];

    delete[] array;
    array = arrayNew;
    size--;

    return value;
}


