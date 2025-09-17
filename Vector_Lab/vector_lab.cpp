#include <iostream>
#include <cmath>
using namespace std;
void get_vector(double vector_1[], double vector_2[]);
void cross_product(double cross_product_result[], double vector_1[], double vector_2[]);
void normalize(double cross_product_result[], double normalized_value);
void display_vector(double cross_product_result[], double normalized_value);
const int x=0, y=1, z=2;

int main() 
{
    //initializing variables/arrays
    double normalized_value;
    double cross_product_result[3];
    double vector_1[3],vector_2[3];

    //calling functions
    get_vector(vector_1, vector_2);
    cross_product(cross_product_result, vector_1, vector_2);
    normalize(cross_product_result, normalized_value);
    display_vector(cross_product_result, normalized_value);

    return 0;
}

void get_vector(double vector_1[], double vector_2[])
{
    cout << "Give me your first vector in form ?IHAT ?JHAT ?KHAT" << endl;
    for(int i=0;i<3;i++)
    {
        cin >> vector_1[i];
    }
    cout << "Give me your second vector in form ?IHAT ?JHAT ?KHAT" << endl;
    for(int i=0;i<3;i++)
    {
        cin >> vector_2[i];
    } 
}

void cross_product(double cross_product_result[], double vector_1[], double vector_2[])
{
    double result_IHAT, result_JHAT, result_KHAT;
    result_IHAT = (vector_1[y] * vector_2[z]) - (vector_1[z] * vector_2[y]);
    result_JHAT = (vector_1[z] * vector_2[x]) - (vector_1[x] * vector_2[z]);
    result_KHAT = (vector_1[x] * vector_2[y]) - (vector_1[y] * vector_2[x]);
    for(int i=0;i<3;i++)
    {
        switch (i){
            case 0:
                cross_product_result[i] = result_IHAT;
            case 1:
                cross_product_result[i] = result_JHAT;
            case 2:
                cross_product_result[i] = result_KHAT;
        }
    }
}

void normalize(double cross_product_result[], double normalized_value){
    normalized_value = sqrt(pow(cross_product_result[0], 2.0) + pow(cross_product_result[1], 2.0) + pow(cross_product_result[2], 2.0)); 
}

void display_vector(double cross_product_result[], double normalized_value)
{
    cout << "Here is your vector: ";
    for(int i=0;i<3;i++)
    {
        cout << cross_product_result[i];
    }
    cout << endl << "Here is your normalized value:" << normalized_value;
}